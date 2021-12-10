#include <iostream>
#include <dlfcn.h>

#include "base_handler.h"

static const std::string derived_path = "../derived/libderived.dylib";

int main()
{
  BaseHandler handler(derived_path);
  auto drived = handler.create();
  drived->set_value(15);
  std::cout << drived->get_value() << std::endl;
  return 0;
}
