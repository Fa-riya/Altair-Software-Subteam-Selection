#include <bits/stdc++.h>
using namespace std;

const int vertices = 7; //number of vertices
vector<int> edges[vertices]; //an array of vectors to create an adjacency list
bool visited_vertex[vertices];//bool array to keep track if all vertices can be visited

//function to create an adjacency list
void addEdge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
}

//dfs function that traverses the graph through adjacency list
//recursively gets called
//will be called for a vertex only if it has not been visited before
//marks the adjacent vertices as visited
void dfs(int ver) {
    visited_vertex[ver] = true;
    for (int connected_vertex : edges[ver]) {
        if (!visited_vertex[connected_vertex]) {
            dfs(connected_vertex);
        }
    }
}

//checks if all the vertices have been visited
//if visited then returns true,else false
bool path() {

    for (int i = 0; i < vertices; i++) {
        visited_vertex[i] = false;
    }
    dfs(0);
    for (int i = 0; i < vertices; i++) {
        if (!visited_vertex[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //dataset of the edges
    vector<pair<int, int>> edge = {{0, 1}, {1, 2}, {2, 0}, {3, 4}, {4, 5}, {5, 6}, {6, 3}};

    //calling function to create adjacency list
    for (const auto& AnEdge : edge) {
        addEdge(AnEdge.first, AnEdge.second);
    }

    //function to check if path to all vertices exist
    bool ans = path();
    cout << boolalpha << ans << endl;

    return 0;
}
