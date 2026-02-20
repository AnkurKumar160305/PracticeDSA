#include <bits/stdc++.h> 
class CircularQueue{
    int size;
    int* arr;
    int qfront,rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size=n;
        arr=new int[size];
        qfront=rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((rear + 1) % size == qfront){ //full
            return false;
        }else if(qfront==-1){//empty
            qfront=rear=0;
        }else if(rear==size-1 && qfront!=0){//last
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(qfront==-1){
            return -1;
        }
        int ans=arr[qfront];
        if(qfront==rear){  //single element
            qfront=rear=-1;
        }else if(qfront==size-1){//cyclic nature
            qfront=0;
        }else{
            qfront++;
        }
        return ans;
    }
};