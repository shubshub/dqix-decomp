#include <globaldefs.h>

// Local copy of GrottoTileLists0201a300 (World/GrottoTileGraph.h)
struct InitStruct {
    unsigned char tileCapacity;
    unsigned char pairCapacity;
    unsigned char tileCount;
    unsigned char pairCount;
    int tiles;
    int pairs;
    int unknownC;
    int unknown10;
    int unknown14;
    int unknown18;
    int linked;
    int unknown20;
    unsigned char originCapacity;
    unsigned char originCount;
    int origins;
};

// Main, originally InitializeStruct_020280b0 (USA 0x020280b0, EUR 0x020280c0, JPN 0x0202791c)
ARM void NodeGraph_Reset(struct InitStruct* graph) {
    graph->linked = 0;
    graph->tileCapacity = 0;
    graph->pairCapacity = 0;
    graph->tileCount = 0;
    graph->pairCount = 0;
    graph->tiles = 0;
    graph->pairs = 0;
    graph->unknownC = 0;
    graph->unknown10 = 0;
    graph->unknown14 = 0;
    graph->unknown18 = 0;
    graph->unknown20 = 1;
    graph->originCapacity = 0;
    graph->originCount = 0;
    graph->origins = 0;
}
