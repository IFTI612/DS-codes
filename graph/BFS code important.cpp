#include<bits/stdc++.h>
using namespace std;
vector<int>Node_Vec[100];
int level[12];

void BFS(int source)
{
    queue<int> q;
    q.push(source);
    level[source] = 0;
    while(!q.empty())
    {
        int par = q.front();
        for(int j = 0;j<Node_Vec[par].size();j++)
        {
            int child = Node_Vec[par][j];
            if(level[child]==-1)
            {
                level[child]=level[par]+1;
                q.push(child);
            }
        }
        q.pop();
    }

}

int main()
{

    int node_no, edge_no;
    printf("Enter the number of nodes: ");
    scanf("%d", &node_no);
    printf("Enter the number of edges: ");
    scanf("%d", &edge_no);
    for(int i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB;
        scanf("%d %d", &nodeA, &nodeB);
        Node_Vec[nodeA].push_back(nodeB); // for undirected graph
        Node_Vec[nodeB].push_back(nodeA);
    }


//Print Node Adjacency List by traversing the list
    for(int i = 1; i <= node_no; i++)
    {
        printf("%d -> ", i);
        for(int j = 0; j < Node_Vec[i].size(); j++)
        {
            printf("%d ", Node_Vec[i][j]);
        }
        printf("\n");
    }



    for(int i = 1 ;i<=node_no;i++)
    {
        level[i]=-1;
    }
    BFS(1);
    cout<<level[3]<<endl;
}


