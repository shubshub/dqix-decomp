#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct02030b7c { int field0; void* field4; };
struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" int STD_GetStringLength(const char* s);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

struct Struct_ov015_0218b6e4 { int a; int b; };
struct Struct_ov015_0218ba1c { void* f0; Struct_ov015_0218b6e4* arr; void* f8; int count; };
extern "C" void func_ov015_0218ba1c(struct Struct_ov015_0218ba1c* obj, struct Struct_ov015_0218b6e4* src);

struct NamedNode0218b6e4 {
    char* name;
    unsigned short val1;
    unsigned char val2;
    NamedNode0218b6e4* next;
};

extern AllocatorUnion g_mainAllocator;
extern struct Struct_ov015_0218ba1c* data_ov015_02194560;

// USA: func_ov015_0218b6e4
extern "C" ARM int func_ov015_0218b6e4(char* obj, int count) {
    char* base = obj;
    obj = obj + 8;
    char* n0 = (char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)base))->ToString();
    struct Struct_ov015_0218b6e4 entry;
    entry.a = 0;
    entry.b = 0;
    if (n0 != 0) {
        int len = STD_GetStringLength(n0);
        char* buf = (char*)AllocatorUnion_AllocateRounded(&g_mainAllocator, len + 1);
        entry.a = (int)buf;
        if (buf != 0) {
            strcpy(buf, n0);
        }
    }

    int i = 1;
    while (i < count) {
        struct NamedNode0218b6e4* node;
        char* name = (char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)obj))->ToString();
        int v1 = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 8)))->ToInt();
        char* var9 = obj + 0x10;
        obj = obj + 0x18;
        int v2 = ((Script::Parameter*)((struct Variant02030b0c*)var9))->ToInt();

        node = (struct NamedNode0218b6e4*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xc);
        node->name = 0;
        node->val1 = 0;
        node->val2 = 0;
        node->next = 0;
        if (name != 0) {
            int len = STD_GetStringLength(name);
            char* buf = (char*)AllocatorUnion_AllocateRounded(&g_mainAllocator, len + 1);
            node->name = buf;
            if (buf != 0) {
                strcpy(buf, name);
            }
        }
        node->val1 = (unsigned short)v1;
        node->val2 = (unsigned char)v2;

        struct NamedNode0218b6e4** link = (struct NamedNode0218b6e4**)&entry.b;
        while (*link != 0) {
            link = &(*link)->next;
        }
        *link = node;

        i += 3;
    }

    func_ov015_0218ba1c(data_ov015_02194560, &entry);
    return 1;
}
