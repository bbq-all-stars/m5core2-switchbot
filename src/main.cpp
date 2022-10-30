#include "application.h"

void setup() {
  application* app = application::get_instance();
  app->initialize();
}

void loop() {
  application* app = application::get_instance();
  app->update();
}