#ifndef WEB_INTERFACE_H_
#define WEB_INTERFACE_H_

#include <sstream>
#include <emscripten.h>

extern "C" char* doFetch();

namespace WebInterface {
  struct customIstream {
    explicit operator bool() const;
  };

  template <typename T>
  customIstream& operator>>(customIstream& ci, T& obj) {
    char* received = doFetch();
    std::istringstream is(received);
    is >> obj;
    return ci;
  }

  template <typename T>
  customIstream& getline(customIstream& ci, T& str) {
    str = doFetch();
    return ci;
  }


  extern customIstream cin;
}

#endif