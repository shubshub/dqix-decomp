#include <globaldefs.h>

struct Node02064b24 {
    unsigned short id;
    char pad2[0x12];
    struct Node02064b24* next;
};

struct Obj02064b24 { char pad0[0xc]; void* nodeHead; };

extern "C" struct Obj02064b24* Scenario_FindTrigger(void*, int, void*);
extern "C" int Scenario_RunCommand(void*, struct Node02064b24*, void*);

// Main, originally LookupAndForEachNodeIfMatch02064b24 (USA 0x02064b24, EUR 0x02064b34, JPN 0x02065e10)
extern "C" ARM int Scenario_RunTriggerCommandsById(void* a, int mode, unsigned short id, void* c) {
    struct Obj02064b24* root = Scenario_FindTrigger(a, mode, c);
    if (root == NULL) return 0;
    *(int*)((char*)c + 0x30) = 0;
    struct Node02064b24* node = (struct Node02064b24*)root->nodeHead;
    for (; node != NULL; node = node->next) {
        if (node != NULL && node->id == id) {
            if (Scenario_RunCommand(a, node, c) == 0) return 0;
        }
    }
    return 1;
}
