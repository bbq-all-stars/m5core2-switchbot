#include "first_view.h"

first_view::first_view(lv_obj_t* screen) {
  // button
  lv_obj_t* label;

  lv_obj_t* btn1 = lv_btn_create(screen);
  lv_obj_add_event_cb(btn1, first_view::_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

  label = lv_label_create(btn1);
  lv_label_set_text(label, "Test Button");
  lv_obj_center(label);
}

void first_view::_event_handler(lv_event_t* e) {
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED) {
    LV_LOG_USER("Clicked");
  } else if (code == LV_EVENT_VALUE_CHANGED) {
    LV_LOG_USER("Toggled");
  }
}
