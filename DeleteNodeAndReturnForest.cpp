#include<iostream>
#include<vector>
#include<unordered_set>
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

node*helper(node*root,unordered_set<int>&set,vector<node*>&ans){
       if(root==NULL) return NULL;
       root->left=helper(root->left,set,ans);
       root->right=helper(root->right,set,ans);
       if(set.find(root->val)!=set.end()){
           if(root->left!=NULL){
               ans.push_back(root->left);
           }
           if(root->right!=NULL){
               ans.push_back(root->right);
           }
           return NULL;
       }
       return root;

   }
    vector<node*> delNodes(node* root, vector<int>& to_delete) {
        unordered_set<int>set;
        for(auto ele:to_delete){
            set.insert(ele);
        }
        vector<node*>ans;
        helper(root,set,ans);
        if(set.find(root->val)==set.end()){
            ans.push_back(root);

        }
        return ans;
        
    }
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
      display(root);

}