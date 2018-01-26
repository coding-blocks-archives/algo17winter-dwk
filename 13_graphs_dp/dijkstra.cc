// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pair {
    int wt;
    int id;
    Pair(int i, int w) {
        wt = w;
        id = i;
    }

    Pair() {
        // for pairs without any arguments
        // default
        wt = 0;
        id = 0;
    }

    bool operator()(const Pair& a, const Pair& b){
        // shall a come before b
        // if a comes before b => its a maxheap
        return a.wt > b.wt;
    }
};


class Graph {
    typedef vector<Pair> vp;
    vector<vp> v;
    int nVertices;
public:
    Graph(int n) {
        nVertices = n;
        v.resize(nVertices);
    }

    void addEdge(int src, int dest, int wt) {
        Pair p(dest, wt);
        v[src].push_back(p);
        // bidirectional
        p.id = src;
        v[dest].push_back(p);
    }

    int dijkstra(int src, int dest) {
        priority_queue<Pair, vector<Pair>, Pair> pq;
        const int inf = 1e6;
        vector<int> dist(nVertices, inf);

        dist[src] = 0;
        pq.push(Pair(src, 0));
        while (!pq.empty()) {
            Pair p = pq.top();
            pq.pop();
            int cur = p.id;

            if (dist[cur] < p.wt) continue;
            // B - 16
            // B - 86
            dist[cur] = p.wt;

            for (int i = 0; i < v[cur].size(); ++i) {
                Pair ngbr = v[cur][i];
                int wt = ngbr.wt + dist[cur];
                if (dist[ngbr.id] > wt) {
                    Pair x(ngbr.id, wt);
                    pq.push(x);
                }
            }
        }
        return dist[dest];
    }
};


int main() {
    Graph g(7);
    g.addEdge(0, 1, 80);
    g.addEdge(0, 3, 10);
    g.addEdge(3, 1, 6);
    g.addEdge(1, 2, 70);
    g.addEdge(3, 4, 20);
    g.addEdge(4, 5, 50);
    g.addEdge(4, 6, 10);
    g.addEdge(5, 6, 5);
    int ans = g.dijkstra(0, 5);
    cout << ans;

}