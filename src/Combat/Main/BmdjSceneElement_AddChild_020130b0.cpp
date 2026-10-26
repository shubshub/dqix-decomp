#include <globaldefs.h>

// A BmdjSceneElement (World/BmdjScriptNode.h; ZoneResourceRuntimeNode in World/ZoneResourceTree.h): its parent,
// first child and next sibling links (BmdjSceneElement::parent, linkedElement2c, unknown30)
struct ListNode {
    char unk[0x28];
    struct ListNode* parent;
    struct ListNode* firstChild;
    struct ListNode* next;
};

// Main, originally AppendToNodeList_020130b0 (USA 0x020130b0, EUR 0x020130c0, JPN 0x02012e78)
ARM void BmdjSceneElement_AddChild(struct ListNode* parent, struct ListNode* child) {
    struct ListNode* sibling;
    child->parent = parent;
    sibling = parent->firstChild;
    if (sibling == 0) {
        parent->firstChild = child;
        return;
    }
    while (sibling->next != 0) {
        sibling = sibling->next;
    }
    sibling->next = child;
}
