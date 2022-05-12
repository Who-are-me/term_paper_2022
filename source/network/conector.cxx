#include "conector.hxx"


Conector::Conector() {
    cookies_manager.setHost("");
    cookies_manager.setCommand("");
}


Conector::~Conector() {
    delete manager;
}
