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

node*construct_tree(vector<int>arr,vector<int>&IDX){
    if(IDX[0]>arr.size() || arr[IDX[0]]==-1){
        IDX[0]++;
        return NULL;
    }

    node*root=new node(arr[IDX[0]++]);
    root->left=construct_tree(arr,IDX);
    root->right=construct_tree(arr,IDX);
    return root;
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
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      vector<int>IDX={0};
      node*root=construct_tree(arr,IDX);
      display(root);

}