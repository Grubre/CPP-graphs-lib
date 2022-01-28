#include "graph.h"

class Weighted_Graph : public Graph{
public:
    enum class TraverseAlgorithm
    {
        DFS,
        BFS
    };

//setters
public:
    void addNode();
    void addNode(const std::vector<int> &neighborIDs, bool twoWay = true);
    void removeNode(int id);

    void addVertex(int NodeAID, int NodeBID, bool twoWay = true);
    void removeVertex(int NodeAID, int NodeBID, bool twoWay = true);

//constructors & destructors
public:
    Weighted_Graph();
    Weighted_Graph(unsigned int _size);
    ~Weighted_Graph();

//variables
protected:
    //bool m_isSymetricallyValued;
};