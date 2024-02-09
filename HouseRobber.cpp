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
vector<int>HouseRobber(node*root){
    if(root==NULL){
        return {0,0};
    }
    vector<int>left=HouseRobber(root->left);
    vector<int>right=HouseRobber(root->right);
    vector<int>ans{0,0};
    ans[0]=max(left[0],left[1])+max(right[0],right[1]);
    ans[1]=left[0]+root->val+right[0];
    return ans;
}

    int robber(node* root) {
        vector<int>ans=HouseRobber(root);
        return max(ans[0],ans[1]);
        
    }
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
     cout<<robber(root);

}