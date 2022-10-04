# KataGo In Web Assembly
[KataGo](https://github.com/lightvector/KataGo) is an ai for the game go. This project is a port of it so it can be run in browser.

To compile requires [emsdk](https://emscripten.org/docs/getting_started/downloads.html), [cmake](https://cmake.org/download/), and [eigen3](https://eigen.tuxfamily.org/index.php?title=Main_Page). To compile run:
```
emcmake cmake .
make
```
from inside the cpp folder.
Running wasm requires a web server. If python is installed this can be done by running
```
python3 -m http.server
```
and navigating to katago.html.