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
int height(node*root){
      if(root==NULL){
          return 0;
      }
      return max(height(root->left) , height(root->right))+1;
  }
  vector<int>arr;
  bool check(node*root,int level){
      if(root==NULL){
          return true;
      }
      if(level%2==0){
          if(root->val%2==0) return false;
          if(arr[level]>=root->val) return false;
          arr[level]=root->val;


      }else{
          if(root->val%2==1) return false;
          if(arr[level]<=root->val) return false;
          arr[level]=root->val;

      }
      return check(root->left,level+1) && check(root->right,level+1);
  }
   
    bool isEvenOddTree(node* root) {
        int depth=height(root);
         arr.reserve(depth);
        for(int i=0;i<depth;i++){
            if(i%2==0){
                arr[i]=INT_MIN;
            }else{
                arr[i]=INT_MAX;
            }
        }
        return check(root,0);
        
    }
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
      display(root);

}