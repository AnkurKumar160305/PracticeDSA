#include<bits/stdc++.h>
using namespace std;


// 1-Reverse a string using stack
int main(){
    string str="Hello World";
    stack<int> s;

    for(int i=0;i<str.length();i++){
        s.push(str[i]);
    }

    string ans="";
    while(!s.empty()){
        char ch=s.top();
        ans+=ch;
        s.pop();
    }
    cout<<ans<<endl;
}


//2-Delete the middle element of a stack
void solve(stack<int> &Stack,int count,int size){
    if(count==size/2){
        Stack.pop();
        return;
    }
    int temp = Stack.top();
    Stack.pop();

    solve(Stack,count+1,size);
    Stack.push(temp);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count=0;
   solve(inputStack,count,N);
   
}


// 3-Valid Parentheses
bool isValidParenthesis(string str)
{
    stack<int> s;
    for(char ch:str){
        if(ch=='{' || ch=='(' || ch=='['){
            s.push(ch);
        }else{
            if(s.empty()){
                return false;
            }
            if((ch=='}' && s.top()!='{') || (ch==')' && s.top()!='(') || (ch==']' && s.top()!='[')){
                return false;
            }
            s.pop();
        }
    }
    return true;
}


// 4-Insert an element at the bottom of a stack
#include <bits/stdc++.h> 

void solve(stack<int>& myStack, int x,int size){
    if(size==0){
        myStack.push(x);
        return;
    }
    int t=myStack.top();
    myStack.pop();
    solve(myStack,x,size-1);
    myStack.push(t);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    int size=myStack.size();
    solve(myStack,x,size);
    return myStack;
}


//5-Reverse a stack using recursion
void insertAtBottom(stack<int> &stack,int element){
    if(stack.empty()){
        stack.push(element);
        return;
    }
    int t=stack.top();
    stack.pop();
    insertAtBottom(stack,element);
    stack.push(t);
}

void solve(stack<int> &stack){
    if(stack.empty()){
        return;
    }
    int t=stack.top();
    stack.pop();
    solve(stack);
    insertAtBottom(stack,t);
}

void reverseStack(stack<int> &stack) {
    solve(stack);
}


// 6-Sort a stack using recursion in decreasing order
void insertSorted(stack<int> &st,int x){
	if(st.empty() || st.top()<=x){
		st.push(x);
		return;
	}
	int t=st.top();
	st.pop();
	insertSorted(st,x);
	st.push(t);
}


void sortStack(stack<int> &st)
{
	if(st.empty()){
		return;
	}
	int t=st.top();
	st.pop();
	sortStack(st);
	insertSorted(st,t);
}

//7-Redundant Brackets
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(char ch:s){
        if(ch=='('){
            st.push(ch);
        }
        else{
            bool hasOperator=false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' 
                || top == '/') {
                    hasOperator = true;
                }
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
            if (!hasOperator) return true;
        }
    }
    return false;
}
