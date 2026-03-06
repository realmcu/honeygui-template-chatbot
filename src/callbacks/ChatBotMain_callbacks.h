#ifndef CHATBOTMAIN_CALLBACKS_H
#define CHATBOTMAIN_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"
#include "gui_obj_focus.h"

// 定时动画计数器（在 callbacks.c 中定义）
extern uint16_t hg_rect_rightEyeOuter_timer_cnt;
extern uint16_t hg_rect_leftEyeOuter_timer_cnt;

// 事件回调函数声明
void hg_rect_emotionButton_onClick(void *obj, gui_event_t *e);
void hg_time_label_time_time_update_cb(void *p);

// 用户配置的定时器回调函数声明
void eye_animation_callback(void *obj);

// 自定义函数声明（从 callbacks.c 保护区自动提取）
void eye_animation_callback(void *obj);
void hg_rect_emotionButton_onClick(void *obj, gui_event_t *e);

#endif // CHATBOTMAIN_CALLBACKS_H
