#include <globaldefs.h>

struct Node02064530 {
    char pad0[0x14];
    struct Node02064530* next;  // 0x14
};

extern "C" int Scenario_RunCommand(void*, struct Node02064530*, void*);

// Main, originally ForEachNodeAllMatch02064530 (USA 0x02064530, EUR 0x02064540, JPN 0x0206581c)
extern "C" ARM int Scenario_RunCommands(void* a, struct Node02064530* node, void* c) {
    while (node != NULL) {
        if (Scenario_RunCommand(a, node, c) == 0) return 0;
        node = node->next;
    }
    return 1;
}
