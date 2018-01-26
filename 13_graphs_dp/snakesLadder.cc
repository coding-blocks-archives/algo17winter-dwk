// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    vvi v;
    int nVertices;
public:
    Graph(int n){
        nVertices = n;
        v.resize(nVertices);
    }

    void addEdge(int src, int dest){
        v[src].push_back(dest);
        v[dest].push_back(src);
    }

    int sortestPath(int src, int dest){
        // vector<bool> visited(nVertices, false);
        queue<int> q;
        vi dist(nVertices, -1); // dist of all vertices frm the src

        q.push(src);
        dist[src] = 0;

        while(q.empty() == false){
            int cur = q.front();
            q.pop();

            for(int i = 0; i < v[cur].size(); ++i){
                int ngbr = v[cur][i];
                if (dist[ngbr] == -1){
                    // still unvisited
                    dist[ngbr] = 1 + dist[cur];
                    q.push(ngbr);
                }
            }
        }

        // for(int i = 0; i < 36; ++i) cout << dist[i] << " ";

        //distance
        return dist[dest];
    }
};

int main(){

    Graph g(36);

    int snakeLadder[36] = {};
    snakeLadder[1]      =       14;
    snakeLadder[4]      =       6;
    snakeLadder[8]      =       26;
    snakeLadder[16]     =       3;
    snakeLadder[17]     =       28;
    snakeLadder[19]     =       5;
    snakeLadder[23]     =       15;
    snakeLadder[24]     =       34;
    snakeLadder[31]     =       29;
    snakeLadder[33]     =       11;


    for(int curBox = 0; curBox < 36; ++curBox){
        if (snakeLadder[curBox] != 0){
            continue;   // do not compute moves
        }
        for(int dice = 1; dice <= 6; ++dice){
            int destBox = curBox + dice;
            if (snakeLadder[destBox] != 0){
                // it means either a snake or a ladder
                destBox = snakeLadder[destBox];
            }
            if (destBox < 36){
                g.addEdge(curBox, destBox);
            }
        }
    }

    int ans = g.sortestPath(0, 35);
    cout << ans;
    
}