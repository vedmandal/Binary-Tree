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
  
node *bbuildTree(vector<int> &inOrder, int si, int ei)
       {
           if (si > ei)
               return nullptr;

           int mid = (si + ei) / 2;
           node *nod = new node(inOrder[mid]);

           nod->left = bbuildTree(inOrder, si, mid - 1);
           nod->right = bbuildTree(inOrder, mid + 1, ei);

           return nod;
       }

       node *constructFromInOrder(vector<int> &in)
       {
           int n = in.size();
           return bbuildTree(in, 0, n - 1);
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