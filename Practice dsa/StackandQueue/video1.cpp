#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    //properties
    int* arr;
    int top;
    int size;

    //behaviors
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }


    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        return top==-1;
    }
};

int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.peek()<<endl; //30
    st.pop();
    cout<<st.peek()<<endl; //20
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl; //1 (true)
    cout<<st.peek()<<endl; //Stack is empty -1
    return 0;
}