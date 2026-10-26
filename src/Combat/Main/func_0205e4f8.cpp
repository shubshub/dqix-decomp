#include <globaldefs.h>

extern "C" void VCountIrq_PushDisable(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* LinkSession_GetOwnRecord(void* base);
extern "C" void VCountIrq_PopDisable(void);

struct Struct_0205e4f8 {
    unsigned char id;
    unsigned char pad[0x18 - 1];
    struct Struct_0205e4f8* next;
};

struct Elem0205e4f8 {
    unsigned char pad[0x10];
    unsigned char id;
    unsigned char pad2[0x14 - 0x11];
};

// USA: func_0205e4f8
extern "C" ARM int func_0205e4f8(void* obj, int id) {
    int result = 0;
    VCountIrq_PushDisable();
    struct Struct_0205e4f8* node = *(struct Struct_0205e4f8**)((char*)obj + 0x150c);
    while (node != NULL) {
        if (node->id == id) {
            result = 1;
            break;
        }
        node = node->next;
    }
    if (!result) {
        struct Elem0205e4f8* arr = (struct Elem0205e4f8*)LinkSession_GetOwnRecord(LinkSession_GetInstance());
        for (int i = 0; i < 5; i++) {
            if (arr[i].id == id) {
                result = 1;
                break;
            }
        }
    }
    VCountIrq_PopDisable();
    return result;
}
