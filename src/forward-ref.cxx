#include "forward-ref.h"

#include <utility>

#include "util.h"

namespace Playground {

void F(Chatty& v, const std::string& prefix) { v.TellLorR((prefix + "F: passed as &").c_str()); }

void F(Chatty&& v, const std::string& prefix) {  
  v.TellLorR((prefix + "F: passed as &&").c_str()); 
  std::move(v).TellLorR((prefix + "F: passed as &&, and std::move").c_str()); 
}

template<typename T>
void TF(T&& t, const std::string& prefix) {
  std::cout << prefix << "TF: calling F with t as is" << std::endl;
  F(t, prefix + "  ");

  std::cout << prefix << "TF: calling F with std::move" << std::endl;
  F(std::move(t), prefix + "  ");

  std::cout << prefix << "TF: calling F with std::forward" << std::endl;
  F(std::forward<T>(t), prefix + "  ");
}

void TestForwardRef() {
  // some l-value/r-value testing
  // l-value
  Chatty lorr;
  lorr.TellLorR("local variable");
  std::move(lorr).TellLorR("std::move");

  // r-value
  Chatty().TellLorR("temporary object");

  F(lorr, "");
  F(Chatty(), "");

  // std::forward
  std::cout << "passing l-value" << std::endl;
  TF(lorr, "  "); 

  std::cout << "passing r-value" << std::endl;
  TF(Chatty(), "  ");        // R-value
}

}  // namespace Playground
