#include<bits/stdc++.h>
using namespace std;

void FOR(int i,int n)
{
    if(i<=n)
    {
        /*********************** if I write code here. It will do something in forward(forward call).*************************/

        cout<<"forward call"<<i<<endl;

        /*******************************************************************************************/
        FOR(i+1,n);

        /*********************** if I write code here. It will do something in reverse(backward call).*********/
        cout<<"backward call"<<i<<endl;
    }

}

int main()
{

    for(int i=0;i<=5;i++)
    {
        cout<<"Doing something in for"<<i<<endl;
    }

    /// using for by using recursion
    FOR(1,5);


    return 0;

}
