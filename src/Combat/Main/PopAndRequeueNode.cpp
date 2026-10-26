#include <globaldefs.h>

void VCountIrq_PushDisable(void);
void BlankFunction020d84e4(void);
void BlankFunction020d84e8(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void VCountIrq_PopDisable(void);
int LinkSession_IsActive(int* obj);

struct QNode0205e1e4 {
    char pad[0x18];
    struct QNode0205e1e4* next;
};
struct QList0205e1e4 {
    struct QNode0205e1e4* head;
    struct QNode0205e1e4* tail;
    int count;
};
struct QNode0205e1e4* DequeueNode(struct QList0205e1e4* list);

struct QNode0205e18c {
    char pad[0x18];
    struct QNode0205e18c* next;
};
struct QList0205e18c {
    struct QNode0205e18c* head;
    struct QNode0205e18c* tail;
    int count;
};
void EnqueueNode(struct QList0205e18c* list, struct QNode0205e18c* node);

// USA: func_0205e41c
ARM struct QNode0205e1e4* PopAndRequeueNode_0205e41c(void* obj, int* outPtr) {
    struct QNode0205e1e4* node;
    VCountIrq_PushDisable();
    BlankFunction020d84e4();
    node = NULL;
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        node = DequeueNode((struct QList0205e1e4*)((char*)obj + 0x1518));
        if (node == NULL) {
            *outPtr = -1;
            node = NULL;
        } else {
            EnqueueNode((struct QList0205e18c*)((char*)obj + 0x1500), (struct QNode0205e18c*)node);
            *outPtr = *(short*)((char*)node + 0x14);
        }
    }
    BlankFunction020d84e8();
    VCountIrq_PopDisable();
    return node;
}
