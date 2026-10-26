#if defined(jpn)
enum { Enum_ov017_021cd608_1816 = 0x508 };
#else
enum { Enum_ov017_021cd608_1816 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021cd608_3 {
    char pad[8];
    unsigned short id;
};

extern "C" struct Struct_ov017_021cd608_3* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_020ac4c0(void* dst);
extern "C" int func_020ac494(void* src);
extern "C" void func_ov000_02163378(void* dst, int* src, unsigned char val);

struct Struct_020a0858 {
    char pad[0x48];
    unsigned int value;
};

struct Struct_020a0300 {
    char pad[0x24];
    unsigned int val : 24;
    unsigned int top : 8;
};

extern "C" void func_020a0858(struct Struct_020a0858* p, unsigned int amount);
extern "C" void func_020a0300(struct Struct_020a0300* p, unsigned int amount);

struct Struct_ov017_021cd608_4 {
    struct Struct_020a0858 head;
    char pad0[0x68 - sizeof(struct Struct_020a0858)];
    struct Struct_020a0300 tail;
    char pad1[0xb0 - 0x68 - sizeof(struct Struct_020a0300)];
};

struct Struct_ov017_021cd608 {
    unsigned short id;
    unsigned short low[4];
    unsigned char high[4];
    unsigned char val;
    unsigned char apply;
};

struct Struct_ov017_021cd608_2 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021cd608 payload;
};

// USA: func_ov017_021cd608
extern "C" ARM void func_ov017_021cd608(int unused0, struct Struct_ov017_021cd608_2* evt, int arg2, unsigned char* base) {
    int i;
    void* table = *(void**)(base + 0x3000 + Enum_ov017_021cd608_1816);
    struct Struct_ov017_021cd608* p = &evt->payload;
    int var3[4];
    struct Struct_ov017_021cd608_4 block;

    struct Struct_ov017_021cd608_3* owner = func_ov017_021b8478(table);
    if (owner->id != p->id) {
        return;
    }
    void* b = func_ov017_021b8468(table);
    if (b == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        var3[i] = p->low[i] + (p->high[i] << 16);
    }
    if (p->apply) {
        int idx = GameState_GetProtagonistIndex(GameState::GetInstance());
        func_020ac4c0(&block);
        func_020a0858(&block.head, var3[idx]);
        func_020a0300(&block.tail, var3[idx]);
        func_020ac494(&block);
    } else {
        func_ov000_02163378(b, var3, p->val);
    }
}
