#include "../includes/subscenarios.hpp"

ScenarioResult scenario1_1(Dataset &dataset) {

    auto& nodes = dataset.getNodes();

    std::vector<int> capacities(static_cast<int>(nodes.size()) + 1, 0);
    std::set<std::pair<int /* capacity */, int /* node */>, std::greater<std::pair<int, int>>> capacitiesHeap;


    for (auto& [index, node] : nodes) {
        capacitiesHeap.insert({0, index});
        capacities.at(index) = 0;
        node.parent = -1;
    }

    capacitiesHeap.erase({0, 1});
    capacitiesHeap.insert({INF, 1});
    capacities.at(1) = INF;
    nodes[1].parent = 1;

    while (!capacitiesHeap.empty()) {

        int v = capacitiesHeap.extract(capacitiesHeap.begin()).value().second;

        auto& orig = nodes.at(v);

        for (auto& edge : orig.adj) {
            auto& w = edge.dest;

            if (std::min(capacities[v], edge.capacity) > capacities[w]) {

                capacitiesHeap.erase({capacities[w], w});
                capacities[w] = std::min(capacities[v], edge.capacity);
                nodes.at(w).parent = v;
                capacitiesHeap.insert({capacities[w], w});
            }
        }
    }

    int node = nodes.at(nodes.size()).label;
    std::vector<int> path;

    while(node != nodes.at(1).label) {
        path.insert(path.begin(), node);
        node = nodes.at(node).parent;
    }
    path.insert(path.begin(), nodes.at(1).label);

    return {-1, capacities[50], path};
}

ScenarioResult scenario1_2(Dataset &dataset) {
    //TODO
}

ScenarioResult scenario2_1(Dataset &dataset) {
    //TODO
}

ScenarioResult scenario2_2(Dataset &dataset) {
    //TODO
}

ScenarioResult scenario2_3(Dataset &dataset) {
    std::vector<int> parent;
    std::vector<int> path;

    auto& nodes = dataset.getNodes();
    
    Node startingNode = nodes.at(1);
    Node destinationNode = nodes.at(nodes.size());

    int maxFlow = dataset.edmondsKarp(startingNode.label, destinationNode.label).first;

    return {maxFlow, -1, path};
}

ScenarioResult scenario2_4(Dataset &dataset) {
    //TODO
}

ScenarioResult scenario2_5(Dataset &dataset) {
    //TOD
}