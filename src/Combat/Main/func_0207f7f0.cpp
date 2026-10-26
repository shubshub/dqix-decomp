#include <globaldefs.h>
#include "Combat/MenuNodeChain.h"

// USA: func_0207f7f0
extern "C" ARM void func_0207f7f0(Manager0207f7f0* mgr, Node0207f7f0* nodes, int count) {
    unsigned char i;
    mgr->nodes = nodes;
    mgr->count = (unsigned char)count;
    if (mgr->nodes != NULL && mgr->count != 0) {
        for (i = 1; i < mgr->count; i++)
            mgr->nodes[i].prev = &mgr->nodes[i - 1];
    }
}
