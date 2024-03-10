#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int val;
    node*left;
    node*right;
    node(int val){
        this->val=val;
    }
};

int idx=0;
node*construct_tree(vector<int>arr){
    if(arr.size()==0 || arr[idx]==-1){
        idx++;
        return NULL;
    }
    node*root=new node(arr[idx++]);
    root->left=construct_tree(arr);
    root->right=construct_tree(arr);
    return root;


}
 

int bst_idx = 0;
node *constructBSTFromPostOrder(vector<int> &arr, int lr, int rr)
{
    if (bst_idx == -1 || arr[bst_idx] < lr || arr[bst_idx] > rr)
        return nullptr;

    node *nod = new node(arr[bst_idx--]);
    nod->right = constructBSTFromPostOrder(arr, nod->val, rr);
    nod->left = constructBSTFromPostOrder(arr, lr, nod->val);

    return nod;
}

node *bstFromPostorder(vector<int> &preorder)
{
    return constructBSTFromPostOrder(preorder, -1e8, 1e8);
}

void display(node*root){
    if(root==NULL){
        return;
    }
    string str=root->left!=NULL?to_string(root->left->val):".";
    str+= "<-"+to_string(root->val)+"->";
    str+=root->right!=NULL?to_string(root->right->val):".";
    cout<<str<<endl;
    display(root->left);
    display(root->right);
}
int main(){
    
     

}