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

bool Search(Bstnode* root,int data)
{
    if(root==NULL) return false;
    else if(root->data==data)return true;
    else if(root->data<=data) return Search(root->right,data);
    else return Search(root->left,data);
}

int main()
{
    Bstnode* root=NULL;
    root=Insert(root,5);
    root=Insert(root,1);
    root=Insert(root,10);
    root=Insert(root,5);

    int number;
    cout<<"Enter no. to be searched\n";
    cin>>number;
    if(Search(root,number))cout<<"Found\n";
    else cout<<"Not Found\n";
    return 0;
}
