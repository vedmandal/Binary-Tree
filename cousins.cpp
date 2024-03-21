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

void dfsHelper(node* root, int x, int y, int level, node* parent, int& xLevel, int& yLevel, int& xParent, int& yParent) {
        if (!root) return;

        if (root->val == x) {
            xLevel = level;
            xParent = parent ? parent->val : -1;
        } else if (root->val == y) {
            yLevel = level;
            yParent = parent ? parent->val : -1;
        }

       
        if (xLevel != -1 && yLevel != -1 && xLevel == yLevel && xParent != yParent) {
            return;
        }

        dfsHelper(root->left, x, y, level + 1, root, xLevel, yLevel, xParent, yParent);
        dfsHelper(root->right, x, y, level + 1, root, xLevel, yLevel, xParent, yParent);
    }
    bool isCousins(node* root, int x, int y) {
         if (!root) return false; 

        int xLevel = -1, yLevel = -1, xParent = -1, yParent = -1;

        dfsHelper(root, x, y, 0, nullptr, xLevel, yLevel, xParent, yParent);

        return xLevel == yLevel && xParent != yParent;
        
    }
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
    

}