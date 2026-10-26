#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"


extern char g_fileLoadBuffer[];

extern "C" int func_020aaf84(void* buf, int a, int b, int c);
extern "C" void func_020a93e0(char* param0);
extern "C" void* Scenario_GetInstance(void);
extern "C" int func_020a9a50(void* ctx, char* dst, int flag);
extern "C" void Font_DecodeText(unsigned char* src, char* dst, int n);
extern "C" void __clear(void* buf, int n);

struct Struct020865b0;
extern "C" int PartyMemberRecord_GetVocation(struct Struct020865b0* p);

extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int* word, unsigned int bits);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int bits);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" int func_020ac864(int flag);

struct Struct_020ab5d4_5 {
    char data[0x30];
    unsigned char unknown_30_;
    unsigned char unknown_31_;
    unsigned short unknown_32_;
};

struct Struct_020ab5d4 {
    struct Struct_020ab5d4_5 elems[4];
    int unknown_d0_;
    unsigned char unknown_d4_;
    unsigned char f109;
    unsigned char unknown_d6_;
    unsigned char f10b;
};

struct Struct_020ab5d4_2 {
    char pad[0x3c00];
};

// USA: func_020ab5d4
#if defined(jpn)
struct Struct_020ab5d4_3 {
    char data[0xc];
    unsigned char f0c;
    unsigned char unknown_d_;
    unsigned short unknown_e_;
};

struct Struct_020ab5d4_4 {
    struct Struct_020ab5d4_3 elems[4];
    int f40;
    unsigned char unknown_44_;
    unsigned char f45;
    unsigned char f46;
    unsigned char f47;
};

extern "C" ARM int func_020ab5d4(void* param0, int param1, int param2, void* param3) {
    if (func_020aaf84(param0, 0, 0, 1) == 0) {
        return 0;
    }
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    unsigned char* base = (unsigned char*)&g_fileLoadBuffer[0] + 0x28000;
    GameState* gs = GameState::GetInstance();
    unsigned char* arr = base + 4;
    struct Struct_020ab5d4_4 loc;
    loc.unknown_44_ = arr[0x1d11];
    loc.f40 = *(unsigned short*)(arr + 0x2c4c);
    int i;
    for (i = 0; i < loc.unknown_44_; i++) {
        unsigned char* e = arr + (arr[0x1d0c] + i) * 0x23c;
        if (e != 0) {
            struct Struct_020ab5d4_3* el = &loc.elems[i];
            int v = PartyMemberRecord_GetVocation((struct Struct020865b0*)e);
            el->f0c = v;
            unsigned char* p = e + v;
            el->unknown_d_ = p[0xf];
            el->unknown_e_ = p[2];
            memcpy(el->data, e + 0x140, 0xc);
        }
    }
    unsigned char* var9 = base + 0x2cac;
    void* ctx = Scenario_GetInstance();
    func_020a9a50(var9, (char*)ctx, 0);
    loc.f45 = Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, 0x796);
    loc.f46 = *(int*)var9;
    loc.f47 = Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, 0x1142) != 0;
    memcpy((char*)gs + 0x7c40, &loc, 0x48);
    memcpy(param3, (char*)(((struct Struct_020ab5d4_2*)(base + 0x1d8)) + 1) + 0x3c, 4);
    if (func_020ac864(0) == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
#else
extern "C" ARM int func_020ab5d4(void* param0, int param1, int param2, void* param3) {
    if (func_020aaf84(param0, 0, 0, 1) == 0) {
        return 0;
    }
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    unsigned int* flags = (unsigned int*)GlobalFlags_GetInstance();
    FlagWord_SetBits(flags, 0x2000000);
    unsigned char* base = (unsigned char*)&g_fileLoadBuffer[0] + 0x28000;
    GameState* gs = GameState::GetInstance();
    unsigned char* arr = base + 4;
    func_020a93e0((char*)arr);
    char buf[0x30];
    struct Struct_020ab5d4 loc;
    loc.unknown_d4_ = arr[0x1d11];
    loc.unknown_d0_ = *(unsigned short*)(arr + 0x2c4c);
    int i;
    for (i = 0; i < loc.unknown_d4_; i++) {
        unsigned char* e = arr + (arr[0x1d0c] + i) * 0x23c;
        if (e != 0) {
            struct Struct_020ab5d4_5* el = &loc.elems[i];
            int v = PartyMemberRecord_GetVocation((struct Struct020865b0*)e);
            el->unknown_30_ = v;
            unsigned char* p = e + v;
            el->unknown_31_ = p[0xf];
            el->unknown_32_ = p[2];
            __clear(buf, 0x30);
            Font_DecodeText(e + 0x140, buf, 1);
            memcpy(el->data, buf, 0x30);
        }
    }
    unsigned char* var22 = base + 0x2cac;
    void* ctx = Scenario_GetInstance();
    func_020a9a50(var22, (char*)ctx, 0);
    loc.f109 = Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, 0x796);
    loc.unknown_d6_ = *(int*)var22;
    loc.f10b = Scenario_TestFlag((int)ctx, (unsigned char*)ctx + 0x8c, 0x1142) != 0;
    memcpy((char*)gs + 0x7e80, &loc, 0xd8);
    memcpy(param3, (char*)(((struct Struct_020ab5d4_2*)(base + 0x1d8)) + 1) + 0x3c, 4);
    if (func_020ac864(0) == 0) {
        BackgroundLoader::RemoveLockGlobal();
        FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x2000000);
        return 0;
    }
    BackgroundLoader::RemoveLockGlobal();
    FlagWord_ClearBits((struct FlagWord020466f4*)flags, 0x2000000);
    return 1;
}
#endif
