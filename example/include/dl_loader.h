#ifndef _DL_LOADER_H_
#define _DL_LOADER_H_

#include "base.h"
#include <dlfcn.h>

#include "base.h"

class BaseHandler
{
private:
  void *_handle;
  Base_creator_t creator = nullptr;

public:
  BaseHandler()
  {
    _handle = dlopen("libdrived.dylib", RTLD_NOW);
    if (!_handle)
    {
      throw std::runtime_error(dlerror());
    }
    reset_dlerror();
    creator = reinterpret_cast<Base_creator_t>(dlsym(_handle, "create"));
    check_dlerror();
  }

  virtual ~BaseHandler()
  {
    if (_handle)
    {
      dlclose(_handle);
    }
  }

  static void reset_dlerror()
  {
    dlerror();
  }

  static void check_dlerror()
  {
    const char *dlsym_error = dlerror();
    if (dlsym_error)
    {
      throw std::runtime_error(dlsym_error);
    }
  }

  std::unique_ptr<Base> create()
  {
    return std::unique_ptr<Base>(creator());
  }
};

#endif