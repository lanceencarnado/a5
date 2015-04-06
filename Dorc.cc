#include "Dorc.h"

Dorc::Dorc() 
{
  id = nextId++;
  space = random(3) + 4;
  item = "swords";
}

void Dorc::loot() {
    cout << "Dorc (" << id << ") steals " << item << endl;
}

