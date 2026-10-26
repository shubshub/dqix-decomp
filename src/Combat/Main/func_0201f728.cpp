#include <globaldefs.h>
#if defined(jpn)
enum { kAllocatorOffset = 4, Enum_0201f728_16 = 0xc, kListOffset = 0x6a8 };
#else
enum { kAllocatorOffset = 8, Enum_0201f728_16 = 0x10, kListOffset = 0x754 };
#endif
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Struct_0201d530 { int type; union { int i; float f; } value; };

struct Variant02030b0c { int tag; union { int i; float f; } u; };

extern int data_020fdc4c;

struct Struct_0201f728 {
    struct Struct_0201d530 x;
    struct Struct_0201d530 y;
};

struct Struct_0201f728_2 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short* data;
    int x;
    int y;
    struct Struct_0201f728_2* next;
};

// USA: func_0201f728
extern "C" ARM int func_0201f728(struct Struct_0201f728* arg0, int n) {
    if (n < 3) return 0;
    struct Struct_0201f728_2* node = (struct Struct_0201f728_2*)
        ((SafeAllocator*)*(char**)((char*)&data_020fdc4c + kAllocatorOffset))->Allocate(0x14);
    if (node == 0) return 0;
    node->type = 1;
    node->count = n - 2;
    node->data = (short*)
        ((SafeAllocator*)*(char**)((char*)&data_020fdc4c + kAllocatorOffset))->Allocate(node->count * 2);
    if (node->data == 0) return 0;
    node->x = (int)(((Script::Parameter*)&arg0->x)->ToFloat() * 4096.0f);
    struct Variant02030b0c* p = (struct Variant02030b0c*)((char*)arg0 + 0x10);
    node->y = (int)(((Script::Parameter*)&arg0->y)->ToFloat() * 4096.0f);
    for (int i = 0; i < node->count; i++) {
        node->data[i] = (short)((Script::Parameter*)p)->ToInt();
        p++;
    }
    struct Struct_0201f728_2* head = *(struct Struct_0201f728_2**)((char*)(*(void**)((char*)&data_020fdc4c + Enum_0201f728_16)) + kListOffset);
    node->id = head ? head->id + 1 : 1;
    node->next = *(struct Struct_0201f728_2**)((char*)(*(void**)((char*)&data_020fdc4c + Enum_0201f728_16)) + kListOffset);
    *(struct Struct_0201f728_2**)((char*)(*(void**)((char*)&data_020fdc4c + Enum_0201f728_16)) + kListOffset) = node;
    return 1;
}
