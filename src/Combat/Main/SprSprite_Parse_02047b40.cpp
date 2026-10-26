#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void SprSprite_Init(void* obj, int flag);
extern "C" void func_02047f70(void* obj, void* buf, unsigned int size, SafeAllocator* alloc);

struct Struct_02047b40_4;
struct Struct020478bc;

extern "C" void func_02047ed4(struct Struct_02047b40_4* obj, int* outSize, void* buf, unsigned int size, SafeAllocator* alloc);
extern "C" void func_020478bc(struct Struct020478bc* o, int arg1);

struct Struct_02047b40_5 {
    int count;
    void* buffer;
};

extern "C" void func_02048090(struct Struct_02047b40_5* obj, int count, SafeAllocator* alloc);

struct Struct_02047b40_6 {
    int size;
    unsigned short info;
    unsigned short unknown_6_;
};

struct Struct_02047b40_7 {
    unsigned char width;
    unsigned char height;
    unsigned char count;
    unsigned char pad3;
    Struct_02047b40_6* unknown_4_;
};

struct Struct_02047b40_8 {
    int a;
    int b;
    int c;
};

struct Struct_02047b40_9 {
    unsigned int count;
    Struct_02047b40_8* items;
};

struct Struct_02047b40 {
    unsigned short width;
    unsigned short height;
    unsigned int count;
};

struct Struct_02047b40_2 {
    unsigned short x;
    unsigned short y;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Obj02047b40 {
    char pad0[4];
    unsigned short mode;
    unsigned short groupCount;
    Struct_02047b40_7* groups;
    Struct_02047b40_9* unknown_c_;
    char pad10[4];
    Struct_02047b40_5 frames;
    char unknown_1c_[0x84 - 0x1c];
    unsigned char unknown_84_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char unknown_84_2_ : 6;
};

// Main, originally func_02047b40 (USA 0x02047b40, EUR 0x02047b50, JPN 0x02048960)
extern "C" ARM void SprSprite_Parse(struct Obj02047b40* obj, unsigned char* src, SafeAllocator* alloc) {
    unsigned char* data;
    unsigned int tail;
    int flag;
    Struct_02047b40_7* group;
    Struct_02047b40_6* tex;
    int g;
    int k;
    int n;
    Struct_02047b40* var8;
    Struct_02047b40_2* var9;
    unsigned int w;
    unsigned int h;
    unsigned int shift;
    unsigned int size;
    if (src == 0) {
        return;
    }
    flag = obj->unknown_84_0_;
    if (flag) {
        if (flag) {
            SprSprite_Init(obj, flag);
        }
        obj->unknown_84_0_ = 0;
    }
    memcpy(&obj->groupCount, src, 2);
    memcpy(&obj->mode, src + 2, 2);
    data = src + 4;
    group = obj->groups = (Struct_02047b40_7*)alloc->Allocate(obj->groupCount * 8);
    for (g = 0; g < obj->groupCount; g++, group++) {
        var8 = (Struct_02047b40*)data;
        data += 8;
        group->width = var8->width;
        group->height = var8->height;
        group->count = var8->count;
        tex = group->unknown_4_ = (Struct_02047b40_6*)alloc->Allocate(group->count * 8);
        for (k = 0; k < group->count; k++) {
            var9 = (Struct_02047b40_2*)data;
            h = 8 << var9->unknown_4_;
            shift = 0;
            data += 8;
            w = 8 << var9->unknown_6_;
            if (obj->mode == 3) {
                shift = 1;
                size = h * w;
                func_02047ed4((Struct_02047b40_4*)obj, &tex->size, data, size >> 1, alloc);
            } else {
                size = h * w;
                func_02047ed4((Struct_02047b40_4*)obj, &tex->size, data, size, alloc);
            }
            data += size >> shift;
            tex->info = (var9->unknown_6_ << 4) | var9->unknown_4_;
            tex->unknown_6_ = var9->x | ((group->height - var9->y - w) << 8);
            tex++;
        }
    }
    memcpy(&tail, data, 4);
    data += 4;
    if (tail <= 0x10) {
        func_02047f70(obj, data, 0x20, alloc);
    } else if (tail <= 0x100) {
        func_02047f70(obj, data, 0x200, alloc);
    } else {
        func_02047f70(obj, data, tail, alloc);
    }
    data += tail * 2;
    data += 0x1e;
    memcpy(&obj->frames, data, 4);
    data += 4;
    func_02048090(&obj->frames, obj->frames.count, alloc);
    if (obj->frames.count > 0) {
        for (n = 0; n < obj->frames.count; n++) {
            memcpy((char*)obj->frames.buffer + n * 0x1e, data, 0x1e);
            data += 0x1e;
        }
        Struct_02047b40_9* set = obj->unknown_c_ = (Struct_02047b40_9*)alloc->Allocate(obj->frames.count * 8);
        for (int m = 0; m < obj->frames.count; m++, set++) {
            memcpy(set, data, 4);
            data += 4;
            set->items = (Struct_02047b40_8*)alloc->Allocate(set->count * 12);
            Struct_02047b40_8* out = set->items;
            int* pa = (int*)data;
            data += set->count * 4;
            int* pb = (int*)data;
            data += set->count * 4;
            int* pc = (int*)data;
            data += set->count * 4;
            for (unsigned int i = 0; i < set->count; i++) {
                out->a = *pa;
                out->b = *pb;
                out->c = *pc;
                pa++;
                pb++;
                pc++;
                out++;
            }
        }
    }
    obj->unknown_84_0_ = 1;
    obj->flag1 = 1;
    if (obj->unknown_c_ != 0) {
        if (obj->unknown_c_->count == 0 && obj->frames.count == 1) {
            func_020478bc((Struct020478bc*)obj, 0);
        } else {
            func_020478bc((Struct020478bc*)obj, 1);
        }
    } else {
        func_020478bc((Struct020478bc*)obj, 0);
    }
}
