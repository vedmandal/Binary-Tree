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

 struct comp {
       public:
           bool operator()(const qpair &a, const qpair &b) const{
               
                   return a.nod->val > b.nod->val;
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


       vector<vector<int>> verticalTraversal(node* root) {
        vector<int>ans(2,0);
        width(root,0,ans);
        int len=ans[1]-ans[0]+1;
        vector<vector<int>>res(len);
       priority_queue<qpair,vector<qpair>,comp>q;
        priority_queue<qpair,vector<qpair>,comp>cq;
       

        q.push(qpair(root,abs(ans[0])));
        while(q.size()>0){
            int s=q.size();
            while(s-->0){
                qpair temp=q.top();
                q.pop();
                res[temp.l].push_back(temp.nod->val);
                if(temp.nod->left!=NULL){
                    cq.push(qpair(temp.nod->left,temp.l-1));
                }
                if(temp.nod->right!=NULL){
                    cq.push(qpair(temp.nod->right,temp.l+1));
                }

                
            }
             priority_queue<qpair,vector<qpair>,comp>temp=q;
             q=cq;
             cq=temp;

        }
        return res;

        
    }



int main(){
 vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};

  node*root=construct_tree(arr);
  vector<vector<int>>ans=verticalTraversal(root);
  for(vector<int>res:ans){
    for(int val:res){
        cout<<val<<" ";
    }
    cout<<endl;
  }
}