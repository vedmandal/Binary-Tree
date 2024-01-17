#include<iostream>
#include<vector>
#include<stack>
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
typedef pair<node*,int>vpairs;
void iterative_traversals(node*root){
    string pre,in,post;
    stack<vpairs>s;
    s.push(vpairs(root,1));
    while(s.size()>0){
        vpairs temp=s.top();
        if(temp.second==1){
            pre+=to_string(temp.first->val)+" ";
             temp.second++;
            s.pop();
            s.push(temp);
           
            if(temp.first->left!=NULL){
                s.push(vpairs(temp.first->left,1));
            }

        }else if(temp.second==2){
            in+=to_string(temp.first->val)+" ";
            s.pop();
            temp.second++;
            s.push(temp);
            if(temp.first->right!=NULL){
                  s.push(vpairs(temp.first->right,1));

            }


        }else{
            post+=to_string(temp.first->val)+" ";
            s.pop();

        }

    }
    cout<<pre<<endl;
    cout<<in<<endl;
    cout<<post<<endl;


    
}
int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
      iterative_traversals(root);
   

}