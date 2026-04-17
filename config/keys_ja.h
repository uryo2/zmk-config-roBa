#pragma once

#include <dt-bindings/zmk/keys.h>

// ---------------------------------------------------------
// JIS Symbols Mapping
// ---------------------------------------------------------
#define JP_EXCL   LS(NUMBER_1)        // !
#define JP_DQT    LS(NUMBER_2)        // "
#define JP_HASH   LS(NUMBER_3)        // #
#define JP_DLLR   LS(NUMBER_4)        // $
#define JP_PRCNT  LS(NUMBER_5)        // %
#define JP_AMPRS  LS(NUMBER_6)        // &
#define JP_SQT    LS(NUMBER_7)        // '
#define JP_LPAR   LS(NUMBER_8)        // (
#define JP_RPAR   LS(NUMBER_9)        // )

#define JP_EQUAL  LS(MINUS)           // =
#define JP_MINUS  MINUS               // -
#define JP_CARET  EQUAL               // ^
#define JP_TILDE  LS(EQUAL)           // ~
#define JP_YEN    INTERNATIONAL_3     // ¥
#define JP_PIPE   LS(INTERNATIONAL_3) // |
#define JP_AT     LEFT_BRACKET        // @
#define JP_GRAVE  LS(LEFT_BRACKET)    // `
#define JP_LBRC   RIGHT_BRACKET       // [
#define JP_LCBR   LS(RIGHT_BRACKET)   // {
#define JP_RBRC   NON_US_HASH         // ]
#define JP_RCBR   LS(NON_US_HASH)     // }
#define JP_SEMI   SEMICOLON           // ;
#define JP_PLUS   LS(SEMICOLON)       // +
#define JP_COLON  SQT                 // :
#define JP_ASTER  LS(SQT)             // *
#define JP_BSLH   INTERNATIONAL_1     // \ 
#define JP_UNDER  LS(INTERNATIONAL_1) // _