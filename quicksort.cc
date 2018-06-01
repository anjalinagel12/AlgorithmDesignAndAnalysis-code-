#include<iostream>
#include<stdlib.h>


using namespace std;
int comparision=0;




void Ascending(int A[],int n)
{
    for(int i=0;i<n;i++)
     A[i]=i+1;
}

void Descending(int A[],int n)
{
    int j=0;
    for(int i=n-1;i>=0;i--)
     A[j++]=i+1;
}

void Random(int A[],int n)
{
    for(int i=0;i<n;i++)
        A[i]=random()%n;
}

void Display()
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<"\t";
}



int Partition(int A[],int l,int r)
{
    int p=A[l];
    int i=l;
    int j=r+1;
   do
    {
       do
        {
            i=i++;
            comparision++;
        }
        while(A[i]<p);
        do
        {
            j=j--;
            comparision++;
        }while(A[j]>p);
       swap(A[i],A[j]);
    }
    while(i<j);
       swap(A[i],A[j]);
       swap(A[l],A[j]);

    return j;
}

int QuickSort(int A[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=Partition(A,l,r);
        QuickSort(A,l,s-1);
        QuickSort(A,s+1,r);
    }
}

int main()
 {
    int ch;
    while(1)
    {
        cout<<"\n\n1.Ascending Order\n2.Descending Order\n3.Random\n4.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"Enter the number of elements\n";
                     cin>>n;
                    Ascending(A,n);
                   cout<<"Array elements are:\n";
                   Display();
                   QuickSort(A,0,n-1);
                    cout<<"\nThe Array After Sorting\n";
                   Display();

                   break;

            case 2: cout<<"Enter the number of elements\n";
                    cin>>n;
                    Descending(A,n);
                   cout<<"Array elements are:\n";
                   Display();
                   QuickSort(A,0,n-1);
                    cout<<"\nThe Array After Sorting\n";
                   Display();
                 //  cout<<"\nThe Number of Comparisions are: "<<comparision;
                   break;

            case 3: cout<<"Enter the number of elements\n";
                    cin>>n;
                    Random(A,n);
                   cout<<"Array elements are\n";
                   Display();
                   QuickSort(A,0,n-1);
                   cout<<"\nThe Array After Sorting\n";
                   Display();
                   //cout<<"\nThe Number of Comparisions are: "<<comparision;
                   break;

        case 4:exit(0);
        default:cout<<"Invalid Choice\n";
    }
    cout<<"\nThe Number of Comparisions are: "<<comparision;
    comparision=0;
 }
 return 0;
 }
