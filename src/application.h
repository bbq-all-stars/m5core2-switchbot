#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <Arduino.h>
#include <M5Core2.h>
#include <lvgl.h>

#include "../.pio/libdeps/m5stack-core2/lv_conf.h"
#include "views/application_view.h"

#define DISP_HOR_RES 320
#define DISP_VER_RES 240

class application {
 public:
  application();
  virtual ~application();
  void initialize();
  void update();
  static application *get_instance();

 private:
  static application *_singleton;
  static void _touchpad_read(lv_indev_drv_t *indev_driver,
                             lv_indev_data_t *data);
  static void _disp_flush(lv_disp_drv_t *disp, const lv_area_t *area,
                          lv_color_t *color_p);
};

#endif