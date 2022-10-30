#ifndef APPLICATION_VIEW_H_
#define APPLICATION_VIEW_H_

#include <lvgl.h>

#include "../.pio/libdeps/m5stack-core2/lv_conf.h"
#include "first_view.h"

class application_view {
 private:
  static application_view* _singleton;

 public:
  application_view();
  virtual ~application_view();
  void initialize();
  static application_view* get_instance();
};

#endif