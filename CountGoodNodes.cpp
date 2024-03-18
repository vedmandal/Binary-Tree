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

int countgoodnodes(node*root,int maxi){
    if(root==NULL){
        return 0;
    }
    int ans=0;
    
    if(maxi<=root->val){
        ans=1;
    }
    maxi=max(maxi,root->val);
    int left=countgoodnodes(root->left,maxi);
    int right=countgoodnodes(root->right,maxi);
    ans+=left+right;
    return ans;

}
    int goodNodes(node* root) {
        return countgoodnodes(root,INT_MIN);
   }
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
     cout<<goodNodes(root);

}