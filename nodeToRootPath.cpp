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

bool nodetopath(node*root,int data,vector<int>&ans){
    if(root==NULL){
        return false;
    }
    if(root->val==data){
        ans.push_back(root->val);
        return true;
    }
    bool res=nodetopath(root->left, data, ans) or nodetopath(root->right, data, ans);
    if(res) ans.push_back(root->val);
    return res;
    
}
vector<int>nodetopathusingheapmover__(node*root,int data){
    vector<int>ans;
    nodetopath(root, data, ans);
    return ans;
}

int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
     vector<int>ans=nodetopathusingheapmover__(root,60);
     for(int val:ans){
        cout<<val<<" ";
     }
}