//
// Created by zacha on 10/4/2020.
//

#ifndef LAB3_ABQ_H
#define LAB3_ABQ_H



template <class input_type> class ABQ {
private:
    float scaleFactor;
    int currentCapacity;
    int currentSize;
    input_type *storageArray;
    int timesResized;
    int queueAccess;
public:
    ABQ();
    ABQ(int capacity);
    ABQ(int capacity, float scale);
    ABQ(const ABQ &d);
    ABQ &operator=(const ABQ &d);
    ~ABQ();
    void enqueue(input_type data);
    input_type dequeue();
    input_type peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    input_type* getData();
    void zeroTimesResized();

};

template<class input_type>
ABQ<input_type>::ABQ() {
    currentSize = 0;
    currentCapacity = 1;
    scaleFactor = 2.0;
    storageArray = new input_type[currentCapacity];
    timesResized = 0;
}

template<class input_type>
ABQ<input_type>::ABQ(int capacity) {
    currentSize = 0;
    currentCapacity = capacity;
    scaleFactor = 2.0;
    storageArray = new input_type[currentCapacity];
    timesResized = 0;
}

template<class input_type>
ABQ<input_type>::ABQ(const ABQ &d) {
    currentSize = d.currentSize;
    currentCapacity = d.currentCapacity;
    scaleFactor = d.scaleFactor;
    storageArray = new input_type[currentCapacity];
    for(int i=0;i<=currentSize;i++){
        storageArray[i] = d.storageArray[i];
    }

}

template<class input_type>
ABQ<input_type> &ABQ<input_type>::operator=(const ABQ &d) {
    for(int i=0;i<=currentSize;i++){
        d.storageArray[i] = storageArray[i];
    }
    return *this;
}

template<class input_type>
ABQ<input_type>::~ABQ() {
    delete [] storageArray;

}

template<class input_type>
void ABQ<input_type>::enqueue(input_type data) {
    if(currentSize == currentCapacity){
        input_type *resizedArray = new input_type[static_cast<int>(scaleFactor*currentCapacity)];
        for(int i = 0;i<currentSize;i++){
            resizedArray[i] = storageArray[i];
        }
        delete [] storageArray;
        storageArray = resizedArray;
        currentCapacity = scaleFactor * currentCapacity;
        timesResized++;
    }
    storageArray[currentSize] = data;
    currentSize++;
}

template<class input_type>
input_type ABQ<input_type>::dequeue() {
    input_type returnData;
    if(currentSize == 0){
        throw std::runtime_error("Queue is empty, cannot return element");
    }
    else {
        returnData = storageArray[queueAccess];
        queueAccess = getMaxCapacity() - getSize();
        if(currentSize < currentCapacity/scaleFactor){
            input_type *resizedArray = new input_type[static_cast<int>(currentCapacity / scaleFactor)];
            for(int i = 0;i<currentSize;i++){
                resizedArray[i] = storageArray[queueAccess+i];
            }
            delete [] storageArray;
            storageArray = resizedArray;
            currentCapacity = currentCapacity / scaleFactor;
            timesResized++;
            queueAccess = 0;
        }
    }
    return returnData;
}

template<class input_type>
input_type ABQ<input_type>::peek() {
    if(currentSize == 0){
        throw std::runtime_error("Queue is empty, cannot return element");
    }
    else {
        return storageArray[0];
    }
}

template<class input_type>
unsigned int ABQ<input_type>::getSize() {
    return currentSize;
}

template<class input_type>
unsigned int ABQ<input_type>::getMaxCapacity() {
    return currentCapacity;
}

template<class input_type>
input_type *ABQ<input_type>::getData() {
    return storageArray;
}

template<class input_type>
ABQ<input_type>::ABQ(int capacity, float scale) {
    currentCapacity = capacity;
    scaleFactor = scale;
    currentSize = 0;
    storageArray = new input_type[currentCapacity];
    timesResized = 0;
}


template<class input_type>
void ABQ<input_type>::zeroTimesResized() {
    timesResized = 0;
}



#endif //LAB3_ABQ_H
