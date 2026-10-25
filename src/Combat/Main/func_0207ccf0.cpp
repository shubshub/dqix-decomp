#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory/SignedAllocator.h"
#include "GameState/GameState.h"

struct ItemTable;
struct Element020de650;
struct Obj02061bd8;
struct Obj0207d200;

extern struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern void* InitAllocatorAndLoadGp2File0207d6dc(SafeAllocator* self, int param1, int param2);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int flags);
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
unsigned char* GetFieldAt0x150_02053c6c(unsigned char* combatant);
extern "C" int func_0207cf30(void* self, short key, int amount, unsigned char flag);
extern "C" void func_0207cc18(void* self, struct Element020de650* elem);
extern "C" int func_0207d134(void* self, short key, int amount);
int UpdateKeyValue0207d200(struct Obj0207d200* self, short key, int amount);
extern void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern AllocatorUnion g_mainAllocator;

struct Obj0207ccf0 {
    char pad[0x2c];
    struct ItemTable* container;
    void* field30;
    int field34;
};

struct Struct_0207ccf0_2 {
    char unknown_0_[4];
    void* unknown_4_;
    unsigned int unknown_8_0_ : 4, unknown_8_4_ : 21, unknown_b_1_ : 1, unknown_b_2_ : 6;
};

struct Struct_0207ccf0_3 {
    char unknown_0_[0x134];
    int unknown_134_;
};

static inline int inline_0207ccf0(unsigned int arg0) { return arg0 <= 7; }

// USA: func_0207ccf0
extern "C" ARM int func_0207ccf0(struct Struct_0207ccf0* arg0, short arg1, int arg2, int arg3, unsigned char arg4, unsigned char arg5, unsigned char arg6) {
    int var0 = 0;
    if (arg0->unknown_2c_ == NULL) {
        func_0207d6dc((SafeAllocator*)arg0, (int)&arg1, 1);
        var0 = 1;
    }
    int ret = -1;
    struct Entry0207ccf0* elem = (struct Entry0207ccf0*)ItemTable_Find(self->container, key);
    if (elem != NULL) {
        struct Combatant0207ccf0* combatant = (struct Combatant0207ccf0*)GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), flags);
        if (combatant == NULL) return -1;
        if (CheckField0x56bLowNibble((struct Obj02061bd8*)combatant)) return -1;
        short* slots = (short*)(GetFieldAt0x150_02053c6c((unsigned char*)combatant) + 0x454);
        int count = 0;
        if (a && c && elem->flag25) {
            if (func_0207cf30(self, key, amount, b)) {
                count = amount;
                ret = 1;
            }
        } else if (var2->unknown_8_0_ == 8) {
            for (int var6 = 0; var6 < 8; var6++) {
                if (var4[var6] <= 0) {
                    var4[var6] = arg1;
                    var5 = (short)(var5 + 1);
                    var1 = 0;
                    func_0207cc18(arg0, (struct Struct_0201099c_9*)var2);
                    arg0->unknown_30_ = var2->unknown_4_;
                    arg0->unknown_34_ = var3->unknown_134_;
                    if (var5 == arg2) break;
                }
            }
        }
        if ((var1 == 0 && var5 < arg2) || arg4) {
            short var7 = (short)(arg2 - var5);
            if (inline_0207ccf0(var2->unknown_8_0_)) {
                if (func_0207d134(arg0, arg1, (signed char)var7)) var1 = 1;
            } else if (var2->unknown_8_0_ == 9) {
                if (func_0207d200((struct Struct_0207ccf0_4*)arg0, arg1, (signed char)var7)) var1 = 1;
            } else {
                if (func_0207cf30(arg0, arg1, var7, arg5)) var1 = 1;
            }
        }
    } else {
        var1 = -2;
    }
    if (fresh) {
        SafeAllocator* alloc = (SafeAllocator*)self;
        SignedAllocatorHeader* sig = alloc->GetSignedAllocator();
        alloc->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, sig);
        self->container = NULL;
    }
    return var1;
}
