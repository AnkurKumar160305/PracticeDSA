#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int index;
    Node* next;
    Node(int x){
        this->index=x;
        next=NULL;
    }
};

class NStack{
public:
    stack<int> st; //Empty index
    int *arr;   //Original Array
    Node **Top; //Top element index of particular stack
    NStack(int N,int S){
        arr=new int[S];
        Top=new Node*[N];
        for(int i=0;i<N;i++){
            Top[i]=NULL;
        }
        for(int i=0;i<S;i++){
            st.push(i);
        }
    }

    bool push(int x,int m){
        //if no empty index left
        if(st.empty()){
            return 0;
        }
        arr[st.top()]=x;
        Node* temp=new Node(st.top());
        temp->next=Top[m-1];
        Top[m-1]=temp;
        st.pop();
        return 1;
    }

    int pop(int m){
        if(Top[m-1]==NULL){
            return -1;
        }
        Node* temp=Top[m-1];
        int element=arr[Top[m-1]->index];
        st.push(Top[m-1]->index);
        Top[m-1]=Top[m-1]->next;
        delete temp;
        return element;
    }
};