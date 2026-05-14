#define DT_DRV_COMPAT zmk_input_processor_accel

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/input/input.h>
#include <zephyr/sys/util.h>

#if __has_include(<zephyr/drivers/input_processor.h>)
#include <zephyr/drivers/input_processor.h>
#elif __has_include(<drivers/input_processor.h>)
#include <drivers/input_processor.h>
#else
/* Fallback if input_processor.h is not found.
   ZMK might be too old or the path changed.
   We can define a basic wrapper if needed, but usually one of the above works in Zephyr 3.5. */
#warning "Input processor header not found, trying basic input.h"
#endif

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

struct accel_config {
    uint16_t input_type;
    bool track_remainders;
    int32_t min_factor;
    int32_t max_factor;
    int32_t speed_threshold;
    int32_t speed_max;
    int32_t acceleration_exponent;
};

struct accel_data {
    uint32_t last_time;
    int32_t rem_x;
    int32_t rem_y;
};

struct zmk_input_processor_state {
    uint8_t dummy; // We don't use this, but need the pointer type
};

static int accel_process(const struct device *dev, struct input_event *event,
                         uint32_t param1, uint32_t param2,
                         struct zmk_input_processor_state *state)
{
    const struct accel_config *cfg = dev->config;
    struct accel_data *data = dev->data;

    if (event->type != cfg->input_type) {
        return 0; // Not our event type
    }

    if (event->code != INPUT_REL_X && event->code != INPUT_REL_Y && event->code != INPUT_REL_WHEEL && event->code != INPUT_REL_HWHEEL) {
        return 0; 
    }

    uint32_t now = k_uptime_get_32();
    uint32_t dt = now - data->last_time;
    if (dt == 0 || dt > 1000) {
        data->last_time = now;
        data->rem_x = 0;
        data->rem_y = 0;
        return 0;
    }
    data->last_time = now;

    // Speed in units/s
    int32_t speed = (((event->value) < 0 ? -(event->value) : (event->value)) * 1000) / dt;

    int32_t factor = cfg->min_factor;
    
    if (speed > cfg->speed_threshold) {
        if (speed >= cfg->speed_max) {
            factor = cfg->max_factor;
        } else {
            // Calculate acceleration
            int32_t speed_range = cfg->speed_max - cfg->speed_threshold;
            int32_t factor_range = cfg->max_factor - cfg->min_factor;
            int32_t speed_diff = speed - cfg->speed_threshold;
            
            // Linear or exponential depending on exponent
            int64_t ratio = (int64_t)speed_diff * 1000 / speed_range;
            if (cfg->acceleration_exponent == 2) {
                ratio = (ratio * ratio) / 1000;
            } else if (cfg->acceleration_exponent == 3) {
                ratio = (ratio * ratio * ratio) / 1000000;
            }
            
            factor = cfg->min_factor + (int32_t)((ratio * factor_range) / 1000);
        }
    }

    // Apply factor
    int32_t value = event->value * factor;
    int32_t rem = 0;
    
    if (cfg->track_remainders) {
        if (event->code == INPUT_REL_X) {
            value += data->rem_x;
            rem = value % 1000;
            data->rem_x = rem;
        } else if (event->code == INPUT_REL_Y) {
            value += data->rem_y;
            rem = value % 1000;
            data->rem_y = rem;
        }
    }

    event->value = value / 1000;

    return 0;
}

struct zmk_input_processor_driver_api {
    int (*handle_event)(const struct device *dev, struct input_event *event,
                        uint32_t param1, uint32_t param2,
                        struct zmk_input_processor_state *state);
};

static const struct zmk_input_processor_driver_api accel_api = {
    .handle_event = accel_process,
};

static int accel_init(const struct device *dev)
{
    return 0;
}

#define ACCEL_INST(n)                                                                  \
    static struct accel_data accel_data_##n;                                           \
    static const struct accel_config accel_config_##n = {                              \
        .input_type = DT_INST_PROP(n, input_type),                                     \
        .track_remainders = DT_INST_PROP(n, track_remainders),                         \
        .min_factor = DT_INST_PROP(n, min_factor),                                     \
        .max_factor = DT_INST_PROP(n, max_factor),                                     \
        .speed_threshold = DT_INST_PROP(n, speed_threshold),                           \
        .speed_max = DT_INST_PROP(n, speed_max),                                       \
        .acceleration_exponent = DT_INST_PROP(n, acceleration_exponent),               \
    };                                                                                 \
    DEVICE_DT_INST_DEFINE(n, accel_init, NULL, &accel_data_##n,                        \
                          &accel_config_##n, POST_KERNEL,                              \
                          CONFIG_INPUT_INIT_PRIORITY, &accel_api);

DT_INST_FOREACH_STATUS_OKAY(ACCEL_INST)
