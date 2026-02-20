#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
}


#include <bits/stdc++.h> 
class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;
public:
    Queue() {
        size=10001;
        arr=new int[size];
        rear=qfront=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return qfront==rear;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==size){
            return;
        }else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear==qfront){
            return -1;
        }else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=rear=0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(!isEmpty()){
            return arr[qfront];
        }
        return -1;
    }
};