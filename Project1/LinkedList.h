//
// Created by zacha on 10/8/2020.
//

#ifndef PROJECT1_LINKEDLIST_H
#define PROJECT1_LINKEDLIST_H

template<typename Type>
class LinkedList {
private:


public:
    struct NodeClass{
        NodeClass* head;
        NodeClass* tail;
        Type nodeData;

    };
    NodeClass* listHead;
    NodeClass* listTail;
    int nodeCount;
    void AddHead(Type data);
    void AddTail(Type data);
    void AddNodesHead(Type datas[]);
    void AddNodesTail(Type datas[]);
    int NodeCount();
    void PrintForward();
    void PrintReverse();
    LinkedList();
    ~LinkedList();

};


#endif //PROJECT1_LINKEDLIST_H
