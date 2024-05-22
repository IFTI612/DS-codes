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


void selection_sort(vector<int>v)
{

    int n = v.size();



    for(int j = 0;j<=n-2;j++)
    {
        int mini = v[j];
        int pos = j;

        for(int i=j+1 ;i<=n-1 ;i++)
        {
            if (v[i]<mini)
            {
                mini = v[i];
                pos = i;
            }
        }
        swap(v[pos],v[j]);
    }
    int k , t;
    cin>>k;

    t = binSearch(v,k);

    if(t==1)
    {
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }

}


int main()
{
    int x,n;
    cin>> n;

    vector<int> v ;
    for(int i=0 ; i < n ; i++)
    {
        cin>> x;  ///input
        v.push_back(x);
    }

    selection_sort(v);
    return 0;
}



