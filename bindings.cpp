#include <fstream>
#include <iostream>
#include <string>

#include <emscripten/bind.h>

void run() {
  std::ifstream fin;
  std::string line;

  fin.open("input/preload.txt", std::ios::in);

  if (!fin) {
    std::cout << "Could not open preload.txt." << std::endl;
    return;
  }

  std::getline(fin, line);
  fin.close();

  std::cout << line << std::endl;
}

EMSCRIPTEN_BINDINGS(export) { emscripten::function("run", &run); }
