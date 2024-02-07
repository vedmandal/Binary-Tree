



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




int camera = 0;
int MinCamerasInBT_(node *root)
{
    if (root == NULL)
        return 1;

    if (root->left == NULL && root->right == NULL)
        return -1;

    int lans = MinCamerasInBT_(root->left);
    int rans = MinCamerasInBT_(root->right);

    if (lans == -1 || rans == -1)
    {
        camera++;
        return 0;
    }
    else if (lans == 0 || rans == 0)
        return 1;

    return -1;
}

    int minCameraCover(node* root) {

        if (root == NULL)
        return 0;

    if (MinCamerasInBT_(root) == -1)
        camera++;

    return camera;
        
    }

int main(){
      vector<int>arr={50,40,30,-1,-1,45,-1,-1,60,62,-1,-1,75,-1,-1};
      node*root=construct_tree(arr);
    cout<<minCameraCover(root);

}