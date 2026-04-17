#pragma once

#include <dt-bindings/zmk/keys.h>

// ---------------------------------------------------------
// JIS Symbols Mapping
// ---------------------------------------------------------
#define JP_EXCL   LS(N1)          // !
#define JP_DQT    LS(N2)          // "
#define JP_HASH   LS(N3)          // #
#define JP_DLLR   LS(N4)          // $
#define JP_PRCNT  LS(N5)          // %
#define JP_AMPRS  LS(N6)          // &
#define JP_SQT    LS(N7)          // '
#define JP_LPAR   LS(N8)          // (
#define JP_RPAR   LS(N9)          // )

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