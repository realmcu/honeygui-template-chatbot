#include "ChatBotChat_callbacks.h"
#include "../ui/ChatBotChat_ui.h"
#include "../user/ChatBotChat_user.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

// Time string global variables (defined in UI file)
extern char hg_time_label_chat_time_time_str[10];

// Timer animation counters
uint16_t hg_rect_wave_1_timer_cnt = 0;

// Event callback function implementations

void ChatBotChatView_key_0_cb(void *obj, gui_event_t *e)
{
    GUI_UNUSED(obj);
    GUI_UNUSED(e);
    // Check key name
    if (strcmp(e->indev_name, "Home") == 0)
    {
        gui_view_switch_direct(gui_view_get_current(), "ChatBotTemplateMainView", SWITCH_OUT_ANIMATION_FADE, SWITCH_IN_ANIMATION_FADE);
    }
}

void hg_time_label_chat_time_time_update_cb(void *p)
{
    GUI_UNUSED(p);
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t == NULL)
    {
        return;
    }
    
    snprintf(hg_time_label_chat_time_time_str, sizeof(hg_time_label_chat_time_time_str), "%02d:%02d", t->tm_hour, t->tm_min);
    
    gui_text_content_set((gui_text_t *)hg_time_label_chat_time, hg_time_label_chat_time_time_str, strlen(hg_time_label_chat_time_time_str));
}

// Preset timer callback functions

/**
 * 动画 1
 * Component: hg_rect_wave_1
 */
void wave1_timer_0_cb(void *obj)
{
    GUI_UNUSED(obj);
    // Call the implementation function in protected area (if exists)
    // Define wave1_timer_0_cb_impl() in custom_functions protected area for custom logic
#ifdef __cplusplus
    extern "C" {
#endif
    extern void wave1_timer_0_cb_impl(void) __attribute__((weak));
#ifdef __cplusplus
    }
#endif
    
    if (wave1_timer_0_cb_impl) {
        wave1_timer_0_cb_impl();
    } else {
        // TODO: Implement timer callback logic
        // Or define wave1_timer_0_cb_impl() in custom_functions protected area
    }
}

/* @protected start custom_functions */
// 自定义函数

// Wave animation implementation
void wave1_timer_0_cb_impl(void)
{
    // Array of wave pointers for easier manipulation
    static gui_rounded_rect_t* waves[30] = {NULL};
    
    // Re-initialize wave array every time to handle view switching
    // This ensures we always have valid pointers after view recreation
    waves[0] = hg_rect_wave_1; waves[1] = hg_rect_wave_2; waves[2] = hg_rect_wave_3; waves[3] = hg_rect_wave_4; waves[4] = hg_rect_wave_5;
    waves[5] = hg_rect_wave_6; waves[6] = hg_rect_wave_7; waves[7] = hg_rect_wave_8; waves[8] = hg_rect_wave_9; waves[9] = hg_rect_wave_10;
    waves[10] = hg_rect_wave_11; waves[11] = hg_rect_wave_12; waves[12] = hg_rect_wave_13; waves[13] = hg_rect_wave_14; waves[14] = hg_rect_wave_15;
    waves[15] = hg_rect_wave_16; waves[16] = hg_rect_wave_17; waves[17] = hg_rect_wave_18; waves[18] = hg_rect_wave_19; waves[19] = hg_rect_wave_20;
    waves[20] = hg_rect_wave_21; waves[21] = hg_rect_wave_22; waves[22] = hg_rect_wave_23; waves[23] = hg_rect_wave_24; waves[24] = hg_rect_wave_25;
    waves[25] = hg_rect_wave_26; waves[26] = hg_rect_wave_27; waves[27] = hg_rect_wave_28; waves[28] = hg_rect_wave_29; waves[29] = hg_rect_wave_30;
    
    // Verify all wave pointers are valid before proceeding
    for (int i = 0; i < 30; i++) {
        if (waves[i] == NULL) {
            // Some wave components are not ready, skip this frame
            return;
        }
    }
    
    // Increment animation counter with overflow protection
    hg_rect_wave_1_timer_cnt++;
    
    // Reset counter to prevent overflow and maintain smooth animation
    if (hg_rect_wave_1_timer_cnt >= 31416) {
        hg_rect_wave_1_timer_cnt = 0;
    }
    
    // Create wave animation effect
    for (int i = 0; i < 30; i++) {
        // Double-check pointer validity before use
        gui_obj_t *wave_obj = (gui_obj_t *)waves[i];
        if (wave_obj != NULL && wave_obj->magic == GUI_MAGIC_NUMBER) {
            // Calculate wave height using sine wave with phase offset
            float phase = (hg_rect_wave_1_timer_cnt * 0.2f) + (i * 0.3f); // Different phase for each wave
            float amplitude = 12.0f; // Maximum height variation
            float base_height = 15.0f; // Base height
            
            // Calculate new height using sine wave
            int new_height = (int)(base_height + amplitude * sinf(phase));
            
            // Ensure height is within reasonable bounds (6-30 pixels)
            if (new_height < 6) new_height = 6;
            if (new_height > 30) new_height = 30;
            
            // Calculate new Y position to keep waves centered at same horizontal line
            int center_y = 25; // Center line position (middle of the 60px window)
            int new_y = center_y - (new_height / 2);
            
            // Update wave position and size safely
            wave_obj->y = new_y;
            wave_obj->h = new_height;
            
        }
    }
}
/* @protected end custom_functions */
