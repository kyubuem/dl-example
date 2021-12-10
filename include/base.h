#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>

class Base
{
public:
  Base();
  virtual ~Base();

  virtual void set_value(const int a) = 0;
  virtual int get_value() const = 0;
};

using Base_creator_t = Base *(*)();

#endif