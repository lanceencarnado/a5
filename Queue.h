#ifndef QUEUE_H
#define QUEUE_H

#include "Pirate.h"
#include <cstdlib>

template <class T>
class Queue
{
    class Node 
    {
        friend class Queue;
        private:
            Pirate* data;
            Node*   next;
            Node*   prev;
    };
    
    public:
        Queue();
        Queue(Queue<T>&);
        ~Queue();
        void pop();
        T* front();
        int getPirateSpace(int pID);
        T* find(int);
        void deleteData();
        Queue<T>& operator+=(T*);
        Queue<T>& operator-=(T*);
        T* operator[](int index);
        bool operator!();
    
    private:
        Node* head;
};

template <class T>
Queue<T>::Queue() : head (0){ }

template <class T>
Queue<T>::Queue(Queue<T>){
    head = 0;
    Node *origCurrNode;
    
    origCurrNode = origQueue.head;
    
    while (origCurrNode != 0) {
        *this += origCurrNode->data;
        origCurrNode = origCurrNode->next;
    }
}

template <class T>
Queue<T>::~Queue(){ }

//to do
template <class T>
void Queue<T>::pop(){ }

//to do
template <class T>
T* Queue<T>::front(){ }

//to do
template <class T>
int Queue<T>::getPirateSpace(int pID){ }

//to do
template <class T>
T* Queue<T>::find(int){ }

//to do
template <class T>
void Queue<T>::deleteData(){ }

//to do
template <class T>
Queue<T>& Queue<T>::operator+=(T*){ }

//to do
template <class T>
Queue<T>& Queue<T>::operator-=(T*){ }

//to do
template <class T>
bool Queue<T>::operator!(){ }

#endif
