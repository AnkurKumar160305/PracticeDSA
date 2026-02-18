ListNode* reverseBetween(ListNode* head,int left,int right){
    if(left>=right){
        return head;
    }
    ListNode dummy(0);
    dummy.next=head;
    ListNode* prev=&dummy;
    for(int i=1;i<left;i++){
        prev=prev->next;
    }
    ListNode* curr=prev->next;
    for(int i=0;i<right-left;i++){
        ListNode* temp=curr->next;
        curr->next=temp->next;
        temp->next=prev->next;
        prev->next=temp;
    }
    return dummy.next;

}

ListNode* swapAndReverse(ListNode* head, int k) {
    // add your code here
    if(!head){
        return head;
    }
    int n=0;
    ListNode* temp=head;
    while(temp){
        n++;
        temp=temp->next;
    }
    if(k>n){
        return head; 
    }
    int pos1=k;
    int pos2=n-k+1;
    if(pos1>pos2){
        swap(pos1,pos2);
    }

    ListNode* node1=head;
    for(int i=1;i<pos1;i++){
        node1=node1->next;
    }
    ListNode* node2=head;
    for(int i=1;i<pos2;i++){
        node2=node2->next;
    }
    swap(node1->val,node2->val);

    if(pos2-pos1>1){
        head=reverseBetween(head,pos1+1,pos2-1);
    }
    return head;
    
}