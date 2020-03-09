#include<iostream>

using namespace std;
struct Bstnode{
    int data;
    Bstnode* left;
    Bstnode* right;
};
Bstnode* Getnewnode(int data){
    Bstnode* newnode=new Bstnode();
    newnode->data=data;
    newnode->right=newnode->left=NULL;
    return newnode;
}
Bstnode* Insert(Bstnode* root,int data)
{
    if(root==NULL)
    {
        root=Getnewnode(data);
    }
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

int FindMin(Bstnode* root)
{
    if(root==NULL)
    {
        cout<<"Error:Tree in empty";
        return -1;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

int FindMax(Bstnode* root)
{
    if(root==NULL)
    {
        cout<<"Error:Tree in empty";
        return -1;
    }
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
int main()
{
    Bstnode* root=NULL;
    root=Insert(root,5);
    root=Insert(root,18);
    root=Insert(root,10);
    root=Insert(root,5);
    root=Insert(root,7);
    root=Insert(root,12);
    root=Insert(root,15);
    root=Insert(root,90);
    root=Insert(root,49);

    cout<<FindMin(root);
    cout<<FindMax(root);
}
