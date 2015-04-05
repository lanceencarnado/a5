#include "Cell.h"

int Cell::nextId = 1;

Cell::Cell(int size)
      : spaceRemaining(size)
{
    cellNumber = nextId++;
}

Queue<Pirate*>&     Cell::getPirates()   { return pirates; }
int                 Cell::getSpace()   { return spaceRemaining; }


/*   Function:  fits()                                          */
/*         in:  Pirate pointer                                  */
/*        out:  Boolean stating whether the Pirate fits         */
/*    Purpose:  Determines if the given Pirate fits in the Cell */

bool Cell::fits(Pirate* pirate)
{
    if ((spaceRemaining - pirate->getSpace()) < 0)
        return false;

    return true;
}

/*   Function:  overloaded subtraction operator                 */
/*         in:  Pirate space int                                */
/*    Purpose:  Subtracts the given space from the Cell         */

Cell& Cell::operator+=(int pSpace) 
{ 
    spaceRemaining += pSpace; 
    return *this;
}

/*   Function:  overloaded subtraction operator                 */
/*         in:  Pirate space int                                */
/*    Purpose:  Subtracts the given space from the Cell         */

Cell& Cell::operator-=(int pSpace) 
{ 
    spaceRemaining -= pSpace; 
    return *this;
}

/*   Function:  overloaded addition operator                    */
/*         in:  Pirate pointer                                  */
/*    Purpose:  Adds a new pirate to the Cell                   */

Cell& Cell::operator+=(Pirate* newPirate){
    pirates += newPirate;
    
    return *this;
}

/*   Function:  getPirateSpace                         			*/
/*         in:  ID of a pirate                                  */
/*        out:  The space of a pirate with matching ID          */
/*    Purpose:  Returns the space of a pirate (this is used     */
/*              when removing a pirate, in order to increase    */
/*              the space that is left in a cell after a pirate */
/*              is removed from it)                             */
/*              (a temporary queue is made in order to find     */
/*              the Pirate)                                     */

int Cell::getPirateSpace(int pirateId) {
    Queue<Pirate*>* tempQueue = new Queue<Pirate*>(pirates);
    int foundSpace;
    
    while (!(*tempQueue)) {
        if ((*tempQueue)[0]->getId() == pirateId) {
            foundSpace = (*tempQueue)[0]->getSpace();
            delete tempQueue;
            return foundSpace;
        }
        tempQueue->pop();
    }
    
    delete tempQueue;
    return 0;
}

/*   Function:  find                                 			*/
/*         in:  ID of a pirate                                  */
/*        out:  A pointer to the pirate with a matching ID      */
/*    Purpose:  Returns a pointer to the pirate that is being   */
/*              searched for                                    */
/*              (for deallocation purposes in the               */
/*              removePirate() function in the Brig)            */
/*              (a temporary queue is made in order to find     */
/*              the Pirate)                                     */

Pirate* Cell::find(int pirateId) {
    Queue<Pirate*>* tempQueue = new Queue<Pirate*>(pirates);
    Pirate* foundPirate;
    
    while (!(*tempQueue)) {
        if ((*tempQueue)[0]->getId() == pirateId) {
            foundPirate = (*tempQueue)[0];
            delete tempQueue;
            return foundPirate;
        }
        tempQueue->pop();
    }
    
    delete tempQueue;
    return 0;
}
