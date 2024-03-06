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


    
node *cbuildTree(vector<int> &postorder, int psi, int pei, vector<int> &inorder, int isi, int iei) 
{
    if (psi > pei)
        return nullptr;

    node *nod = new node(postorder[pei]);

    int idx = isi;
    while (inorder[idx] != postorder[pei])
        idx++;

    int tel = idx - isi;

    nod->left = cbuildTree(postorder, psi, psi + tel - 1, inorder, isi, idx - 1);
    nod->right = cbuildTree(postorder, psi + tel, pei - 1, inorder, idx + 1, iei);

    return nod;
}

node *createbuildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    return cbuildTree(postorder, 0, n - 1, inorder, 0, n - 1);
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
      node*root=construct_tree(arr);
      display(root);

}