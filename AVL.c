#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;


    x->right = y;
    y->left = T2;


    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;


    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key)
{

    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);


    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        printf("LL Rotation occured at %d\n",node->key);
        return rightRotate(node);
    }


    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        printf("RR Rotation occured at %d\n",node->key);
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        printf("LR Rotation occured at %d\n",node->key);
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        printf("RL Rotation occured at %d\n",node->key);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}


struct Node * minValueNode(struct Node* node)
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int key)
{

    if (root == NULL)
        return root;


    if ( key < root->key )
        root->left = deleteNode(root->left, key);


    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {

        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left :
                                             root->right;


            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;

            free(temp);
        }
        else
        {

            struct Node* temp = minValueNode(root->right);


            root->key = temp->key;


            root->right = deleteNode(root->right, temp->key);
        }
    }


    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        printf("LL Roatation occured at %d\n",root->key);
        return rightRotate(root);
    }
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        printf("LR Roatation occured at %d\n",root->key);
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        printf("RR Roatation occured at %d\n",root->key);
        return leftRotate(root);
    }


    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        printf("RL Roatation occured at %d\n",root->key);
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void inOrder(struct Node* root)
{
    if(root==NULL)return;
    inOrder(root->left);
    printf("%d ",root->key);
    inOrder(root->right);
}
void preOrder(struct Node* root)
{
    if(root==NULL)return;
    printf("%d ",root->key);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct Node* root)
{
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->key);
}
void traverse(struct node* root)
{
    printf("Preorder :\n");
    preOrder(root);
    printf("\nInorder :\n");
    inOrder(root);
    printf("\nPostorder :\n");
    postOrder(root);
}

void main()
{
    int no,op;
    struct Node* root=NULL;
    do
    {
        printf("Enter Operation t be performed:\n0 to insert\n1 to Delete Node\n2 to traverse\n3 to exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 0:
                    printf("Enter Number to be inserted: ");
                    scanf("%d",&no);
                    root=insert(root,no);
                    break;
            case 1:
                    printf("Enter Number to be Deleted: ");
                    scanf("%d",&no);
                    root=deleteNode(root,no);
                    break;
            case 2:traverse(root);break;
        }
    }while(op!=3);
}

