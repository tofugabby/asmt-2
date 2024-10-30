#ifndef LINKED_BAG_H
#define LINKED_BAG_H


#include "Node.h"
#include <vector>


template <typename ItemType>
class LinkedBag {
private:
   Node<ItemType>* headPtr;
   int itemCount;


public:
   LinkedBag();
   LinkedBag(const LinkedBag<ItemType>& aBag);
   ~LinkedBag();


   bool isEmpty() const;
   int getCurrentSize() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;


   bool append(const ItemType& newEntry);
   Node<ItemType>* findKthItem(const int& k) const;


private:
   Node<ItemType>* getPointerTo(const ItemType& anEntry) const;
};


// Template definitions


template <typename ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {}


template <typename ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {
   itemCount = aBag.itemCount;
   headPtr = nullptr;


   Node<ItemType>* origChainPtr = aBag.headPtr;
   if (origChainPtr != nullptr) {
       headPtr = new Node<ItemType>(origChainPtr->getItem());
       Node<ItemType>* newChainPtr = headPtr;
       origChainPtr = origChainPtr->getNext();


       while (origChainPtr != nullptr) {
           Node<ItemType>* newNode = new Node<ItemType>(origChainPtr->getItem());
           newChainPtr->setNext(newNode);
           newChainPtr = newChainPtr->getNext();
           origChainPtr = origChainPtr->getNext();
       }
   }
}


template <typename ItemType>
LinkedBag<ItemType>::~LinkedBag() {
   clear();
}


template <typename ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
   return itemCount == 0;
}


template <typename ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
   return itemCount;
}


template <typename ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
   Node<ItemType>* newNode = new Node<ItemType>(newEntry, headPtr);
   headPtr = newNode;
   itemCount++;
   return true;
}


template <typename ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
   Node<ItemType>* entryNode = getPointerTo(anEntry);
   if (entryNode != nullptr) {
       entryNode->setItem(headPtr->getItem());
       Node<ItemType>* nodeToDelete = headPtr;
       headPtr = headPtr->getNext();
       delete nodeToDelete;
       itemCount--;
       return true;
   }
   return false;
}


template <typename ItemType>
void LinkedBag<ItemType>::clear() {
   while (headPtr != nullptr) {
       Node<ItemType>* nodeToDelete = headPtr;
       headPtr = headPtr->getNext();
       delete nodeToDelete;
   }
   itemCount = 0;
}


template <typename ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
   return getPointerTo(anEntry) != nullptr;
}


template <typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
   int frequency = 0;
   Node<ItemType>* curPtr = headPtr;
   while (curPtr != nullptr) {
       if (curPtr->getItem() == anEntry) {
           frequency++;
       }
       curPtr = curPtr->getNext();
   }
   return frequency;
}


template <typename ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   while (curPtr != nullptr) {
       bagContents.push_back(curPtr->getItem());
       curPtr = curPtr->getNext();
   }
   return bagContents;
}


template <typename ItemType>
bool LinkedBag<ItemType>::append(const ItemType& newEntry) {
   Node<ItemType>* newNode = new Node<ItemType>(newEntry);
   if (headPtr == nullptr) {
       headPtr = newNode;
   } else {
       Node<ItemType>* curPtr = headPtr;
       while (curPtr->getNext() != nullptr) {
           curPtr = curPtr->getNext();
       }
       curPtr->setNext(newNode);
   }
   itemCount++;
   return true;
}


template <typename ItemType>
Node<ItemType>* LinkedBag<ItemType>::findKthItem(const int& k) const{
    if(k < 0 || k > itemCount) {
        return nullptr;
    }
    Node<ItemType>* curPtr = headPtr;
    int count = 0;
    while (curPtr != nullptr) {
        if (count == k) {
            return curPtr;
        }
        curPtr = curPtr->getNext();
        count++;
    }
    return curPtr;
}


template <typename ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const {
   Node<ItemType>* curPtr = headPtr;
   while (curPtr != nullptr) {
       if (curPtr->getItem() == anEntry) {
           return curPtr;
       }
       curPtr = curPtr->getNext();
   }
   return nullptr;
}


#endif  // LINKED_BAG_H