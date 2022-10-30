#include "application.h"

#define DISP_HOR_RES 320
#define DISP_VER_RES 240

TFT_eSPI tft = TFT_eSPI(); /* TFT instance */

application * application::_singleton = NULL;

application::application(){}
application::~application(){
    delete _singleton;
}

void application::initialize(){
    M5.begin(true, true, true, true);
    tft.begin(); /* TFT init */
    tft.setRotation(1);         /* Landscape orientation */

    /*Initialize the display*/
    static lv_disp_draw_buf_t disp_buf;
    static lv_color_t buf1[DISP_HOR_RES * 10];
    static lv_color_t buf2[DISP_HOR_RES * 10];
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, DISP_HOR_RES * 10);

    lv_init();

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = application::_disp_flush;
    disp_drv.hor_res = DISP_HOR_RES;
    disp_drv.ver_res = DISP_VER_RES;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = application::_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    // initialize views
    application_view * app_view = application_view::get_instance();
    app_view->initialize();
}

void application::update(){
  M5.update();
  lv_task_handler();
  delay(5);
}

application * application::get_instance(){
    if (_singleton == NULL){
        _singleton = new application();
    }
    return _singleton;
}

void application::_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data){
    TouchPoint_t pos = M5.Touch.getPressPoint();
    bool touched = ( pos.x == -1 ) ? false : true;

    if(!touched) {
        data->state = LV_INDEV_STATE_REL;
    } else {
        data->state = LV_INDEV_STATE_PR;
            
        /*Set the coordinates*/
        data->point.x = pos.x;
        data->point.y = pos.y;
    }
}

void application::_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p){
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors(&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}