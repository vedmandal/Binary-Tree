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

void width(node*root,int hl,vector<int>&ans){
    if(root==nullptr){
        return ;
    }
    ans[0]=min(hl,ans[0]);
    ans[1]=max(hl,ans[1]);
    width(root->left,hl-1,ans);
    width(root->right, hl+1, ans);
    
}
int width_(node*root){
    vector<int>ans(2,0);
    width(root, 0,ans);
    return ans[1]-ans[0]+1;
}
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
    cout<<width_(root);

}