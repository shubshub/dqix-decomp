#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LootPointList_GetInstance(void);
extern "C" void* func_02057924(void);
extern "C" int rand(void);
extern "C" int _s32_div_f(int a, int b);
extern "C" int Zone3D_GetGroundHeight(int seed, void* v);
extern "C" int LootPointList_AppliesToMap(void* unused, char* str);

struct Struct_0208f168_2 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 4;
    unsigned int unknown_1_5_ : 4;
    unsigned int unknown_2_1_ : 8;
    unsigned int type4 : 4;
    unsigned int kind : 2;
    unsigned int flag : 1;
};

struct Struct_0208f168_3 {
    unsigned int unknown_0_0_ : 21;
    unsigned int unknown_2_5_ : 8;
    unsigned int unknown_3_5_ : 3;
};

struct Struct_0208f168_4 {
    unsigned int packed;
    struct Struct_0208f168_3 f4;
    struct Struct_0208f168_2* owner;
    Vector3i vec[8];
    struct Struct_0208f168_4* next;
};

struct Head0208f168 {
    char pad[4];
    struct Struct_0208f168_4* head;
};

struct Struct_0208f168_6 {
    int index;
    Vector3i vec;
    int frame;
    struct Struct_0208f168_6* link;
};

struct Struct_0208f168 {
    char pad[8];
    void* obj;
    struct Struct_0208f168_6* head;
};

// USA: func_0208f168
extern "C" ARM void func_0208f168(struct Struct_0208f168* self, void* alloc) {
    if (alloc == 0) {
        return;
    }

    void* g = Zone3D_GetInstance();
    char* name = *(char**)((char*)g + 8);
    struct Head0208f168* h = (struct Head0208f168*)LootPointList_GetInstance();

    if (name == 0) {
        return;
    }
    if (LootPointList_AppliesToMap(h, name + 5) == 0) {
        return;
    }

    if (self->obj != 0) {
        ((Object3D*)self->obj)->SetAnimationByIndex(0, 0);
        void* var3 = ((Object3D*)self->obj)->GetCurrentAnimationConfig();
        if (var3 == 0) {
            return;
        }
        BCFG::AnimationRecord* rec = ((BCFG*)var3)->GetAnimationRecord(0);
        if (rec == 0) {
            return;
        }

        GameState* bs = GameState::GetInstance();
#if defined(jpn)
        struct Struct_0208f168_2* table = (struct Struct_0208f168_2*)((char*)bs + 0x27c + 0x5800);
#else
        struct Struct_0208f168_2* table = (struct Struct_0208f168_2*)((char*)bs + 0xdc + 0x5c00);
#endif
        struct Struct_0208f168_4* node = h->head;
        func_02057924();
        bs->GetProtagonist();

        unsigned int counter = 0;
        while (node != 0) {
            int idx = (node->packed << 9) >> 25;
            struct Struct_0208f168_2* e = &table[idx];
            if (e->flag) {
                node->owner = e;
                node->f4.unknown_2_5_ = ((*(unsigned int*)e << 7) >> 24);
                int count = e->unknown_1_1_;
                if (idx >= 0x62) {
                    count = 8;
                }
                int j = 0;
                for (; j < count; j++) {
                    Vector3i* v = node->vec;
                    if (((*(unsigned int*)e << 7) >> 24) & (1 << j)) {
                        struct Struct_0208f168_6* item = (struct Struct_0208f168_6*)((SafeAllocator*)alloc)->Allocate(0x18);
                        if (item == 0) {
                            return;
                        }
                        item->index = j + (counter << 3);
                        int base = rec->startTime;
                        item->frame = base + (rand() % (rec->endTime - base));
                        node->vec[j].y = Zone3D_GetGroundHeight((int)g, (void*)&v[j]);
                        *(Vector3i*)((int*)&item->vec) = *(Vector3i const*)((int*)&v[j]);
                        struct Struct_0208f168_6* n = self->head;
                        if (n == 0) {
                            self->head = item;
                            item->link = 0;
                        } else {
                            while (n->link != 0) {
                                n = n->link;
                            }
                            n->link = item;
                            item->link = 0;
                        }
                    }
                }
            }
            counter = (counter + 1) & 0xff;
            node = node->next;
        }
    } else {
        return;
    }
}
