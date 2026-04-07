#ifndef CHATBOTSETTINGS_CALLBACKS_H
#define CHATBOTSETTINGS_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"
#include "gui_obj_focus.h"

// Event callback function declarations
void aboutItemBg_clicked_cb(void *obj, gui_event_t *e);
void autoReplyItemBg_clicked_cb(void *obj, gui_event_t *e);
void brightnessItemBg_clicked_cb(void *obj, gui_event_t *e);
void fontSizeItemBg_clicked_cb(void *obj, gui_event_t *e);
void hg_image_settings_return_clicked_cb(void *obj, gui_event_t *e);
void historyItemBg_clicked_cb(void *obj, gui_event_t *e);
void languageItemBg_clicked_cb(void *obj, gui_event_t *e);
void notificationItemBg_clicked_cb(void *obj, gui_event_t *e);
void themeItemBg_clicked_cb(void *obj, gui_event_t *e);
void voiceItemBg_clicked_cb(void *obj, gui_event_t *e);
void volumeItemBg_clicked_cb(void *obj, gui_event_t *e);
void wifiItemBg_clicked_cb(void *obj, gui_event_t *e);
void hg_time_label_settings_time_time_update_cb(void *p);

// Toggle button state callback function declarations
void hg_button_notification_on_callback(void);
void hg_button_notification_off_callback(void);
void hg_button_autoReply_on_callback(void);
void hg_button_autoReply_off_callback(void);

#endif // CHATBOTSETTINGS_CALLBACKS_H
