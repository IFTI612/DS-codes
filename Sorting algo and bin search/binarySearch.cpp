#include<bits/stdc++.h>
using namespace std;

int binSearch(vector<int> a,int k)
{
    int lo = 0;
    int hi = a.size()-1;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;

        if(a[mid]==k)
            return 1;
        else if (a[mid]>k)
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
return 0;
}


int main()
{
    int x,n,k,t;
    cin>> n;
    ///int arr[n];///declaration
    vector<int> v ;
    for(int i=0 ; i < n ; i++)
    {
        cin>> x;  ///input
        v.push_back(x);
    }
    cin>> k;

    t=binSearch(v,k);
    if(t==1)
    {
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }





}

