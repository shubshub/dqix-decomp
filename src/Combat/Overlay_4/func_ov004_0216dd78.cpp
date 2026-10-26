#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);
extern "C" void* func_ov023_021fa598(void*);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int func_020ab7a8(void* obj, int flag);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" void func_02012028(void* obj, unsigned char value);

struct Struct_ov004_02171034_3 {
    #if defined(jpn)
    unsigned char pad0[0xc];
#else
    unsigned char pad0[0x10];
#endif
    unsigned char* unknown_10_;
};
extern struct Struct_ov004_02171034_3 data_ov004_02171034;

// USA: func_ov004_0216dd78
extern "C" ARM int func_ov004_0216dd78(void* a) {
    void* var0 = func_ov011_021849c8(a);
    void* var1 = func_ov023_021f6880(var0, 0x192);
    if (!var1) return 0;
    if (func_ov023_021f6f10(var1) != 4) return 0;

    void* table = func_ov023_021fa598(var1);
    void* battle = GameState::GetInstance();
    MessageSystem* message = (MessageSystem*)MessageSystem_GetInstance();
    struct FlagWord020466f4* flagWord = (struct FlagWord020466f4*)GlobalFlags_GetInstance();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    int ret = 1;
    void* node2 = func_ov023_021f6880(var0, 2);
    if (!node2) return 0;
    if (func_ov023_021f6f10(node2) != 0xb) return 0;

    *(unsigned char*)((char*)node2 + 0xc) &= ~8;
    message->b19ca = 0;
    message->unknown_19af_ = 0;

    int state = func_020ab7a8((void*)data_ov004_02171034.unknown_10_, ret);
    if (state == 5) {
        FlagWord_ClearBits(flagWord, 0x80);
        data_ov004_02171034.unknown_10_[1] = 0;
        func_ov011_021848a0(a, 0x194);
        ret = 0;
    } else if (state == 1) {
        FlagWord_ClearBits(flagWord, 0x80);
        data_ov004_02171034.unknown_10_[1] = 0;
        void* entry = func_02072a68((struct TableA68*)table, 0x5dc);
#if defined(jpn)
        func_0204500c(message, (const char*)entry, 0);
#else
        func_0204500c(message, (const char*)entry, 0, 0xe3);
#endif
        func_02012028(battle, 0);
        ret = 0;
    } else if (state == 2) {
        FlagWord_ClearBits(flagWord, 0x80);
        data_ov004_02171034.unknown_10_[1] = 0;
        void* entry = func_02072a68((struct TableA68*)table, 0x5dd);
#if defined(jpn)
        func_0204500c(message, (const char*)entry, 0);
#else
        func_0204500c(message, (const char*)entry, 0, 0xe3);
#endif
        func_02012028(battle, 0);
        ret = 0;
    } else if (state == 3) {
        FlagWord_ClearBits(flagWord, 0x80);
        data_ov004_02171034.unknown_10_[1] = 0;
        func_ov011_021848a0(a, 0x195);
        ret = 0;
    }

    if (ret == 0) {
        *(unsigned char*)((char*)node2 + 0xc) |= 8;
    }
    BackgroundLoader::RemoveLockGlobal();
    return ret;
}
