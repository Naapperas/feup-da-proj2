#ifndef DA_PROJ2_GRAPH_H
#define DA_PROJ2_GRAPH_H

class Graph;

#include <climits>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * @brief Represents an edge connecting two nodes.
 */
struct Edge {
    /**
     * @brief The destination node.
     */
    int dest = -1;
    int capacity = -1;
    int duration = -1;

    bool residual = false; // maybe used, maybe not

    Edge(const int dest, const int capacity, const int duration)
        : dest(dest), capacity(capacity), duration(duration){};
    Edge(){};

    bool operator==(const Edge &other) const { return dest == other.dest; }
};

namespace std {
    template <> struct hash<Edge> {
        std::size_t operator()(const Edge &e) const { return e.dest; }
    };
}

/**
 * @brief Represents a node in a Graph.
 */
struct Node {
    /**
     * @brief The outgoing edges connecting this node to others.
     */
    std::unordered_set<Edge> adj{};

    int label = -1;
    int parent = -1;

    bool visited = false, printed = false;

    int minTime = INT_MAX, maxTime = INT_MIN;

    // max(incoming-ES) - min(incoming-ES) [scenarios 2.4 and 2.5]
    int waitTime = -1;

    Node(const int label) : label(label){};
    Node(){};
};

/**
 * @brief Holds data from a dataset to be used by different scenarios.
 *
 * @details Also has several static methods to make dataset management easier.
 */
class Graph {
    /**
     * @brief This graph's nodes.
     *
     * The keys are each node's id and the values are the nodes
     * themselves.
     */
    std::unordered_map<int, Node> nodes;

    /**
     * @brief Marks all nodes as unvisited.
     *
     */
    void resetVisits();

public:
    Graph(){};
    Graph(int n) {
        for (int i = 1; i <= n; ++i)
            nodes.insert({i, {i}});
    };

    void addEdge(const int src, const int dest, const int capacity,
                 const int duration);
    void addEdge(Node &src, Node &dest, const int capacity, const int duration);

    /**
     * @return This graph's nodes.
     */
    std::unordered_map<int, Node> &getNodes() { return nodes; };
    /**
     * @brief Get the node with the specified code.
     *
     * @param id The stop code.
     * @return The node.
     */
    Node &getNode(const int &id) { return nodes.at(id); };

    /**
     * @brief Performs a Breadth-First Search algorithm.
     *
     * @param s Starting node
     * @param t Destination node
     * @return the path between <s> and <t> generated by this algorithm and the
     * maximum capacity of that path
     */
    std::pair<int, std::list<int>> BFS(int s, int t);

    /**
     * @brief Checks if an element with the given key exists
     *
     * @param id the number of the node to check
     * @return true if the node belongs to this graph, false otherwise
     */
    bool hasNode(int id) const { return nodes.contains(id); }

    /**
     * @brief Adds a new node associated with the given id
     *
     * @param i the id of the node
     * @param node the node to add
     */
    void addNode(int i, const Node &node);
    void addNode(int i);

    /**
     * @brief Clears this graph
     *
     */
    void clear() { nodes.clear(); };

    std::string toDotFile();
};

#endif
