#include "app_weather_callbacks.h"
#include "../ui/app_weather_ui.h"
#include "../user/app_weather_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Event callback function implementations

void app_weatherView_key_0_cb(void *obj, gui_event_t *e)
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

void hg_list_item_day_0_switch_view_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    gui_view_switch_direct(gui_view_get_current(), "ChatBotTemplateMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
    gui_view_switch_direct(gui_view_get_current(), "ChatBotFeaturesView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
}

/* @protected start custom_functions */
// Custom functions
/* @protected end custom_functions */
