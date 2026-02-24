class MyCircularDeque {
    int *arr;
    int front;
    int rear;
    int capacity;
public:
    MyCircularDeque(int k) {
        // add your code here
        capacity=k;
        arr=new int[k];
        front=rear=-1;
    }

    bool insertFront(int value) {
        // add your code here
       
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            front=rear=0;
        }else if(front==0){
            front=capacity-1;
        }else{
            front--;
        }
        arr[front]=value;
        return true;
    }

    bool insertLast(int value) {
        // add your code here
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            front=rear=0;
        }else if(rear==capacity-1){
            rear=0;
        }else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }

    bool deleteFront() {
        // add your code here
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            front=rear=-1;
        }else if(front==capacity-1){
            front=0;
        }else{
            front++;
        }
        return true;
    }

    bool deleteLast() {
        // add your code here
        if(isEmpty()){
            return false;
        }
        if(front==rear){
            front=rear=-1;
        }else if(rear==0){
            rear=capacity-1;
        }else{
            rear--;
        }
        return true;
    }

    int getFront() {
        // add your code here
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        // add your code here
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        // add your code here
        return front==-1;
    }

    bool isFull() {
        // add your code here
         return ((front==0 && rear==capacity-1) || (rear==(front-1+capacity)%capacity));
    }
};

