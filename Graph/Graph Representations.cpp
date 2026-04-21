/* 1. Adjacency Matrix */
/* 1. Adjacency Matrix Directed Graph */

/*  0 1 1
    1 0 1
    1 1 0
    T.C : 0(1)
    S.C : v * v (v is vertex hai )
*/
#include<iostream>
using namespace std;

int main(){
    int V;
    cout << "Enter number of vertices: ";
    cin>> V;
    int adj[V][V];

    //initialize matrix with 0
    for(int i=0; i<V; i++){
        for(int j = 0; j<V; j++){
            adj[i][j] = 0;
        }
    }

    int edges;
    cout << "Enter numbre of edges :";
    cin>> edges;

    cout << "Enter edges (u v):\n";
    for(int i=0; i<edges; i++){
        int u, v;
        cin>> u >> v;

        adj[u][v] = 1;
        //adj[v][u] = 1;
    }
    //print matrix
    cout << "\n adjacency matrix:\n";
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Adjacency Matrix for Undirected Graph */
/* T.C. = O(1) for edge operations, O(V²) for traversal
S.C. = O(V²) */

#include<iostream>
using namespace std;

int main(){
    int V;
    cout << "Enter number of vertices: ";
    cin>> V;
    int adj[V][V];

    //initialize matrix with 0
    for(int i=0; i<V; i++){
        for(int j = 0; j<V; j++){
            adj[i][j] = 0;
        }
    }

    int edges;
    cout << "Enter numbre of edges :";
    cin>> edges;

    cout << "Enter edges (u v):\n";
    for(int i=0; i<edges; i++){
        int u, v;
        cin>> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    //print matrix
    cout << "\n adjacency matrix:\n";
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/* Adjacency List (Graph Representation) */
/* Directed Graph (Adjacency List */
/* T.C. = O(1) for insertion, O(V + E) for traversal
S.C. = O(V + E) */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); // only one direction
    }

    // Print list
    cout << "\nAdjacency List:\n";
    for(int i = 0; i < V; i++) {
        cout << i << " -> ";
        for(int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
/* Undirected Graph (Adjacency List) */
/* T.C. = O(1) (insertion), O(V + E) (traversal)
S.C. = O(V + E) */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // both directions
    }

    // Print list
    cout << "\nAdjacency List:\n";
    for(int i = 0; i < V; i++) {
        cout << i << " -> ";
        for(int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

