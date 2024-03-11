#include<iostream>
#include<vector>
#include<string>
#include <sstream>

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
 

int indx = 0;
   node *deserialize(vector<int> &arr)
   {
       if (indx >= arr.size() || arr[indx] == -1001)
       {
           indx++;
           return nullptr;
       }

       node *nod = new node(arr[indx++]);
       nod->left = deserialize(arr);
       nod->right = deserialize(arr);

       return nod;
   }

  
   node *deserialize(string s)
   {
       stringstream ss(s);
       string word;
       vector<int> arr;
       while (ss >> word)
       {
           arr.push_back(stoi(word));
       }
       return deserialize(arr);
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
    
     

}