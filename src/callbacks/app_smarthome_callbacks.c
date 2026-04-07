#include "app_smarthome_callbacks.h"
#include "../ui/app_smarthome_ui.h"
#include "../user/app_smarthome_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Time string global variables (defined in UI file)
extern char hg_time_label_smarthome_time_time_str[10];
extern char hg_time_label_active_time_time_str[10];
extern char hg_time_label_smarttv_time_time_str[10];
extern char hg_time_label_ac_time_time_str[10];
extern char hg_time_label_room_time_time_str[10];
extern char hg_time_label_living_time_time_str[10];

// Event callback function implementations

void app_smarthomeView_key_0_cb(void *obj, gui_event_t *e)
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

void hg_image_smarthome_active_bg_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_active_device", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_image_smarthome_rooms_bg_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_room_list", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_window_active_back_clicked_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_smarthomeView", SWITCH_OUT_TO_RIGHT_USE_TRANSLATION, SWITCH_IN_FROM_LEFT_USE_TRANSLATION);
}

void hg_window_smarttv_back_clicked_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_living_room", SWITCH_OUT_TO_RIGHT_USE_TRANSLATION, SWITCH_IN_FROM_LEFT_USE_TRANSLATION);
}

void hg_window_ac_back_clicked_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_living_room", SWITCH_OUT_TO_RIGHT_USE_TRANSLATION, SWITCH_IN_FROM_LEFT_USE_TRANSLATION);
}

void hg_image_room_living_bg_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_living_room", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_window_room_back_clicked_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_smarthomeView", SWITCH_OUT_TO_RIGHT_USE_TRANSLATION, SWITCH_IN_FROM_LEFT_USE_TRANSLATION);
}

void hg_image_living_ac_icon_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_air_conditioner", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_MOVE_FADE);
}

void hg_image_living_tv_icon_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_smart_tv", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_MOVE_FADE);
}

void hg_window_living_back_clicked_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "view_room_list", SWITCH_OUT_TO_RIGHT_USE_TRANSLATION, SWITCH_IN_FROM_LEFT_USE_TRANSLATION);
}

void hg_time_label_smarthome_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(hg_time_label_smarthome_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_smarthome_time, hg_time_label_smarthome_time_time_str, strlen(hg_time_label_smarthome_time_time_str));
}

void hg_time_label_active_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(hg_time_label_active_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_active_time, hg_time_label_active_time_time_str, strlen(hg_time_label_active_time_time_str));
}

void hg_time_label_smarttv_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(hg_time_label_smarttv_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_smarttv_time, hg_time_label_smarttv_time_time_str, strlen(hg_time_label_smarttv_time_time_str));
}

void hg_time_label_ac_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(hg_time_label_ac_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_ac_time, hg_time_label_ac_time_time_str, strlen(hg_time_label_ac_time_time_str));
}

void hg_time_label_room_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(hg_time_label_room_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_room_time, hg_time_label_room_time_time_str, strlen(hg_time_label_room_time_time_str));
}

void hg_time_label_living_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    sprintf(hg_time_label_living_time_time_str, "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_living_time, hg_time_label_living_time_time_str, strlen(hg_time_label_living_time_time_str));
}

/* @protected start custom_functions */
// Custom functions
/* @protected end custom_functions */
