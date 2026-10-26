#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

// Local copies of Elem02028170 and GrottoTileLists0201a300 (World/GrottoTileGraph.h)
struct GraphNode {
    unsigned char id;
    unsigned char pad1[3];
    short x;
    short y;
    short z;
    unsigned char pad2[6];
};

struct NodeGraph {
    unsigned char pad0[2];
    unsigned char tileCount;
    unsigned char pad1[1];
    struct GraphNode* tiles;
};

// Main, originally func_02028460 (USA 0x02028460, EUR 0x02028470, JPN 0x02027ccc)
extern "C" ARM int NodeGraph_FindClosestNode(struct NodeGraph* graph, Vector3fix* position) {
    if (graph->tileCount == 0) return 0;

    struct GraphNode* nodes = graph->tiles;
    Vector3fix nodePosition0;
    nodePosition0.x = (int)nodes[0].x << 12;
    nodePosition0.y = (int)nodes[0].y << 12;
    nodePosition0.z = (int)nodes[0].z << 12;
    int closestIndex = 0;
    int closestDistance = Vector3fix_Distance(position, &nodePosition0);

    for (int i = 1; i < graph->tileCount; i++) {
        Vector3fix nodePosition;
        nodePosition.x = (int)nodes[i].x << 12;
        nodePosition.y = (int)nodes[i].y << 12;
        nodePosition.z = (int)nodes[i].z << 12;
        int distance = Vector3fix_Distance(position, &nodePosition);
        if (distance < closestDistance) {
            closestIndex = i;
            closestDistance = distance;
        }
    }
    return closestIndex;
}
