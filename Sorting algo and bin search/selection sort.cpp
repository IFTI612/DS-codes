#include<bits/stdc++.h>
using namespace std;

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

    for(int i=0 ; i < n ; i++)
    {
        cout<<v[i]<<endl;
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



