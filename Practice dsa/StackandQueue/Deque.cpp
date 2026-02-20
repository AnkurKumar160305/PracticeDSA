#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    cout<<dq.size()<<endl;
    dq.pop_back();
    cout<<dq.size()<<endl;
    cout<<dq.front()<<endl;
}



#include <bits/stdc++.h> 
class Deque
{
    int* arr;
    int size;
    int front,rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size=n;
        arr=new int[size];
        front=rear=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(isFull()){ //full
            return false;
        }else if(isEmpty()){
            front=rear=0;
        }else if(front==0 && rear!=size-1){
            front=size-1;
        }else{
            front--;
        }
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(isFull()){ //full
            return false;
        }else if(isEmpty()){
            front=rear=0;
        }else if(rear==size-1 && front!=0){
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int ans=arr[front];
        if(front==rear){  //single element
            front=rear=-1;
        }else if(front==size-1){//cyclic nature
            front=0;
        }else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int ans=arr[rear];
        if(front==rear){  //single element
            front=rear=-1;
        }else if(rear==0){//cyclic nature
            rear=size-1;
        }else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        if(front==-1 && rear==-1){
            return true;
        }
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        if((rear + 1) % size == front){ //full
            return true;
        }
        return false;
    }
};