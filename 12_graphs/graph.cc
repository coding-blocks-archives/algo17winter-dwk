// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;

class Graph{
    vector<vector<int> > v;
    int nVertices;

    void dfs(int src, vector<bool>& visited){
        visited[src] = true;
        cout << src << " ";

        for(int i = 0; i < v[src].size(); ++i){
            int ngbr = v[src][i];
            if (visited[ngbr] == false){
                dfs(ngbr,visited);
            }
        }
    }

public:
    Graph(int n){
        nVertices = n;
        v.resize(n);
    }

    void addEdge(int src, int dest){
        v[src].push_back(dest);
        v[dest].push_back(src); // bidirectional
    }

    void dfs(){
        vector<bool> visited(nVertices, false);
        cout << "\nDFS PRINT\n";
        dfs(0, visited);
    }


    void printGraph(){
        for(int i = 0; i < nVertices; ++i){
            cout << i << " : ";
            
            vector<int>& adjList = v[i];

            for(int j = 0; j < adjList.size(); ++j){
                cout << adjList[j] << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    // g.addEdge(100, 1000);
    g.printGraph();

    g.dfs();
    return 0;
}