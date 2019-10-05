#include<iostream>
#include "181B027_lab4.h"
using namespace std;
int main()
{
int n,*a,m,l;
cout<<"enter size of array: ";
cin>>n;
a=Rdm(n);
cout<<"Array without sorting:\n";
for(int i=0;i<n;i++)
    cout<<*(a+i)<<" ";
for (int i=0;i<(n-1);i++)
    {
        m=a[i];
        l=i;
        for(int j=i+1;j<n;j++)
            {
            if(*(a+j)<m)
                {
                m=*(a+j);
                l=j;
                }
            }
        int t=*(a+i);
        *(a+i)=*(a+l);
        *(a+l)=t;
        cout<<"\nIn "<<i+1<<" pass:\n";
        for(int k=0;k<n;k++)
             cout<<*(a+k)<<" ";
    }
cout<<"\nArray in sorted form by selection sort:\n";
for(int i=0;i<n;i++)
    cout<<*(a+i)<<" ";
return 0;
}
