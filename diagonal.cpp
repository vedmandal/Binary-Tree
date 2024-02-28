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


vector<vector<int>> diagonalOrder(node *root)
   {
       queue<node*> que;
       que.push(root);
       vector<vector<int>> ans;
       while (que.size() != 0)
       {
           int size = que.size();
           vector<int> smallAns;
           while (size-- > 0)
           {
               node *nod = que.front();
               que.pop();

               while (nod != nullptr)
               {
                   smallAns.push_back(nod->val);
                   if (nod->left != nullptr)
                   { 
                       que.push(nod->left);
                   }
                   nod = nod->right; 
               }
           }
           ans.push_back(smallAns);
       }

       return ans;
   }

int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
     vector<vector<int>>ans=diagonalOrder(root);
     for(vector<int>res:ans){
        for(int val:res){
            cout<<val<<" ";
        }
        cout<<endl;
     }

}