#include "ChatBotMain_callbacks.h"
#include "../ui/ChatBotMain_ui.h"
#include "../user/ChatBotMain_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Time string global variables (defined in UI file)
extern char hg_time_label_time_time_str[10];

// Timer animation counters
uint16_t hg_rect_leftEyeOuter_timer_cnt = 0;

// Event callback function implementations

void hg_rect_emotionButton_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    hg_rect_emotionButton_onClick(obj, e);
}

void hg_rect_notification_1_bg_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_weatherView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_notification_2_bg_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_musicView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_notification_4_bg_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "ChatBotSettingsView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_time_label_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(hg_time_label_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_time, hg_time_label_time_time_str, strlen(hg_time_label_time_time_str));
}

// Preset timer callback functions

/**
 * 动画 1
 * Component: hg_rect_leftEyeOuter
 */
void eye_animation_callback(void *obj)
{
    GUI_UNUSED(obj);
    // Call the implementation function in protected area (if exists)
    // Define eye_animation_callback_impl() in custom_functions protected area for custom logic
#ifdef __cplusplus
    extern "C" {
#endif
    extern void eye_animation_callback_impl(void) __attribute__((weak));
#ifdef __cplusplus
    }
#endif
    
    if (eye_animation_callback_impl) {
        eye_animation_callback_impl();
    } else {
        // TODO: Implement timer callback logic
        // Or define eye_animation_callback_impl() in custom_functions protected area
    }
}

/* @protected start custom_functions */
// 自定义函数


/* @protected end custom_functions */
