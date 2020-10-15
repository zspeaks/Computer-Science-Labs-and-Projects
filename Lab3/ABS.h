//
// Created by zacha on 10/4/2020.
//

#ifndef LAB3_ABS_H
#define LAB3_ABS_H

template <class input_type> class ABS {
private:
    float scaleFactor;
    int currentCapacity;
    int currentSize;
    input_type *storageArray;
    int timesResized{};

public:
    ABS();
    ABS(int capacity);
    ABS(int capacity, float scale);
    ABS(const ABS &d);
    ABS &operator=(const ABS &d);
    ~ABS();
    void push(input_type data);
    input_type pop();
    input_type peek();
    unsigned int getSize();
    unsigned int getMaxCapacity();
    input_type* getData();
    int getTimesResized();
    void zeroTimesResized();
};

template<class input_type>
ABS<input_type>::ABS() {
    currentSize = 0;
    currentCapacity = 1;
    scaleFactor = 2.0;
    storageArray = new input_type[currentCapacity];
    timesResized = 0;
}

template<class input_type>
ABS<input_type>::ABS(int capacity) {
    currentSize = 0;
    currentCapacity = capacity;
    scaleFactor = 2.0;
    storageArray = new input_type[currentCapacity];
    timesResized = 0;
}

template<class input_type>
ABS<input_type>::ABS(const ABS &d) {
    currentSize = d.currentSize;
    currentCapacity = d.currentCapacity;
    scaleFactor = d.scaleFactor;
    storageArray = new input_type[currentCapacity];
    for(int i=0;i<=currentSize;i++){
        storageArray[i] = d.storageArray[i];
    }
}

template<class input_type>
ABS<input_type>& ABS<input_type>::operator=(const ABS &d) {
    for(int i=0;i<=currentSize;i++){
        d.storageArray[i] = storageArray[i];
    }
    return *this;
}

template<class input_type>
ABS<input_type>::~ABS() {
    delete [] storageArray;
}

template<class input_type>
void ABS<input_type>::push(input_type data) {
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
input_type ABS<input_type>::pop() {
    input_type returnData;
    if(currentSize == 0){
        throw std::runtime_error("Stack is empty, cannot return element");
    }
    else {
        returnData = storageArray[currentSize - 1];
        currentSize--;
        if(currentSize < currentCapacity/scaleFactor){
            input_type *resizedArray = new input_type[static_cast<int>(currentCapacity / scaleFactor)];
            for(int i = 0;i<currentSize;i++){
                resizedArray[i] = storageArray[i];
            }
            delete [] storageArray;
            storageArray = resizedArray;
            currentCapacity = currentCapacity / scaleFactor;
            timesResized++;
        }
    }
    return returnData;
}

template<class input_type>
input_type ABS<input_type>::peek() {
    if(currentSize == 0){
        throw std::runtime_error("Stack is empty, cannot return element");
    }
    else{
        return storageArray[currentSize-1];
    }

}

template<class input_type>
unsigned int ABS<input_type>::getSize() {
    return currentSize;
}

template<class input_type>
unsigned int ABS<input_type>::getMaxCapacity() {
    return currentCapacity;
}

template<class input_type>
input_type *ABS<input_type>::getData() {
    return storageArray;
}

template<class input_type>
ABS<input_type>::ABS(int capacity, float scale) {
    currentCapacity = capacity;
    scaleFactor = scale;
    currentSize = 0;
    storageArray = new input_type[currentCapacity];
    timesResized = 0;
}

template<class input_type>
int ABS<input_type>::getTimesResized() {
    return timesResized;
}

template<class input_type>
void ABS<input_type>::zeroTimesResized() {
    timesResized = 0;
}


#endif //LAB3_ABS_H
