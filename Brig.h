#ifndef BRIG_H
#define BRIG_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "defs.h"
#include "Borc.h"
#include "Dorc.h"
#include "Porc.h"
#include "Cell.h"

class Brig 
{
    public:
        Brig();
        ~Brig();
        int removePirate(int);
        list<Cell*>& getCells();
        Brig& operator+=(Pirate*);
    
    private:
        list<Cell*> cells;
};

#endif

