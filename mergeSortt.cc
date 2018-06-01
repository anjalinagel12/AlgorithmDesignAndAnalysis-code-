#include<iostream>
#include<cstdlib>
using namespace std;
void mergesort(int *, int);
void merge(int *, int * , int * , int ,int );
int cmp=0;


int main()
{
   int a[20], n,i;
   cout<<"\n Enter no. of elements(n) to be sorted ";
   cin>>n;
   cout<<"\n Enter elements :";
   for(i=0;i<n;i++)
   cin>>a[i];
   mergesort(a,n);
   cout<<"\n Elements in sorted manner are :";
   for(i=0;i<n;i++)
   cout<<"\n"<<a[i];
   cout<<"\n \n The no. of comparisions taken are "<<cmp<<endl<<endl<<endl<<endl;
   return 0;
}


void mergesort(int *a, int n)
{
   int b[20],c[20],i=0,j,k;
   if(n>1)
   {

       for(i=0;i<(n/2);i++)
       b[i]=a[i];

       k=i;

       for(j=(n/2),i=0;j<n;j++,i++)
       c[i]=a[j];

       mergesort(b,k);
       mergesort(c,i);
       merge(b,c,a,k,i);
   }
}

void merge(int *b,int *c, int *a, int p, int q)
{
    int i,j,k;
    i=j=k=0;
    while(i<p && j<q)
    {
        cmp++;
        if(b[i]<c[j])
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
    }
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
