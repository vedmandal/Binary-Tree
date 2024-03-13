#include<iostream>
#include<vector>
#include<queue>
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
  vector<int> find_largestValueinEachTreeRow(node* root) {
        if(root==NULL){
            return {};
        }
        queue<node*>q;
        q.push(root);
        vector<int>ans;
        while(q.size()>0){
            int s=q.size();
            int res=INT_MIN;
            while(s-->0){
                node*temp=q.front();
                q.pop();
                res=max(res,temp->val);
                
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            ans.push_back(res);
        }
        return ans;
        
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
     vector<int>res=find_largestValueinEachTreeRow(root);
     for(int val:res){
        cout<<val<<endl;
     }

}