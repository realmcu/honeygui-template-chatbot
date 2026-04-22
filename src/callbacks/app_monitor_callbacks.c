#include "app_monitor_callbacks.h"
#include "../ui/app_monitor_ui.h"
#include "../user/app_monitor_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Time string global variables (defined in UI file)
extern char lbl_monitor_time_time_str[10];
extern char lbl_cam_timestamp_time_str[22];

// Event callback function implementations

void app_monitorMainView_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "ChatBotTemplateMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
    }
    else if (strcmp(e->indev_name, "Menu") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "ChatBotFeaturesView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
    }
}

void lbl_monitor_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(lbl_monitor_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)lbl_monitor_time, lbl_monitor_time_time_str, strlen(lbl_monitor_time_time_str));
}

void lbl_cam_timestamp_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(lbl_cam_timestamp_time_str, "%04d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    
    gui_text_content_set((gui_text_t *)lbl_cam_timestamp, lbl_cam_timestamp_time_str, strlen(lbl_cam_timestamp_time_str));
}

/* @protected start custom_functions */
// Custom functions
/* @protected end custom_functions */
