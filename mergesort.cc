#include<iostream>
#include<stdio.h>
using namespace std;
int comp=0;
void Merge(int *b,int *b,int *a,int p,int q)
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        comp++;
        if(b[i]<=c[j])
        {
            a[k]=b[i];
            i=i+1;
        }
        else
        {
            a[k]=c[j];
            j=j+1;
        }
        k=k+1;

        if(i==p)
        {
            while(j<q)
            {
                a[k++]=c[j];
                j++;
            }
        }
        else
        {
            while(i<p)
            {
                a[k++]=b[i];
                i++;
            }
        }
    }
}




void mergesort(int a[],int n)
{
    int b[n],c[n],i,j,p,q;
    if(n>1)
    {
        for(i=0;i<n/2;i++)
        {
            b[i]=a[i];
            p=i+1;
        }
        for(i=n/2,j=0;j<n;j++,i++)
        {
            c[j]=a[i];
            q=j+1;
        }
        mergesort(b,p);
        mergesort(c,q);
        Merge(b,c,a,p,q);

    }
}


int main()
{
    int n,i,j,temp;
    cout<<"Enter number of items in array:";
    cin>>n;
    int a[n];
    cout<<"Enter items of the array: ";
    for(i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,n);
    cout<<"\nArray after sorting:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}
