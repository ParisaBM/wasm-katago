#include "web_interface.h"

namespace web_interface {
    EM_ASYNC_JS(char*, do_fetch, (), {
        var jsString = await get_input();
        var lengthBytes = lengthBytesUTF8(jsString)+1;
        var stringOnWasmHeap = _malloc(lengthBytes);
        stringToUTF8(jsString, stringOnWasmHeap, lengthBytes);
        return stringOnWasmHeap;
    });

    template <typename T>
    custom_istream& operator>>(custom_istream& ci, T& obj) {
        char* received = do_fetch();
        std::istringstream is(received);
        is >> obj;
        return ci;
    }

    custom_istream cin = custom_istream();
}