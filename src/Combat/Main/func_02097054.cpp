#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Struct_02097054 {
    char unknown_0_[0xc];
    unsigned char unknown_c_;
    char unknown_d_[0x1f];
    union {
        char** strings;
        unsigned int unknown1_2c_;
    };
};
struct Struct_02097054_2 {
    unsigned short count;
    unsigned short unknown_2_;
    unsigned int unknown_4_0_ : 31;
    unsigned int unknown_7_7_ : 1;
    Struct_02097054 nodes[1];
};
struct Struct_02097054_3 {
    unsigned short count;
    unsigned short unknown_2_;
    unsigned int unknown_4_0_ : 31;
    unsigned int unknown_7_7_ : 1;
    Struct_02097054* nodes;
    unsigned int* strings;
};
struct Struct_02097054_4 {
    unsigned short count;
    char unknown_2_[6];
    Struct_02097054* node;
    int unknown_c_;
};
struct Struct_02096fd8;
struct Struct_02097000_2;
struct Struct_02097000;
struct Struct_02097054_5;
struct Struct_02097054_6;
extern "C" int func_02096fd8(Struct_02096fd8*);
extern "C" int func_02097000(Struct_02097000_2*, void (*)(Struct_02097000_2*, Struct_02097000*));
extern "C" Struct_02097054_6* func_020971a8(Struct_02097054_5*, int, int (*)(Struct_02097054_6*));
extern "C" short func_02096f78(unsigned char*);
extern "C" char* func_02096f80(Struct_02097054_3*, unsigned int, int);
extern "C" char* func_020da150(SafeAllocator*, const char*);

// USA: func_02097054
extern "C" ARM void func_02097054(Struct_02097054_4* dst, SafeAllocator* allocator, Struct_02097054_2* source, int unused, short key) {
    Struct_02097054_3 header;
    memset(dst, 0, 0x10);
    if (key < 0) return;
    if (source != 0) {
        memcpy(&header, source, 8);
        header.nodes = source->nodes;
        header.strings = (unsigned int*)((char*)source + (8 + func_02096fd8((Struct_02096fd8*)&header)));
        if (header.unknown_7_7_ == 0) {
            func_02097000((Struct_02097000_2*)&header, 0);
            header.unknown_7_7_ = 1;
            source->unknown_7_7_ = 1;
        }
    }
    Struct_02097054* found = (Struct_02097054*)func_020971a8((Struct_02097054_5*)&header, key, (int (*)(Struct_02097054_6*))func_02096f78);
    Struct_02097054* copy = (Struct_02097054*)allocator->Allocate(0x30);
    if (found == 0 || copy == 0) return;
    memcpy(copy, found, 0x30);
    short var3 = copy->unknown_c_;
    char** output = (char**)allocator->Allocate(var3 * 4);
    unsigned int* input = (unsigned int*)(header.nodes + header.count) + found->unknown1_2c_;
    copy->strings = output;
    for (int i = 0; i < var3; i++) {
        unsigned int var7 = *input;
        input++;
        char* text = func_02096f80(&header, var7, 0);
        *output = func_020da150(allocator, text);
        output++;
    }
    dst->count = 1;
    dst->node = copy;
}
