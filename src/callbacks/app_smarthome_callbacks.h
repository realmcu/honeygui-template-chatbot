#ifndef APP_SMARTHOME_CALLBACKS_H
#define APP_SMARTHOME_CALLBACKS_H

#include "gui_api.h"
#include "gui_text.h"
#include "gui_obj_focus.h"

// Event callback function declarations
void app_smarthomeView_key_0_cb(void *obj, gui_event_t *e);
void hg_image_living_ac_icon_clicked_cb(void *obj, gui_event_t *e);
void hg_image_living_tv_icon_clicked_cb(void *obj, gui_event_t *e);
void hg_image_room_living_bg_clicked_cb(void *obj, gui_event_t *e);
void hg_image_smarthome_active_bg_clicked_cb(void *obj, gui_event_t *e);
void hg_image_smarthome_rooms_bg_clicked_cb(void *obj, gui_event_t *e);
void hg_window_ac_back_clicked_0_cb(void *obj, gui_event_t *e);
void hg_window_active_back_clicked_0_cb(void *obj, gui_event_t *e);
void hg_window_living_back_clicked_0_cb(void *obj, gui_event_t *e);
void hg_window_room_back_clicked_0_cb(void *obj, gui_event_t *e);
void hg_window_smarttv_back_clicked_0_cb(void *obj, gui_event_t *e);
void hg_time_label_smarthome_time_time_update_cb(void *p);
void hg_time_label_active_time_time_update_cb(void *p);
void hg_time_label_smarttv_time_time_update_cb(void *p);
void hg_time_label_ac_time_time_update_cb(void *p);
void hg_time_label_room_time_time_update_cb(void *p);
void hg_time_label_living_time_time_update_cb(void *p);

#endif // APP_SMARTHOME_CALLBACKS_H
