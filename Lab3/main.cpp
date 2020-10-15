#include <iostream>
#include "ABQ.h"
#include "ABS.h"
#include <chrono>
using namespace std;
void individualTest(float scales, int N){
    ABS<unsigned int> testStack = ABS<unsigned int>(2,scales);
    ABQ<unsigned int> testQueue = ABQ<unsigned int>(2,scales);
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    for(int i = 0;i<N;i++){
        testStack.push(i);
    }
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "I resized " << testStack.getTimesResized();
    cout << " times and it took me " << time_span.count() << "seconds" << endl;
    testStack.zeroTimesResized();
    t1 = chrono::steady_clock::now();
    for(int i = 0;i<N;i++){
        testStack.pop();
    }
    t2 = chrono::steady_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "I resized " << testStack.getTimesResized();
    cout << " times and it took me " << time_span.count() << "seconds" << endl;
    t1 = chrono::steady_clock::now();
    for(int i = 0;i<N;i++){
        testQueue.enqueue(i);
    }
    t2 = chrono::steady_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "I resized " << testStack.getTimesResized();
    cout << " times and it took me " << time_span.count() << "seconds" << endl;
    testQueue.zeroTimesResized();
    t1 = chrono::steady_clock::now();
    for(int i = 0;i<N;i++){
        testQueue.dequeue();
    }
    t2 = chrono::steady_clock::now();
    time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout << "I resized " << testStack.getTimesResized();
    cout << " times and it took me " << time_span.count() << "seconds" << endl;
    cout << "New N" << endl;
}

void testReport(float scales){
    individualTest(scales,10000000);
    individualTest(scales,30000000);
    individualTest(scales,50000000);
    individualTest(scales,75000000);
    individualTest(scales,100000000);
    cout << "New scale" << endl;
}
int main()
{
    testReport(1.5);
    testReport(2.0);
    testReport(3.0);
    testReport(10.0);
    testReport(100.0);
    return 0;
}

