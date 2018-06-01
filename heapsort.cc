#include<iostream>
#include<stdio.h>
using namespace std;
void heapify(int a[],int n,int i)
{
    int largest,l,r;
    largest=i;
    l=2*i+1;
    r=2*i+2;
    if(l<n&&a[l]>a[largest])
        largest=l;
    if(r<n&&a[r]>a[largest])
        largest=r;
    if(i!=largest)
    {
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}
void heapsort(int a[],int n)
{
    int i,j;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        swap(a[i],a[0]);
        heapify(a,i,0);
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
    heapsort(a,n);
    cout<<"\nArray after sorting(heapsort) :\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}
