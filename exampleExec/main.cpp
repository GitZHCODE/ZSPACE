#include <zCore.h>
#include <geometry/zGraph.h>

// here: include the public header file of the structural API, for dummy purposes


void main() {

// define the connectivity graph as a z graph
zSpace::zGraph graph;

zSpace::zPointArray _positions = {
    zSpace::zVector(0, 0, 0),
    zSpace::zVector(1, 0, 0),
    zSpace::zVector(1, 1, 0),
    zSpace::zVector(0, 1, 0),
    zSpace::zVector(0.5, 0.5, 0.3)
};


// the edge connectivity of a tetrahedron
zSpace::zIntArray _edgeConnects = {0, 1, 1, 2, 2, 3, 3, 0, 0, 4, 1, 4, 2, 4, 3, 4};

graph.create(positions, edgeConnects);

void* model;

// define the first four nodes to have reactions, defined a simple load on the fifth node

// get the geometry from the zGraph
model->FromZGraph(graph);

// perform the structural analysis as described in the specification

// get the result by a function like the following
zSpace::zPointArray = model->displacements.ToZPointArray();

// similarly, for axial strains etc


}