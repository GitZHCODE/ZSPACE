#pragma once
#include <vector>

namespace structural
{

    class Node
    {
        double x;
        double y;
        double z;
        double radius;
        int id;

    public:
        Node(double, double, double, double, int);
    };
    class NodeReaction
    {
    public:
        enum ReactionType
        {
            fixed,
            free
        };
        int nodeid;
        NodeReaction(int, ReactionType, ReactionType, ReactionType, ReactionType, ReactionType, ReactionType);

    private:
        ReactionType x;
        ReactionType y;
        ReactionType z;
        ReactionType xx;
        ReactionType yy;
        ReactionType zz;
    };
    class FrameElement
    {
        int node1;
        int node2;
        // and some fields for cross section areas and material properties
    public:
        FrameElement(int, int);
    };
    class Load
    {
        double Fx;
        double Fy;
        double Fz;
        int id;

    public:
        Load(double, double, double, int);
    };

    // the geometrical input
    class Input
    {
    public:
        std::vector<Node> nodes;
        std::vector<NodeReaction> reactions;
        std::vector<FrameElement> frameElements;
    };
    class LoadCase
    {
        const Input *input;
        // the following can also be empty, in which case the load is just due to self-weight
        std::vector<Load> appliedLoads;

    public:
        LoadCase(const Input &input, const std::vector<Load> &appliedLoads);
    };
    // the result
    class Displacement
    {
    public:
        double dx;
        double dy;
        double dz;
    };
    class LoadCaseResult
    {
    public:
        const LoadCase *loadCase;
        std::vector<Displacement> displacements;
    };

    static LoadCaseResult analyze(const Input &input, const std::vector<LoadCase> loadcases);
} // namespace structural