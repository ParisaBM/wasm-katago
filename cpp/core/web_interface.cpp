#include "web_interface.h"
#include <stdlib.h>

EM_JS(char*, do_fetch, (), {
  return Asyncify.handleAsync(function () {
    out("waiting for a fetch");
    const p = new Promise((res) => resolve_input = res);
    return p.then(function (jsString) {
        var lengthBytes = lengthBytesUTF8(jsString)+1;
        var stringOnWasmHeap = _malloc(lengthBytes);
        stringToUTF8(jsString, stringOnWasmHeap, lengthBytes);
        return stringOnWasmHeap;
    });
  });
});

namespace web_interface {
  custom_istream cin = custom_istream();
}