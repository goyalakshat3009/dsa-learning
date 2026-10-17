#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topoSort(int curr, vector<bool> &vis, stack<int> &s) {
        vis[curr] = true;
        for(int neighbor : adj[curr]) {
            if(!vis[neighbor]) {
                topoSort(neighbor, vis, s);
            }
        }
        s.push(curr);
    }

    void dfs(int curr, vector<bool> &vis, vector<vector<int>> &transpose) {
        vis[curr] = true;
        cout << curr << " ";
        for(int neighbor : transpose[curr]) {
            if(!vis[neighbor]) {
                dfs(neighbor, vis, transpose);
            }
        }
    }

    void kosaraju() {
        // step-1 topo order
        stack<int> s;
        vector<bool> vis(V, false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topoSort(i,vis,s);
            }
        }

        // step-2 transpose graph
        vector<vector<int>> adjT(V);
        for(int u=0; u<V;u++) { // u-->v
            vis[u]=false;
            for(int neighbor : adj[u]) {
                adjT[neighbor].push_back(u); // v-->u
            }
        }

        // step-3 find components
        cout << "Printing the SCC: \n";
        while(s.size()>0) {
            int curr=s.top();
            s.pop();

            if(!vis[curr]) {
                dfs(curr,vis,adjT);
                cout<<endl;
            }
        }
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,0);
    graph.addEdge(2,1);
    graph.addEdge(3,4);

    graph.kosaraju();
    return 0;
}