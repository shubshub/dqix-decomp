#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" int func_020ab7a8(void* obj, int flag);
extern "C" void func_0200fb94(char* obj, unsigned char value);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
extern "C" void* func_ov004_0216ae9c(void* a, int id);
extern "C" void func_ov023_021f8960(char* base, short a, unsigned short b);

struct Struct_ov004_02171034_3 {
#if defined(jpn)
#else
    unsigned char pad0[2];
#endif
    unsigned char flag2;
#if defined(jpn)
    unsigned char pad1[4];
#else
#endif
    unsigned char unknown_3_;
#if defined(jpn)
    unsigned char pad4[6];
#else
    unsigned char pad4[0xc];
#endif
    unsigned char* unknown_10_;
};
extern struct Struct_ov004_02171034_3 data_ov004_02171034;

// USA: func_ov004_0216e258
extern "C" ARM int func_ov004_0216e258(void* a) {
    GameState* battle = GameState::GetInstance();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int state = func_020ab7a8((void*)data_ov004_02171034.unknown_10_, 0);
    int ret = 1;
    if (state == 5) {
        func_0200fb94((char*)battle, 5);
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        data_ov004_02171034.flag2 = 0;
        data_ov004_02171034.unknown_10_[1] = 0;
        func_ov011_021848a0(a, 0x3e7);
        ret = 0;
    } else if (state == 1) {
        char* g = (char*)MessageSystem_GetInstance();
        MessageSystem_Reset(g);
        MessageSystem_Stop(g);
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        void* node = func_ov004_0216ae9c(a, 0xd4);
        func_ov023_021f8960((char*)node, 0, 7);
        data_ov004_02171034.unknown_10_[1] = 0;
        func_ov011_021848a0(a, 0x1f4);
        ret = 0;
    } else if (state == 2) {
        char* g = (char*)MessageSystem_GetInstance();
        MessageSystem_Reset(g);
        MessageSystem_Stop(g);
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        void* node = func_ov004_0216ae9c(a, 0xd4);
        func_ov023_021f8960((char*)node, 0, 7);
        data_ov004_02171034.unknown_10_[1] = 0;
        func_ov011_021848a0(a, 0x1f5);
        ret = 0;
    } else if (state == 3) {
        char* g = (char*)MessageSystem_GetInstance();
        MessageSystem_Reset(g);
        MessageSystem_Stop(g);
        data_ov004_02171034.unknown_3_ = 4;
        data_ov004_02171034.unknown_10_[1] = 0;
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        func_ov011_021848a0(a, 0x190);
        ret = 0;
    }
    BackgroundLoader::RemoveLockGlobal();
    return ret;
}
