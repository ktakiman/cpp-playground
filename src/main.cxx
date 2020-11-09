#include <iostream>
#include <fstream>
#include <filesystem>

#include "env_check.h"

using namespace Playground;

int main(int argc, char* argv[]) {

  if (argc < 2) {
    CheckCompiler();
    CheckTargetSystem();
  } else {
    int index = std::stoi(argv[1]);

    switch (index) {
      case 1:
        break;
      default:
        std::cout << "play #" << index << " not implemented yet" << std::endl;
        break;
    }
  }

}


