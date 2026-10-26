#include <globaldefs.h>
#include "NitroSDK/Graphics.h"
#include "NitroSDK/Matrix.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Filesystem/NarcHandle.h"
#include "Memory/SafeAllocator.h"
#include "Resource/MessageSystem.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Combat/MapDisplay.h"

#if defined(jpn)
#define func_020c51dc func_020c6ca8
#endif


struct ClearTarget0205a234 {
    int field0;
    unsigned short field4;
};
struct Foo0207df50;
struct Struct020dfc40;
struct Container020e0310;
struct Struct020a9ea4;
struct PacRecord;
struct FlagWord020466f4;
struct Obj020444e0;
struct Obj0203bdb0;

extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void func_020daf9c(int a, int b, int c, int d);
extern "C" void SpriteContext_Init(char* obj);
extern "C" void Sprite_Init(Struct0205a198* obj);
extern "C" void func_0205a234(ClearTarget0205a234* obj);
extern "C" void GXx_SetMasterBrightness_(short* reg, int value);
extern "C" void func_0200fb84(int* obj, int value);
extern "C" char* BgVram_GetInstance();
extern "C" void BgVram_Clear(char* obj);
extern "C" void* OamManager_GetInstance(void);
extern "C" void OamManager_Init(char* ctx);
void LockStagedTextureVRAMCopying();
extern "C" unsigned int DisableTextureImageVRAMBanks();
extern "C" unsigned int DisableTexturePaletteVRAMBanks();
extern "C" unsigned int DisableMainBGVRAMBanks();
extern "C" unsigned int DisableSubBGVRAMBanks();
extern "C" unsigned int DisableMainObjVRAMBanks();
extern "C" unsigned int DisableSubObjVRAMBanks();
extern "C" void MapVRAMBanksToTextureImage(int banks);
extern "C" void func_020bb48c(unsigned int mode, int arg1);
extern "C" void MapVRAMBanksToTexturePalette(int banks);
extern "C" void MapVRAMBanksToMainBG(int banks);
extern "C" void GX_SetGraphicsMode(int mode, int a, int b);
extern "C" void MapVRAMBanksToMainObj(int banks);
void UpdateVRAMStagingVRAMBanks();
void UnlockStagedTextureVRAMCopying();
void Finish3DRendering();
extern "C" void func_020c51dc();
extern "C" void func_020c537c();
extern "C" void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" void G3i_OrthoW_(int, int, int, int, int, int, int, int, void*);
extern "C" void func_020bb780(void* arg, int flag);
extern "C" void VramState_Reserve(void* obj, int a, int b);
extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" void func_02042c68(MessageSystem* g);
extern "C" void MessageSystem_Stop(MessageSystem* g);
extern "C" void func_02042b30(void* g, void* tables);
extern "C" void VramState_Rewind(Foo0207df50* obj);
extern "C" void VramState_Restore(char* obj);
extern "C" void func_020432c4(MessageSystem* g);
extern "C" void VramState_Save(char* obj);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020440b8(char* g, void* alloc, void* data);
extern "C" void DebugConsole_Clear();
extern "C" void DebugConsole_Upload();
extern "C" void KeyTable_Reset(Struct020dfc40* obj);
extern "C" void KeyTable_Load(void* dest, SafeAllocator* allocator, void* fileData, unsigned int size);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void func_020d86d0(int a, int b);
extern "C" void OS_WaitVBlankIntr();
extern "C" void func_020bbcb4();
void UnlockAndSetMainBrightness(GameResources* res, int target, int frames);
void UnlockAndSetSubBrightness(GameResources* res, int target, int frames);
void UpdateAndApplyBrightness(GameResources* res);
extern "C" void func_020c38d4();
extern "C" void __clear(void* ptr, int size);
unsigned long long GetCurrentTimestamp();
extern "C" void Main_UpdateLidAndInput();
extern "C" int func_020457e0(MessageSystem* g);
extern "C" void FlagWord_SetBits(unsigned int* field, unsigned int bits);
extern "C" void func_020a9ea4(Struct020a9ea4* obj);
extern "C" int Pac_CountFiles(PacRecord* entries);
extern "C" void* Pac_GetFile(PacRecord* recs, int index, void** outField, int* outSize);
extern "C" void SpriteContext_LoadFile(void* obj, void* rec, int size, SafeAllocator* alloc);
extern "C" int func_020ab7a8(void* obj, int flag);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* field, unsigned int bits);
extern "C" void func_0209c6d8(void* actor, int id);
extern "C" int func_ov019_0218c240(void* scene);
extern "C" int func_020aba5c(int flag);
extern "C" void func_02043368(MessageSystem* g);
extern "C" void func_020bbd9c();
extern "C" void G3X_Reset();
extern "C" void G3X_ResetMtxStack();
extern "C" void G3i_LookAt_(int, int, int, int, void*);
extern "C" void func_020444e0(Obj020444e0* obj);
extern "C" void func_ov019_0218c178(void* scene);
extern "C" void OamManager_FlushBuffers(void* oam);
extern "C" void func_0204359c(void* obj, int value);
extern "C" void OamManager_UploadBuffers(Obj0203bdb0* obj);
extern "C" void func_020439b0(MessageSystem* g, int a);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_0200fb94(char* obj, unsigned char value);
extern "C" void func_02012010(void* obj, int value);

void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);

#if defined(jpn)
#define data_ov019_0218c2c0 data_ov019_0218cea0
#define data_ov019_0218c2d4 data_ov019_0218ceb4
#define data_ov019_0218c294 data_ov019_0218ce7c
#define data_ov019_0218c2a0 data_ov019_0218ce88
#define data_ov019_0218c2fe data_ov019_0218ced3
#endif
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
extern AllocatorUnion g_mainAllocator;
extern char g_bgmPlayer[];
extern char data_ov019_0218c2c0[];
extern char data_ov019_0218c2d4[];
extern char data_ov019_0218c2d8[];
extern char data_ov019_0218c2ed[];
extern char data_ov019_0218c2fe[];
extern Vector3fix data_ov019_0218c294;
extern Vector3fix data_ov019_0218c2a0;

#if defined(jpn)
struct TableA68;
struct Struct_020727d8;
struct StreamHeader;
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" void func_020727d8(struct Struct_020727d8* list);
extern "C" void func_020728ac(int param0, int param1, struct StreamHeader* buffer, int length, int arg4, unsigned short arg5, unsigned char arg6);
extern char data_ov019_0218ceb8[];
enum { Enum_ov019_0218b5a8_24 = 0x8, Enum_ov019_0218b5a8_728 = 0x228 };
#else
enum { Enum_ov019_0218b5a8_24 = 0x18, Enum_ov019_0218b5a8_728 = 0x2d8 };
#endif

struct Struct_ov019_0218b5a8 {
    char resources[0x28];
    unsigned char drawn;
    char unknown_29_[0x2c - 0x29];
    char menu[0x34 - 0x2c];
    char texts[Enum_ov019_0218b5a8_24];
    int flags;
    int unknown_50_;
    char icons[0x90 - 0x54];
    ClearTarget0205a234* unknown_90_;
    Struct0205a198* unknown_94_;
    char unknown_98_[0xa0 - 0x98];
    short iconCount;
    char unknown_a2_[0xa4 - 0xa2];
    unsigned char unknown_a4_;
    char unknown_a5_[0xa8 - 0xa5];
    Struct0205a198 entries[14];
    ClearTarget0205a234 tail;
};

static inline void inline_ov019_0218b5a8(MessageSystem* g, Struct_ov019_0218b5a8* self, int id) {
#if defined(jpn)
    func_0204500c(g, (const char*)func_02072a68((struct TableA68*)self->texts, id), 0);
#else
    func_0204500c(g, KeyTable_Get((Container020e0310*)self->texts, id), 0, 0xe3);
#endif
}

static inline void inline_ov016_0218b5c4(int offset) {
    unsigned int dispcnt = DISPCNT;
    DISPCNT = (dispcnt & ~0x7000000) | (offset << 24);
}

static inline void inline_ov016_0218b5c4_2(int offset) {
    unsigned int dispcnt = DISPCNT;
    DISPCNT = (dispcnt & ~0x38000000) | (offset << 27);
}

static inline void inline_ov017_021a86d0_2(int plane) {
    unsigned int dispcnt = DISPCNT;
    DISPCNT = (dispcnt & ~0x1f00) | (plane << 8);
}

static inline void inline_ov019_0218b5a8_2(int mode) {
    unsigned int dispcnt = DISPCNT;
    DISPCNT = (dispcnt & 0xffcfffef) | mode;
}

static inline void inline_ov017_021c0850(int sel) {
    *(volatile unsigned short*)0x4000304 = (unsigned short)((*(volatile unsigned short*)0x4000304 & ~0x8000) | (sel << 15));
}

static inline void inline_ov019_0218b5a8_3(int priority) {
    BG0CNT = (unsigned short)((BG0CNT & ~3) | priority);
}

static inline void inline_ov019_0218b5a8_4(int t, int b, int l, int r, int n, int f, int scaleW, void* mtx) {
    G3i_OrthoW_(t, b, l, r, n, f, scaleW, 1, mtx);
}

static inline void inline_ov019_0218b5a8_5(int num) {
    GXFIFO_MATRIX_STORE = num;
}

static inline void inline_ov019_0218b5a8_6(int x1, int arg1, int x2, int y2) {
    *(volatile unsigned int*)0x4000580 = x1 | (arg1 << 8) | (x2 << 16) | (y2 << 24);
}

static inline void inline_ov019_0218b5a8_7() {
    DISPCNTSUB |= 0x10000;
}

static inline void inline_ov019_0218b5a8_8(int mode) {
    GXFIFO_MATRIX_MODE = mode;
}

static inline void inline_ov019_0218b5a8_9(Vector3fix* camPos, Vector3fix* camUp, Vector3fix* target, void* mtx) {
    G3i_LookAt_((int)camPos, (int)camUp, (int)target, 1, mtx);
}

// USA: func_ov019_0218b5a8
extern "C" ARM void func_ov019_0218b5a8(Struct_ov019_0218b5a8* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned int* inputFlags = GlobalFlags_GetInstance();
    func_020daf9c(0, 0, 1, 0);
    self->flags = 0;
    self->unknown_50_ = 0;
    SpriteContext_Init(self->icons);
    for (int i = 0; i < 14; i++) {
        Sprite_Init(&self->entries[i]);
    }
    func_0205a234(&self->tail);
    GXx_SetMasterBrightness_((short*)0x400006c, -16);
    GXx_SetMasterBrightness_((short*)0x400106c, -16);
    func_0200fb84((int*)gs, (int)self);
    loader->ClearQueue();
    BgVram_Clear(BgVram_GetInstance());
    void* ctx = OamManager_GetInstance();
    OamManager_Init((char*)ctx);
    LockStagedTextureVRAMCopying();
    DisableTextureImageVRAMBanks();
    DisableTexturePaletteVRAMBanks();
    DisableMainBGVRAMBanks();
    DisableSubBGVRAMBanks();
    DisableMainObjVRAMBanks();
    DisableSubObjVRAMBanks();
    MapVRAMBanksToTextureImage(0xf);
    func_020bb48c(4, 1);
    MapVRAMBanksToTexturePalette(0x40);
    MapVRAMBanksToMainBG(0x10);
    inline_ov016_0218b5c4(0);
    inline_ov016_0218b5c4_2(0);
    BG1CNT = (BG1CNT & 0x43) | 4;
    inline_ov017_021a86d0_2(0x11);
    GX_SetGraphicsMode(1, 0, 1);
    MapVRAMBanksToMainObj(0x20);
    inline_ov019_0218b5a8_2(0x10);
    inline_ov017_021c0850(0);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    inline_ov019_0218b5a8_3(0);
    Set3DClearColor(0, 0x1f, 0x7fff, 0, 0);
    inline_ov019_0218b5a8_4(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, NULL);
    inline_ov019_0218b5a8_5(0);
    inline_ov019_0218b5a8_6(0, 0, 255, 191);
    func_020bb48c(4, 1);
    func_020bb780((void*)0x4000, 1);

    char tables[0x70];
    char savedTables[0x70];
    VramState_Reserve(tables, 0x4000, 0x20);
    VramState_Reserve(savedTables, 0x4000, 0x20);
    MessageSystem* g = MessageSystem_GetInstance();
    func_02042c68(g);
    MessageSystem_Stop(g);
    func_02042b30(g, tables);
    VramState_Rewind((Foo0207df50*)tables);
    VramState_Restore(tables);
    func_020432c4(g);
    VramState_Save(tables);

    unsigned int size;
    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(data_ov019_0218c2c0, g_fileLoadBuffer, &size) == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x19000);
    SafeAllocator alloc;
    alloc.ResetAllocatorPointer();
    alloc.CreateTypeA(buffer, 0x19000);
    NarcHandle narc;
    if (narc.Initialize(data_ov019_0218c2d4, g_fileLoadBuffer)) {
        VramState_Restore(savedTables);
        func_020440b8((char*)g, &alloc, g_fileLoadBuffer);
        VramState_Save(savedTables);
        narc.Destroy();
    }
    DebugConsole_Clear();
    DebugConsole_Upload();
    *(int*)((char*)g + Enum_ov019_0218b5a8_728) = 0;
#if defined(jpn)
    if (LoadFileIntoMemory(data_ov019_0218ceb8, g_fileLoadBuffer, &size) == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_020727d8((struct Struct_020727d8*)self->texts);
    func_020728ac((int)self->texts, (int)&alloc, (struct StreamHeader*)g_fileLoadBuffer, size, 0, 0, 0);
#else
    void* strings = ExtractFileFromGP2(data_ov019_0218c2d8, data_ov019_0218c2ed, &size);
    if (strings == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    KeyTable_Reset((Struct020dfc40*)self->texts);
    KeyTable_Load(self->texts, &alloc, strings, size);
#endif
    BackgroundLoader::RemoveLockGlobal();

    int state = 0;
    unsigned char mode = gs->unknown_5cc8_;
    if (mode == 0) {
        inline_ov019_0218b5a8(g, self, 0);
    } else if (mode == 1) {
        inline_ov019_0218b5a8(g, self, 1);
    } else if (mode == 2) {
        inline_ov019_0218b5a8(g, self, 2);
        state = 1;
    } else if (mode == 4) {
        inline_ov019_0218b5a8(g, self, 10);
    } else {
        inline_ov019_0218b5a8(g, self, 8);
        state = 8;
    }
    g->active = 1;
    func_020d86d0(0, 1);
    OS_WaitVBlankIntr();
    func_020bbcb4();
    UnlockAndSetMainBrightness((GameResources*)self, 0, 5);
    UnlockAndSetSubBrightness((GameResources*)self, -16, 1);
    UpdateAndApplyBrightness((GameResources*)self);
    func_020c38d4();
    inline_ov019_0218b5a8_7();

    Vector3fix target = data_ov019_0218c294;
    Vector3fix eye;
    __clear(&eye, sizeof(eye));
    Vector3fix up = data_ov019_0218c2a0;
    int running = 1;
    unsigned long long last = GetCurrentTimestamp();

    for (;;) {
        Main_UpdateLidAndInput();
        switch (state) {
        case 1:
            if (g->active == 0) {
                if (func_020457e0(g) == 0) {
                    FlagWord_SetBits(inputFlags, 0x80);
                    inline_ov019_0218b5a8(g, self, 5);
                    func_020a9ea4((Struct020a9ea4*)self->menu);
                    state = 3;
                } else if (func_020457e0(g) == 1) {
                    inline_ov019_0218b5a8(g, self, 3);
                    state = 2;
                }
                g->active = 1;
            }
            break;
        case 2:
            if (g->active == 0) {
                if (func_020457e0(g) == 0) {
                    inline_ov019_0218b5a8(g, self, 4);
                    state = 9;
                } else if (func_020457e0(g) == 1) {
                    inline_ov019_0218b5a8(g, self, 2);
                    state = 1;
                }
                g->active = 1;
            }
            break;
        case 3:
            if (g->mode == 4) {
                BackgroundLoader::AddLockGlobal();
                BackgroundLoader::FreeAllocationsGlobal();
                if (self->unknown_50_ == 0) {
                    if (LoadFileIntoMemory(data_ov019_0218c2fe, g_fileLoadBuffer, &size) == NULL) {
                        BackgroundLoader::RemoveLockGlobal();
                        return;
                    }
                    SpriteContext_Init(self->icons);
                    for (int i = 0; i < 14; i++) {
                        Sprite_Init(&self->entries[i]);
                    }
                    func_0205a234(&self->tail);
                    self->unknown_a4_ = 0;
                    self->unknown_94_ = self->entries;
                    self->iconCount = 14;
                    self->unknown_90_ = &self->tail;
                    void* data = g_fileLoadBuffer;
                    int count = Pac_CountFiles((PacRecord*)data);
                    for (int i = 0; i < count; i++) {
                        void* field;
                        int recSize;
                        void* rec = Pac_GetFile((PacRecord*)data, i, &field, &recSize);
                        SpriteContext_LoadFile(self->icons, rec, recSize, &alloc);
                    }
                    self->flags |= 1;
                    self->unknown_50_++;
                } else if (self->unknown_50_ == 1) {
                    int result = func_020ab7a8(self->menu, 1);
                    if (result == 1) {
                        inline_ov019_0218b5a8(g, self, 0);
                        g->active = 1;
                        FlagWord_ClearBits((FlagWord020466f4*)inputFlags, 0x80);
                        self->flags &= ~1;
                        state = 0;
                    } else if (result == 2) {
                        inline_ov019_0218b5a8(g, self, 1);
                        g->active = 1;
                        FlagWord_ClearBits((FlagWord020466f4*)inputFlags, 0x80);
                        self->flags &= ~1;
                        state = 0;
                    } else if (result == 3) {
                        FlagWord_ClearBits((FlagWord020466f4*)inputFlags, 0x80);
                        state = 6;
                    } else if (result == 5) {
                        FlagWord_ClearBits((FlagWord020466f4*)inputFlags, 0x80);
                        state = 4;
                    }
                    BackgroundLoader::RemoveLockGlobal();
                }
            }
            break;
        case 4:
            self->flags &= ~1;
            if (g->active == 0) {
                inline_ov019_0218b5a8(g, self, 7);
                g->active = 1;
                func_0209c6d8(g_bgmPlayer, 0x35);
                state = 5;
            }
            break;
        case 5:
            if (g->active == 0) {
                running = 0;
            }
            break;
        case 6:
            self->flags &= ~1;
            if (g->active == 0) {
                if (gs->unknown_5cc8_ == 0) {
                    inline_ov019_0218b5a8(g, self, 0);
                    state = 0;
                } else {
                    inline_ov019_0218b5a8(g, self, 6);
                    func_0209c6d8(g_bgmPlayer, 0x3d);
                    state = 7;
                }
                g->active = 1;
            }
            break;
        case 7:
            self->flags &= ~1;
            if (g->active == 0) {
                inline_ov019_0218b5a8(g, self, 4);
                state = 9;
                g->active = 1;
            }
            break;
        case 9:
            if (g->active == 0) {
                running = 0;
            }
            break;
        case 8:
            self->flags &= ~1;
            if (g->mode == 3 && func_ov019_0218c240(self) != 0) {
                if (func_020aba5c(1) == 0) {
                    inline_ov019_0218b5a8(g, self, 1);
                    state = 0;
                } else {
                    inline_ov019_0218b5a8(g, self, 9);
                    state = 9;
                }
            }
            break;
        }
        if (!running) {
            break;
        }
        UpdateAndApplyBrightness((GameResources*)self);
        loader->RemoveAllLocks();
        if (!(self->flags & 1)) {
            func_02043368(g);
        }
        if (g->mode != 3 && !(state == 3 && g->mode == 4)) {
            g->func_020444d4(1);
        }
        func_020bbd9c();
        G3X_Reset();
        G3X_ResetMtxStack();
        RenderConfig::Reset();
        DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
        DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
        inline_ov019_0218b5a8_8(0);
        inline_ov019_0218b5a8_9(&eye, &up, &target, NULL);
        inline_ov019_0218b5a8_4(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, NULL);
        inline_ov019_0218b5a8_8(2);
        func_020444e0((Obj020444e0*)g);
        func_ov019_0218c178(self);
        OamManager_FlushBuffers(ctx);
        func_0204359c(g, 0x10);
        func_020d86d0(0, 1);
        self->drawn = 1;
        OS_WaitVBlankIntr();
        OamManager_UploadBuffers((Obj0203bdb0*)ctx);
        func_020439b0(g, 1);
        gs->CalculateDeltaTime((GetCurrentTimestamp() - last) * 64 * 1000 / 33514);
        last = GetCurrentTimestamp();
    }

    alloc.Destroy();
    AllocatorUnion_Free(&g_mainAllocator, buffer);
    func_0200fb94((char*)gs, 6);
    func_02012010(gs, 0);
}
