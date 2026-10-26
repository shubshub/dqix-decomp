#include <globaldefs.h>

// A BmdjSceneElement (World/BmdjScriptNode.h; ZoneResourceRuntimeNode in World/ZoneResourceTree.h): its next
// sibling link (BmdjSceneElement::unknown30)
struct Node020130e0 {
    char unk[0x30];
    struct Node020130e0* next;
};

// Main, originally AppendNodeToList020130e0 (USA 0x020130e0, EUR 0x020130f0, JPN 0x02012ea8)
extern "C" ARM void BmdjSceneElement_AppendSibling(struct Node020130e0* first, struct Node020130e0* node) {
    struct Node020130e0* last = first->next;
    if (last == 0) {
        first->next = node;
        return;
    }
    while (last->next != 0) {
        last = last->next;
    }
    last->next = node;
}
