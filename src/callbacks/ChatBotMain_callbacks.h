#ifndef CHATBOTMAIN_CALLBACKS_H
#define CHATBOTMAIN_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"
#include "gui_obj_focus.h"

// Timer animation counters (defined in callbacks.c)
extern uint16_t hg_rect_rightEyeOuter_timer_cnt;
extern uint16_t hg_rect_leftEyeOuter_timer_cnt;

// Event callback function declarations
void hg_rect_emotionButton_clicked_cb(void *obj, gui_event_t *e);
void hg_time_label_time_time_update_cb(void *p);

// User-configured timer callback function declarations
void eye_animation_callback(void *obj);

#endif // CHATBOTMAIN_CALLBACKS_H
