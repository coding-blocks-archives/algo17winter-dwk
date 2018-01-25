// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

    void dfsForTS(int src, vector<bool>& visited, vector<int>& ans){
        visited[src] = true;
        for(int i = 0; i < v[src].size(); ++i){
            int ngbr = v[src][i];
            if (visited[ngbr] == false){
                dfsForTS(ngbr,visited,ans);
            }
        }
        ans.push_back(src);
    }

public:
    Graph(int n){
        nVertices = n;
        v.resize(n);
    }

    void addEdge(int src, int dest, bool bidirectional = false){
        v[src].push_back(dest);
        if (bidirectional) v[dest].push_back(src); // bidirectional
    }

    void dfs(){
        vector<bool> visited(nVertices, false);
        cout << "\nDFS PRINT\n";
        dfs(0, visited);
    }

    void bfs(int src){
        queue<int> q;
        vector<bool> visited(nVertices, false);
        cout << "\nBFS PRINT\n";
        q.push(src);
        visited[src] = true;
        while(q.empty() == false){
            int cur = q.front();
            q.pop();
            cout << cur << " ";

            for(int i = 0; i < v[cur].size(); ++i){
                int ngbr = v[cur][i];
                if (visited[ngbr] == false){
                    visited[ngbr] = true;
                    q.push(ngbr);
                }
            }
        }
    }

    int connectedComp(){
        vector<bool> visited(nVertices, false);
        int cnt = 0;
        for(int src = 0; src < nVertices; ++src){
            if (visited[src] == false){
                dfs(src, visited);
                ++cnt;
                cout << endl;
            }
        }
        return cnt;
    }

    vector<int> toplogicalSort(){
        // tarjan algo
        vector<bool> visited(nVertices, false);
        vector<int> ans;
        dfsForTS(0, visited,ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> toplogicalSort_levelWise(){
        vector<int> indegree(nVertices, 0);

        for(int src = 0; src < nVertices; ++src){
            for(int i = 0; i < v[src].size(); ++i){
                int ngbr = v[src][i];
                indegree[ngbr]++;
            }
        }

        vector<int>::iterator it = find(indegree.begin(), indegree.end(), 0);
        int startingVtx = it - indegree.begin();
        queue<int> q;
        q.push(startingVtx);
        vector<int> ans;

        while(q.empty() == false){
            int cur = q.front();
            ans.push_back(cur);
            q.pop();

            for(int i = 0; i < v[cur].size(); ++i){
                int ngbr = v[cur][i];
                indegree[ngbr]--;
                if (indegree[ngbr] == 0){
                    q.push(ngbr);
                }
            }
        }
        return ans;
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
    // Graph g(9);
    // g.addEdge(0, 1, true);
    // g.addEdge(0, 2, true);
    // g.addEdge(1, 2, true);
    // g.addEdge(1, 4, true);
    // g.addEdge(2, 3, true);
    // g.addEdge(4, 5, true);
    // g.addEdge(4, 6, true);
    // g.addEdge(5, 6, true);
    // g.addEdge(100, 1000);
    // g.printGraph();

    // g.dfs();
    // cout << endl;
    // g.bfs(0);

    // int ans = g.connectedComp();
    // cout << ans << endl;

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);

    vector<int> ans = g.toplogicalSort_levelWise();
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }

    return 0;
}