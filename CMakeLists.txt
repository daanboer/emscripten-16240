cmake_minimum_required(VERSION 3.14)
project(emscripten-bug)

set(CMAKE_CXX_STANDARD 17)

add_executable(emscripten_bug bindings.cpp)
target_include_directories(emscripten_bug PRIVATE /usr/lib/emscripten/system/include)

set_target_properties(emscripten_bug PROPERTIES LINK_FLAGS "\
  -s MODULARIZE=1 \
  -s EXPORT_NAME=create_module \
  -s EXPORTED_RUNTIME_METHODS=run \
  --bind \
  --preload-file ${PROJECT_SOURCE_DIR}/preload.txt@input/ \
  --pre-js ${PROJECT_SOURCE_DIR}/pre.js")

set_target_properties(emscripten_bug
  PROPERTIES 
  ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/wasm"
  LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/wasm"
  RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/wasm"
)
