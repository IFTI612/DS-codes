#include<bits/stdc++.h>
using namespace std;

vector<int>v1;


void Merge(int lo,int mid,int hi)
{
    int m, n;
    int i=0 , j=0;
    m = mid -lo +1;
    n = hi -mid;
    vector<int> l , r ;

    for(int i = 0 ; i<=m-1; i++)
    {
        l.push_back(v1[lo+i]);
    }

    for(int j = 0 ; j<=n-1; j++)
    {
        r.push_back(v1[mid+1+j]);
    }
    l[m]=INT_MAX;
    r[n]=INT_MAX;


    i = 0;
    j = 0;


    for(int k = lo; k<=hi ; k++)
    {
        if(l[i]<=r[j])
        {
            v1[k] = l[i];
            i++;
        }
        else
        {
            v1[k] = r[j];
            j++;
        }
    }

}





void MeregeSort(int lo,int hi)
{
    int mid;
     if(lo<hi)
     {
         mid = (lo+hi)/2;
         /***********************************************forward***********************************************/
         MeregeSort(lo,mid);///divide
         MeregeSort(mid+1,hi);///divide
         /***********************************************forward***********************************************/

         /***********************************************backward***********************************************/
         Merge(lo,mid,hi);///merge
         /***********************************************backward***********************************************/
     }

}






int main()
{
    int n,temp;


    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v1.push_back(temp);
    }

    MeregeSort(0,n-1);

    for(int i=0;i<n;i++)
    {
       cout<<v1[i]<<endl;
    }

    return 0;
}
