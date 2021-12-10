#include "derived.h"
#include <iostream>

extern "C"
{
  Base *create()
  {
    std::cout << __func__ << std::endl;
    return new Derived;
  }
}

Derived::Derived() : Base(), a{0}
{
  std::cout << __func__ << std::endl;
}

Derived::~Derived()
{
  std::cout << __func__ << std::endl;
}

void Derived::set_value(const int a)
{
  this->a = a;
}

int Derived::get_value() const
{
  return a;
}
