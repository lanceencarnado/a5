#include "Pirate.h"

int Pirate::nextId = 1001;

Pirate::Pirate() { }

Pirate::~Pirate() { }

int Pirate::getId()    { return id; }
int Pirate::getSpace() { return space; }

