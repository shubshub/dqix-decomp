#include <globaldefs.h>

extern "C" void VCountIrq_PushDisable(void);
extern "C" void func_020d84e4(void);
extern "C" void func_020d84e8(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void VCountIrq_PopDisable(void);
extern "C" int LinkSession_IsActive(int* obj);

struct Struct_0205e1e4_2 {
    char pad[0x18];
    struct Struct_0205e1e4_2* next;
};
struct Struct_0205e1e4 {
    struct Struct_0205e1e4_2* head;
    struct Struct_0205e1e4_2* tail;
    int count;
};
extern "C" struct Struct_0205e1e4_2* func_0205e1e4(struct Struct_0205e1e4* list);

struct Struct_0205e18c_2 {
    char pad[0x18];
    struct Struct_0205e18c_2* next;
};
struct Struct_0205e18c {
    struct Struct_0205e18c_2* head;
    struct Struct_0205e18c_2* tail;
    int count;
};
extern "C" void func_0205e18c(struct Struct_0205e18c* list, struct Struct_0205e18c_2* node);

// USA: func_0205e41c
extern "C" ARM struct Struct_0205e1e4_2* func_0205e41c(void* obj, int* outPtr) {
    struct Struct_0205e1e4_2* node;
    VCountIrq_PushDisable();
    func_020d84e4();
    node = NULL;
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        node = func_0205e1e4((struct Struct_0205e1e4*)((char*)obj + 0x1518));
        if (node == NULL) {
            *outPtr = -1;
            node = NULL;
        } else {
            func_0205e18c((struct Struct_0205e18c*)((char*)obj + 0x1500), (struct Struct_0205e18c_2*)node);
            *outPtr = *(short*)((char*)node + 0x14);
        }
    }
    func_020d84e8();
    VCountIrq_PopDisable();
    return node;
}
