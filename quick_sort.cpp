#include<iostream>
#include "181B081_LAB4_1.h"
using namespace std;
int partition_p(int *a,int low,int high)
{
    int left,right,temp;
    left=low+1;
    right=high;
    int pivot=a[low];
    while(left<=right)
    {
        while(a[left]<=pivot && left<=high)
        {
            left++;
        }
        while(a[right]>pivot && right>=low+1)
        {
           right--;
        }
        if(left<=right)
        {
           temp=a[right];
           a[right]=a[left];
           a[left]=temp;
           left++;
           right--;
        }
    }
    temp=a[right];
    a[right]=pivot;
    a[low]=temp;
    for(int k=0;k<=high;k++)
        cout<<a[k]<<" ";
    cout<<"\n";
    return right;
}
void q_sort(int*a,int low,int high)
{
    if(low<high)
    {
        int new_loc;
        new_loc=partition_p(a,low,high);
        q_sort(a,low,new_loc-1);
        q_sort(a,new_loc+1,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int *a;
    a=ramu(n);
    int i;
    cout<<"Array without sorting:\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" "<<endl;
    q_sort(a,0,n-1);
    cout<<"final"<<"\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" "<<endl;
    return 0;
}

