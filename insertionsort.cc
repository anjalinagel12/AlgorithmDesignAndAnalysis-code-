  #include<iostream>
#include<stdio.h>
using namespace std;
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

    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=a[i];
        while(temp<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
    cout<<"\nArray after insertion sorting:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"\t";
    cout<<endl;

}
