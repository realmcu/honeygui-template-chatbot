#include "ChatBotFeatures_callbacks.h"
#include "../ui/ChatBotFeatures_ui.h"
#include "../user/ChatBotFeatures_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Time string global variables (defined in UI file)
extern char hg_time_label_features_time_time_str[10];

// Event callback function implementations

void ChatBotFeaturesView_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "ChatBotTemplateMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
    }
}

void hg_rect_weather_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_weatherView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_music_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_musicView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_calendar_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_calendarView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_smarthome_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_smarthomeView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_reminders_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_reminderMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_monitor_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_monitorMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_alarm_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_alarmMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_game_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_gamesMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_news_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "app_newsMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_rect_settings_card_clicked_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "ChatBotSettingsView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

void hg_time_label_features_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    snprintf(hg_time_label_features_time_time_str, sizeof(hg_time_label_features_time_time_str), "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_features_time, hg_time_label_features_time_time_str, strlen(hg_time_label_features_time_time_str));
}

/* @protected start custom_functions */
// Custom functions
/* @protected end custom_functions */
