/*
from : https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
pass test case(main) 
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
public:
    Graph(int vertex)
    : V(vertex),
      adj_list(vertex, std::vector<int>())
      {}
    void addEdge(int v, int w) {
        adj_list.at(v).push_back(w);
    }
    void BFS(int start) {
        std::list<int> q;
        std::vector<bool> visited(V, false);

        // add w that adjacent from v to queue
        q.push_back(start);
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            cout << "visiting : " << v << endl;
            visited[v] = true;
            for (int w : adj_list.at(v)) {
                if (!visited[w])
                    q.push_back(w);
            }
        }
    }
private:
    int V; // vertex
    vector<vector<int>> adj_list;
};

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
