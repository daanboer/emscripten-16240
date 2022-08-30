### Emscripten bug [#16240](https://github.com/emscripten-core/emscripten/issues/16240)

A minimal example showing the emscripten bug mentioned in issue [#16240](https://github.com/emscripten-core/emscripten/issues/16240). The example can be compiled using cmake.
```
emcmake cmake -B build .
cmake --build build
```
Then you can e.g. use python to start a web server.
```
python -m http.server 3000
```
The test page now runs at `http://localhost:3000`.
