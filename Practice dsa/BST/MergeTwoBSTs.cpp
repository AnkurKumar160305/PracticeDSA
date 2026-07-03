/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

vector<int> mergeArrays(vector<int> a,vector<int> b){
    vector<int> ans(a.size()+b.size());
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            ans[k++]=a[i++];
        }else{
            ans[k++]=b[j++];
        }
    }
    while(i<a.size()){
        ans[k++]=a[i++];
    }
    while(j<b.size()){
        ans[k++]=b[j++];
    }

    return ans;
}

void inorder(TreeNode *root,vector<int>& in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

// TreeNode* inordertoBst(int s,int e,vector<int>& ans){
//     if(s>e){
//         return NULL;
//     }
//     int mid=s+(e-s)/2;
//     TreeNode* root=new TreeNode(ans[mid]);
//     root->left=inordertoBst(s,mid-1,ans);
//     root->right=inordertoBst(mid+1,e,ans);
//     return root;
// }


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    vector<int> mergedArray=mergeArrays(bst1,bst2);
    return mergedArray;
    // int s=0,e=mergedArray.size()-1;
    // return inordertoBst(s,e,mergedArray);
}




//Most optimal 
/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/



void convertIntoSortedDLL(TreeNode* root,TreeNode* &head){
    if(root==NULL){
        return;
    }

    convertIntoSortedDLL(root->right,head);

    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;

    convertIntoSortedDLL(root->left,head);
}

TreeNode* mergeLinkedList(TreeNode* head1,TreeNode* head2){
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    TreeNode* head=NULL;
    TreeNode* tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;

            }else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;

            }
        }

    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }

    return head;
}

int countNodes(TreeNode* head){
    int count=0;
    TreeNode* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->right;
    }
    return count;
}
TreeNode* sortedLLtoBST(TreeNode* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    TreeNode* left=sortedLLtoBST(head,n/2);
    TreeNode* root=head;
    root->left=left;
    head=head->right;

    root->right=sortedLLtoBST(head,n-n/2-1);
    return root;
}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.

    //1- convert BST into Sorted LL
    TreeNode* head1=NULL;
    convertIntoSortedDLL(root1,head1);
    if (head1) head1->left = NULL;

    TreeNode* head2=NULL;
    convertIntoSortedDLL(root2,head2);
    if (head2) head2->left = NULL;

    //2- Merge Two Sorted LL
    TreeNode* head=mergeLinkedList(head1,head2);

    //3-Convert Sorted Merge LL into BST
    int n=countNodes(head);
    return sortedLLtoBST(head,n);
}