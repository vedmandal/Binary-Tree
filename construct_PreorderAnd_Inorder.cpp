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
node *buildTree(vector<int> &preorder, int psi, int pei, vector<int> &inorder, int isi, int iei) // si=starting index, ei = end index.
     {
         if (psi > pei)
             return nullptr;

         node *nod = new node(preorder[psi]);

         int idx = isi;
         while (inorder[idx] != preorder[psi])
             idx++;

         int tel = idx - isi;

         nod->left = buildTree(preorder, psi + 1, psi + tel, inorder, isi, idx - 1);
         nod->right = buildTree(preorder, psi + tel + 1, pei, inorder, idx + 1, iei);

         return nod;
     }

     node *buildTree(vector<int> &preorder, vector<int> &inorder)
     {
         int n = preorder.size();
         return buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
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