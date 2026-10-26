#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int u; };

struct Struct_ov000_02169a40;
extern "C" void func_ov000_02169a40(struct Struct_ov000_02169a40* s);

struct Struct_ov000_02169bf0 {
    unsigned short* data;
    unsigned short count;
    unsigned int unknown_8_;
    struct Struct_ov000_02169bf0* next;
};

struct Struct_ov000_02184264_3 {
    struct Struct_ov000_02169bf0* head;
    struct Struct_ov000_02169bf0* tail;
    SafeAllocator* alloc;
};
extern struct Struct_ov000_02184264_3 data_ov000_02184264;

// USA: func_ov000_02169bf0
extern "C" ARM int func_ov000_02169bf0(struct Variant02030b0c* v, int count) {
    struct Struct_ov000_02169bf0* node = (struct Struct_ov000_02169bf0*)data_ov000_02184264.alloc->Allocate(0x10);
    func_ov000_02169a40((struct Struct_ov000_02169a40*)node);
    node->count = count;
    if (node->count != 0) {
        unsigned short buffer[0x20];
        unsigned short var2 = 0;
        int i = 0;
        for (; i < node->count; v++, i++) {
            buffer[i] = (unsigned short)((Script::Parameter*)v)->ToInt();
            if (buffer[i] == 1) var2 = 1;
        }
        if (var2) {
            buffer[node->count] = 2;
            buffer[node->count + 1] = 0xdb;
            node->count = node->count + 2;
        }
        node->data = (unsigned short*)data_ov000_02184264.alloc->Allocate(node->count * 2);
        memcpy(node->data, buffer, node->count * 2);
    }
    struct Struct_ov000_02169bf0* tail = data_ov000_02184264.tail;
    if (tail == 0) {
        data_ov000_02184264.tail = node;
    } else {
        tail->next = node;
        data_ov000_02184264.tail = node;
    }
    if (!data_ov000_02184264.head) {
        data_ov000_02184264.head = node;
    }
    return 1;
}
