// https://www.hackerrank.com/challenges/primsmstsub

#include <cmath>
#include <set>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int node;
    int next_node;
    int weight;

    Edge(int node, int next_node, int weight) {
        this->node = node;
        this->next_node = next_node;
        this->weight = weight;
    }
};

struct GreaterByWeight
{
  bool operator()(const Edge& lhs, const Edge& rhs) const
  {
    return lhs.weight > rhs.weight;
  }
};

int main() {
    int n, m; cin >> n >> m;

    vector<vector< Edge>> neighbours = vector<vector< Edge>>();

    for (int i = 0; i < n; i++)
        neighbours.push_back(vector< Edge>());

    for (int i = 0; i < m; i++) {
        int node1, node2, weight; cin >> node1 >> node2 >> weight;
        neighbours[node1-1].push_back(Edge(node1, node2, weight));
        neighbours[node2-1].push_back(Edge(node2, node1, weight));
    }

    int S; cin >> S;
    set<int> visited_nodes = set<int>();
    visited_nodes.insert(S);

    priority_queue<Edge, vector<Edge>, GreaterByWeight> edges = priority_queue<Edge, vector<Edge>, GreaterByWeight>();

    for (auto it = neighbours[S-1].begin(); it != neighbours[S-1].end(); it++)
                edges.push(*it);

    long total_weight = 0;
    while (visited_nodes.size() != n && !edges.empty()) {
        Edge edge = edges.top();
        edges.pop();

        if (visited_nodes.find(edge.next_node) == visited_nodes.end()) {
            total_weight += edge.weight;
            visited_nodes.insert(edge.next_node);

            for (auto it = neighbours[edge.next_node-1].begin(); it != neighbours[edge.next_node-1].end(); it++)
                if (visited_nodes.find(it->next_node) == visited_nodes.end())
                    edges.push(*it);
        }
    }

    cout << total_weight;
    return 0;
}
