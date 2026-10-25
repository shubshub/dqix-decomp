#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" int func_020ab7a8(void* obj, int flag);
void SetByte0x4_0200fb94(char* obj, unsigned char value);
void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_ov011_021848a0(void* obj, int val);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
void* GetNodeIfType6_0216ae9c(void* a, int id);
void SetOffset100Fields_021f8960(char* base, short a, unsigned short b);

struct Struct_ov004_02171034_3 {
#if defined(jpn)
#else
    unsigned char unknown_0_[2];
#endif
    unsigned char unknown_2_;
#if defined(jpn)
    unsigned char unknown_1_[4];
#else
#endif
    unsigned char unknown_3_;
#if defined(jpn)
    unsigned char unknown_6_[6];
#else
    unsigned char unknown_4_[0xc];
#endif
    unsigned char* unknown_10_;
};
extern struct Struct_ov004_02171034_3 data_ov004_02171034;

// USA: func_ov004_0216e258
extern "C" ARM int func_ov004_0216e258(void* arg0) {
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    int state = func_020ab7a8((void*)data_ov004_02171034.ptr10, 0);
    int ret = 1;
    if (state == 5) {
        SetByte0x4_0200fb94((char*)battle, 5);
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        data_ov004_02171034.flag2 = 0;
        data_ov004_02171034.ptr10[1] = 0;
        func_ov011_021848a0(a, 0x3e7);
        ret = 0;
    } else if (state == 1) {
        char* g = (char*)MessageSystem_GetInstance();
        MessageSystem_Reset(g);
        MessageSystem_Stop(g);
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        void* node = GetNodeIfType6_0216ae9c(a, 0xd4);
        SetOffset100Fields_021f8960((char*)node, 0, 7);
        data_ov004_02171034.ptr10[1] = 0;
        func_ov011_021848a0(a, 0x1f4);
        ret = 0;
    } else if (state == 2) {
        char* g = (char*)MessageSystem_GetInstance();
        MessageSystem_Reset(g);
        MessageSystem_Stop(g);
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        void* node = GetNodeIfType6_0216ae9c(a, 0xd4);
        SetOffset100Fields_021f8960((char*)node, 0, 7);
        data_ov004_02171034.ptr10[1] = 0;
        func_ov011_021848a0(a, 0x1f5);
        ret = 0;
    } else if (state == 3) {
        char* g = (char*)MessageSystem_GetInstance();
        MessageSystem_Reset(g);
        MessageSystem_Stop(g);
        data_ov004_02171034.state3 = 4;
        data_ov004_02171034.ptr10[1] = 0;
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x80);
        func_ov011_021848a0(a, 0x190);
        ret = 0;
    }
    BackgroundLoader::RemoveLockGlobal();
    return var2;
}
