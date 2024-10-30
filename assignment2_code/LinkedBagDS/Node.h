#ifndef NODE_H
#define NODE_H


template <typename ItemType>
class Node {
private:
    ItemType item;
    Node<ItemType>* next;


public:
    Node();  // Default constructor
    Node(const ItemType& anItem);  // Constructor with item
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);  // Constructor with item and next pointer


    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);


    ItemType getItem() const;
    Node<ItemType>* getNext() const;
};


// Template definitions


template <typename ItemType>
Node<ItemType>::Node() : next(nullptr) {}


template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) {}


template <typename ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr)
   : item(anItem), next(nextNodePtr) {}


template <typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}


template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr) {
    next = nextNodePtr;
}


template <typename ItemType>
ItemType Node<ItemType>::getItem() const {
    return item;
}


template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return next;
}


#endif  // NODE_H
