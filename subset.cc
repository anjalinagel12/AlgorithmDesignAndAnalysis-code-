#include<iostream>
#include<stdio.h>
using namespace std;
int sum,size,set[100],flag=0,stk[100],top,ct=0,i;
void push(int data)
{
			stk[++top]=data;
}
void pop()
{
			top--;
}
void display()
{
    cout<<"Solution #"<<++ct<<"{";
	for(i=1;i<=top;i++)
    {
        cout<<stk[i]<<" ";
    }
    cout<<"}"<<endl;
}
bool findsubset(int pos,int sum)
{
			int i;
			static int foundsoln=0;
			if(sum==0)
			{
				display();
				foundsoln=1;
			}
			if(sum>0)
			{
				for(i=pos;i<=size;i++)
				{
					push(set[i]);
					findsubset(i+1,sum-set[i]);
					pop();
				}
			}

			return(foundsoln);
}
int main()
{
	cout<<"enter the maximum no of elements";
    cin>>size;
    cout<<"enter the elements";
    for(int i=1;i<=size;i++)
        cin>>set[i];
	cout<<"enter the sum"<<endl;
	cin>>sum;

	if(findsubset(1,sum))
	{
        cout<<"above are the solution"<<endl;

	}
	else
        cout<<"no solution exist"<<endl;

}
