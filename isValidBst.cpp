#include<iostream>
#include<vector>
#include<string>
#include <sstream>

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
 long prevBSTVal = -1e14;
bool isValidBST(node *root)
{
    if (root == nullptr)
        return true;

    if (!isValidBST(root->left))
        return false;

    if (prevBSTVal >= root->val)
        return false;

    prevBSTVal = root->val;
    if (!isValidBST(root->right))
        return false;

    return true;
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