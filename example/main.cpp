#include <iostream>
#include <dlfcn.h>

#include "base.h"
#include "dl_loader.h"

static const std::string drivedPath = "libdrived.dylib";

int main()
{
  BaseHandler handler;
  auto drived = handler.create();
  drived->set_value(10);
  std::cout << drived->get_value() << std::endl;
  return 0;
}