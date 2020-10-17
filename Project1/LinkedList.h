//
// Created by zacha on 10/8/2020.
//

#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H
#include "vector"
template<typename Type>
class LinkedList {
public:
    struct NodeClass{
        NodeClass* head;
        NodeClass* tail;
        Type nodeData;
        NodeClass(NodeClass* _head, NodeClass* _tail, Type data);
    };
    // Ways to print
    void PrintForward() const;
    void PrintReverse() const;
    void PrintForwardRecursive(const NodeClass* node) const;
    void PrintForwardReverse(const NodeClass* node) const;

    // Accessors
    unsigned int NodeCount();
    const NodeClass* Find(const Type& data) const;
    NodeClass* Find(const Type& data);
    void FindAll(std::vector<NodeClass*>& outData, const Type& data) const;
    const NodeClass* GetNode(unsigned int index) const;
    NodeClass* GetNode(unsigned int index);
    const NodeClass* Head() const;
    NodeClass* Head();
    const NodeClass* Tail() const;
    NodeClass* Tail();

    // Insertions
    void AddHead(Type data);
    void AddTail(Type data);
    void AddNodesHead(Type* datas, unsigned int count);
    void AddNodesTail(Type* datas, unsigned int count);
    void InsertAfter(NodeClass* node, const Type& data);
    void InsertBefore(NodeClass* node, const Type& data);
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
    bool operator ==(LinkedList<Type>& rhs);


    // Construction / Destruction
    LinkedList();
    LinkedList(const LinkedList<Type>& list);
    ~LinkedList();
private:
    NodeClass* listHead;
    NodeClass* listTail;
    unsigned int nodeCount;
};


// NodeClass Method Definitions
template<typename Type>
LinkedList<Type>::NodeClass::NodeClass(LinkedList::NodeClass *_head, LinkedList::NodeClass *_tail, Type data) {
    head = _head;
    tail = _tail;
    nodeData = data;
}


// Linked List Method Definitions



// Printing
template<typename Type>
void LinkedList<Type>::PrintForward() const {
    for(unsigned int i = 0; i < nodeCount; i++){
        LinkedList<Type>::NodeClass node = * GetNode(i);
        std::cout << node.nodeData << std::endl;
    }
}

template<typename Type>
void LinkedList<Type>::PrintReverse() const {
    for(unsigned int i = nodeCount; i > 0; i--){
        LinkedList<Type>::NodeClass node = * GetNode(i-1);
        std::cout << node.nodeData << std::endl;
    }
}



// Accessors
template<typename Type>
unsigned int LinkedList<Type>::NodeCount() {
    return nodeCount;
}

template<typename Type>
const typename LinkedList<Type>::NodeClass *LinkedList<Type>::GetNode(unsigned int index) const {
    if(index > nodeCount){
        throw std::out_of_range("Index out of range!");
    }
    else{
        const typename LinkedList<Type>::NodeClass* returnNodePointer = Head();
        for(unsigned int i = 0;i<index;i++){

            returnNodePointer = (*returnNodePointer).tail;
        }
        return returnNodePointer;
    }
}


template<typename Type>
typename LinkedList<Type>::NodeClass *LinkedList<Type>::GetNode(unsigned int index) {
    if(index > nodeCount){
        throw std::out_of_range("Index out of range!");
    }
    else{
        typename LinkedList<Type>::NodeClass* returnNodePointer = Head();
        for(unsigned int i = 0;i<index;i++){
            returnNodePointer = (*returnNodePointer).tail;
        }
        return returnNodePointer;
    }
}

template<typename Type>
const typename LinkedList<Type>::NodeClass* LinkedList<Type>::Head() const {
    return listHead;
}

template<typename Type>
typename LinkedList<Type>::NodeClass* LinkedList<Type>::Head() {
    return listHead;
}

template<typename Type>
const typename LinkedList<Type>::NodeClass* LinkedList<Type>::Tail() const {
    return listTail;
}

template<typename Type>
typename LinkedList<Type>::NodeClass* LinkedList<Type>::Tail() {
    return listTail;
}


// Insertion
template<typename Type>
void LinkedList<Type>::AddHead(Type data) {
    if (nodeCount > 0){
        typename LinkedList<Type>::NodeClass* tempPointer  = listHead;
        listHead = new NodeClass(nullptr,listHead,data);
        (*tempPointer).head = listHead;
    }
    else{
        listHead = new NodeClass(nullptr,listHead,data);
        listTail = listHead;
    }
    nodeCount++;
}

template<typename Type>
void LinkedList<Type>::AddTail(Type data) {
    if (nodeCount > 0){
        typename LinkedList<Type>::NodeClass* tempPointer  = listTail;
        listTail = new NodeClass(listTail, nullptr, data);
        (*tempPointer).tail = listTail;
    }
    else{
        listTail = new NodeClass(listTail, nullptr, data);
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


// Removal


// Operators

template<typename Type>
Type &LinkedList<Type>::operator[](unsigned int index) {
    return GetNode(index);
}


// Construction / Destruction

template<typename Type>
LinkedList<Type>::LinkedList() {
    listHead = nullptr;
    listTail = nullptr;
    nodeCount = 0;


}

template<typename Type>
LinkedList<Type>::~LinkedList() {
    for(unsigned int i = 0; i < nodeCount; i++){
        typename LinkedList<Type>::NodeClass* tempNodePointer = LinkedList<Type>::GetNode(1);
        delete GetNode(0);
        listHead = tempNodePointer;
    }
}



#endif //PROJECT1_LINKEDLIST_H
