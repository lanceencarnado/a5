#include "Porc.h"

Porc::Porc() 
{
  id = nextId++;
  space = random(3) + 2;
  item = "anchors";
}

void Porc::loot() {
    cout << "Porc (" << id << ") steals " << item << endl;
}

