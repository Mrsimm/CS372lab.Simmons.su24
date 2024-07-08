#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

int main() {
    Graph<int> g;

cout << "Test for the Graph class" << endl;
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);


    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

  
    g.printNodes();
    g.printEdges();

   
    cout << "Is 1 adjacent to 3? " << (g.adjacent(1, 3) ? "Yes" : "No") << endl;
    cout << "Neighbors of 2: ";
    vector<int> nbrs = g.neighbors(2);
    for (auto nbr : nbrs) 
    {
        cout << nbr << " ";
    }
    cout << endl;

   
    g.deleteEdge(1, 2);
    g.printEdges();
    cout << "Graph test over." << endl;
    cout << "AdjListGraph class test" << endl;

    vector<int> nodes = { 0, 1, 2, 3, 4 };
    vector<pair<int, int>> edges = { {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 4} };

    AdjListGraph<int> graph(nodes, edges);


    cout << "Initial graph:" << endl;
    graph.printNodes();
    graph.printEdges();


    cout << "Adjacent(0, 1): " << (graph.adjacent(0, 1) ? "true" : "false") << endl;
    cout << "Adjacent(0, 3): " << (graph.adjacent(0, 3) ? "true" : "false") << endl;
    cout << "Neighbors of 0: ";
    auto neighbors = graph.neighbors(0);
    for (int neighbor : neighbors) 
    {
        cout << neighbor << " ";
    }
    cout << endl;


    graph.addEdge(1, 2);
    graph.deleteEdge(3, 4);

 
    cout << "Graph after modifications:" << endl;
    graph.printNodes();
    graph.printEdges();

    return 0;
    return 0;
}