#include "util.h"

namespace Playground {

void Chatty::TellLorR(const char* prefix) & {
  std::cout << std::setw(40) << std::left << prefix << "L value" << std::endl;
}

void Chatty::TellLorR(const char* prefix) && {
  std::cout << std::setw(40) << std::left << prefix << "R value" << std::endl;
}

}  // namespace Playground

