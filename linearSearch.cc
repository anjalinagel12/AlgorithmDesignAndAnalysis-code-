#include<iostream>
#include<stdlib.h>

using namespace std;

int linear_search(int array[],int n,int key,int count=0,int comp=0)
{
   comp++;
   if(count>=n)
   {
      return -1;
   }
   if(key==array[count])
   {
      cout<<"key found at position "<<comp<<"\n";
      return count+1;
   }
   linear_search(array,n,key,++count,comp);

}


int binarysearch_des(int array[],int key,int high,int low=0,int comp=0)
{
  int mid=(low+high)/2;
  comp++;

   if(key==array[mid])
   {
      cout<<"the number of comparision made is"<<comp<<"\n";
      return mid+1;
   }

   if(low<=high)
   {
       comp++;
      if(key>array[mid])
      {
          binarysearch_des(array,key,mid-1,0,comp);
      }
      else
      {
         binarysearch_des(array,key,high,mid+1,comp);
      }
   }
   else
   {
      return -1;

   }
}


int binarysearch_ass(int array[],int key,int high,int low=0,int comp=0)
{
   int mid=(low+high)/2;
   comp++;

   if(key==array[mid])
   {
      cout<<"the number of comparision is"<<comp<<"\n";
      return mid+1;

   }

   if(low<=high)
   {
       comp++;
       if(key<array[mid])
       {
           binarysearch_ass(array,key,mid-1,0,comp);
       }
       else
       {
           binarysearch_ass(array,key,high,mid+1,comp);
       }
   }
   else
   {
       return -1;
   }
}


int main()
{
   int key, a,n,i,j,ser_res=-1,temp,c1,c2;
   cout<<"enter the number of n elements\n";
   cin>>n;
   int *array=new int[n];
   int *arr_des=new int[n];
   int *arr_ass=new int[n];


   for(i=0;i<n;i++)
   {
      a=random()%n;
      array[i]=a;
   }
   cout<<"array in random order\n";
  for (i=0;i<n;i++)
  {
     cout<<array[i]<<"\n";
   }
   cout<<"array in ascending order\n";
   for(i=0;i<n;i++)
   {
     arr_ass[i]=i+1;
     cout<<arr_ass[i]<<"\n";
   }
   cout<<"array in descending order\n";
   for(i=n;i>0;i--)
   {
   int j=0;
   arr_des[j]=i;
      cout<<arr_des[j]<<"\n";
   }

   while(1)
   {

     cout<<"1.binary search\n 2.linear search\n 3 exit\n";
     cout<<"enter your choice\n";
     cin>>c1;
     if(c1==1)
     {
       cout<<"enter the key element\n";
       cin>>key;

       cout<<"1.binary ascending\n 2.binary descending\n 3.exit\n";
       cout<<"enter your choice\n";
       cin>>c2;
       switch(c2)
       {
         case 1:ser_res=binarysearch_ass(arr_ass,key,n);
                 break;

         case 2:ser_res=binarysearch_des(arr_des,key,n);
                 break;
       }
       if(ser_res==-1)
       {
          cout<<"key not found\n";
       }
       else
       {
         cout<<"the element found in position"<<ser_res<<"\n";
       }
       }

       else if(c1==2)
       {
          cout<<"enter the key element\n";
          cin>>key;

          cout<<"1.linear ascending\n 2.linear descending\n 3.linear random\n";
          cout<<"enter your choice\n";
          cin>>c2;
          switch(c2)
          {
             case 1:ser_res=linear_search(arr_ass,key,n);
                     break;
             case 2:ser_res=linear_search(arr_des,key ,n);
                     break;
             case 3:ser_res=linear_search(array,key,n);
                     break;
          }
          if(ser_res==-1)
          {
             cout<<"key not found\n";
          }
          else
          {
            cout<<"key found at position "<<ser_res<<"\n";
          }
          }
          else if(c1==3)
          {
            exit(0);
          }
          free(array);
          free(arr_des);
          free(arr_ass);
          }
        }
