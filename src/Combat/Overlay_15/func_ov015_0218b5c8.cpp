#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct02030b7c;
struct Variant02030b0c;
extern "C" int STD_GetStringLength(const char* s);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

struct Struct_ov015_0218b5c8 {
    int a;
    int b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};
struct Struct_ov015_0218b9d4 {
    Struct_ov015_0218b5c8* arr;
    int pad4;
    int count;
};
extern "C" void func_ov015_0218b9d4(struct Struct_ov015_0218b9d4* list, struct Struct_ov015_0218b5c8* src);

extern AllocatorUnion g_mainAllocator;
extern struct Struct_ov015_0218b9d4* data_ov015_02194560;

// USA: func_ov015_0218b5c8
extern "C" ARM int func_ov015_0218b5c8(char* obj) {
    char* n1 = (char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)obj))->ToString();
    char* n2 = (char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)(obj + 8)))->ToString();
    int v1 = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 0x10)))->ToInt();
    int v2 = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 0x18)))->ToInt();
    int v3 = ((Script::Parameter*)((struct Variant02030b0c*)(obj + 0x20)))->ToInt();

    struct Struct_ov015_0218b5c8 entry;
    entry.a = 0;
    entry.b = 0;
    entry.c = 0;
    entry.d = 0;
    entry.e = 0;

    if (n1 != 0) {
        int len = STD_GetStringLength(n1);
        char* buf = (char*)AllocatorUnion_AllocateRounded(&g_mainAllocator, len + 1);
        entry.a = (int)buf;
        if (buf != 0) {
            strcpy(buf, n1);
        }
    }
    if (n2 != 0) {
        int len = STD_GetStringLength(n2);
        char* buf = (char*)AllocatorUnion_AllocateRounded(&g_mainAllocator, len + 1);
        entry.b = (int)buf;
        if (buf != 0) {
            strcpy(buf, n2);
        }
    }

    entry.c = (unsigned short)v1;
    entry.d = (unsigned char)v2;
    entry.e = (unsigned char)v3;
    func_ov015_0218b9d4(data_ov015_02194560, &entry);
    return 1;
}
