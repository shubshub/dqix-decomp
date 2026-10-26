#include <globaldefs.h>
#include "Combat/SearchEntry.h"

extern "C" void* memset(void* dst, int value, unsigned int length);

struct Struct0205e16c;
extern "C" ARM void LinkMessageList_Clear(struct Struct0205e16c* p);

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

extern "C" void* LinkSession_GetInstance(void);
extern "C" void LinkSession_UpdateMemberCount(void);
extern "C" void* LinkSession_GetOwnRecord(void* base);

struct SearchStruct;

struct Elem0205e22c {
    unsigned char pad[0x10];
    unsigned char field10;
    unsigned char pad2[0x14 - 0x11];
};

// Main, originally func_0205e22c (USA 0x0205e22c, EUR 0x0205e23c, JPN 0x0205f518)
extern "C" ARM void LinkMessageQueue_Reset(void* obj) {
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)obj + 0x1500));
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)obj + 0x150c));
    LinkMessageList_Clear((struct Struct0205e16c*)((char*)obj + 0x1518));

    memset(obj, 0, 0x1500);

    struct Struct_0205e18c_2* nodes = (struct Struct_0205e18c_2*)obj;
    for (int i = 0; i < 0xc0; i++) {
        func_0205e18c((struct Struct_0205e18c*)((char*)obj + 0x1500), &nodes[i]);
    }

    void* base = LinkSession_GetInstance();
    LinkSession_UpdateMemberCount();

    struct Elem0205e22c* arr = (struct Elem0205e22c*)LinkSession_GetOwnRecord(base);
    memset(arr, 0, 0x74);

    for (int j = 0; j < 5; j++) {
        arr[j].field10 = 0xff;
    }

    int idx = 0;
    int off = 0;
    int size = 0x74;
    for (; idx < 4; idx++) {
        void* entry = LinkSession_GetReceivedRecord((struct SearchStruct*)base, idx);
        if (entry != NULL) {
            memset(entry, off, size);
        }
    }

    memset((char*)obj + 0x1524, 0xff, 0x20);
}
