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

node*get_right_most_node(node*leftnode,node*curr){
    while(leftnode->right!=NULL and leftnode->right!=curr){
        leftnode=leftnode->right;

    }
    return leftnode;

}

vector<int>morris_inorder_traversal(node*root){
    vector<int>ans;
    node*curr=root;
    while(curr!=NULL){
        node*leftnode=curr->left;
        if(leftnode==NULL){
            ans.push_back(curr->val);
            curr=curr->right;
        }else{
            node*rightmostnode=get_right_most_node(leftnode,curr);
            if(rightmostnode->right==NULL){
                rightmostnode->right=curr;
                curr=curr->left;
            }else{
                rightmostnode->right=NULL;
                ans.push_back(curr->val);
                curr=curr->right;
            }


        }
    }
    return ans;
}
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
     vector<int>ans=morris_inorder_traversal(root);
      for(int val:ans){
         cout<<val<<" ";
     }

}