#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);
extern "C" void* func_ov023_021fa598(void*);
int MessageSystem_GetInstance(void);
void* GlobalFlags_GetInstance(void);
extern "C" int func_020ab7a8(void* obj, int flag);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_ov011_021848a0(void* obj, int val);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
void SetByte0x7f70_02012028(void* obj, unsigned char value);

struct Struct_ov004_02171034_3 {
    #if defined(jpn)
    unsigned char unknown_0_[0xc];
#else
    unsigned char unknown1_0_[0x10];
#endif
    unsigned char* unknown_10_;
};
extern struct Struct_ov004_02171034_3 data_ov004_02171034;

// USA: func_ov004_0216dd78
extern "C" ARM int func_ov004_0216dd78(void* arg0) {
    void* var0 = func_ov011_021849c8(arg0);
    void* var1 = func_ov023_021f6880(var0, 0x192);
    if (!var1) return 0;
    if (func_ov023_021f6f10(var1) != 4) return 0;

    void* table = func_ov023_021fa598(node1);
    void* battle = GameState::GetInstance();
    MessageSystem* message = (MessageSystem*)MessageSystem_GetInstance();
    struct FlagWord020466f4* flagWord = (struct FlagWord020466f4*)GlobalFlags_GetInstance();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    int var6 = 1;
    void* var7 = func_ov023_021f6880(var0, 2);
    if (!var7) return 0;
    if (func_ov023_021f6f10(var7) != 0xb) return 0;

    *(unsigned char*)((char*)var7 + 0xc) &= ~8;
    var4->unknown_19ca_ = 0;
    var4->unknown_19af_ = 0;

    int state = func_020ab7a8((void*)data_ov004_02171034.ptr10, ret);
    if (state == 5) {
        FlagWord_ClearBits(flagWord, 0x80);
        data_ov004_02171034.ptr10[1] = 0;
        func_ov011_021848a0(a, 0x194);
        ret = 0;
    } else if (state == 1) {
        FlagWord_ClearBits(flagWord, 0x80);
        data_ov004_02171034.ptr10[1] = 0;
        void* entry = FindEntryByKey_02072a68((struct TableA68*)table, 0x5dc);
#if defined(jpn)
        func_0204500c(var4, (const char*)var9, 0);
#else
        func_0204500c(var4, (const char*)var9, 0, 0xe3);
#endif
        SetByte0x7f70_02012028(battle, 0);
        ret = 0;
    } else if (state == 2) {
        FlagWord_ClearBits(flagWord, 0x80);
        data_ov004_02171034.ptr10[1] = 0;
        void* entry = FindEntryByKey_02072a68((struct TableA68*)table, 0x5dd);
#if defined(jpn)
        func_0204500c(var4, (const char*)var10, 0);
#else
        func_0204500c(var4, (const char*)var10, 0, 0xe3);
#endif
        SetByte0x7f70_02012028(battle, 0);
        ret = 0;
    } else if (state == 3) {
        FlagWord_ClearBits(flagWord, 0x80);
        data_ov004_02171034.ptr10[1] = 0;
        func_ov011_021848a0(a, 0x195);
        ret = 0;
    }

    if (var6 == 0) {
        *(unsigned char*)((char*)var7 + 0xc) |= 8;
    }
    BackgroundLoader::RemoveLockGlobal();
    return var6;
}
