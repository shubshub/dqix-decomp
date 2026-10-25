#include <globaldefs.h>

#include "GameState/GameState.h"
#include "NitroSDK/Timing.h"
#include "NitroSDK/GamecardBusOwnership.h"
#include "NitroSDK/NetworkIdentity.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

struct Struct_ov031_022114fc;
struct Struct_ov031_02211658;
struct Struct_ov031_02244660 {
    int unknown_0_;
    Struct_ov031_02291e68 unknown_4_;
    unsigned int unknown_44_;
    unsigned long long unknown_48_;
    unsigned int unknown_50_;
};
struct Struct_02245528;
struct Struct_02038598_4;
extern Struct_ov031_02291e68 data_ov031_02291e68;
extern unsigned char data_ov031_02291e04[];
#if defined(jpn)
static const int kSessionSaveOffset = 0x6120;
static const int kIdentityValueOffset = 0x34;
static const int kTransferDoneOffset = 0x20;
#else
static const int kSessionSaveOffset = 0x6380;
static const int kIdentityValueOffset = 0x10;
static const int kTransferDoneOffset = 0x30;
#endif
extern "C" int func_ov031_02211764(int*, int*);
extern "C" void func_ov031_02211820();
extern "C" int func_ov031_0221156c(void*);
extern "C" void func_ov031_022114fc(Struct_ov031_022114fc*, int);
extern "C" int func_ov031_02211608(void*);
extern "C" int func_ov031_022115d0(void*);
extern "C" void func_ov031_02211020(int, int);
extern "C" void func_ov031_022110f0(void (*)(int));
extern "C" int func_ov031_022111e0();
extern "C" int func_020ab314(int*, int, int);
extern "C" void func_ov031_022120f8();
void* GlobalFlags_GetInstance();
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" int func_ov031_02211310(int, void*, unsigned int, void (*)(), int);
extern "C" void* func_ov031_022112e4();
extern "C" int func_ov031_0221126c();
extern "C" int func_ov031_02212184();
extern "C" int func_ov031_02211644(void*);
extern "C" void func_020d0040(int);
extern "C" int func_020d06fc(void*);
extern "C" void func_020d0050(int);
extern "C" void func_ov031_02211658(Struct_ov031_02211658*);
extern "C" void func_ov031_02245528(Struct_02245528*, int);
extern "C" void func_ov031_0224342c(int);
extern "C" void func_ov031_02243418();

// USA: func_ov031_02244660
// KEEP-NAME: func_ov031_02244660
extern "C" ARM void func_ov031_02244660(Struct_02245528* arg0) {
    GameState* var0 = GameState::GetInstance();
    unsigned char* var1 = (unsigned char*)arg0;
    if ((*(unsigned char*)(var1 + 0x35)) == 3 || (*(unsigned char*)(var1 + 0x35)) == 4) {
        int var2, var3;
        if (func_ov031_02211764(&var2, &var3)) {
            (*(unsigned char*)(var1 + 0x35)) = 7;
            (*(unsigned char*)(var1 + 0x399)) = 1;
            (*(int*)(var1 + 0x394)) = -var2;
            if (var3 == 6) {
                (*(unsigned char*)(var1 + 0x35)) = 8;
            }
            func_ov031_02211820();
        }
    }
    switch ((*(unsigned char*)(var1 + 0x35))) {
    case 0:
        memcpy(&data_ov031_02291e68, &((Struct_ov031_02244660*)((unsigned char*)var0 + kSessionSaveOffset))->unknown_4_, sizeof(Struct_ov031_02291e68));
        if (!func_ov031_0221156c(&data_ov031_02291e68)) {
            func_ov031_022114fc((Struct_ov031_022114fc*)&data_ov031_02291e68, 0x5944514a);
        } else if (!func_ov031_02211608(&data_ov031_02291e68)) {
            func_ov031_022114fc((Struct_ov031_022114fc*)&data_ov031_02291e68, 0x5944514a);
        }
        int var4 = func_ov031_022115d0(&data_ov031_02291e68);
        (*(int*)(data_ov031_02291e04 + kIdentityValueOffset)) = var4;
        func_ov031_02211020(0x3f6, var4);
        func_ov031_022110f0(func_ov031_0224342c);
        if (func_ov031_022111e0()) {
            (*(unsigned char*)(var1 + 0x35)) = 3;
        } else {
            (*(unsigned char*)(var1 + 0x35)) = 7;
        }
        break;
    case 3: {
        memset((*(unsigned char**)(var1 + 0x37c)), 0, 0x6f60);
        int var5[2];
        if (!func_020ab314(var5, 0, 0)) {
            func_ov031_022120f8();
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
            (*(unsigned char*)(state + 0x35)) = 7;
            break;
        }
        (*(unsigned char**)(state + 0x37c)) = (unsigned char*)&g_fileLoadBuffer + 0x28000;
        (*(int*)(data_ov031_02291e04 + kTransferDoneOffset)) = 0;
        if (!func_ov031_02211310(1, (*(unsigned char**)(var1 + 0x37c)), 0x8000, func_ov031_02243418, 0)) {
            (*(unsigned char*)(var1 + 0x35)) = 7;
            break;
        }
        (*(unsigned long long*)(var1 + 0x3a8)) = GetCurrentTimestamp() + 0xefb5f7;
        (*(unsigned char*)(var1 + 0x35)) = 4;
        break;
    }
    case 4:
        if ((*(int*)(data_ov031_02291e04 + kTransferDoneOffset))) {
            (*(unsigned long long*)(var1 + 0x3a8)) = GetCurrentTimestamp() + 0xefb5f7;
            (*(unsigned char*)(var1 + 0x35)) = 5;
            ((Struct_ov031_02244660*)((unsigned char*)GameState::GetInstance() + kSessionSaveOffset))->unknown_50_ |= 2;
        } else {
            void* var6 = func_ov031_022112e4();
            unsigned long long var7 = GetCurrentTimestamp();
            if ((*(void**)(var1 + 0x3a4)) != var6) {
                (*(void**)(var1 + 0x3a4)) = var6;
                (*(unsigned long long*)(var1 + 0x3a8)) = var7 + 0xefb5f7;
            }
        }
        break;
    case 5:
        if (func_ov031_0221126c()) {
            (*(unsigned char*)(var1 + 0x35)) = 6;
        } else {
            void* var8 = func_ov031_022112e4();
            unsigned long long var9 = GetCurrentTimestamp();
            if ((*(void**)(var1 + 0x3a4)) != var8) {
                (*(void**)(var1 + 0x3a4)) = var8;
                (*(unsigned long long*)(var1 + 0x3a8)) = var9 + 0xefb5f7;
            }
        }
        break;
    case 6:
        if (func_ov031_02212184()) {
            Struct_ov031_02244660* var10 = ((Struct_ov031_02244660*)((unsigned char*)GameState::GetInstance() + kSessionSaveOffset));
            (*(unsigned char*)(var1 + 0x44)) |= 2;
            if (func_ov031_02211644(&data_ov031_02291e68)) {
                unsigned int var11 = GenerateLockOwnerID();
                int var12;
                if (var11 == (unsigned int)-3) {
                    var12 = 0;
                } else {
                    (*(unsigned short*)(data_ov031_02291e04 + 0xa)) = var11;
                    func_020d0040((*(unsigned short*)(data_ov031_02291e04 + 0xa)));
                    var12 = func_020d06fc((void*)0x1001);
                    func_020d0050((*(unsigned short*)(data_ov031_02291e04 + 0xa)));
                }
                if (var12) {
                    func_ov031_02211658((Struct_ov031_02211658*)&data_ov031_02291e68);
                    memcpy(&var10->unknown_4_, &data_ov031_02291e68, sizeof(Struct_ov031_02291e68));
                }
            }
            Struct_ov031_02291e68 var13 = data_ov031_02291e68;
            var10->unknown_48_ = func_ov031_022457e0((int)arg0, var13);
            (*(unsigned char*)(var1 + 0x3d0)) = 0;
            func_ov031_02245528(arg0, 0);
        }
        break;
    case 8:
        if (func_ov031_0221126c()) {
            (*(unsigned char*)(var1 + 0x35)) = 7;
        }
        break;
    case 7:
        if (func_ov031_02212184()) {
            if (!(*(unsigned char*)(var1 + 0x399))) {
                int var14, var15;
                func_ov031_02211764(&var14, &var15);
                (*(int*)(var1 + 0x394)) = -var14;
            }
            if ((*(int*)(var1 + 0x394)) == 0x2711 || (*(int*)(var1 + 0x394)) == 0x2712 ||
                (*(int*)(var1 + 0x394)) == 0x271a || (*(int*)(var1 + 0x394)) == 0x2724 ||
                (*(int*)(var1 + 0x394)) == 0x272e || (*(int*)(var1 + 0x394)) == 0x2738 ||
                (*(int*)(var1 + 0x394)) == 0x2742 || (*(int*)(var1 + 0x394)) == 0x274c) {
                (*(int*)(var1 + 0x394)) += 0x44c;
            }
            if ((*(int*)(var1 + 0x394)) == 0) {
                (*(int*)(var1 + 0x394)) = 0x2b5c;
            }
            (*(unsigned char*)(var1 + 0x3d0)) = 0;
            (*(unsigned char*)(var1 + 0x399)) = 1;
            func_ov031_02245528(arg0, 0);
        }
        break;
    }
}
