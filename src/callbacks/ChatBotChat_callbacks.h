#ifndef CHATBOTCHAT_CALLBACKS_H
#define CHATBOTCHAT_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"
#include "gui_obj_focus.h"

// Timer animation counters (defined in callbacks.c)
extern uint16_t hg_rect_wave_1_timer_cnt;

// Event callback function declarations
void ChatBotChatView_key_0_cb(void *obj, gui_event_t *e);
void hg_time_label_chat_time_time_update_cb(void *p);

// User-configured timer callback function declarations
void wave1_timer_0_cb(void *obj);

// Custom function declarations (auto-extracted from callbacks.c protected area)
void wave1_timer_0_cb_impl(void);

#endif // CHATBOTCHAT_CALLBACKS_H
