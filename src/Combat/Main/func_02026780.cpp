#include <globaldefs.h>
#include "World/LootableContainer.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Matrix.h"
struct MapDisplay;

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void* Zone3D_GetInstance(void);

extern "C" void MapDisplay_ClearRedChests(char* obj);
extern "C" void func_020269e4(char* obj, const void* src);

struct Struct_02026780_4 {
    unsigned short uniqueID;
    unsigned short itemIDOrRank;
    unsigned short lock : 2;
    unsigned short lootType : 2;
    unsigned short containerType : 3;
    short angleOrCupboardNode;
    Vector3fix position;
    struct Struct_02026780_4* pNext;
};

struct Struct_02026780_5 {
    unsigned char type;
    unsigned char pad1;
    unsigned char unknown_2_;
    unsigned char pad3;
    char* names;
    fix32_t x;
    fix32_t z;
    struct Struct_02026780_5* next;
};

struct Struct_02026780 {
#if defined(jpn)
    unsigned char pad0[0x6a8];
#else
    unsigned char pad0[0x754];
#endif
    struct Struct_02026780_5* nodes;
    unsigned char pad2[0x22];
    unsigned char count;
    unsigned char pad3[1];
    char* names;
    unsigned char unknown_780_;
    unsigned char pad5[0x9b8 - 0x781];
    unsigned char flag;
};

struct Struct_02026780_2 {
    unsigned short id;
    unsigned short f2;
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    unsigned short unknown_a_;
    unsigned int pad;
    Vector3fix pos;
};

struct Struct_02026780_3 {
    char unk_0[4];
    Struct_02026780_4* pContainerList_;
    unsigned short unknown_8_;
};

// USA: func_02026780
extern "C" ARM int func_02026780(MapDisplay* arg0, void* arg1, unsigned int fileSize) {
    Struct_02026780* self = (Struct_02026780*)arg0;
    char buffer[0x800];
    SafeAllocator alloc;
    Struct_02026780_3 mgr;
    Struct_02026780_2 rec;
    int i;
    int var6;
    fix32_t ax;
    fix32_t var8;
    struct Struct_02026780_5* node;

    if (self->count == 0 || self->names == 0) {
        return 0;
    }

    if (LinkSession_IsGuest(LinkSession_GetInstance()) != 0) {
        MapDisplay_ClearRedChests((char*)self);
        return 0;
    }

    Zone3D_GetInstance();
    alloc.ResetAllocatorPointer();
    alloc.ResetAllocatorPointer();
    alloc.CreateTypeA(buffer, sizeof(buffer));

    self->unknown_780_ = 0;

    for (i = 0; i < self->count; i++) {
        ax = 0;
        var8 = ax;
        node = self->nodes;
        var6 = 1;

        while (node != 0 && var6) {
            if (node->type == 1) {
                int j = 0;
                while (j < node->unknown_2_ && var6) {
                    if (*(unsigned short*)(node->names + j * 2)
                        == *(unsigned short*)(self->names + i * 0x1a)) {
                        ax = node->x;
                        var8 = node->z;
                        var6 = 0;
                    }
                    j++;
                }
            }
            node = node->next;
        }

        alloc.Reset();
        ((LootableContainerManager*)&mgr)->Reset();
        ((LootableContainerManager*)&mgr)->Reset();

        ((LootableContainerManager*)&mgr)->LoadZoneContainers(
            arg1, fileSize, self->names + i * 0x1a + 2, &alloc);

        for (Struct_02026780_4* c = mgr.pContainerList_; c != 0; c = c->pNext) {
            VectorizedMemset(&rec, 0, sizeof(rec));
            rec.id = c->uniqueID;
            rec.f2 = c->lock;
            rec.f4 = c->lootType;
            rec.unknown_6_ = c->containerType;
            rec.pos = c->position;

            if (rec.unknown_6_ == 0) {
                if (c->itemIDOrRank == 0) {
                    rec.f8 = 0;
                } else {
                    rec.f8 = 1;
                }
                rec.unknown_a_ = rec.f8;
                if (!var6) {
                    rec.pos.x = ax + fix32_Divide(c->position.x, 9830);
                    rec.pos.z = var8 + fix32_Divide(c->position.z, 9830);
                }
                func_020269e4((char*)self, &rec);
            }
        }

        ((LootableContainerManager*)&mgr)->ResetAllocator(&alloc);
        ((LootableContainerManager*)&mgr)->Reset();
    }

    alloc.Destroy();
    self->flag = 0;
    return 1;
}
