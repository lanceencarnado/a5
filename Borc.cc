#include "Borc.h"

Borc::Borc() 
{
  id = nextId++;
  space = random(3) + 5;
  item = "gold coins";
}

void Borc::loot() {
    cout << "Borc (" << id << ") loots " << item << endl;
}
