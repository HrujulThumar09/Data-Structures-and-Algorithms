#include<stdio.h>
int binarySearch(int a[],int l,int r,int key)
{
    if(r>=l)
    {
        int mid=(r+l)/2;
        if(a[mid]==key) return mid;

        if(a[mid]<key)return binarySearch(a,mid+1,r,key);

        return binarySearch(a,0,mid-1,key);
    }
    return -1;
}
int main()
{
    printf("Enter Number of Elements: ");
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter %d element: ",i+1);
        scanf("%d",&a[i]);
    }
    int key,c,result;
    do
    {
        printf("Enter Element to be searched: ");
        scanf("%d",&key);
        result=binarySearch(a,0,n-1,key);
        if(result==-1)printf("Element not found\n");
        else printf("The element is at index %d\n",result);

        printf("Do you want to search another element?\nEnter 0 to search another element\n1 to exit\n");
        scanf("%d",&c);
    }while(c!=1);
}
