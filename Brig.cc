#include "Brig.h"

Brig::Brig() { }

Brig::~Brig() {
    // Deletes the data contained in each queue in each cell
    list<Cell*>::iterator itr;
    for (itr = cells.begin(); itr != cells.end(); ++itr) {
        (*itr)->getPirates().deleteData();
    }
}

/*   Function:  overloaded addition assignment operator         */
/*         in:  Location of pirate to be added to the brig		*/
/*    Purpose:  Adds a single pirate to the brig in a cell		*/
/*				that has enough space for it					*/

Brig& Brig::operator+=(Pirate* pirate)
{
    Cell* newCell;
    bool added = false;
    
    list<Cell*>::iterator itr;
    for (itr = cells.begin(); itr != cells.end(); ++itr) {
        if ((*itr)->fits(pirate)) {
            (*itr)->getPirates() += pirate;
            *(*itr) -= pirate->getSpace();
            added = true;
            break;
        }
    }
    
    if (!added) {
        newCell = new Cell;
        cells.push_back(newCell);
        newCell->getPirates() += pirate;
        *newCell -= pirate->getSpace();        
    }
    
    return *this;
}

/*   Function:  removePirate	                         		*/
/*         in:  ID of pirate to be removed from the brig		*/
/*    Purpose:  Removes a pirate with a matching ID from the    */
/*              brig                                            */

int Brig::removePirate(int pirateId) {
    Cell* currCell;
    Pirate* foundPirate;

    list<Cell*>::iterator itr;
    for (itr = cells.begin(); itr != cells.end(); ++itr) {
        currCell = *itr;
        foundPirate = currCell->find(pirateId);
        if (foundPirate != 0) {
            *currCell += (currCell->getPirateSpace(pirateId));
            currCell->getPirates() -= foundPirate;  // remove it from the Queue
            delete foundPirate;                       // deallocate the data
            return C_OK;
        } 
    }
    
    return C_NOK;   // if we've reached this then the Pirate wasn't found
}

list<Cell*>& Brig::getCells() { return cells; }

