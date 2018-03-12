#include<stdio.h>
struct interval
{
    int left;
    int right;
    int present;
};
void mergesort(struct interval a[],int low,int high);
void merge(struct interval a[],int low,int mid,int high);
main()
{
    printf("enter the total intervals:\n");
    int n;
    scanf("%d",&n);
    struct interval a[n];
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the %d interval:",i+1);
        scanf("%d %d",&a[i].left,&a[i].right);
        a[i].present=1;
    }

    mergesort(a,0,n-1);
    int j=0;
    int next=a[0].right;
    for(i=1;i<n;i++)
    {
        if(a[i].left>next)
        {
            next=a[i].right;
        }
        else
        {
            a[i].present=0;
        }
    }
    printf("the intervals are:\n");
    for(i=0;i<n;i++)
    {
        if(a[i].present==1)
        printf("[%d %d] \t",a[i].left,a[i].right);
    }

    
}
void mergesort(struct interval a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);


    }
}
void merge(struct interval a[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    struct interval a1[n1],a2[n2];
    int i,j,k;
    for(i=0;i<n1;i++)
    {
        a1[i].right=a[low+i].right;
        a1[i].left=a[low+i].left;
    
    }


    for(j=0;j<n2;j++)
    {
        a2[j].right=a[mid+1+j].right;
        a2[j].left=a[mid+1+j].left;
    
    }
    i=0;j=0;
    k=low;
    while(i<n1 && j<n2)
    {
        if(a1[i].right<=a2[j].right)
        {
            a[k].right=a1[i].right;
            a[k].left=a1[i].left;
            i++;
        }
        else
        {
            a[k].right=a2[j].right;
            a[k].left=a2[j].left;
            j++;
        }
        k++;

    }
    while(i<n1)
    {
        a[k].right=a1[i].right;
        a[k].left=a1[i].left;
        i++;
        k++;
    }
     while(j<n2)
    {
        a[k].right=a2[j].right;
        a[k].left=a2[j].left;
        j++;
        k++;
    }
}
