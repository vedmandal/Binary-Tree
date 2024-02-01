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

vector<int>path;

  bool find_and_root_to_node_path(node*root,int target){
    if(root==NULL){
        return false;
    }
    if(root->val==target){
        path.push_back(root->val);
        return true;
    }

    bool lans=find_and_root_to_node_path(root->left,target);
    if(lans){
        path.push_back(root->val);
        return true;
    }
    bool rans=find_and_root_to_node_path(root->right,target);
    if(rans){
         path.push_back(root->val);
        return true;

    }
    return false;


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
     cout<<find_and_root_to_node_path(root,60)<<endl;
     for(int val:path){
        cout<<val<<" ";
     }

}