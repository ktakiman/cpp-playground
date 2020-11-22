#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "cpp17-stl-update.h"
#include "env_check.h"

using namespace Playground;

std::unordered_map<int, void (*)()> _tests = {{1, TestVariant}};

int main(int argc, char* argv[]) {
  if (argc < 2) {
    CheckCompiler();
    CheckTargetSystem();
  } else {
    int index = std::stoi(argv[1]);

    if (auto i = _tests.find(index); i->first) {
      i->second();
    } else {
      std::cout << "play #" << index << " not implemented yet" << std::endl;
    }
  }
}

