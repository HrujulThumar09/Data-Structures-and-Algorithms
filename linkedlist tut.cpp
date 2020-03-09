#include<iostream>
using namespace std;
struct node{
        int data;
        struct node *next;
};
struct node* head;
struct node* newnode(int t)
{
    struct node* a=new node();
    a->data=t;
    a->next=NULL;
    return a;
}
void InsertatEnd(int t)
{
    struct node* a=newnode(t);
    if(head==NULL)
    {
        head=a;
    }
    else
    {
        struct node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=a;
    }

}
void InsertatStart(int t)
{
    struct node* a=newnode(t);
    a->next=head;
    head=a;
}
void InsertAtPos(int j,int k)
{
    node* temp1=newnode(k);
    if(j==1)
    {
        temp1->next=head;
        head=temp1;
        return;
    }
    node* temp2=head;
    for(int i=1;i<j-1;i++)
    {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
void Print()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}
int main()
{
    int n,t,j,k;
    head=NULL;//empty
    cout<<"HOW many Numbers";
    cin>>n;
    cout<<"For inserting at End of list";
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Number";
        cin>>t;
        InsertatEnd(t);
        Print();
    }
    cout<<"For inserting at Start of list";
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Number";
        cin>>t;
        InsertatStart(t);
        Print();
    }
    cout<<"Enter number for  inserting at that position";
    cin>>j;
    cout<<"Enter number";
    cin>>k;
    InsertAtPos(j,k);
    Print();
    return 0;
}
