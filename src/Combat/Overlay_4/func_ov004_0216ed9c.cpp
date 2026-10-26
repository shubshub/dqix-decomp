#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { listOffset = 0x4ec, Enum_ov004_0216ed9c_2888 = 0x928, Enum_ov004_0216ed9c_1172 = 0x1e4, Enum_ov004_0216ed9c_9088 = 0x120, Enum_ov004_0216ed9c_16384 = 0x6000 };
#else
enum { listOffset = 0x6fc, Enum_ov004_0216ed9c_2888 = 0xb48, Enum_ov004_0216ed9c_1172 = 0x494, Enum_ov004_0216ed9c_9088 = 0x2380, Enum_ov004_0216ed9c_16384 = 0x4000 };
#endif

extern "C" int rand(void);

struct Struct_ov004_0216ed9c_2 { int x, y, z; };

class Struct_ov004_0216ed9c_3 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void inline_ov004_0216ed9c_9(const Struct_ov004_0216ed9c_2* v);
};

struct Struct_ov004_021589e8 {
    unsigned int low : 12;
    unsigned int f12 : 4;
    unsigned int unknown_2_0_ : 5;
    unsigned int unknown_2_5_ : 5;
    unsigned int top : 6;
};

struct Struct_ov004_0216ed9c_4 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned short unknown_c_;
    unsigned char unknown_e_[0x20];
    unsigned char unknown_2e_[6];
    signed char unknown_34_;
    Struct_ov004_021589e8 unknown_38_;
    unsigned char counts[12];
    int unknown_48_;
};

struct Struct_ov004_02171048_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char pad[2];
    Struct_ov004_0216ed9c_4* ptr;
};
extern Struct_ov004_02171048_3 data_ov004_02171048;

struct Struct_ov004_0217028c { unsigned int unknown_0_[12]; };
extern Struct_ov004_0217028c data_ov004_0217028c;

struct Struct_ov004_0216ed9c {
    unsigned char unknown_0_[0x44];
    Struct_ov004_021589e8 unknown_44_;
};

struct TableA68;
struct StoreStruct;
struct Struct_ov004_021583a8_4;
struct Struct_ov004_021583a8_5;
struct Struct_ov004_0215883c_3;
struct Struct_ov004_021583a8;
struct Struct_ov004_021583a8_2;

extern "C" void* func_ov004_0216ea38(void* ctx, int key);
extern "C" int MessageSystem_GetInstance(void);
extern "C" int func_020d4ac8(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov004_0216ed9c_3* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021fb27c(void* node, unsigned short v);
extern "C" void FieldTask_ConnectWifi(void* a, void* b);
extern "C" int func_ov017_021b1fd4(void* obj);
extern "C" void func_ov023_021fa078(void* obj, void* ctx, unsigned short val, Struct_ov004_0216ed9c_2* arg3, int p5, int p6);
extern "C" unsigned char func_ov017_021b2024(Struct_ov004_021583a8_4* obj);
extern "C" unsigned char func_ov017_021b2038(Struct_ov004_021583a8_5* obj);
extern "C" void* func_02072a68(TableA68* table, int key);
#if defined(jpn)
extern "C" void func_0204500c(void* field, void* buf, int p2);
#define FUNC_0204500C(g, b) func_0204500c(g, b, 0)
enum { Enum_ov004_0216ed9c_2456 = 0x868, Enum_ov004_0216ed9c_2464 = 0x870, Enum_ov004_0216ed9c_92 = 0x28, Enum_ov004_0216ed9c_2400 = 0x800 };
#else
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
#define FUNC_0204500C(g, b) func_0204500c(g, b, 0, 0xe3)
enum { Enum_ov004_0216ed9c_2456 = 0x998, Enum_ov004_0216ed9c_2464 = 0x9a0, Enum_ov004_0216ed9c_92 = 0x5c, Enum_ov004_0216ed9c_2400 = 0x960 };
#endif
extern "C" unsigned char func_ov017_021b204c(Struct_ov004_0215883c_3* obj);
extern "C" unsigned char func_ov017_021b1fe8(Struct_ov004_021583a8* obj);
extern "C" void* func_ov017_021b1fc0(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" int func_020ac7b4(int flag);
extern "C" int func_ov017_021b1ffc(Struct_ov004_021583a8_2* obj);
extern "C" void func_02046380(void* g);
extern "C" void func_020465c0(StoreStruct* base, int index, int value);

static inline char* inline_ov004_0216ed9c(char* actor) {
    return *(char**)(actor + 0x3000 + Enum_ov004_0216ed9c_2888);
}

// USA: func_ov004_0216ed9c
extern "C" ARM int func_ov004_0216ed9c(void* self) {
    Struct_ov004_0216ed9c_3* node;
    GameState* gs = GameState::GetInstance();
    char* actor = (char*)GetGameResources();
    void* list = *(void**)(actor + 0x3000 + listOffset);
    char* five = inline_ov004_0216ed9c(actor);
    TableA68* table = (TableA68*)func_ov004_0216ea38(self, 4);
    int g = MessageSystem_GetInstance();
    unsigned char state = data_ov004_02171048.ptr->unknown_2e_[0];

    if (state == 2) {
        int v = func_020d4ac8();
        node = func_ov023_021f6880(func_ov011_021849c8(self), 0x97);
        if (node == 0 || func_ov023_021f6f10(node) != 1) {
            node = 0;
        }
        func_ov023_021fb27c(node, v + 8);
        FieldTask_ConnectWifi(five, list);
        {
            int slot;
            Struct_ov004_0216ed9c_4* blk;
            Struct_ov004_0216ed9c_4* block;
            int n;
            int i;
            Struct_ov004_0216ed9c_3* var14;
            int id;
            int total = func_ov017_021b1fd4(five) >> 12;
            int count = total - data_ov004_02171048.ptr->unknown_48_;
            if (count == 0) goto spawned;

            for (i = 0; i < count; i++) {
                slot = rand() % 12;
                blk = data_ov004_02171048.ptr;
                while (blk->counts[slot] >= 10) {
                    slot = (slot + 1) % 12;
                }
                blk->counts[slot]++;

                block = data_ov004_02171048.ptr;
                n = block->counts[slot];
                id = block->unknown_48_ + 0x578 + i;

                var14 = func_ov023_021f6880(func_ov011_021849c8(self), id);
                if (var14 == 0 || func_ov023_021f6f10(var14) != 0) {
                    var14 = 0;
                }
                if (!var14) goto spawned;

                Struct_ov004_0216ed9c_2 dst;
                Struct_ov004_0216ed9c_2 pos;
                pos.x = (slot * 21) << 12;
                pos.y = (n * -19) << 12;
                pos.z = 0;
                var14->inline_ov004_0216ed9c_9(&pos);

                dst.x = (slot * 21) << 12;
                dst.y = (0xc0 - n * 19) << 12;
                dst.z = 0;

                void* effect = func_ov023_021f6880(func_ov011_021849c8(self), 0xffff);
                if (!effect) goto spawned;
                func_ov023_021fa078(effect, self, id, &dst, 0xd000, 0xd000);
            }
            data_ov004_02171048.ptr->unknown_48_ = total;
        }
spawned:

        unsigned char a = func_ov017_021b2024((Struct_ov004_021583a8_4*)five);
        unsigned char b = func_ov017_021b2038((Struct_ov004_021583a8_5*)five);
        if (data_ov004_02171048.unknown_1_ == 0 && a == 5 && b == 0) {
            FUNC_0204500C((void*)g, func_02072a68(table, 0xcc));
            *(int*)(g + Enum_ov004_0216ed9c_2456) = 1;
            data_ov004_02171048.unknown_1_ = 1;
        }
        if (data_ov004_02171048.unknown_0_ == 0 && a == 5 && b == 5) {
            FUNC_0204500C((void*)g, func_02072a68(table, 0xcd));
            *(int*)(g + Enum_ov004_0216ed9c_2456) = 1;
            data_ov004_02171048.unknown_0_ = 1;
        }
        if (*(int*)(actor + 0x4000 + Enum_ov004_0216ed9c_1172) == 0) {
            data_ov004_02171048.ptr->unknown_2e_[0]++;
            GameState::GetInstance();
        }
    } else if (state == 3) {
        if (*(int*)(g + Enum_ov004_0216ed9c_2464) != 3) return 1;

        Struct_ov004_0216ed9c_3* node = func_ov023_021f6880(func_ov011_021849c8(self), 0x97);
        if (node) {
            *((unsigned char*)node + 0xc) |= 8;
        }
        char* buf = *(char**)(g + Enum_ov004_0216ed9c_92);
        memset(buf, 0, Enum_ov004_0216ed9c_2400);

        if (func_ov017_021b204c((Struct_ov004_0215883c_3*)five)) {
            const char* s = (const char*)func_02072a68(table, 0x71);
            memcpy(buf, s, strlen(s));
        } else if (func_ov017_021b1fe8((Struct_ov004_021583a8*)five) & 2) {
            func_ov017_021b1fc0(five);
            data_ov004_02171048.ptr->unknown_2e_[1] = 1;
            const char* s = (const char*)func_02072a68(table, 0xca);
            int len = strlen(s);
            memcpy(buf, s, len);
            if (data_ov004_02171048.ptr->unknown_2e_[3]) {
                const char* s2 = (const char*)func_02072a68(table, 0xd6);
                memcpy(buf + len, s2, strlen(s2));
            }
            func_ov011_021848a0(self, 0xca);

            Struct_ov004_0216ed9c_4* blk = data_ov004_02171048.ptr;
            Struct_ov004_021589e8* date = &blk->unknown_38_;
            date->unknown_2_0_++;
            if (date->unknown_2_0_ == 0) date->unknown_2_0_ = 1;
            Struct_ov004_0217028c month = data_ov004_0217028c;
            if ((&month.unknown_0_[-1])[date->f12] < date->unknown_2_0_ || date->unknown_2_0_ == 0) {
                date->unknown_2_0_ = 1;
                date->f12++;
                if (date->f12 > 12) {
                    date->f12 = 1;
                    date->low++;
                }
            }
            memcpy(&((Struct_ov004_0216ed9c*)((char*)gs + Enum_ov004_0216ed9c_9088 + Enum_ov004_0216ed9c_16384))->unknown_44_, &data_ov004_02171048.ptr->unknown_38_, 4);
            if (!func_020ac7b4(0)) return 0;
            if (!func_020ac7b4(1)) return 0;
        } else {
            const char* s = (const char*)func_02072a68(table, 0xcb);
            memcpy(buf, s, strlen(s));
            int w = func_ov017_021b1ffc((Struct_ov004_021583a8_2*)five);
            func_02046380((void*)g);
            func_020465c0((StoreStruct*)g, 0, w);
            func_ov011_021848a0(self, 0xcb);
            data_ov004_02171048.ptr->unknown_2e_[1] = 0;
        }

        FUNC_0204500C((void*)g, *(char**)(g + Enum_ov004_0216ed9c_92));
        *(int*)(g + Enum_ov004_0216ed9c_2456) = 1;
        five[1] = 1;
        data_ov004_02171048.ptr->unknown_2e_[0] = 0;
        Struct_ov004_0216ed9c_4* blk = data_ov004_02171048.ptr;
        memset(blk->counts, 0, 0xc);
        blk->unknown_48_ = 0;
        return 0;
    }
    return 1;
}
