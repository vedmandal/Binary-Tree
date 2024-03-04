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

void pathSum_(node* root, int tar,vector<vector<int>>res,vector<int> smallAns) {
   if (root == NULL)
     return;

   if (root->left == NULL && root->right == NULL) {
     if (tar - root->val == 0) {
         vector<int> base(smallAns) ;
       base.push_back(root->val);
       res.push_back(base);
     }

     return;
   }

   smallAns.push_back(root->val);
   pathSum_(root->left, tar - root->val, res, smallAns);
   pathSum_(root->right, tar - root->val, res, smallAns);
   smallAns.pop_back();
 }

  vector<vector<int>> pathSum(node* root, int targetSum) {
      vector<vector<int>> res ;
      vector<int>smallans;
   pathSum_(root, targetSum, res,smallans);
   return res;

 }

int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
    vector<vector<int>>ans=pathSum(root,120);
    for(vector<int>res:ans){
        for(int val:res){
            cout<<val<<" ";
        }
        cout<<endl;
    }

}