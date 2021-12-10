#ifndef _DRIVED_H_
#define _DRIVED_H_

#include "base.h"

class Derived : public Base
{
public:
  Derived();
  virtual ~Derived();

  void set_value(const int a) override;
  int get_value() const override;

private:
  int a;
};

#endif
