#include <globaldefs.h>

struct Struct0205e16c;
extern "C" ARM void LinkMessageList_Clear(struct Struct0205e16c* p);
extern "C" void LinkMessageQueue_Reset(void* queue);

// One message node of the link message queue (data_02100044), func_0205e57c's Node0205e57c.
struct MessageNode_0202c7bc {
    unsigned char message[0x14];
    short sourceSlot;     // func_0205e57c: the party slot whose record an incoming message came from
    unsigned short flags;
    struct MessageNode_0202c7bc* next;
};

// The queue: 0xc0 nodes (0x1500 bytes), then its free (+0x1500), pending (+0x150c) and active (+0x1518) lists.
enum {
    kFreeListOffset = 0x1500,
    kPendingListOffset = 0x150c,
    kActiveListOffset = 0x1518,
};

// Main, originally ResetBattleArray0202c7bc (USA 0x0202c7bc, EUR 0x0202c7cc, JPN 0x0202c32c)
extern "C" ARM void* LinkMessageQueue_Construct(void* queue) {
    struct MessageNode_0202c7bc* node = (struct MessageNode_0202c7bc*)queue;
    struct MessageNode_0202c7bc* end = (struct MessageNode_0202c7bc*)((char*)queue + kFreeListOffset);
    do {
        node->sourceSlot = 0;
        node->flags = 0;
        node->next = 0;
        node++;
    } while (node < end);
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)queue + kFreeListOffset));
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)queue + kPendingListOffset));
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)queue + kActiveListOffset));
    LinkMessageQueue_Reset(queue);
    return queue;
}
