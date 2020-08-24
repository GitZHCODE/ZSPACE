#include <zCore.h>
#include <geometry/zGraph.h>
#include "structural.h"

int main() {

// define the connectivity graph as a z graph
zSpace::zGraph graph;

zSpace::zPointArray positions = {
    zSpace::zVector(0, 0, 0),
    zSpace::zVector(1, 0, 0),
    zSpace::zVector(1, 1, 0),
    zSpace::zVector(0, 1, 0),
    zSpace::zVector(0.5, 0.5, 0.3)
};

// the edge connectivity of a tetrahedron
zSpace::zIntArray edgeConnects = {0, 1, 1, 2, 2, 3, 3, 0, 0, 4, 1, 4, 2, 4, 3, 4};

graph.create(positions, edgeConnects);

// define the first four nodes to have reactions, defined a simple load on the fifth node

structural::Input input;    
int counter = 0;    
for (auto p: positions)
    input.nodes.push_back(structural::Node(p.x, p.y, p.z, 0, counter++));

// assume the first four nodes are supported
for (int i = 0; i < 4; i++)
input.reactions.push_back(structural::NodeReaction(
    i,
    structural::NodeReaction::fixed,    
    structural::NodeReaction::fixed, 
    structural::NodeReaction::fixed, 
    structural::NodeReaction::fixed,
    structural::NodeReaction::fixed, 
    structural::NodeReaction::fixed
));

// take the connectivity from the zGraph
for (int i = 0; i < edgeConnects.size()/2; i++)
    input.frameElements.push_back(structural::FrameElement(edgeConnects[2 * i], edgeConnects[2 * i + 1]));

// apply one load to the fifth element:
structural::Load load1(0, 0, -10.0, 4);

// define just one load case
structural::LoadCase loadCase(input, {load1});

// perform the structural analysis
structural::LoadCaseResult result = structural::analyze(input, {loadCase});

// get the result by a function like the following
auto displacements = result.displacements;

// copy construct a new graph
auto displacedGraph = graph;

// read the displacements out of the load result;
int i = 0;
for (auto d : displacements) 
    displacedGraph.vertexPositions[i++] = zSpace::zVector(d.dx, d.dy, d.dz);


// similary, obtain axial strains etc

return 0;
}