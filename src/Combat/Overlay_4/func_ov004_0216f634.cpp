#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

struct Struct_02000c9c_16;
struct Struct_02000c9c_17;

extern "C" void func_ov011_021848a0(void* self, int state);
extern "C" SafeAllocator* func_ov011_021845f8(void* self, int index);
extern "C" void Overlay_Load(unsigned int id);
extern "C" int func_ov031_0221156c(void* data);
void SePlayer_Reset(void* obj);
void SoundPlayer_Reset(void* obj);
int ProcessAndClassify_02212cbc(void* data);
int CompareField10PairOrZero_02211608(void* data);
void BgmPlayer_Init(Actor0209c174* actor);
void BgmPlayer_LoadArchive(void* obj);
void SePlayer_Init(Obj_0205e88c* obj);
void SePlayer_LoadArchive(void* obj, int mode);
extern char g_sePlayer;
extern char g_bgmPlayer;

struct Struct_ov004_0216f634_2 {
    char unknown_0_[0x30];
    unsigned char unknown_30_;
    char unknown_31_;
    unsigned char unknown_32_;
    unsigned char unknown_33_;
    signed char unknown_34_;
};

struct Struct_ov004_02171048_6 {
    int unknown_0_;
    Struct_ov004_0216f634_2* unknown_4_;
};

extern Struct_ov004_02171048_6 data_ov004_02171048;

struct Struct_ov004_0216f634 {
    int unknown_0_;
    char unknown_4_[0x40];
};

// USA: func_ov004_0216f634
extern "C" ARM int func_ov004_0216f634(void* arg0) {
    if (data_ov004_02171048.unknown_4_->unknown_30_ == 0) {
        func_ov011_021848a0(arg0, 0xd3);
    } else {
        GameState* gs = GameState::GetInstance();
        SePlayer_Reset(&g_sePlayer);
        SoundPlayer_Reset(&g_bgmPlayer);
        Overlay_Load(OVERLAY_ID(31));
        SafeAllocator* allocator = func_ov011_021845f8(self, 0);
        if (allocator == NULL) {
            return 0;
        }
        data_ov004_02171048.unknown_4_->unknown_34_ = func_ov031_02212cbc(((SafeAllocator*)((char*)var1 + 4))->Allocate(0x700));
        char var2[0x40];
#if defined(jpn)
        memcpy(var2, &((Struct_ov004_0216f634*)((char*)var0 + 0x6120))->unknown_4_, 0x40);
#else
        memcpy(var2, &((Struct_ov004_0216f634*)((char*)var0 + 0x6380))->unknown_4_, 0x40);
#endif
        data_ov004_02171048.flags->b32 = func_ov031_0221156c(buf) != 0;
        data_ov004_02171048.flags->b33 = CompareField10PairOrZero_02211608(buf) != 0;
        Overlay_Load(OVERLAY_ID(32));
        BgmPlayer_Init((Actor0209c174*)&g_bgmPlayer);
        BgmPlayer_LoadArchive(&g_bgmPlayer);
        SePlayer_Init((Obj_0205e88c*)&g_sePlayer);
        SePlayer_LoadArchive(&g_sePlayer, 100);
        if (data_ov004_02171048.flags->b34 == 3) {
            func_ov011_021848a0(self, 0xd4);
            return 0;
        }
        func_ov011_021848a0(arg0, 100);
    }
    return 0;
}
