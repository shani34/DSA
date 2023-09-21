#include<iostream>

using namespace std;

struct Treenode{
    int data;
    Treenode *left ;
    Treenode *right ;

     Treenode(int data)
    {
        data = data;
        left = NULL;
        right = NULL;
    }
};


//cases if left is null then print
// if take the rightmost guy on left subtree and create thread with parent.

vector<int>MorrisInorder(Treenode *root){
  vector<int>inorder;
  Treenode *cur=root;

  while(cur!=NULL){
      //case 1
      if(cur->left==NULL){
            inorder.push_back(cur->data);
            cur=cur->right;
      }//case 2
      else{
        Treenode *prev=cur->left;
        while(prev->right && prev->right!=cur){
            prev=prev->right;
        }
        if(prev->right==NULL){
            //make thread to parent node
            prev->right=cur;
            //move cur node to left pointer
            cur=cur->left;
        }
        else{
            //set NULL pointer in second visit
            prev->right=NULL;
            //move to right cur pointer since it has been visited to right
            inorder.push_back(cur->data);
            cur=cur->right;
        }
      }

  }
  return inorder;
}

vector<int>MorrisPreorder(Treenode *root){
  vector<int>preorder;
  Treenode *cur=root;

  while(cur!=NULL){
      //case 1
      if(cur->left==NULL){
            preorder.push_back(cur->data);
            cur=cur->right;
      }//case 2
      else{
        Treenode *prev=cur->left;
        while(prev->right && prev->right!=cur){
            prev=prev->right;
        }
        if(prev->right==NULL){
            //make thread to parent node
            prev->right=cur;
            cout<<cur->data<<endl;
            preorder.push_back(cur->data);
            //move cur node to left pointer
            cur=cur->left;
        }
        else{
            //set NULL pointer in second visit
            prev->right=NULL;
            //move to right cur pointer since it has been visited to right
            
            cur=cur->right;
        }
      }

  }
  return preorder;
}
int main(){
    Treenode* root = new Treenode(10);
    root->left = new Treenode(20);
    root->right = new Treenode(30);
    root->right->left = new Treenode(40);
    root->right->right = new Treenode(50);
   
    cout << "Morris(postorder) Traversal: ";
    vector<int> ans;
    ans= MorrisPreorder(root);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
   
    return 0;
}