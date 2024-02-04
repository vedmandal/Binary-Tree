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


void print_node_with_single_child(node*root){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL and root->right==NULL || root->left==NULL and root->right!=NULL){
        cout<<root->val <<" ";
    }
    print_node_with_single_child(root->left);
    print_node_with_single_child(root->right);
}
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
      print_node_with_single_child(root);
     

}