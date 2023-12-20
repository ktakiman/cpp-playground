#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

#include "cpp17-stl-update.h"
#include "env_check.h"
#include "format.h"
#include "forward-ref.h"
#include "meta-programming.h"
#include "numeric-cast.h"
#include "template-test.h"
#include "type-traits.h"

using namespace Playground;

std::map<int, std::pair<const char*, void (*)()>> _tests = {
    {1, {"std::variant", TestVariant}},
    {2, {"std::optional", TestOptional}},
    {3, {"std::any", TestAny}},
    {4, {"forward ref", TestForwardRef}},
    {5, {"meta-programming", TestMetaProgramming}},
    {6, {"format", TestFormat}},
    {7, {"numeric-cast", TestNumericCast}},
    {8, {"type-traits", TestTypeTraits}},
};

int main(int argc, char* argv[]) {
  if (argc < 2) {
    CheckCompiler();
    CheckTargetSystem();
    std::cout << std::endl << std::endl << "= Playlist =" << std::endl;
    for (auto& test : _tests) {
      std::cout << "  " << std::setw(2) << test.first << ": "
                << test.second.first << std::endl;
    }
  } else {
    int index = std::stoi(argv[1]);

    if (auto i = _tests.find(index); i->first) {
      i->second.second();
    } else {
      std::cout << "play #" << index << " not implemented yet" << std::endl;
    }
  }
}
