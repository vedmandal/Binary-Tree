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



int ans = 0;
pair<int, int> dfs(node *root)
{
    if (root == nullptr)
        return {-1, -1};

    pair<int, int> left = dfs(root->left);
    pair<int, int> right = dfs(root->right);

    ans = max(ans, max(left.second, right.first) + 1);
    return {left.second + 1, right.first + 1};
}
 int longestZigZag(node* root) {
        dfs(root);
    return ans;
        
    }

int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
     cout<<longestZigZag(root);

}