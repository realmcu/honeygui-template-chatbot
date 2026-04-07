#ifndef CHATBOTFEATURES_CALLBACKS_H
#define CHATBOTFEATURES_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"
#include "gui_obj_focus.h"

// Event callback function declarations
void ChatBotFeaturesView_key_0_cb(void *obj, gui_event_t *e);
void hg_rect_alarm_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_calendar_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_game_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_monitor_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_music_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_news_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_reminders_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_settings_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_smarthome_card_clicked_cb(void *obj, gui_event_t *e);
void hg_rect_weather_card_clicked_cb(void *obj, gui_event_t *e);
void hg_time_label_features_time_time_update_cb(void *p);

#endif // CHATBOTFEATURES_CALLBACKS_H
