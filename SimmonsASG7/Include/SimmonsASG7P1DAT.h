#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <class N>
class Graph {

public:
    vector<N> nodes;
    vector<pair<N, N>> edges;
    Graph() {}

    Graph(const vector<N>& nodes, const vector<pair<N, N>>& edges)
        : nodes(nodes), edges(edges) {}

    virtual ~Graph() {}

    virtual bool adjacent(N x, N y) {
        for (const auto& edge : edges) {
            if ((edge.first == x && edge.second == y) || (edge.first == y && edge.second == x)) {
                return true;
            }
        }
        return false;
    }

    virtual vector<N> neighbors(N x) {
        vector<N> result;
        for (const auto& edge : edges) {
            if (edge.first == x) {
                result.push_back(edge.second);
            }
            else if (edge.second == x) {
                result.push_back(edge.first);
            }
        }
        return result;
    }

    virtual void addNode(N x) {
        nodes.push_back(x);
    }

    virtual void addEdge(N x, N y) {
        if (!adjacent(x, y)) {
            edges.emplace_back(x, y);
        }
    }

    virtual void deleteEdge(N x, N y) {
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if ((it->first == x && it->second == y) || (it->first == y && it->second == x)) {
                edges.erase(it);
                break;
            }
        }
    }

    void printNodes() {
        cout << "Nodes: ";
        for (const auto& node : nodes) {
            cout << node << " ";
        }
        cout << endl;
    }

    void printEdges() {
        cout << "Edges: ";
        for (const auto& edge : edges) {
            cout << "(" << edge.first << "," << edge.second << ") ";
        }
        cout << endl;
    }

    virtual Graph& operator=(const Graph& other) {
        if (this != &other) {
            nodes = other.nodes;
            edges = other.edges;
        }
        return *this;
    }
};

template <class N>
class AdjListGraph : public Graph<N> {
private:
    using Edges = list<N>;
    vector<Edges> adjacencyList;

public:
    AdjListGraph() : Graph<N>() {}

    AdjListGraph(const vector<N>& newNodes, const vector<pair<N, N>>& newEdges)
        : Graph<N>(newNodes, newEdges) {
        adjacencyList.resize(newNodes.size());
        for (const auto& edge : newEdges) {
            addEdge(edge.first, edge.second);
        }
    }
    size_t size() const 
    {
        return adjacencyList.size();
    }

    virtual bool adjacent(N x, N y) override {
        size_t index = findIndex(x);
        if (index < adjacencyList.size()) {
            auto& neighbors = adjacencyList[index];

            for (const auto& neighbor : neighbors) {
                if (neighbor == y) {
                    return true;
                }
            }
        }
        return false;
    }

    virtual vector<N> neighbors(N x) override {
        vector<N> result;
        size_t index = findIndex(x);
        if (index < adjacencyList.size()) {
            auto& neighbors = adjacencyList[index];
            for (const auto& neighbor : neighbors) {
                result.push_back(neighbor);
            }
        }
        return result;
    }

    virtual void addNode(N node) override {
        Graph<N>::addNode(node);
        adjacencyList.push_back(Edges());
    }

    virtual void addEdge(N x, N y) override {
        if (!adjacent(x, y)) {
            size_t indexX = findIndex(x);
            size_t indexY = findIndex(y);
            if (indexX < adjacencyList.size() && indexY < adjacencyList.size()) {
                adjacencyList[indexX].push_back(y);
                adjacencyList[indexY].push_back(x);
                Graph<N>::addEdge(x, y);
            }
        }
    }

    virtual void deleteEdge(N x, N y) override {
        size_t indexX = findIndex(x);
        size_t indexY = findIndex(y);
        if (indexX < adjacencyList.size() && indexY < adjacencyList.size()) {
            auto& neighborsX = adjacencyList[indexX];
            auto& neighborsY = adjacencyList[indexY];


            neighborsX.remove(y);
            neighborsY.remove(x);

            Graph<N>::deleteEdge(x, y);
        }
    }

private:
    size_t findIndex(N node) {

        for (size_t i = 0; i < Graph<N>::nodes.size(); ++i) {
            if (Graph<N>::nodes[i] == node) {
                return i;
            }
        }
        return adjacencyList.size();
    }
};

template <class N>
class AdjMatrixGraph : public Graph<N> {
private:
    static const int MaxSize = 100;
    vector<N> nodeVector;
    vector<vector<bool>> adjMatrix;
    unsigned int numNodes = 0;

public:
    AdjMatrixGraph() : Graph<N>() {
        initializeMatrix();
    }

    AdjMatrixGraph(const AdjMatrixGraph& other) : Graph<N>(other) {
        numNodes = other.numNodes;
        adjMatrix = other.adjMatrix;
    }

    AdjMatrixGraph& operator=(const AdjMatrixGraph& source) {
        if (this != &source) {
            Graph<N>::operator=(source);
            numNodes = source.numNodes;
            adjMatrix = source.adjMatrix;
        }
        return *this;
    }

    AdjMatrixGraph(vector<N> newNodes, vector<pair<N, N>> newEdges)
        : Graph<N>(newNodes, newEdges) {
        initializeMatrix();

        for (const auto& edge : newEdges) {
            addEdge(edge.first, edge.second);
        }
    }

    ~AdjMatrixGraph() {}

    virtual bool adjacent(N x, N y) override {
        size_t indexX = findIndex(x);
        size_t indexY = findIndex(y);
        if (indexX < numNodes && indexY < numNodes) {
            return adjMatrix[indexX][indexY];
        }
        return false;
    }

    virtual vector<N> neighbors(N x) override {
        vector<N> result;
        size_t index = findIndex(x);
        if (index < numNodes) {
            for (size_t i = 0; i < numNodes; ++i) {
                if (adjMatrix[index][i]) {
                    result.push_back(nodeVector[i]);
                }
            }
        }
        return result;
    }

    virtual void addNode(N node) override {
        Graph<N>::addNode(node);
        nodeVector.push_back(node);
        numNodes++;
    }

    virtual void addEdge(N x, N y) override {
        size_t indexX = findIndex(x);
        size_t indexY = findIndex(y);
        if (indexX < numNodes && indexY < numNodes) {
            adjMatrix[indexX][indexY] = true;
            adjMatrix[indexY][indexX] = true;
            Graph<N>::addEdge(x, y);
        }
    }

    virtual void deleteEdge(N x, N y) override {
        size_t indexX = findIndex(x);
        size_t indexY = findIndex(y);
        if (indexX < numNodes && indexY < numNodes) {
            adjMatrix[indexX][indexY] = false;
            adjMatrix[indexY][indexX] = false;
            Graph<N>::deleteEdge(x, y);
        }
    }

private:
    void initializeMatrix() {
        adjMatrix.assign(MaxSize, vector<bool>(MaxSize, false));
    }

    size_t findIndex(N node) {

        for (size_t i = 0; i < nodeVector.size(); ++i) {
            if (nodeVector[i] == node) {
                return i;
            }
        }
        return numNodes;
    }
};
