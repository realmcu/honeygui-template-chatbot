#ifndef APP_ALARM_CALLBACKS_H
#define APP_ALARM_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"
#include "gui_obj_focus.h"

// Event callback function declarations
void app_alarmMainView_key_0_cb(void *obj, gui_event_t *e);

// Toggle button state callback function declarations
void hg_button_item0_left_switch_on_callback(void);
void hg_button_item0_left_switch_off_callback(void);
void hg_button_item0_right_switch_on_callback(void);
void hg_button_item0_right_switch_off_callback(void);
void hg_button_item1_left_switch_on_callback(void);
void hg_button_item1_left_switch_off_callback(void);
void hg_button_item1_right_switch_on_callback(void);
void hg_button_item1_right_switch_off_callback(void);
void hg_button_item2_left_switch_on_callback(void);
void hg_button_item2_left_switch_off_callback(void);
void hg_button_item2_right_switch_on_callback(void);
void hg_button_item2_right_switch_off_callback(void);

#endif // APP_ALARM_CALLBACKS_H
