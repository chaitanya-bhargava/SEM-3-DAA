/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/
#include <iostream>
#include <stack>
using namespace std;

//DISPLAY ADJACENCY MATRIX
void display(int* g1,int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<*(g1+i*n+j)<<" ";
        }
        cout<<endl;
    }
}

//ADD EDGE IN GRAPH
void addEdge(int u, int v, int *g1, int n)
{
    *(g1+u*n+v)=1;
    *(g1+v*n+u)=1;
}

//DFS
void DFS(int *g1, int u, int n)
{
    int visited[n]; //VISITED ARRAY
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    stack<int> s; //STACK
    s.push(u);
    visited[u] = 1;
label:
    while (!s.empty())
    {
        int x = s.top();
        s.pop();
        cout<<x<<" ";
        for(int i=0;i<n;i++)
        {
            if(*(g1+x*n+i)==1){
            if (visited[i] == 1)
            {
                continue;
            }
            s.push(i);
            visited[i] = 1;
            }
        }
    }
    //FOR UNVISITED NODES
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            s.push(i);
            visited[i] = 1;
            goto label;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of vertices:" << endl;
    cin >> n;
    int g1[n][n]; //ADJACENCY MATRIX
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g1[i][j] = 0;
        }
    }
    cout << "Enter number of edges:" << endl;
    int m;
    cin >> m;
    cout << "Enter pair of vertices:" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, (int *)g1, n);
    }
    int start;
    cout << "Enter starting vertex for dfs:" << endl;
    cin >> start;
    // display((int*)g1,n);
    DFS((int *)g1, start, n);
    return 0;
}
