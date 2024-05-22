#include<bits/stdc++.h>
using namespace std;

vector<int> v;


int Partition(int lo, int hi)
{
    int pivot = v[lo];
    int i = lo;
    int j= hi;
    while(i<j)
    {
        while(v[i]<=pivot)
        {
            i++;
        }
        while(v[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(v[i],v[j]);

        }
    }
    swap(v[lo],v[j]);

    return j;
}





void QuickSort(int lo, int hi)
{
    int p;
    if(lo<hi)
    {
        p = Partition(lo,hi);
        QuickSort( lo, p-1);
        QuickSort(p+1, hi);

    }
}


int main()
{
    int n, temp;
    cin>>n;

    for(int i = 0 ; i<n; i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    QuickSort(0,n-1);

    for(int i = 0 ; i<n; i++)
    {
        cout<<v[i]<<endl;
    }

    return 0;
}
