#include "env_check.h"

#include <iostream>
#include <filesystem>

namespace Playground {

//------------------------------------------------------------------------------
void CheckCompiler() {

#ifdef __GNUC__
  std::cout << "__GNUC__ = " << __GNUC__ << std::endl;
#endif

#ifdef __clang__
  std::cout << "__clang__ = " << __clang__ << std::endl;
#endif

#ifdef _MSC_VER
  std::cout << "_MSC_VER = " << _MSC_VER << std::endl;
#endif

#ifdef __MINGW32__
  std::cout << "__MINGW32__ = " << __MINGW32__ << std::endl;
#endif

#ifdef __MINGW64__
  std::cout << "__MINGW64__ = " << __MINGW64__ << std::endl;
#endif

}

//------------------------------------------------------------------------------
void CheckTargetSystem() {

#ifdef __linux__
  std::cout << "__linux__ = " << __linux__ << std::endl;
#endif

#ifdef __APPLE__
  std::cout << "__APPLE__ = " << __APPLE__ << std::endl;
#endif

#ifdef _WIN32
  std::cout << "_WIN32 = " << _WIN32 << std::endl;
#endif

#ifdef _WIN64
  std::cout << "_WIN64 = " << _WIN64 << std::endl;
#endif

  std::cout << "Temp dir = " << std::filesystem::temp_directory_path() << std::endl;
}

}
