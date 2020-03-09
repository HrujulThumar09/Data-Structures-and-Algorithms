#include<iostream>
using namespace std;
struct Bst{
    int data;
    Bst* right;
    Bst* left;
};
Bst* GetNewNode(int data)
{
    Bst* temp=new Bst();
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
}
Bst* Insert(Bst* root,int data)
{
    Bst* newnode=GetNewNode(data);
    if(root==NULL)root=newnode;
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
}
void preorder(Bst* root)
{
    if(root==NULL)return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void inorder(Bst* root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void postorder(Bst* root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
int main()
{
    Bst* root=NULL;
    root=Insert(root,1);
    root=Insert(root,2);
    root=Insert(root,3);
    root=Insert(root,4);
    root=Insert(root,5);
    root=Insert(root,6);
    root=Insert(root,7);
    root=Insert(root,8);
    cout<<"Preorder Traversal\n";
    preorder(root);
    cout<<"\nInorder Traversal\n";
    inorder(root);
    cout<<"\nPostorder Traversal\n";
    postorder(root);
}
