#include<iostream>
#include "head.h"
using namespace std;
int n;
int merg(int *a,int low,int mid,int high,int* temp)
{
   int i,j;
   i=low;
   j=mid+1;
   int k=low;
   while(i<=mid && j<=high)
   {
       if(a[i]>a[j])
       {
           temp[k]=a[j];
           j++;
       }
       else
       {
           temp[k]=a[i];
           i++;
       }
       k++;
   }
   while(i<=mid)
   {
        temp[k]=a[i];
        k++;
        i++;
   }
    while(j<=high)
   {
        temp[k]=a[j];
        k++;
        j++;
   }
   for(i=low;i<=high;i++)
    a[i]=temp[i];
}
void m_sort(int*a,int low,int high,int *temp)
{
    if(low<high)
    {
        int mid;
        mid=(low+high)/2;
        m_sort(a,low,mid,temp);
        m_sort(a,mid+1,high,temp);
        merg(a,low,mid,high,temp);
            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<"\n";
    }
}
int main()
{

    cin>>n;
    int a[n];
    int temp[n];
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    m_sort(a,0,n-1,temp);
    cout<<"final"<<"\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    delete []a;
    return 0;
}

