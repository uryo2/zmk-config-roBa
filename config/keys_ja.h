#pragma once

#include <dt-bindings/zmk/keys.h>

// ---------------------------------------------------------
// JIS Symbols Mapping
// ---------------------------------------------------------
#define JP_EXCL   LS(NUMBER_1)    // !
#define JP_DQT    LS(NUMBER_2)    // "
#define JP_HASH   LS(NUMBER_3)    // #
#define JP_DLLR   LS(NUMBER_4)    // $
#define JP_PRCNT  LS(NUMBER_5)    // %
#define JP_AMPRS  LS(NUMBER_6)    // &
#define JP_SQT    LS(NUMBER_7)    // '
#define JP_LPAR   LS(NUMBER_8)    // (
#define JP_RPAR   LS(NUMBER_9)    // )

#define JP_EQUAL  LS(MINUS)       // =
#define JP_MINUS  MINUS           // -
#define JP_CARET  EQUAL           // ^
#define JP_TILDE  LS(EQUAL)       // ~
#define JP_YEN    INT3            // ¥
#define JP_PIPE   LS(INT3)        // |
#define JP_AT     LBKT            // @
#define JP_GRAVE  LS(LBKT)        // `
#define JP_LBRC   RBKT            // [
#define JP_LCBR   LS(RBKT)        // {
#define JP_RBRC   NON_US_HASH     // ]
#define JP_RCBR   LS(NON_US_HASH) // }
#define JP_SEMI   SEMI            // ;
#define JP_PLUS   LS(SEMI)        // +
#define JP_COLON  SQT             // :
#define JP_ASTER  LS(SQT)         // *
#define JP_BSLH   INT1            // \ 
#define JP_UNDER  LS(INT1)        // _