#include<bits/stdc++.h>
using namespace std;
void divide(int a[],int l, int r)
{
    for(int i=l;i<=r;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    if(l<r)
    {
        int mid=(l+r)/2;
        divide(a,l,mid);
        divide(a,mid+1,r);
    }
}
int main()
{
    int n; 
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    divide(a,0,n-1);
    return 0;
}