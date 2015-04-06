#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"

class Pirate 
{
  public:
    Pirate();
    int getId();
    int getSpace();
    virtual void loot() = 0;
  protected:
    string      item;
    static int  nextId;
    int         id;
    int         space;
};

#endif

