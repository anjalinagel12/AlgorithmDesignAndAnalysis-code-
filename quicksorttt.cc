#include<iostream>
#include<stdlib.h>
using namespace std;
int swp=0,comp=0,n;




int partition(int a[],int l,int r)
{
   int p,temp,i,j;
   p=a[l];
   i=l+1;
   j=r;
   while(i<=j)
   {
      while(a[i]<p)
      {

        i++;
        comp++;
      }
      while(a[j]>p)
      {

         j--;
         comp++;
       }
       if(i<j)
       {
          swp++;
          swap(a[i],a[j]);
       }
       else
       {
          swp++;
          swap(a[l],a[j]);
       }
     }
     return j;
 }
  void quicksort(int a[],int l,int r)
  {
    int s;
    if(l<r)
    {
       s=partition (a,l,r);
       quicksort(a,l,s-1);
       quicksort(a,s+1,r);
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
    cout<<"\nArray before sorting:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
    quicksort(a,0,n-1);
    cout<<"\nArray after sorting(quicksort):\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}
