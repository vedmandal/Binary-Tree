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


node *tbuildTree(vector<int> &preorder, int psi, int pei, vector<int> &postorder, int ppsi, int ppei) // si=starting index, ei = end index.
   {
       if (psi > pei)
           return nullptr;

       if (psi == pei)
           return new node(preorder[psi]);

       node *nod = new node(preorder[psi]);
       int idx = ppsi;
       while (postorder[idx] != preorder[psi + 1])
           idx++;

       int tel = idx - ppsi + 1;

       nod->left = tbuildTree(preorder, psi + 1, psi + tel, postorder, ppsi, idx);
       nod->right = tbuildTree(preorder, psi + tel + 1, pei, postorder, idx + 1, ppei - 1);

       return nod;
   }

   node *constructFromPrePost(vector<int> &pre, vector<int> &post)
   {
       int n = pre.size();
       return tbuildTree(pre, 0, n - 1, post, 0, n - 1);
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