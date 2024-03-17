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

 int findSecondMinimumValue(node* root, int mini) {
    if (root == nullptr)
      return -1;
    if (root->val > mini)
      return root->val;

    const int leftMin = findSecondMinimumValue(root->left, mini);
    const int rightMin = findSecondMinimumValue(root->right, mini);

    if (leftMin == -1 || rightMin == -1)
      return max(leftMin, rightMin);
    return min(leftMin, rightMin);
  }
   
    int findSecondMinimumValue(node* root) {
         if (root == nullptr)
      return -1;
    return findSecondMinimumValue(root, root->val);
        
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
     cout<<findSecondMinimumValue(root);

}