#include "app_alarm_callbacks.h"
#include "../ui/app_alarm_ui.h"
#include "../user/app_alarm_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Event callback function implementations

void app_alarmMainView_key_0_cb(void *obj, gui_event_t *e)
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

// Toggle button state callback functions

/* USER CODE BEGIN hg_button_item0_left_switch_on_callback */
/**
 * hg_button_item0_left_switch ON state callback
 * Called when button switches to ON state
 */
void hg_button_item0_left_switch_on_callback(void)
{
    // TODO: Implement ON state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_play();
}
/* USER CODE END hg_button_item0_left_switch_on_callback */

/* USER CODE BEGIN hg_button_item0_left_switch_off_callback */
/**
 * hg_button_item0_left_switch OFF state callback
 * Called when button switches to OFF state
 */
void hg_button_item0_left_switch_off_callback(void)
{
    // TODO: Implement OFF state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_pause();
}
/* USER CODE END hg_button_item0_left_switch_off_callback */

/* USER CODE BEGIN hg_button_item0_right_switch_on_callback */
/**
 * hg_button_item0_right_switch ON state callback
 * Called when button switches to ON state
 */
void hg_button_item0_right_switch_on_callback(void)
{
    // TODO: Implement ON state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_play();
}
/* USER CODE END hg_button_item0_right_switch_on_callback */

/* USER CODE BEGIN hg_button_item0_right_switch_off_callback */
/**
 * hg_button_item0_right_switch OFF state callback
 * Called when button switches to OFF state
 */
void hg_button_item0_right_switch_off_callback(void)
{
    // TODO: Implement OFF state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_pause();
}
/* USER CODE END hg_button_item0_right_switch_off_callback */

/* USER CODE BEGIN hg_button_item1_left_switch_on_callback */
/**
 * hg_button_item1_left_switch ON state callback
 * Called when button switches to ON state
 */
void hg_button_item1_left_switch_on_callback(void)
{
    // TODO: Implement ON state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_play();
}
/* USER CODE END hg_button_item1_left_switch_on_callback */

/* USER CODE BEGIN hg_button_item1_left_switch_off_callback */
/**
 * hg_button_item1_left_switch OFF state callback
 * Called when button switches to OFF state
 */
void hg_button_item1_left_switch_off_callback(void)
{
    // TODO: Implement OFF state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_pause();
}
/* USER CODE END hg_button_item1_left_switch_off_callback */

/* USER CODE BEGIN hg_button_item1_right_switch_on_callback */
/**
 * hg_button_item1_right_switch ON state callback
 * Called when button switches to ON state
 */
void hg_button_item1_right_switch_on_callback(void)
{
    // TODO: Implement ON state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_play();
}
/* USER CODE END hg_button_item1_right_switch_on_callback */

/* USER CODE BEGIN hg_button_item1_right_switch_off_callback */
/**
 * hg_button_item1_right_switch OFF state callback
 * Called when button switches to OFF state
 */
void hg_button_item1_right_switch_off_callback(void)
{
    // TODO: Implement OFF state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_pause();
}
/* USER CODE END hg_button_item1_right_switch_off_callback */

/* USER CODE BEGIN hg_button_item2_left_switch_on_callback */
/**
 * hg_button_item2_left_switch ON state callback
 * Called when button switches to ON state
 */
void hg_button_item2_left_switch_on_callback(void)
{
    // TODO: Implement ON state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_play();
}
/* USER CODE END hg_button_item2_left_switch_on_callback */

/* USER CODE BEGIN hg_button_item2_left_switch_off_callback */
/**
 * hg_button_item2_left_switch OFF state callback
 * Called when button switches to OFF state
 */
void hg_button_item2_left_switch_off_callback(void)
{
    // TODO: Implement OFF state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_pause();
}
/* USER CODE END hg_button_item2_left_switch_off_callback */

/* USER CODE BEGIN hg_button_item2_right_switch_on_callback */
/**
 * hg_button_item2_right_switch ON state callback
 * Called when button switches to ON state
 */
void hg_button_item2_right_switch_on_callback(void)
{
    // TODO: Implement ON state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_play();
}
/* USER CODE END hg_button_item2_right_switch_on_callback */

/* USER CODE BEGIN hg_button_item2_right_switch_off_callback */
/**
 * hg_button_item2_right_switch OFF state callback
 * Called when button switches to OFF state
 */
void hg_button_item2_right_switch_off_callback(void)
{
    // TODO: Implement OFF state business logic
    // Hint: Set "Control Target" in button properties to specify control target
    // Example: music_player_pause();
}
/* USER CODE END hg_button_item2_right_switch_off_callback */

/* @protected start custom_functions */
// Custom functions
/* @protected end custom_functions */
