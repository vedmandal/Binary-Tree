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
void width(node*root,int h,vector<int>&ans){

    if(root==NULL){
        return ;
    }
    ans[0]=min(ans[0],h);
    ans[1]=max(ans[1],h);
    width(root->left,h-1,ans);
    width(root->right,h+1,ans);
}
 class qpair{
         public:
         node* nod;
         int l;
         qpair(node*nod,int l){
             this->nod=nod;
             this->l=l;
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


       vector<int> verticalOrderSum(node* root) {
        vector<int>ans(2,0);
        width(root,0,ans);
        int len=ans[1]-ans[0]+1;
        vector<int>res(len);
      queue<qpair>q;
     
       

        q.push(qpair(root,abs(ans[0])));
        while(q.size()>0){
            int s=q.size();
            while(s-->0){
                qpair temp=q.front();
                q.pop();
                res[temp.l]=res[temp.l]+temp.nod->val;
                if(temp.nod->left!=NULL){
                    q.push(qpair(temp.nod->left,temp.l-1));
                }
                if(temp.nod->right!=NULL){
                    q.push(qpair(temp.nod->right,temp.l+1));
                }

                
            }
            

        }
        return res;

        
    }



int main(){
 vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};

  node*root=construct_tree(arr);
  vector<int>ans=verticalOrderSum(root);
  
    for(int val:ans){
        cout<<val<<" ";
    }
    
  }
