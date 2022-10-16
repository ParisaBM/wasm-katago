#ifndef WEB_INTERFACE_H_
#define WEB_INTERFACE_H_

#include <sstream>
#include <emscripten.h>

extern "C" char* do_fetch();

namespace web_interface {
  class custom_istream {};

  template <typename T>
  custom_istream& operator>>(custom_istream& ci, T& obj) {
    char* received = do_fetch();
    std::istringstream is(received);
    is >> obj;
    return ci;
  }

  extern custom_istream cin;
}

#endif