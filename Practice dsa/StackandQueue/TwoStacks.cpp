#include <bits/stdc++.h> 
class TwoStack {

public:
    int size;
    int* arr;
    int top1,top2;

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size=s;
        arr=new int[size];
        top1=-1;
        top2=size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1>=0){
            return arr[top1--];
        }
        return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2<size){
            return arr[top2++];
        }
        return -1;
    }
};
