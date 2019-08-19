/*
Copyright jungwoo
*/

#ifndef CONFIG_H_BEN
#define CONFIG_H_BEN

#include "config_common.h"
#include "../../config.h"

#define BACKLIGHT_BREATHING

#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD

#define BREATHING_PERIOD 5

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
