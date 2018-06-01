#include<iostream>
#include<string.h>

using namespace std;
char P[50],T[50];
int Table[50];
int i,j,k,n,m;

int HorspoolMatching()
{
    for(i=0; i<n; i++)
    {
        Table[T[i]]=m;
        for(j=0; j<=m-2; j++)
            Table[P[j]]=m-1-j;
    }
    i=m-1;
    while(i<=n-1)
    {
        k=0;
        while(k<=m-1 && P[m-1-k]==T[i-k])
        {
            k=k+1;
        }
        if(k==m)
            return (i-m+1);
        else
            i=i+Table[T[i]];
    }
    return -1;
}


int main()
{
    int result=0;
    cout<<"Enter the text string\n";
    cin.getline(T,50);
    cout<<"Enter the Pattern String\n";
    cin.getline(P,50);
    m=strlen(P);
    n=strlen(T);
    cout<<"The length of the Pattern \""<<P<<"\" is :"<<m<<endl;
    cout<<"The length of the Text \""<<T<<"\" is :"<<n<<endl;
    result=HorspoolMatching();
    if(result>=0)
        cout<<"The Pattern \""<<P<<"\" present in the Text \""<<T<<"\" is found at "<<result+1<<" Position"<<endl;
    else
        cout<<"No Matching of Text with Pattern String\n ";

    return 0;

}



