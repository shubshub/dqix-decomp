#if defined(jpn)
enum { Enum_ov017_021b3780_336 = 0x144 };
#else
enum { Enum_ov017_021b3780_336 = 0x150 };
#endif

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_020534ac;
extern "C" void* func_02099ff0(void* dst);

struct Struct_0209a088_2;
struct Struct_0209a088 {
    char pad[0xc];
};
extern "C" void func_0209a088(struct Struct_0209a088* obj, struct Struct_0209a088_2* src);

extern "C" void* func_0209a004(void* list, int key);

extern "C" void PartyMember_RecalculateStats(void* a, int arg1);

extern unsigned char data_ov017_021d6b20;

struct Struct_ov017_021b3780 {
    unsigned int words[10];
    short id;
    char pad2a[2];
};

struct Struct_ov017_021b3780_2 {
    char pad0[0x8];
    short combatantId;
    char pad1[6];
    int unknown_10_;
};

// USA: func_ov017_021b3780
extern "C" ARM int func_ov017_021b3780(struct Struct_ov017_021b3780_2* ctx) {
    GameState* battle = GameState::GetInstance();
    int var1 = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(var1))->GetTaskStatus((int)(ctx->unknown_10_))) {
        return 0;
    }
    GameObject* combatant = func_0200ff1c(battle, ctx->combatantId);
    if (!combatant) {
        return 0;
    }
    int base150 = func_02053c6c((unsigned char*)combatant);
    if (!base150) {
        return 0;
    }

    int key = ctx->unknown_10_;
    int val1;
    volatile int val2;
    ((BackgroundLoader*)((struct Struct_020534ac*)var1))->GetLoadedFileByID((int)(key), (void**)(&val1), (unsigned int*)((int*)&val2));

    struct Struct_0209a088 obj;
    func_02099ff0(&obj);
    int unused = val2;
    func_0209a088(&obj, (struct Struct_0209a088_2*)val1);

    struct Struct_ov017_021b3780* rec = (struct Struct_ov017_021b3780*)(*(char**)((char*)combatant + Enum_ov017_021b3780_336) + 0x2f4);
    unsigned char* table = &data_ov017_021d6b20;
    int i;
    for (i = 0; i < 8; i++, table++, rec++) {
        rec->words[0] = 0;
        rec->words[1] = 0;
        rec->words[2] = 0;
        rec->words[3] = 0;
        rec->words[4] = 0;
        rec->words[5] = 0;
        rec->words[6] = 0;
        rec->words[7] = 0;
        rec->words[8] = 0;
        rec->words[9] = 0;
        rec->id = -1;

        unsigned char idx = *table;
        short threshold = *(short*)((char*)base150 + idx * 0x20 + 0x100 + 0xac);
        if (threshold > 0) {
            void* found = func_0209a004(&obj, threshold);
            if (found) {
                memcpy(rec, found, 0x2c);
            }
        }
    }

    ((BackgroundLoader*)(var1))->RemoveTask((int)(key));
    ctx->unknown_10_ = -1;
    PartyMember_RecalculateStats((void*)base150, 0);
    return 1;
}
