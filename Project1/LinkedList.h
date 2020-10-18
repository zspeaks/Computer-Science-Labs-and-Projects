//
// Created by zacha on 10/8/2020.
//

#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H
#include "vector"
template<typename Type>
class LinkedList {
public:
    struct Node{
        Node* prev;
        Node* next;
        Type data;
        Node(Node* _head, Node* _tail, Type data);
    };
    // Ways to print
    void PrintForward() const;
    void PrintReverse() const;
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive(const Node* node) const;

    // Accessors
    unsigned int NodeCount();
    const Node* Find(const Type& data) const;
    Node* Find(const Type& data);
    void FindAll(std::vector<Node*>& outData, const Type& data) const;
    const Node* GetNode(unsigned int index) const;
    Node* GetNode(unsigned int index);
    const Node* Head() const;
    Node* Head();
    const Node* Tail() const;
    Node* Tail();

    // Insertions
    void AddHead(Type data);
    void AddTail(Type data);
    void AddNodesHead(Type* datas, unsigned int count);
    void AddNodesTail(Type* datas, unsigned int count);
    void InsertAfter(Node* node, const Type& data);
    void InsertBefore(Node* node, const Type& data);
    void InsertAt(const Type& data, unsigned int index);

    // Removal
    bool RemoveHead();
    bool RemoveTail();
    unsigned int Remove(const Type& data);
    bool RemoveAt(unsigned int index);
    void Clear();

    // Operators
    const Type& operator[](unsigned int index) const;
    Type& operator[](unsigned int index);
    bool operator ==(const LinkedList<Type>& rhs) const;
    LinkedList<Type>& operator =(const LinkedList<Type>& rhs);


    // Construction / Destruction
    LinkedList();
    LinkedList(const LinkedList<Type>& list);
    ~LinkedList();
private:
    Node* listHead;
    Node* listTail;
    unsigned int nodeCount;
};


// Node Method Definitions
template<typename Type>
LinkedList<Type>::Node::Node(LinkedList::Node *_head, LinkedList::Node *_tail, Type data) {
    prev = _head;
    next = _tail;
    data = data;
}


// Linked List Method Definitions



// Printing
template<typename Type>
void LinkedList<Type>::PrintForward() const {
    for(unsigned int i = 0; i < nodeCount; i++){
        LinkedList<Type>::Node node = * GetNode(i);
        std::cout << node.data << std::endl;
    }
}

template<typename Type>
void LinkedList<Type>::PrintReverse() const {
    for(unsigned int i = nodeCount; i > 0; i--){
        LinkedList<Type>::Node node = * GetNode(i - 1);
        std::cout << node.data << std::endl;
    }
}

template<typename Type>
void LinkedList<Type>::PrintForwardRecursive(const LinkedList::Node *node) const {
//TODO
}

template<typename Type>
void LinkedList<Type>::PrintReverseRecursive(const LinkedList::Node *node) const {
//TODO
}


// Accessors
template<typename Type>
unsigned int LinkedList<Type>::NodeCount() {
    return nodeCount;
}

template<typename Type>
const typename LinkedList<Type>::Node* LinkedList<Type>::Find(const Type &data) const {
    for(unsigned int i = 0; i < nodeCount; i++){
        LinkedList<Type>::Node* nodePointer = GetNode(i);
        if ((*nodePointer).data == data){
            return nodePointer;
        }
    }
    return nullptr;
}


template<typename Type>
typename LinkedList<Type>::Node* LinkedList<Type>::Find(const Type &data) {
    for(unsigned int i = 0; i < nodeCount; i++){
        LinkedList<Type>::Node* nodePointer = GetNode(i);
        if ((*nodePointer).data == data){
            return nodePointer;
        }
    }
    return nullptr;
}
//TODO
/*
template<typename Type>
void LinkedList<Type>::FindAll(std::vector<Node *> &outData, const Type &data) const {
    for(unsigned int i = 0; i < nodeCount; i++){
        const LinkedList<Type>::Node* nodePointer = this[i];

        if ((*nodePointer).data == data){
            outData.push_back(nodePointer);
        }
    }
}
*/

template<typename Type>
const typename LinkedList<Type>::Node* LinkedList<Type>::GetNode(unsigned int index) const {
    if(index > nodeCount){
        throw std::out_of_range("Index out of range!");
    }
    else{
        const typename LinkedList<Type>::Node* returnNodePointer = Head();
        for(unsigned int i = 0;i<index;i++){

            returnNodePointer = (*returnNodePointer).next;
        }
        return returnNodePointer;
    }
}


template<typename Type>
typename LinkedList<Type>::Node *LinkedList<Type>::GetNode(unsigned int index) {
    if(index > nodeCount){
        throw std::out_of_range("Index out of range!");
    }
    else{
        typename LinkedList<Type>::Node* returnNodePointer = Head();
        for(unsigned int i = 0;i<index;i++){
            returnNodePointer = (*returnNodePointer).next;
        }
        return returnNodePointer;
    }
}

template<typename Type>
const typename LinkedList<Type>::Node* LinkedList<Type>::Head() const {
    return listHead;
}

template<typename Type>
typename LinkedList<Type>::Node* LinkedList<Type>::Head() {
    return listHead;
}

template<typename Type>
const typename LinkedList<Type>::Node* LinkedList<Type>::Tail() const {
    return listTail;
}

template<typename Type>
typename LinkedList<Type>::Node* LinkedList<Type>::Tail() {
    return listTail;
}


// Insertion
template<typename Type>
void LinkedList<Type>::AddHead(Type data) {
    if (nodeCount > 0){
        typename LinkedList<Type>::Node* tempPointer  = listHead;
        listHead = new Node(nullptr, listHead, data);
        (*tempPointer).prev = listHead;
    }
    else{
        listHead = new Node(nullptr, listHead, data);
        listTail = listHead;
    }
    nodeCount++;
}

template<typename Type>
void LinkedList<Type>::AddTail(Type data) {
    if (nodeCount > 0){
        typename LinkedList<Type>::Node* tempPointer  = listTail;
        listTail = new Node(listTail, nullptr, data);
        (*tempPointer).next = listTail;
    }
    else{
        listTail = new Node(listTail, nullptr, data);
        listHead = listTail;
    }
    nodeCount++;
}

template<typename Type>
void LinkedList<Type>::AddNodesHead(Type *datas, unsigned int count) {
    for(unsigned int i = count; i > 0 ; i--){
        AddHead(datas[i-1]);
    }
}

template<typename Type>
void LinkedList<Type>::AddNodesTail(Type *datas, unsigned int count) {
    for(unsigned int i = 0; i < count; i++){
        AddTail(datas[i]);
    }
}

template<typename Type>
void LinkedList<Type>::InsertAfter(LinkedList::Node *node, const Type &data) {
//TODO
}

template<typename Type>
void LinkedList<Type>::InsertBefore(LinkedList::Node *node, const Type &data) {
//TODO
}

template<typename Type>
void LinkedList<Type>::InsertAt(const Type &data, unsigned int index) {
//TODO
}


// Removal
template<typename Type>
bool LinkedList<Type>::RemoveHead() {
    //TODO
}

template<typename Type>
bool LinkedList<Type>::RemoveTail() {
    //TODO
}

template<typename Type>
unsigned int LinkedList<Type>::Remove(const Type &data) {
    //TODO
}

template<typename Type>
bool LinkedList<Type>::RemoveAt(unsigned int index) {
    if(index < nodeCount){
        try {
            LinkedList<Type>::Node* removedNode = GetNode(index);
            LinkedList<Type>::Node* tempHeadStorage =(*removedNode).prev;
            LinkedList<Type>::Node* tempTailStorage =(*removedNode).next;
            if (tempHeadStorage != nullptr){
                (*tempHeadStorage).next = tempTailStorage;
            }
            if (tempTailStorage != nullptr){
                (*tempTailStorage).prev = tempHeadStorage;
            }
            delete removedNode;
            delete tempHeadStorage;
            delete tempTailStorage;
            nodeCount--;
            return true;
        }
        catch (std::exception& e) {
            return false;
        }
    }
    return false;
}

template<typename Type>
void LinkedList<Type>::Clear() {
    for(unsigned int i = 0; i < nodeCount; i++){
        RemoveAt(0);
    }
}


// Operators
template<typename Type>
const Type &LinkedList<Type>::operator[](unsigned int index) const {
    return GetNode(index);
}

template<typename Type>
Type &LinkedList<Type>::operator[](unsigned int index) {
    return GetNode(index);
}

template<typename Type>
bool LinkedList<Type>::operator==(const LinkedList<Type> &rhs) const {
    for(unsigned int i = 0; i < nodeCount; i++){
        if(GetNode(i) != rhs.GetNode(i)){
            return false;
        }
    }
    return true;
}

template<typename Type>
LinkedList<Type> &LinkedList<Type>::operator=(const LinkedList<Type> &rhs) {
    Clear();
    for(unsigned int i = 0; i < rhs.nodeCount; i++){
        AddTail((*rhs.GetNode(i)).data);
    }
    return *this;
}



// Construction / Destruction

template<typename Type>
LinkedList<Type>::LinkedList() {
    listHead = nullptr;
    listTail = nullptr;
    nodeCount = 0;


}
template<typename Type>
LinkedList<Type>::LinkedList(const LinkedList<Type> &list) {
    nodeCount = 0;
    listHead = nullptr;
    listTail = nullptr;
    for(unsigned int i = 0; i < list.nodeCount; i++){
        AddTail((*list.GetNode(i)).data);
    }
}

template<typename Type>
LinkedList<Type>::~LinkedList() {
    for(unsigned int i = 0; i < nodeCount; i++){
        typename LinkedList<Type>::Node* tempNodePointer = LinkedList<Type>::GetNode(1);
        delete GetNode(0);
        listHead = tempNodePointer;
    }
}



#endif //PROJECT1_LINKEDLIST_H
