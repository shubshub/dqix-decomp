#include <globaldefs.h>

struct Node02064704 {
    char pad0[0xc];
    struct Node02064704* next;  // 0xc
};

extern "C" int Scenario_TestCondition(void*, struct Node02064704*, void*);

// USA: func_02064704
extern "C" ARM int func_02064704(void* a, struct Node02064704* node, void* c) {
    while (node != NULL) {
        if (Scenario_TestCondition(a, node, c) == 0) break;
        node = node->next;
    }
    return node == NULL;
}
