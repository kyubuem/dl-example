#ifndef _BASE_HANDLER_H_
#define _BASE_HANDLER_H_

#include "base.h"
#include <dlfcn.h>

class BaseHandler
{
private:
  void *_handle;
  Base_creator_t creator = nullptr;

public:
  explicit BaseHandler(const std::string& lib_path)
  {
    _handle = dlopen(lib_path.c_str(), RTLD_NOW);
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
