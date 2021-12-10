#include "drived.h"
#include <iostream>

extern "C"
{
  Base *create()
  {
    std::cout << __func__ << std::endl;
    return new Drived;
  }
}

Drived::Drived() : Base(), a{0}
{
  std::cout << __func__ << std::endl;
}

Drived::~Drived()
{
  std::cout << __func__ << std::endl;
}

void Drived::set_value(const int a)
{
  this->a = a;
}

int Drived::get_value() const
{
  return a;
}