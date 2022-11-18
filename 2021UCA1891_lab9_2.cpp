/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// DISPLAY ADJACENCY MATRIX
void display(int *g1, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *(g1 + i * n + j) << " ";
        }
        cout << endl;
    }
}

// ADD EDGE IN GRAPH
void addEdge(int u, int v, int *g1, int n)
{
    *(g1 + u * n + v) = 1;
}

// DFS which makes stack
void DFS1(int *g1,int u, int n, vector<int> &visited, stack<int> &S)
{
    visited[u] = 1;
    for (int i = 0; i < n; i++)
    {
        if (*(g1 + u * n + i) == 1)
        {
            if (visited[i] == 0)
            {
                DFS1(g1,i,n,visited,S);
            }
        }
    }
    S.push(u);
}

//DFS to print elements
void DFS2(int *g1,int u, int n, vector<int> &visited)
{
    visited[u] = 1;
    cout<<u<<" ";
    for (int i = 0; i < n; i++)
    {
        if (*(g1 + u * n + i) == 1)
        {
            if (visited[i] == 0)
            {
                DFS2(g1,i,n,visited);
            }
        }
    }
}

//TRANSPOSE GRAPH
void transpose(int* g1,int n){
    vector<int> row(n,0);
    vector<vector<int>> flag(n,row);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(*(g1 + i * n + j)==1){
                if(flag[i][j]==0){
                    flag[j][i]=1;
                    *(g1 + i * n + j)=0;
                    *(g1 + j * n + i)=1;
                }
            }
        }
    }
}

//FUNCTION TO PRINT STRONG COMPONENTS
void strongComponents(int* g1,int n){
    stack<int> S;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            DFS1(g1,i,n,visited,S);
        }
    }
    transpose((int*)g1,n);
    fill(visited.begin(),visited.end(),0);
    while(!S.empty()){
        int x=S.top();
        S.pop();
        if(visited[x]==0){
            DFS2(g1,x,n,visited);
            cout<<endl;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of vertices:" << endl;
    cin >> n;
    int g1[n][n]; // ADJACENCY MATRIX
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
    cout<<"The strongly connected components are:"<<endl;
    strongComponents((int*)g1,n);
    return 0;
}
