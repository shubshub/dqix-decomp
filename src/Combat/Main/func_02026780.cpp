#include <globaldefs.h>
#include "World/LootableContainer.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Matrix.h"
struct Struct_02020554;

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
extern "C" void* Zone3D_GetInstance(void);

extern "C" void func_02026644(char* arg0);
extern "C" void func_020269e4(char* arg0, const void* arg1);

struct Cont02026780 {
    unsigned short uniqueID;
    unsigned short itemIDOrRank;
    unsigned short lock : 2;
    unsigned short lootType : 2;
    unsigned short containerType : 3;
    short angleOrCupboardNode;
    Vector3fix position;
    struct Cont02026780* pNext;
};

struct Struct_02026780_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    char* unknown_4_;
    fix32_t unknown_8_;
    fix32_t unknown_c_;
    struct Struct_02026780_5* unknown_10_;
};

struct Struct_02026780 {
#if defined(jpn)
    unsigned char unknown_0_[0x6a8];
#else
    unsigned char unknown1_0_[0x754];
#endif
    struct Struct_02026780_5* unknown_754_;
    unsigned char unknown_758_[0x22];
    unsigned char unknown_77a_;
    unsigned char unknown_77b_[1];
    char* unknown_77c_;
    unsigned char unknown_780_;
    unsigned char unknown_781_[0x9b8 - 0x781];
    unsigned char unknown_9b8_;
};

struct Struct_02026780_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned int unknown_c_;
    Vector3fix unknown_10_;
};

struct Struct_02026780_3 {
    char unknown_0_[4];
    Struct_02026780_4* unknown_4_;
    unsigned short unknown_8_;
};

// USA: func_02026780
extern "C" ARM int func_02026780(Struct_02020554* arg0, void* arg1, unsigned int arg2) {
    Struct_02026780* var0 = (Struct_02026780*)arg0;
    char var1[0x800];
    SafeAllocator var2;
    Struct_02026780_3 var3;
    Struct_02026780_2 var4;
    int var5;
    int var6;
    fix32_t var7;
    fix32_t var8;
    struct Struct_02026780_5* var9;

    if (var0->unknown_77a_ == 0 || var0->unknown_77c_ == 0) {
        return 0;
    }

    if (func_0202c540(func_0202ae18()) != 0) {
        func_02026644((char*)var0);
        return 0;
    }

    Zone3D_GetInstance();
    alloc.ResetAllocatorPointer();
    alloc.ResetAllocatorPointer();
    alloc.CreateTypeA(buffer, sizeof(buffer));

    var0->unknown_780_ = 0;

    for (var5 = 0; var5 < var0->unknown_77a_; var5++) {
        var7 = 0;
        var8 = var7;
        var9 = var0->unknown_754_;
        var6 = 1;

        while (var9 != 0 && var6) {
            if (var9->unknown_0_ == 1) {
                int var10 = 0;
                while (var10 < var9->unknown_2_ && var6) {
                    if (*(unsigned short*)(var9->unknown_4_ + var10 * 2)
                        == *(unsigned short*)(var0->unknown_77c_ + var5 * 0x1a)) {
                        var7 = var9->unknown_8_;
                        var8 = var9->unknown_c_;
                        var6 = 0;
                    }
                    var10++;
                }
            }
            var9 = var9->unknown_10_;
        }

        var2.Reset();
        ((LootableContainerManager*)&var3)->Reset();
        ((LootableContainerManager*)&var3)->Reset();

        ((LootableContainerManager*)&var3)->LoadZoneContainers(
            arg1, arg2, var0->unknown_77c_ + var5 * 0x1a + 2, &var2);

        for (Cont02026780* c = mgr.pContainerList_; c != 0; c = c->pNext) {
            VectorizedMemset(&rec, 0, sizeof(rec));
            rec.id = c->uniqueID;
            rec.f2 = c->lock;
            rec.f4 = c->lootType;
            rec.f6 = c->containerType;
            rec.pos = c->position;

            if (var4.unknown_6_ == 0) {
                if (var11->unknown_2_ == 0) {
                    var4.unknown_8_ = 0;
                } else {
                    var4.unknown_8_ = 1;
                }
                var4.unknown_a_ = var4.unknown_8_;
                if (!var6) {
                    var4.unknown_10_.x = var7 + fix32_Divide(var11->unknown_8_.x, 9830);
                    var4.unknown_10_.z = var8 + fix32_Divide(var11->unknown_8_.z, 9830);
                }
                func_020269e4((char*)var0, &var4);
            }
        }

        ((LootableContainerManager*)&var3)->ResetAllocator(&var2);
        ((LootableContainerManager*)&var3)->Reset();
    }

    var2.Destroy();
    var0->unknown_9b8_ = 0;
    return 1;
}
