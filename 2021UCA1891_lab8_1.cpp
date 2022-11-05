/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/
#include <iostream>
#include <queue>
using namespace std;

//LINKED LIST NODE
class Node
{
public:
    int data;
    Node *next;
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};

//FUNCTION TO INSERT NODE
void insertNode(int n, Node **head)
{
    Node *temp = new Node(n);
    if ((*head) == NULL)
    {
        (*head) = temp;
    }
    else
    {
        Node *temp2 = (*head);
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
}

//FUNCTION TO DISPLAY LINKED LIST
void display(Node *head)
{
    while (head != NULL)
    {
        cout << "->" << head->data;
        head = head->next;
    }
    cout << endl;
}

//ADD EDGE IN GRAPH
void addEdge(int n, int m, Node *g1[])
{
    insertNode(m, &g1[n]);
}

//PRINT GRAPH IN ADJACENCY LIST
void printGraph(Node **g1, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
        ;
        display(g1[i]);
    }
}

//BFS
void BFS(Node **g1, int u, int n)
{
    int visited[n]; //VISITED ARRAY
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    queue<int> q; //QUEUE
    q.push(u);
    visited[u] = 1;
label:
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        Node *temp = g1[x];
        while (temp != NULL)
        {
            if (visited[temp->data] == 1)
            {
                temp = temp->next;
                continue;
            }
            q.push(temp->data);
            visited[temp->data] = 1;
            temp = temp->next;
        }
    }
    //FOR UNVISITED NODES
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            q.push(i);
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
    Node *g1[n]; //ADJACENCY LIST
    for (int i = 0; i < n; i++)
    {
        g1[i] = NULL;
    }
    cout << "Enter number of edges:" << endl;
    int m;
    cin >> m;
    cout << "Enter pair of vertices:" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, g1);
    }
    int start;
    cout << "Enter starting vertex for bfs:" << endl;
    cin >> start;
    // printGraph(g1,n);
    BFS(g1, start, n);
    return 0;
}
