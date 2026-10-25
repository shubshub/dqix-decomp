#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_020a94f8_2 { int unknown_0_; char unknown_4_[4]; char unknown_8_[12]; };
struct Struct_020ab314_4 {
    int unknown_0_;
    char unknown_4_[0x2ca8];
    char unknown_2cac_[0x344];
    char unknown_2ff0_[0xa0];
    char unknown_3090_[0x330];
    unsigned char unknown_33c0_[0x194];
    char unknown_3554_[0x4d0];
    char unknown_3a24_[0x3b4];
    char unknown_3dd8_[0xec];
    char unknown_3ec4_[0x1b40];
    char unknown_5a04_[0x404];
    char unknown_5e08_[0xad8];
    char unknown_68e0_[0x7c];
    char unknown_695c_[0x1c];
    char unknown_6978_[0x2c4];
    char unknown_6c3c_[0x110];
    char unknown_6d4c_[0x214];
};
struct Struct_020ab314_5 {
    char unknown_0_[0x10];
    Struct_020a94f8_2 unknown_10_;
    char unknown_24_[0x54];
    char unknown_78_[0xc];
    Struct_020ab314_4 unknown_84_;
    char unknown_6fe4_[0x101c];
};
struct Struct_020ab314 { char unknown_0_[0x28000]; Struct_020ab314_5 unknown_28000_; };
struct Struct_020ab314_2 {
    char unknown_0_[RG(0x569c, 0x543c)];
    char unknown_569c_[0x7c];
    char unknown_5718_[RG(0x5cc8 - 0x5718, 0x5a68 - 0x54b8)];
    unsigned char unknown_5cc8_;
    char unknown_5cc9_[RG(0x5e6c - 0x5cc9, 0x5c0c - 0x5a69)];
    char unknown_5e6c_[0x110];
    char unknown_5f7c_[RG(0x6380 - 0x5f7c, 0x6120 - 0x5d1c)];
    char unknown_6380_[0x54];
    char unknown_63d4_[RG(0x71fc - 0x63d4, 0x6fbc - 0x6174)];
    char unknown_71fc_[0x2c4];
    char unknown_74c0_[0x44];
    char unknown_7504_[0xec];
    char unknown_75f0_[0x4d0];
    char unknown_7ac0_[0x3b4];
};
struct Globals020ab314 { char data[0xa0]; char pad_a0[0xd8]; char extra[0x330]; };
struct StateBits5ccc_11544;
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
extern const char data_020f1bf0[];
extern "C" int func_02075910(int, void*, unsigned int, int);
extern "C" int func_020a94f8(Struct_020a94f8_2*, int);
extern "C" int func_020ac864(int);
extern "C" void func_02011544(Struct_02011544*);
extern "C" int func_01ff85b8(void*, int);
extern "C" void* Scenario_GetInstance();
Globals020ab314* GetGlobal02109418_02094d6c();
void* GetSlotEntry020108d8(char*, int);
#if defined(jpn)
extern "C" int func_020a95a4(void*, void*);
#else
extern "C" int func_020a95a4(void*, void*, unsigned char*);
#endif
extern "C" int func_020a9a50(void*, void*, int);
extern "C" void func_020a9af8(unsigned char*);
extern "C" void func_020a9b2c(void*);
extern "C" void func_020a9ba4(void*);
extern "C" void func_020a9c14(void*);
extern "C" void func_020a9d78(void*);
extern "C" void func_020a9e30(void*);

// USA: func_020ab314
extern "C" ARM int func_020ab314(int* arg0, int arg1, int arg2) {
    GameState* var0 = GameState::GetInstance();
    Struct_020ab314_2* var1 = (Struct_020ab314_2*)var0;
    var1->unknown_5cc8_ = 0;
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int valid;
    int id;
    SaveBuffer020ab314* buffer;
    valid = 1;
    if (alternate) id = 0x8084;
    else id = 0x84;
    buffer = &((SaveScratch020ab314*)g_fileLoadBuffer)->buffer;
    VectorizedMemset(buffer, 0, 0x8000);
    if (!func_02075910(0, buffer, 0x10, 0)) valid = 0;
    Buf020a94f8 header;
    if (!VerifyBuffer020a94f8(&header, alternate != 0)) valid = 0;
    VectorizedInvertedMemcpy(&header, &buffer->header, 0x14);
    VerifyAndApplySaveBuffer_020ac864(alternate ? 1 : 0);
    VectorizedInvertedMemcpy(saveState->globals, buffer->globals, 0x54);
    if (!func_02075910(id, &buffer->body, 0x6f60, 0)) valid = 0;
    SaveBody020ab314* body = &buffer->body;
    if (!strcmp(header.signature, data_020f1bf0) && valid) {
        if (func_01ff85b8(body->actorData, 0x6f5c) != body->checksum) {
            saveState->error = alternate ? 3 : 2;
            valid = 0;
        }
    }
    if (!var2) {
        func_02011544((Struct_02011544*)var0);
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    void* context = Scenario_GetInstance();
    Globals020ab314* globals = GetGlobal02109418_02094d6c();
#if defined(jpn)
    func_020a95a4(var6->unknown_4_, func_020108d8((char*)var0, 0));
#else
    unsigned char var9 = 0;
    func_020a95a4(var6->unknown_4_, func_020108d8((char*)var0, 0), &var9);
#endif
    func_020a9a50(var6->unknown_2cac_, var7, 0);
    memcpy(var8, var6->unknown_2ff0_, 0xa0);
    memcpy(func_02094d6c()->unknown_178_, var6->unknown_3090_, 0x330);
    func_020a9af8(var6->unknown_33c0_);
    memcpy(var1->unknown_75f0_, var6->unknown_3554_, 0x4d0);
    memcpy(var1->unknown_7ac0_, var6->unknown_3a24_, 0x3b4);
    memcpy(var1->unknown_7504_, var6->unknown_3dd8_, 0xec);
    func_020a9b2c(var6->unknown_3ec4_);
    func_020a9ba4(var6->unknown_5a04_);
    func_020a9c14(var6->unknown_5e08_);
    memcpy(((Struct_020ab314_2*)GameState::GetInstance())->unknown_569c_, var6->unknown_68e0_, 0x7c);
    if (arg2) {
        func_020a9d78(var6->unknown_695c_);
        func_020a9e30(var6->unknown_6d4c_);
    }
    memcpy(((Struct_020ab314_2*)GameState::GetInstance())->unknown_71fc_, var6->unknown_6978_, 0x2c4);
    memcpy(((Struct_020ab314_2*)GameState::GetInstance())->unknown_5e6c_, var6->unknown_6c3c_, 0x110);
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
