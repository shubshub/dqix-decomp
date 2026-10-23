#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_ov012_02186c1c {
    unsigned int unknown_0_;
    unsigned int unknown_4_0_ : 9;
    int unknown_5_1_ : 10;
    unsigned int unknown_6_3_ : 13;
};
struct Struct_ov012_02186c1c_2 {
    unsigned short unknown_0_0_ : 5;
    unsigned short unknown_0_5_ : 11;
};
struct Struct_0205de24_2;
struct Struct_0205c570;
struct TableA68;
struct SePlayer;
struct Obj021e6e20;
void FindAndLinkMatchingEntry0205de24(Struct0205de24*, unsigned char, unsigned char);
int Window_GetSelectedIndex(Struct_0205c570*);
void BuildMessageB_021898bc(char*);
void* FindEntryByKey_02072a68(TableA68*, int);
void SePlayer_Play(SePlayer*, int, int);
int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20*);
extern SePlayer g_sePlayer;
extern "C" void func_ov023_021e6e60(void*);
extern "C" int func_ov023_021e7148(void*);
extern "C" void func_ov012_0218bba0(void*, int, int);
extern "C" void func_ov012_02189be8(void*, int);

static inline Struct_ov012_02186c1c* inline_ov012_02186c1c(GameState* arg0) {
    return (Struct_ov012_02186c1c*)((char*)arg0 + 0x543c);
}

// USA: func_ov012_02186c1c
extern "C" ARM void func_ov012_02186c1c(char* arg0) {
    if (*(unsigned char*)(arg0 + 0x1340) == 0) {
        *(unsigned char*)(arg0 + 0x1368) = 0;
        int var0 = inline_ov012_02186c1c(GameState::GetInstance())->unknown_5_1_;
        int var1;
        if (var0 < 100) var1 = 2;
        else if (var0 < 200) var1 = 0;
        else if (var0 < 300) var1 = 1;
        else if (var0 == 300) var1 = 3;
        else var1 = 0;
        *(int*)(arg0 + 0x1430) = var1;
        func_0205de24((Struct_0205de24_2*)(arg0 + 0x90), 0, 3);
        func_ov023_021e6e60(arg0);
        func_ov012_021898bc(arg0);
        (*(unsigned char*)(arg0 + 0x1340))++;
        return;
    }
    if (*(unsigned char*)(editor + 0x1340) != 1) return;
    *(unsigned char*)(editor + 0x1368) = 1;
    *(int*)(editor + 0x1430) = Window_GetSelectedIndex((Struct_0205c570*)(editor + 0x90));
    if (func_ov023_021e7148(editor)) {
        int rebuild = 1;
        switch (*(int*)(editor + 0x1430)) {
        case 0:
            *(unsigned char*)(arg0 + 0x1341) = 3;
            *(unsigned char*)(arg0 + 0x1340) = 0;
            break;
        case 1:
            *(unsigned char*)(arg0 + 0x1341) = 4;
            *(unsigned char*)(arg0 + 0x1340) = 0;
            break;
        case 2:
            if (((Struct_ov012_02186c1c_2*)(arg0 + 0x141c))->unknown_0_0_) {
                *(unsigned char*)(arg0 + 0x1341) = 5;
                *(unsigned char*)(arg0 + 0x1340) = 0;
            } else var2 = 0;
            break;
        case 3: {
            GameState* var3 = GameState::GetInstance();
            const char* var4 = (const char*)func_02072a68((Struct_02072a68_2*)(arg0 + 0x1314), 109);
            inline_ov012_02186c1c(var3)->unknown_5_1_ = 300;
            memset(arg0 + 0x1498, 0, 64);
            memcpy(arg0 + 0x1498, var4, strlen(var4));
            func_ov012_0218bba0(arg0, 0, -1);
            func_ov012_02189be8(arg0, var2);
            break;
        }
        }
        if (!rebuild) return;
        SePlayer_Play(&g_sePlayer, 1, 0);
    } else {
        if (!func_ov023_021e6e20((Struct_ov012_02186a7c*)arg0)) return;
        func_ov012_02189be8(arg0, 1);
    }
}
#else
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Struct_0205de24_2 {
    char unknown_0_[0x98];
    void* unknown_98_;
    void* unknown_9c_;
    char unknown_a0_[0x12];
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
};
struct Struct_0205c570;
struct EntryA68 { short key; void* value; };
struct TableA68 { EntryA68* entries; short count; };
struct SePlayer;
struct Obj021e6e20;
struct ProfileTitle {
    char padding0[4];
    unsigned int unknown4 : 9;
    int title : 10;
    unsigned int unknownUpper : 13;
};
struct Struct_01ff8b48_9 {
    char unknown_0_[0x569c];
    Struct_ov012_02186c1c_3 unknown_569c_;
};
struct Struct_ov012_02185ab8 {
    char unknown_0_[0xac];
    Struct_0205de24_2 unknown_ac_;
    char unknown_164_[0x133c - 0x164];
    Struct_02072a68_2 unknown_133c_;
    char unknown_1344_[0x1370 - 0x1344];
    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
    char unknown_1372_[0x13a0 - 0x1372];
    unsigned char unknown_13a0_;
    char unknown_13a1_[0x13c4 - 0x13a1];
    unsigned short unknown_13c4_0_ : 5;
    unsigned short unknown_13c4_5_ : 11;
    char unknown_13c6_[0x13d8 - 0x13c6];
    int unknown_13d8_;
    char unknown_13dc_[0x1440 - 0x13dc];
    char unknown_1440_[0x40];
};

static inline Struct_ov012_02186c1c_3* inline_ov012_02186c1c_2(GameState* arg0) {
    Struct_01ff8b48_9* var0 = (Struct_01ff8b48_9*)arg0;
    return &var0->unknown_569c_;
}
void FindAndLinkMatchingEntry0205de24(Struct0205de24*, unsigned char, unsigned char);
int Window_GetSelectedIndex(Struct_0205c570*);
void BuildMessageB_021898bc(char*);
void* FindEntryByKey_02072a68(TableA68*, int);
void SePlayer_Play(SePlayer*, int, int);
int TestFlagsAndActiveElement2_021e6e20(Obj021e6e20*);
extern SePlayer g_sePlayer;
extern "C" void func_ov023_021e6e60(ProfileEditor*);
extern "C" int func_ov023_021e6de4(ProfileEditor*);
extern "C" void func_ov012_0218adac(ProfileEditor*, int, int, int);
extern "C" void func_ov012_0218930c(ProfileEditor*, int);

// USA: func_ov012_02186c1c
extern "C" ARM void func_ov012_02186c1c(Struct_ov012_02185ab8* arg0) {
    if (arg0->unknown_1370_ == 0) {
        arg0->unknown_13a0_ = 0;
        int var5 = inline_ov012_02186c1c_2(GameState::GetInstance())->unknown_5_1_;
        int var6;
        if (var5 < 100) var6 = 2;
        else if (var5 < 200) var6 = 0;
        else if (var5 == 300) var6 = 3;
        else if (var5 < 300) var6 = 1;
        else {
            var6 = 0;
            switch (var5) {
            case 310:
                var6 = 0;
                break;
            }
        }
        arg0->unknown_13d8_ = var6;
        func_0205de24(&arg0->unknown_ac_, 0, 3);
        func_ov023_021e6e60(arg0);
        func_ov012_021898bc((char*)arg0);
        arg0->unknown_1370_++;
        return;
    }
    if (self->step != 1) return;
    self->active = 1;
    self->cursor = Window_GetSelectedIndex((Struct_0205c570*)&self->entries);
    if (func_ov023_021e6de4(self)) {
        int rebuild = 1;
        switch (self->cursor) {
        case 0:
            arg0->unknown_1371_ = 3;
            arg0->unknown_1370_ = 0;
            break;
        case 1:
            arg0->unknown_1371_ = 4;
            arg0->unknown_1370_ = 0;
            break;
        case 2:
            if (arg0->unknown_13c4_0_) {
                arg0->unknown_1371_ = 5;
                arg0->unknown_1370_ = 0;
            } else var7 = 0;
            break;
        case 3: {
            GameState* var8 = GameState::GetInstance();
            const char* var9 = (const char*)func_02072a68(&arg0->unknown_133c_, 0x6d);
            inline_ov012_02186c1c_2(var8)->unknown_5_1_ = 300;
            memset(arg0->unknown_1440_, 0, sizeof(arg0->unknown_1440_));
            int var10 = strlen(var9);
            memcpy(arg0->unknown_1440_, var9, var10);
            func_ov012_0218adac(arg0, 0, -1, 0);
            func_ov012_0218930c(arg0, var7);
            break;
        }
        }
        if (!rebuild) return;
        SePlayer_Play(&g_sePlayer, 1, 0);
    } else {
        if (!func_ov023_021e6e20((Struct_ov012_02186a7c*)arg0)) return;
        func_ov012_0218930c(arg0, 1);
    }
}
#endif
