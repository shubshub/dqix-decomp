#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "std_library_functions.h"
#include "Input/Input.h"

#if defined(jpn)
#define func_ov016_0218d2f4 func_ov016_0218d9f8
#define data_ov016_0219cfc0 data_ov016_0219cee0
#define data_ov016_0219cfc6 data_ov016_0219cee9
#define data_ov016_0219d022 data_ov016_0219ceef
#endif

struct StreamHeader;
struct Struct_020e57e0 { int words[3]; };
struct FieldBlock63d6_115a8;
struct Actor0209c678;
struct Actor0209c174;
struct Obj_0205e88c;

struct Struct_ov016_0218b5c4_7 { char data[0x40]; };

struct Menu0218b5c4 {
    char pad0[0x4c];
    int mode;
    char unknown_50_[0x5c - 0x50];
    short top;
    short last;
    short cursor;
    char unknown_62_[0x6d - 0x62];
    unsigned char flags;
    char unknown_6e_[0x70 - 0x6e];
    unsigned char unknown_70_;
    char unknown_71_;
    unsigned char unknown_72_;
};

struct Struct_ov016_0218b5c4 {
    SafeAllocator allocator;
    Menu0218b5c4 menu;
    char unknown_88_[0x94 - 0x88];
    int unknown_94_;
};

struct Struct_ov016_0218b5c4_2 {
    unsigned short id;
    char pad2[2];
    int value;
    const char* unknown_8_;
    const char* unknown_c_;
    char pad10;
    unsigned char fade;
};

struct Struct_ov016_0218b5c4_3 {
    Struct_ov016_0218b5c4_2* head;
    int count;
    int owner;
};

extern "C" int GXx_SetMasterBrightness_(short* out, int value);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void GX_SetGraphicsMode(int mode, int flagsA, int valB);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void GlyphMetrics_SetDisplayMode(int code);
extern "C" void GlyphBitmapContext_SetBuffer(void* ptr);
extern "C" void GlyphBitmapContext_SetUpLayer(int);
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" void G3i_OrthoW_(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int gate, void* outBuf);
extern "C" int func_ov016_0218bc70(int enable);
extern "C" void func_ov016_0218e00c(Struct_ov016_0218b5c4_3* list);
struct Struct_ov016_0218b5c4_4;
extern "C" void func_ov016_0218e098(Struct_ov016_0218b5c4_4*, int);
extern "C" void DebugMenu_Init(Menu0218b5c4* menu);
extern "C" void DebugMenuItem_SetText(void* self, const char* src);
extern "C" int func_ov016_0218e174(int*);
extern "C" void DebugMenuItem_Init(char*);
struct Struct_ov016_0218b5c4_5;
extern "C" Struct_ov016_0218b5c4_2* func_ov016_0218e14c(Struct_ov016_0218b5c4_5**, int);
struct ListHead0202a944;
struct ListNode0202a944;
extern "C" void DebugMenu_AddItem(ListHead0202a944*, ListNode0202a944*);
extern "C" void DebugMenu_UpdateLayout(Menu0218b5c4* menu);
extern "C" void DebugMenu_Open(char*, int);
extern "C" void OS_WaitVBlankIntr();
extern "C" void func_020c38d4();
extern "C" int func_020115a8(FieldBlock63d6_115a8* gs);
extern "C" void Main_UpdateLidAndInput();
extern "C" void G3X_Reset();
extern "C" void G3X_ResetMtxStack();
extern "C" void GlyphBitmapContext_Clear();
extern "C" void func_02029988(void* p, int flag);
extern "C" void GlyphBitmapContext_Flush();
extern "C" void func_020d86d0(int a, int b);
extern "C" void func_020bbcb4();
extern "C" void func_020290ac(int flag);
extern "C" void func_020e57e0(Struct_020e57e0* p);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" void func_020e57f4(int, int, StreamHeader*, int);
extern "C" int func_0201201c(void* gs);
struct Struct_ov016_0218b5c4_6;
extern "C" Struct_ov016_0218b5c4_2* func_ov016_0218e124(Struct_ov016_0218b5c4_6**, int);
extern "C" void BgmPlayer_FadeOut(Actor0209c678* actor, int arg);
extern "C" void SoundPlayer_StopStream(void* a, void* b, int c);
extern "C" void func_020bbd9c();
extern "C" void SePlayer_Reset(void* p);
extern "C" void SoundPlayer_Reset(void* p);
extern "C" void SePlayer_Init(Obj_0205e88c* p);
extern "C" void BgmPlayer_Init(Actor0209c174* p);
extern "C" void func_0209c2b8(void* p);
extern "C" void SePlayer_LoadArchive(void* p, int mode);
extern "C" void BgmPlayer_LoadArchive(void* p);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void ROMFilesystem_InitFileTables();
#if defined(jpn)
extern "C" void func_ov016_0218d2f4(char* arg0, char* arg1, Struct_ov016_0218b5c4* self, Struct_ov016_0218b5c4_2* node, int mode);
extern "C" void func_ov016_0218caa8(char* name, Struct_ov016_0218b5c4* self, Struct_ov016_0218b5c4_2* node, int mode);
#define SCRIPT_ARG_0218b5c4
#else
extern "C" void func_ov016_0218d2f4(char* arg0, char* arg1, Struct_ov016_0218b5c4* self, Struct_ov016_0218b5c4_2* node, int mode, Struct_020e57e0* script);
extern "C" void func_ov016_0218caa8(char* name, Struct_ov016_0218b5c4* self, Struct_ov016_0218b5c4_2* node, int mode, Struct_020e57e0* script);
#define SCRIPT_ARG_0218b5c4 , &script
#endif

extern AllocatorUnion g_mainAllocator;
extern char g_bgmPlayer;
extern char g_sePlayer;
extern const char data_ov016_0219cfc0[];
extern const char data_ov016_0219cfc6[];
extern const char data_ov016_0219cfcc[];
extern const char data_ov016_0219cfe6[];
extern const char data_ov016_0219cff7[];
extern const char data_ov016_0219d011[];
extern const char data_ov016_0219d022[];

static inline void inline_ov016_0218b5c4(int o) { DISPCNT = (DISPCNT & ~0x7000000) | (o << 24); }
static inline void inline_ov016_0218b5c4_2(int o) { DISPCNT = (DISPCNT & ~0x38000000) | (o << 27); }
// USA: func_ov016_0218b5c4
extern "C" ARM void func_ov016_0218b5c4(Struct_ov016_0218b5c4* self) {
    char var0[0x50];
    char var1[0x50];
    Struct_ov016_0218b5c4_3 nodes;
    char label[0x30];
#if !defined(jpn)
    Struct_020e57e0 script;
#endif
    char var5[0x28];
    char var6[0x28];
#if !defined(jpn)
    unsigned int size;
#endif

    GameState* gs = GameState::GetInstance();
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(1);
    inline_ov016_0218b5c4(0);
    inline_ov016_0218b5c4_2(0);
    GX_SetGraphicsMode(1, 0, 1);
    volatile unsigned short* var9 = (volatile unsigned short*)0x4000008;
    var9[0] = (var9[0] & ~0x3) | 0x1;
    var9[1] = var9[1] & ~0x3;
    ColorEffect_ConfigureAlphaBlend(0x4000050, BLEND_TARGET_BG0, BLEND_TARGET_BACKDROP, 0x1f, 0x1f);
    ColorEffect_ConfigureAlphaBlend(0x4000050, BLEND_TARGET_BG1, BLEND_TARGET_BG0, 0x1f, 0);
    func_020a0cc4(0x100000);
    self->allocator.CreateTypeB(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x100000), 0x100000, 4);
    void* buffer = self->allocator.Allocate(0x6000);
    GlyphMetrics_SetDisplayMode(3);
    GlyphBitmapContext_SetBuffer(buffer);
    GlyphBitmapContext_SetUpLayer(0);
    Set3DClearColor(0, 0x10, 0x7fff, 0x3f, 0);
    G3i_OrthoW_(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, 0);
    *(volatile unsigned int*)0x400044c = 0;
    func_ov016_0218bc70(0);

    func_ov016_0218e00c(&nodes);
    func_ov016_0218e098((Struct_ov016_0218b5c4_4*)&nodes, (int)self);
    DebugMenu_Init(&self->menu);
    DebugMenuItem_SetText(&self->menu, data_ov016_0219cfc0);
    Struct_ov016_0218b5c4_7* items = (Struct_ov016_0218b5c4_7*)self->allocator.Allocate(func_ov016_0218e174((int*)&nodes) * sizeof(Struct_ov016_0218b5c4_7));
    if (items != 0) {
        for (unsigned int i = 0; i < func_ov016_0218e174((int*)&nodes); i++) {
            DebugMenuItem_Init((char*)&items[i]);
            Struct_ov016_0218b5c4_2* node = func_ov016_0218e14c((Struct_ov016_0218b5c4_5**)&nodes, i);
            if (node != 0) {
                sprintf(label, data_ov016_0219cfc6, node->id, node->value);
                DebugMenuItem_SetText(&items[i], label);
                DebugMenu_AddItem((ListHead0202a944*)&self->menu, (ListNode0202a944*)&items[i]);
            }
        }
    }
    DebugMenu_UpdateLayout(&self->menu);
    int count = func_ov016_0218e174((int*)&nodes);
    self->menu.top = 0;
    self->menu.cursor = 0;
    self->menu.last = count - 1;
    self->menu.flags |= 6;
    self->menu.unknown_72_ = 1;
    self->menu.unknown_70_ = 1;
    self->menu.mode = 8;
    DebugMenu_Open((char*)&self->menu, 1);
    OS_WaitVBlankIntr();
    func_020c38d4();
    DISPCNTSUB |= 0x10000;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x300;
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);

    int id = -1;
    if (func_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
        id = func_020115a8((FieldBlock63d6_115a8*)gs);
        self->unknown_94_ = 0;
    }
    Main_UpdateLidAndInput();
    while (id < 0) {
        Main_UpdateLidAndInput();
        G3X_Reset();
        G3X_ResetMtxStack();
        DISP3DCNT &= (unsigned short)~0x3020;
        if (g_keyManager.TestKeysPressed(1)) {
            Struct_ov016_0218b5c4_2* node = func_ov016_0218e14c((Struct_ov016_0218b5c4_5**)&nodes, self->menu.cursor);
            if (node != 0) {
                id = node->id;
            }
        } else if (g_keyManager.TestKeysPressed(2)) {
            self->unknown_94_ = 0;
            break;
        }
        GlyphBitmapContext_Clear();
        func_02029988(&self->menu, 1);
        GlyphBitmapContext_Flush();
        func_020d86d0(0, 1);
        OS_WaitVBlankIntr();
        func_020bbcb4();
        func_020290ac(0);
        GXx_SetMasterBrightness_((short*)0x400006c, 0);
        GXx_SetMasterBrightness_((short*)0x400106c, -16);
    }

#if !defined(jpn)
    func_020e57e0(&script);
    BackgroundLoader::GetInstance();
    if (id > 0) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        void* file = 0;
        switch (id) {
        case 4:
            file = ExtractFileFromGP2(data_ov016_0219cfcc, data_ov016_0219cfe6, &size);
            break;
        case 8:
            file = ExtractFileFromGP2(data_ov016_0219cff7, data_ov016_0219d011, &size);
            break;
        }
        if (file != 0) {
            func_020e57f4((int)&script, (int)self, (StreamHeader*)file, size);
        }
        BackgroundLoader::RemoveLockGlobal();
    }
#endif
    GlyphBitmapContext_Clear();
    GlyphBitmapContext_Flush();
    func_020d86d0(0, 1);

    int mode = 2;
    if (func_0201201c(gs) == 5) {
        mode = 1;
    } else if (func_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
        mode = 0;
    }

    if (id >= 0) {
        GXx_SetMasterBrightness_((short*)0x400006c, -16);
        GXx_SetMasterBrightness_((short*)0x400106c, -16);
        Struct_ov016_0218b5c4_2* node = func_ov016_0218e124((Struct_ov016_0218b5c4_6**)&nodes, id);
        if (node != 0) {
#if !defined(jpn)
            if (node->fade != 0) {
                BgmPlayer_FadeOut((Actor0209c678*)&g_bgmPlayer, 0);
                SoundPlayer_StopStream(&g_bgmPlayer, 0, 0);
                func_020bbd9c();
                SePlayer_Reset(&g_sePlayer);
                SoundPlayer_Reset(&g_bgmPlayer);
                SePlayer_Init((Obj_0205e88c*)&g_sePlayer);
                BgmPlayer_Init((Actor0209c174*)&g_bgmPlayer);
                func_0209c2b8(&g_bgmPlayer);
            }
#endif
            if (node->unknown_8_ != 0 && node->unknown_c_ != 0) {
                func_ov016_0218bc70(1);
                sprintf(var0, data_ov016_0219d022, node->unknown_8_);
                sprintf(var1, data_ov016_0219d022, node->unknown_c_);
                func_ov016_0218d2f4(var0, var1, self, node, mode SCRIPT_ARG_0218b5c4);
            } else if (node->unknown_8_ != 0 && node->unknown_c_ == 0) {
                func_ov016_0218bc70(1);
                sprintf(var5, data_ov016_0219d022, node->unknown_8_);
                func_ov016_0218caa8(var5, self, node, mode SCRIPT_ARG_0218b5c4);
            } else if (node->unknown_8_ == 0 && node->unknown_c_ != 0) {
                func_ov016_0218bc70(0);
                sprintf(var6, data_ov016_0219d022, node->unknown_c_);
                func_ov016_0218caa8(var6, self, node, mode SCRIPT_ARG_0218b5c4);
            }
#if !defined(jpn)
            if (node->fade != 0) {
                SePlayer_Reset(&g_sePlayer);
                SoundPlayer_Reset(&g_bgmPlayer);
                SePlayer_Init((Obj_0205e88c*)&g_sePlayer);
                BgmPlayer_Init((Actor0209c174*)&g_bgmPlayer);
                SePlayer_LoadArchive(&g_sePlayer, 100);
                BgmPlayer_LoadArchive(&g_bgmPlayer);
            }
#endif
        }
    }

    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    SignedAllocatorHeader* signedAlloc = self->allocator.GetSignedAllocator();
    self->allocator.Destroy();
    AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
    ROMFilesystem_InitFileTables();
    GlyphBitmapContext_SetBuffer(0);
}
