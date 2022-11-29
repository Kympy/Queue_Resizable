#include <iostream>
using namespace std;
#ifndef __QUEUE_H__
#define __QUEUE_H__

template<class T>
class Queue{
private:
    T* queue;
    int size;
    int front;
    int rear;
    void CheckResize(){
        if(front == rear){
            T* temp = new T[size * 2];
            for(int i = 0; i < size; i++){
                temp[i] = queue[i];
            }
            size *= 2;
            delete[] queue;
            queue = temp;
        }
    }
    void Created(){
        cout << "** Queue Created **\n";
    }
    void Deleted(){
        cout << "** Queue Deleted **\n";
    }
public:
    Queue(){
        this->size = 10;
        front = 0;
        rear = -1;
        queue = new T[size];
        Created();
    }
    Queue(int size){
        this->size = size;
        front = 0;
        rear = -1;
        queue = new T[this->size];
        Created();
    }
    ~Queue(){
        delete[] queue;
        Deleted();
    }
    void Enqueue(T data){
        CheckResize();
        rear += 1;
        queue[rear] = data;
    }
    T Dequeue(){
        if(front > rear){
            cout << "## Can't Dequeue ##\n";
            return 999999;
        }
        T temp = queue[front++];
        queue[front - 1] = 999999;
        return temp;
    }
    int Size(){
        return size;
    }
    int Count(){
        if(rear == -1) return 0;
        return rear - front + 1;
    }
    bool Empty(){
        if(Count() == 0){
            return true;
        }
        return false;
    }
};
#endif