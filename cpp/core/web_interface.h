#ifndef WEB_INTERFACE_H_
#define WEB_INTERFACE_H_

#include <sstream>
#include <emscripten.h>

namespace web_interface {
    extern "C" char* do_fetch();

    class custom_istream {};

    template <typename T>
    custom_istream& operator>>(custom_istream&, T&);

    extern custom_istream cin;
}

#endif