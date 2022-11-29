#include <iostream>
#include "Queue.h"
#define endl "\n"
using namespace std;

void Print(Queue<int>* queue);

int main(){
    Queue<int>* myQueue = new Queue<int>;

    myQueue->Enqueue(0);
    Print(myQueue);

    cout << "Popped element : " << myQueue->Dequeue() << endl;

    Print(myQueue);
    for(int i = 1; i <= 10; i++){
        myQueue->Enqueue(i);
    }
    Print(myQueue);

    myQueue->Enqueue(11);
    myQueue->Enqueue(12);
    Print(myQueue);

    for(int i = 1; i <= 12; i++){
        myQueue->Dequeue();
    }
    Print(myQueue);
    
    myQueue->Dequeue();
    Print(myQueue);
    delete myQueue;
    return 0;
}

void Print(Queue<int>* queue){
    cout << "Queue Count : " << queue->Count() << endl;
    cout << "Queue Size : " << queue->Size() << endl;
    string result = queue->Empty() ? "true" : "false";
    cout << "Queue is empty : " << result << endl;
    cout << endl << "=================" << endl;
}