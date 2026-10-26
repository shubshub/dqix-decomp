#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_020e25cc(signed char* p);
struct Struct02020520;
extern "C" void GlyphDestinationRect_Clear(struct Struct02020520* s);
struct Struct_020e1568;
extern "C" void func_020e1568(struct Struct_020e1568* s);
extern "C" void func_020e1588(unsigned char* p);
extern "C" void func_020e15f8(char* obj, int arg1, int arg2);
struct ClearTarget0205a234;
extern "C" void func_0205a234(struct ClearTarget0205a234* target);

struct Struct_020e2490 {
    void* field0;
    void* field4;
    void* field8;
    unsigned char* fieldC;
    unsigned char* field10;
    signed char byte14;
    signed char unknown_15_;
    signed char unknown_16_;
    signed char unknown_17_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    signed char unknown_1e_;
    signed char pad1f;
    void* field20;
};

// USA: func_020e2490
extern "C" ARM void func_020e2490(struct Struct_020e2490* obj, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag) {
    obj->unknown_1c_ = 0;
    obj->unknown_1e_ = 8;
    obj->unknown_18_ = 0;
    obj->unknown_1a_ = 0;
    obj->unknown_16_ = 0;
    func_020e25cc((signed char*)obj);

    obj->field0 = alloc->Allocate(count * 0xc);
    obj->field4 = alloc->Allocate(0xc);
    obj->field8 = alloc->Allocate(count * 0xc);
    obj->fieldC = (unsigned char*)alloc->Allocate(0x40);
    obj->field10 = (unsigned char*)alloc->Allocate(0x4c);
    obj->field20 = arg3;

    int i;
    for (i = 0; i < count; i++) {
        GlyphDestinationRect_Clear((struct Struct02020520*)((char*)obj->field0 + i * 0xc));
        func_020e1568((struct Struct_020e1568*)((char*)obj->field8 + i * 0xc));
    }

    func_020e1588(obj->fieldC);
    *(void**)(obj->fieldC + 0x0) = obj->field0;
    *(void**)(obj->fieldC + 0x4) = obj->field4;
    *(void**)(obj->fieldC + 0x8) = obj->field8;
    obj->fieldC[0x3c] = (unsigned char)count;
    obj->fieldC[0x3d] = flag;

    func_020e15f8((char*)obj->field10, arg1, arg2);
    *(void**)(obj->field10 + 0x4) = obj->fieldC;

    if (obj->field20 != NULL) {
        func_0205a234((struct ClearTarget0205a234*)obj->field20);
    }
}
