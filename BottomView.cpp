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

void widths(node*root,int hl,vector<int>&ans){
     if (root == NULL)
            return;

        ans[0] = min(hl, ans[0]);
        ans[1] = max(hl, ans[1]);

       widths(root->left, hl - 1, ans);
        widths(root->right, hl + 1, ans);

}

typedef pair<node*,int >vpair;


vector<int> BottomView(node* root) {
         queue<vpair>que;
    vector<int>minmax(2,0);
        widths(root, 0, minmax);
        int length = minmax[1] - minmax[0] + 1;
         vector<int>ans;
    for (int i = 0; i < length; i++)
     ans.push_back((0));
     que.push({root,-minmax[0]});
       
      while (que.size() != 0) {
            long size = que.size();
            while (size-- > 0) {
                vpair  rp = que.front();
                que.pop();
            
                ans[rp.second]=rp.first->val;

                if(rp.first->left!= nullptr)
                    que.push({rp.first->left, rp.second - 1});

                if (rp.first->right != nullptr)
                    que.push({rp.first->right, rp.second + 1});
            }
        }

        return ans;
    }



int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
      vector<int>ans=BottomView(root);
      for(int val:ans){
        cout<<val<< " ";
      }
     

}