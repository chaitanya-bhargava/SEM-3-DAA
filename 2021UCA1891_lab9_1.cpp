/*"I have done this assignment on my own. I have not copied any code from
another student or any online source. I understand if my code is found
similar to somebody else's code, my case can be sent to the Disciplinary
committee of the institute for appropriate action."*/
#include <bits/stdc++.h>
using namespace std;

// LINKED LIST NODE
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

//RETURN INDEX OF MIN VALUE FROM ARRAY
int minIndex(vector<int> in_degree)
{
    int min = INT_MAX;
    int index = -1;
    for (int i = 0; i < in_degree.size(); i++)
    {
        if (in_degree[i] < min)
        {
            min = in_degree[i];
            index = i;
        }
    }
    return index;
}

// FUNCTION TO INSERT NODE
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

// FUNCTION TO DISPLAY LINKED LIST
void display(Node *head)
{
    while (head != NULL)
    {
        cout << "->" << head->data;
        head = head->next;
    }
    cout << endl;
}

// ADD EDGE IN GRAPH
void addEdge(int n, int m, Node *g1[])
{
    insertNode(m, &g1[n]);
}

// PRINT GRAPH IN ADJACENCY LIST
void printGraph(Node **g1, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
        ;
        display(g1[i]);
    }
}

//DELETE NODE AND EDGES GOING OUT OF IT
void deleteNode(Node **head, vector<int> &in_degree)
{
    while ((*head) != NULL)
    {
        in_degree[(*head)->data]--;
        *head = (*head)->next;
    }
}

//FUNCTION FOR TOPOLOGICAL SORT
void topologicalSort(Node **g1, vector<int> &in_degree, int n,vector<char> map)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_index = minIndex(in_degree);
        in_degree[min_index] = INT_MAX;
        cout << map[min_index] << "->";
        deleteNode(&(g1[min_index]), in_degree);
    }
    int min_index = minIndex(in_degree);
    in_degree[min_index] = INT_MAX;
    cout << map[min_index];
    deleteNode(&(g1[min_index]), in_degree);
}

//SEARCH FOR NUMBER USING CHAR
int search(vector<char> map,char c){
    for(int i=0;i<map.size();i++){
        if(map[i]==c){
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter number of vertices:" << endl;
    cin >> n;
    cout<<"Enter vertices:"<<endl;
    vector<char> map(n);
    for(int i=0;i<n;i++){
        cin>>map[i];
    }
    sort(map.begin(),map.end()); //SORT CHARACTER MAP SO LETTERS ARE CHOSEN ALPHABETICALLY IN CASE OF CONFLICT
    Node *g1[n]; // ADJACENCY LIST
    vector<int> in_degree(n, 0); //STORE IN DEGREE OF EACH NODE
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
        char u, v;
        cin >> u >> v;
        addEdge(search(map,u),search(map,v), g1);
        in_degree[search(map,v)]++;
    }
    cout << endl;
    topologicalSort(g1, in_degree, n,map);
    return 0;
}
