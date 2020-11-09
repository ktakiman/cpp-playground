#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "env_check.h"
#include "cpp17-stl-update.h"

using namespace Playground;

int main(int argc, char* argv[]) {

  if (argc < 2) {
    CheckCompiler();
    CheckTargetSystem();
  } else {
    int index = std::stoi(argv[1]);

    switch (index) {
      case 1:
        TestVariant();
        break;
      default:
        std::cout << "play #" << index << " not implemented yet" << std::endl;
        break;
    }
  }

}


