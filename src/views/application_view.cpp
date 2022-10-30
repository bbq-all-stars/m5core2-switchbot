#include "application_view.h"

application_view * application_view::_singleton = NULL;

application_view::application_view(){}
application_view::~application_view(){
    delete _singleton;
}

application_view * application_view::get_instance(){
    if (_singleton == NULL){
        _singleton = new application_view();
    }
    return _singleton;
}

void application_view::initialize(){
    first_view _ (lv_scr_act());
}