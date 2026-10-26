#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

struct Actor0209c174;
struct Obj_0205e88c;

extern "C" void func_ov011_021848a0(void* self, int state);
extern "C" SafeAllocator* func_ov011_021845f8(void* self, int index);
extern "C" void Overlay_Load(unsigned int id);
extern "C" int func_ov031_0221156c(void* data);
extern "C" void SePlayer_Reset(void* obj);
extern "C" void SoundPlayer_Reset(void* obj);
extern "C" int func_ov031_02212cbc(void* data);
extern "C" int func_ov031_02211608(void* data);
extern "C" void BgmPlayer_Init(Actor0209c174* actor);
extern "C" void BgmPlayer_LoadArchive(void* obj);
extern "C" void SePlayer_Init(Obj_0205e88c* obj);
extern "C" void SePlayer_LoadArchive(void* obj, int mode);
extern char g_sePlayer;
extern char g_bgmPlayer;

struct Struct_ov004_0216f634_2 {
    char pad0[0x30];
    unsigned char unknown_30_;
    char pad1;
    unsigned char unknown_32_;
    unsigned char unknown_33_;
    signed char unknown_34_;
};

struct Struct_ov004_02171048_6 {
    int f0;
    Struct_ov004_0216f634_2* flags;
};

extern Struct_ov004_02171048_6 data_ov004_02171048;

struct Struct_ov004_0216f634 {
    int f0;
    char data[0x40];
};

// USA: func_ov004_0216f634
extern "C" ARM int func_ov004_0216f634(void* self) {
    if (data_ov004_02171048.flags->unknown_30_ == 0) {
        func_ov011_021848a0(self, 0xd3);
    } else {
        GameState* gs = GameState::GetInstance();
        SePlayer_Reset(&g_sePlayer);
        SoundPlayer_Reset(&g_bgmPlayer);
        Overlay_Load(OVERLAY_ID(31));
        SafeAllocator* allocator = func_ov011_021845f8(self, 0);
        if (allocator == NULL) {
            return 0;
        }
        data_ov004_02171048.flags->unknown_34_ = func_ov031_02212cbc(((SafeAllocator*)((char*)allocator + 4))->Allocate(0x700));
        char buf[0x40];
#if defined(jpn)
        memcpy(buf, &((Struct_ov004_0216f634*)((char*)gs + 0x6120))->data, 0x40);
#else
        memcpy(buf, &((Struct_ov004_0216f634*)((char*)gs + 0x6380))->data, 0x40);
#endif
        data_ov004_02171048.flags->unknown_32_ = func_ov031_0221156c(buf) != 0;
        data_ov004_02171048.flags->unknown_33_ = func_ov031_02211608(buf) != 0;
        Overlay_Load(OVERLAY_ID(32));
        BgmPlayer_Init((Actor0209c174*)&g_bgmPlayer);
        BgmPlayer_LoadArchive(&g_bgmPlayer);
        SePlayer_Init((Obj_0205e88c*)&g_sePlayer);
        SePlayer_LoadArchive(&g_sePlayer, 100);
        if (data_ov004_02171048.flags->unknown_34_ == 3) {
            func_ov011_021848a0(self, 0xd4);
            return 0;
        }
        func_ov011_021848a0(self, 100);
    }
    return 0;
}
