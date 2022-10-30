#ifndef FIRST_VIEW_H_
#define FIRST_VIEW_H_

#include <lvgl.h>

#include "../.pio/libdeps/m5stack-core2/lv_conf.h"

class first_view {
 private:
  static void _event_handler(lv_event_t* e);

 public:
  first_view(lv_obj_t* screen = NULL);
};

#endif