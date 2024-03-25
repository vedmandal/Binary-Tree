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



   node* build(const vector<int>& nums, int i, int j) {
    if (i > j)
      return nullptr;

    const auto it = max_element(nums.begin() + i, nums.begin() + j + 1);
    const int maxNum = *it;
    const int maxIndex = it - nums.begin();

    node* root = new node(maxNum);
    root->left = build(nums, i, maxIndex - 1);
    root->right = build(nums, maxIndex + 1, j);
    return root;
  }
    node* constructMaximumBinaryTree(vector<int>& nums) {

         return build(nums, 0, nums.size() - 1);
        
    }
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
    

}