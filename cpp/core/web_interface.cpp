#include "web_interface.h"
#include <stdlib.h>

EM_JS(char*, doFetch, (), {
  return Asyncify.handleAsync(function () {
    const p = new Promise((res) => resolve_input = res);
    return p.then(function (jsString) {
        var lengthBytes = lengthBytesUTF8(jsString)+1;
        var stringOnWasmHeap = _malloc(lengthBytes);
        stringToUTF8(jsString, stringOnWasmHeap, lengthBytes);
        return stringOnWasmHeap;
    });
  });
});

namespace WebInterface {
  customIstream::operator bool() const {
    return true;
  }

  customIstream cin = customIstream();
}