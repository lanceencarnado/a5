#ifndef QUEUE_H
#define QUEUE_H

#include "Pirate.h"
#include <cstdlib>

template <class T>
class Queue
{
    class Node 
    {
        friend class Queue<T>;
        private:
            T data;
            Node*   next;
            Node*   prev;
    };
    
    public:
        Queue();
        Queue(Queue<T>&);
        ~Queue();
        void pop();
        T front();
        void deleteData();
        Queue<T>& operator+=(T);
        Queue<T>& operator-=(T);
        T operator[](int);
        bool operator!();
    
    private:
        Node* head;
};

template <class T>
Queue<T>::Queue() : head (0){ }

template <class T>
Queue<T>::Queue(Queue<T> &origQueue){
    head = 0;
    Node *origCurrNode;
    
    origCurrNode = origQueue.head;
    
    while (origCurrNode != 0) {
        *this += origCurrNode->data;
        origCurrNode = origCurrNode->next;
    }
}

template <class T>
Queue<T>::~Queue(){
    Node *currNode, *nextNode;
    
    currNode = head;
    
    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
}

/*   Function:  pop                         			        */
/*        out:  Int indicating success or failure               */
/*    Purpose:  Removes the generic type at the front of the    */
/*              Queue                                           */

template <class T>
void Queue<T>::pop(){
    if (head != 0)
        *(this) -= head->data;
}

/*   Function:  front                         			        */
/*        out:  Generic type at the front of the Queue          */
/*    Purpose:  Returns the generic type at the front of        */
/*              the queue                                       */

template <class T>
T Queue<T>::front(){
    return head->data;
}

template <class T>
void Queue<T>::deleteData(){
    Node *currNode, *nextNode;
    
    currNode = head;
    
    while (currNode != 0) {
        nextNode = currNode->next;
        delete currNode->data;
        currNode = nextNode;
    }
}

/*   Function:  overloaded addition assignment operator         */
/*         in:  Generic type to be added to the Queue           */
/*        out:  Reference to the queue (cascading)              */
/*    Purpose:  Adds the generic type to the end of the Queue   */

template <class T>
Queue<T>& Queue<T>::operator+=(T newT){
    Node *newNode;
    Node *currNode, *prevNode;
    
    newNode = new Node;
    newNode->data = newT;
    newNode->prev = 0;
    newNode->next = 0;
    
    prevNode = 0;
    currNode = head;
    
    while (currNode != 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    if (prevNode == 0) {
        head = newNode;
    }
    else {
        prevNode->next = newNode;
        newNode->prev  = prevNode;
    }
    
    newNode->next = currNode;
    
    if (currNode != 0) {
        currNode->prev = newNode;
    }
    
    return *this;
}

/*   Function:  overloaded subtraction assignment operator      */
/*         in:  A generic type to be removed                    */
/*    Purpose:  Removes a generic type from the Queue           */

template <class T>
Queue<T>& Queue<T>::operator-=(T tPtr){
    Node *currNode, *prevNode;
    
    prevNode = 0;
    currNode = head;
    
    while (currNode != 0) {
        if (currNode->data == tPtr)
            break;
        prevNode = currNode;
        currNode = currNode->next;
    }
    
    if (currNode == 0)
        return *this;
    
    if (prevNode == 0) {
        head = currNode->next;
        if (head != 0)
            head->prev = 0;
    }
    else {
        prevNode->next = currNode->next;
        if (currNode->next != 0)
            currNode->next->prev = prevNode;
    }
    
    delete currNode;
    
    return *this;

}

/*   Function:  overloaded subscript operator                   */
/*         in:  Index of the queue                              */
/*        out:  The data at that index                          */
/*    Purpose:  Returns the data at an index                    */

template <class T>
T Queue<T>::operator[](int index){
    Node *currNode;
    int currIndex = 0;
    
    currNode = head;
    
    while (currNode != 0) {
        if (currIndex == index) {
            return currNode->data;
        }
        currNode = currNode->next;
        currIndex += 1;
    }
    
    return 0;
}

/*   Function:  overloaded Negation operator                    */
/*        out:  Boolean indicating empty or non-empty           */
/*    Purpose:  Indicates whether or not the Queue is empty     */

template <class T>
bool Queue<T>::operator!(){
    if (head == 0)
        return false;
    else
        return true;
}

#endif
