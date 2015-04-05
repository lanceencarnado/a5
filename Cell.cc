#include "Cell.h"

int Cell::nextId = 1;

Cell::Cell(int size)
      : spaceRemaining(size)
{
    cellNumber = nextId++;
}

Queue&  Cell::getPirates()   { return pirates; }
int     Cell::getSpace()   { return spaceRemaining; }


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
/*              is removed from it                              */

int Cell::getPirateSpace(int pirateId) {
    Node *currNode;
    
    currNode = pirates.getHead();
    
    while (currNode != 0) {
        if (currNode->data->getId() == pirateId)
            return currNode->data->getSpace();
        currNode = currNode->next;
    }
    
    return 0;
}

/*   Function:  find                                 			*/
/*         in:  ID of a pirate                                  */
/*        out:  A pointer to the pirate with a matching ID      */
/*    Purpose:  Returns a pointer to the pirate that is being   */
/*              searched for                                    */
/*              (for deallocation purposes in the               */
/*              removePirate() function in the Brig)            */

Pirate* Cell::find(int pirateId) {
    Node *currNode;
    
    currNode = pirates.getHead();
    
    while (currNode != 0) {
        if (currNode->data->getId() == pirateId)
            return currNode->data;
        currNode = currNode->next;
    }
    
    return 0;
}
