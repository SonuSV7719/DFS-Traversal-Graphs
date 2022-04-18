#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
int visited[N];
vector<int> output;

void DFS(int source)
{
    if (visited[source]) return;
    output.push_back(source);
    cout << "Current Node of DFS traversal(OUTPUT):" << source << endl;
    visited[source] = 1;
    vector<int>::iterator it;
    for (it = adj[source].begin(); it != adj[source].end(); it++)
    {
        cout << "Parent is: " << source << " " <<"Child is: " << *it << endl;
        if (visited[*it] != 1)
        {
            DFS(*it);
        }
    }
}

int main()
{
    int v, e;
    int source;
    vector<int>::iterator it;
    cout << "Enter total No. of vertices and edges: ";
    cin >> v >> e;

    for (int i = 1; i <= e; i++)
    {
        int x, y;
        cout << "Enter X and Y vertex where edge is present between them: ";
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    cout << "Enter source from where DFS to start with: ";
    cin >> source;
    DFS(source);
    cout << "****************************OUTPUT*****************************" << endl << endl;
    cout << "Output of DFS traversal: ";
    for (it = output.begin(); it != output.end(); it++)
    {
        cout << *it <<" ";
    }

    return 0;
}
