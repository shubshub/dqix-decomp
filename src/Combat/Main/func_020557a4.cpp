#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020546c8;
extern "C" void* func_02055168(struct Struct_020546c8* p);

struct Struct_020557a4;
extern "C" float func_020578e8(Struct_020557a4* a, Struct_020557a4* b);

struct Struct_020557a4_2 {
    char pad0[4];
    int field4;
    char pad1[0x28];
    void* unknown_30_;
    char pad2[0x18];
    float field4c;
    float unknown_50_;
    float field54;
    float unknown_58_;
    unsigned short unknown_5c_;
    unsigned short unknown_5e_;
    unsigned short field60;
    unsigned short unknown_62_;
};

// USA: func_020557a4
extern "C" ARM void func_020557a4(struct Struct_020557a4_2* obj) {
    void* var0 = func_02055168((struct Struct_020546c8*)obj->unknown_30_);

    {
        if (*(unsigned char*)((char*)var0 + 0x10) <= 1)
            goto b2;
        if (*(unsigned char*)((char*)var0 + 0x10) <= obj->unknown_5c_)
            goto b2;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0xec))->GetNthElement(obj->unknown_5c_);
        if (elem == NULL)
            goto b2;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4)
            goto b2;
        obj->unknown_5c_ = obj->unknown_5c_ + 1;
        if (obj->unknown_5c_ >= *(unsigned char*)((char*)var0 + 0x10)) {
            obj->field4c = 0;
            goto b2;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0xec))->GetNthElement(obj->unknown_5c_);
        if (elem2 == NULL)
            goto b2;
        obj->field4c = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
    }

b2:
    {
        if (*(unsigned char*)((char*)var0 + 0x11) <= 1)
            goto b3;
        if (*(unsigned char*)((char*)var0 + 0x11) <= obj->unknown_5e_)
            goto b3;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0xf8))->GetNthElement(obj->unknown_5e_);
        if (elem == NULL)
            goto b3;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4)
            goto b3;
        obj->unknown_5e_ = obj->unknown_5e_ + 1;
        if (obj->unknown_5e_ >= *(unsigned char*)((char*)var0 + 0x11)) {
            obj->unknown_50_ = 0;
            goto b3;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0xf8))->GetNthElement(obj->unknown_5e_);
        if (elem2 == NULL)
            goto b3;
        obj->unknown_50_ = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
    }

b3:
    {
        if (*(unsigned char*)((char*)var0 + 0x12) <= 1)
            goto b4;
        if (*(unsigned char*)((char*)var0 + 0x12) <= obj->field60)
            goto b4;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x104))->GetNthElement(obj->field60);
        if (elem == NULL)
            goto b4;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4)
            goto b4;
        obj->field60 = obj->field60 + 1;
        if (obj->field60 >= *(unsigned char*)((char*)var0 + 0x12)) {
            obj->field54 = 0;
            goto b4;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x104))->GetNthElement(obj->field60);
        if (elem2 == NULL)
            goto b4;
        obj->field54 = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
    }

b4:
    {
        if (*(unsigned char*)((char*)var0 + 0x13) <= 1)
            goto done;
        if (*(unsigned char*)((char*)var0 + 0x13) <= obj->unknown_62_)
            goto done;
        SignedAllocatorHeader* elem =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x110))->GetNthElement(obj->unknown_62_);
        if (elem == NULL)
            goto done;
        if ((unsigned int)(**(int**)elem) >= (unsigned int)obj->field4)
            goto done;
        obj->unknown_62_ = obj->unknown_62_ + 1;
        if (obj->unknown_62_ >= *(unsigned char*)((char*)var0 + 0x13)) {
            obj->unknown_58_ = 0;
            goto done;
        }
        SignedAllocatorHeader* elem2 =
            ((SignedAllocatorList*)((char*)obj->unknown_30_ + 0x110))->GetNthElement(obj->unknown_62_);
        if (elem2 == NULL)
            goto done;
        obj->unknown_58_ = func_020578e8((Struct_020557a4*)elem, (Struct_020557a4*)elem2);
    }

done:
    ;
}
