
#include <iostream>
#include <queue>
#include "SimmonsASG7P1DAT.h"

using namespace std;

bool isConnectedToKevinBacon(AdjListGraph<string>& graph, vector<string>& path)
{
    string start = "You";
    string end = "Kevin Bacon";

    vector<string> parent(graph.size(), "");  // Parent array to store paths
    vector<bool> visited(graph.size(), false); // Visited array to keep track of visited nodes
    queue<string> q;

    // Finding the index of the starting node
    size_t startIndex = 0;
    while (startIndex < graph.size() && graph.nodes[startIndex] != start) {
        ++startIndex;
    }

    if (startIndex == graph.size()) {
        // Start node not found in graph
        return false;
    }

    q.push(start);
    visited[startIndex] = true;

    bool found = false;

    while (!q.empty())
    {
        string current = q.front();
        q.pop();

        // Finding the index of the current node
        size_t currentIndex = 0;
        while (currentIndex < graph.size() && graph.nodes[currentIndex] != current) {
            ++currentIndex;
        }

        if (currentIndex == graph.size()) {
            // Current node not found in graph
            continue;
        }

        if (current == end)
        {
            found = true;
            break;
        }

        for (const auto& neighbor : graph.neighbors(current))
        {
            // Finding the index of the neighbor node
            size_t neighborIndex = 0;
            while (neighborIndex < graph.size() && graph.nodes[neighborIndex] != neighbor) {
                ++neighborIndex;
            }

            if (neighborIndex == graph.size()) {
                // Neighbor node not found in graph
                continue;
            }

            if (!visited[neighborIndex])
            {
                visited[neighborIndex] = true;
                parent[neighborIndex] = current;
                q.push(neighbor);
            }
        }
    }

    if (found) {
        path.clear();
        string step = end;
        while (step != start)
        {
            path.push_back(step);

            // Finding the index of the current step node
            size_t stepIndex = 0;
            while (stepIndex < graph.size() && graph.nodes[stepIndex] != step) {
                ++stepIndex;
            }

            if (stepIndex == graph.size()) {
                // Step node not found in graph
                break;
            }

            step = parent[stepIndex];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
    }

    return found;
}

int main()
{
    AdjListGraph<string> socialGraph;
    vector<string> people = { "You", "Kevin Bacon", "P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", "P9", "P10", "P11", "P12", "P13", "P14", "P15", "P16", "P17", "P18" };
    for (const auto& person : people)
    {
        socialGraph.addNode(person);
    }

    vector<pair<string, string>> connections = {
        {"You", "P1"},
        {"You", "P2"},
        {"Kevin Bacon", "P3"}
    };

    for (const auto& connection : connections)
    {
        socialGraph.addEdge(connection.first, connection.second);
        socialGraph.addEdge(connection.second, connection.first);
    }

    vector<string> path;
    bool connected = isConnectedToKevinBacon(socialGraph, path);

    if (connected)
    {
        cout << "You are connected to Kevin Bacon!" << endl;
        cout << "Path: ";
        for (const auto& person : path)
        {
            cout << person << " -> ";
        }
        cout << endl;
    }
    else
    {
        cout << "You are not connected to Kevin Bacon." << endl;
    }

    return 0;
}
