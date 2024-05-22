#include<bits/stdc++.h>
using namespace std;

void find_index(vector<int>v)
{

    int n = v.size();
    int mini = v[0];
    int pos = 0;

    for(int i = 1;i<=n-1;i++)
    {
        if(v[i]<mini)
        {
            mini = v[i];
            pos = i;
        }
    }
    cout<<pos<<endl;

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

    find_index(v);
    return 0;
}


