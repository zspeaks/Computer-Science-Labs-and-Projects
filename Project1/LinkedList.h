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


// Accessors
template<typename Type>
unsigned int LinkedList<Type>::NodeCount() {
    return nodeCount;
}

// Insertion
template<typename Type>
void LinkedList<Type>::AddHead(Type data) {
    listHead = new NodeClass(nullptr,listHead,data);
    nodeCount++;
}

template<typename Type>
void LinkedList<Type>::AddTail(Type data) {
    listTail = new NodeClass(listTail, nullptr, data);
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
    for(int i = 0; i < count; i++){
        AddTail(datas[i]);
    }
}

// Removal


// Operators


// Construction / Destruction










#endif //PROJECT1_LINKEDLIST_H
