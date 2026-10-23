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

#if defined(jpn)
#define func_020c39a0 func_020c546c
#endif

struct Struct_02043368 {
    int unknown_0_;
    unsigned short unknown_4_;
};
struct Struct_0203d028;
struct Struct_0201099c_14;
struct Struct_0201099c_3;
struct Struct_020a9ea4;
struct Struct_02020cb8_4;
struct Struct_02020aec;
struct Struct_02038598_4;
struct Struct_020444e0;
struct Struct_0203bdb0;

unsigned int* GetDataPtr02114e04_020d6c00();
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
void SpriteContext_Init(char* obj);
void Sprite_Init(Struct0205a198* obj);
void ClearField0And40205a234(ClearTarget0205a234* obj);
extern "C" void func_020c39a0(short* reg, int value);
void SetWord0x0_0200fb84(int* obj, int value);
char* GetData02105254_0203b628();
void ClearThreeRegions0203b634(char* obj);
extern "C" void* func_0203bd08(void);
extern "C" void func_0203bd24(char* arg0);
void LockStagedTextureVRAMCopying();
extern "C" unsigned int DisableTextureImageVRAMBanks();
extern "C" unsigned int DisableTexturePaletteVRAMBanks();
extern "C" unsigned int DisableMainBGVRAMBanks();
extern "C" unsigned int DisableSubBGVRAMBanks();
extern "C" unsigned int DisableMainObjVRAMBanks();
extern "C" unsigned int DisableSubObjVRAMBanks();
extern "C" void MapVRAMBanksToTextureImage(int banks);
extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void MapVRAMBanksToTexturePalette(int banks);
extern "C" void MapVRAMBanksToMainBG(int banks);
extern "C" void func_020c391c(int arg0, int arg1, int arg2);
extern "C" void MapVRAMBanksToMainObj(int banks);
void UpdateVRAMStagingVRAMBanks();
void UnlockStagedTextureVRAMCopying();
void Finish3DRendering();
extern "C" void func_020c51dc();
void ResetMatrixStacks020c537c();
void Set3DClearColor_020c5588(int color, int alpha, int depth, int polygonId, int fogEnable);
void ComputeAndLoadMatrix020c5770(int, int, int, int, int, int, int, int, void*);
void InitGlobalStateAndInstallHandlers020bb780(void* arg, int flag);
extern "C" void VramState_Reserve(void* obj, int a, int b);
MessageSystem* GetGlobalField0x1c020421a0();
extern "C" void func_02042c68(MessageSystem* g);
extern "C" void func_02043124(MessageSystem* g);
void SetField0x1e28_02042b30(void* g, void* tables);
void CopyInternalFields0207df50(Foo0207df50* obj);
void VramState_Restore(char* obj);
extern "C" void func_020432c4(MessageSystem* g);
void VramState_Save(char* obj);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void CallFunc0202f310AtField0x19e0_020440b8(char* g, void* alloc, void* data);
void ClearBuffer0202ad30();
void FlushAndClearBuffer0202adf0();
void KeyTable_Reset(Struct020dfc40* obj);
extern "C" void KeyTable_Load(void* dest, SafeAllocator* allocator, void* fileData, unsigned int size);
const char* KeyTable_Get(Container020e0310* texts, int id);
void WriteControlAndToggle020d86d0(int a, int b);
void DelayThenSyncBit0_020c9820();
void ProcessRingJobs020bbcb4();
void UnlockAndSetMainBrightness(GameResources* res, int target, int frames);
void UnlockAndSetSubBrightness(GameResources* res, int target, int frames);
void UpdateAndApplyBrightness(GameResources* res);
extern "C" void func_020c38d4();
extern "C" void __clear(void* arg0, int arg1);
unsigned long long GetCurrentTimestamp();
void InitCombatSubsystems02012efc();
extern "C" int func_020457e0(MessageSystem* g);
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
void ClearStruct020a9ea4(Struct020a9ea4* obj);
int Pac_CountFiles(ActiveEntry02046900* entries);
void* Pac_GetFile(Rec020467f0* recs, int index, void** outField, int* outSize);
extern "C" void SpriteContext_LoadFile(void* obj, void* rec, int size, SafeAllocator* alloc);
extern "C" int func_020ab7a8(void* obj, int flag);
void ClearFlags020466f4(FlagWord020466f4* field, unsigned int bits);
void ResetAndDispatchActorContext0209c6d8(void* actor, int id);
int TriggerDispatchIfFlagOrByte_0218c240(void* scene);
int SendShortBufferOrReturnZero020aba5c(int flag);
extern "C" void func_02043368(MessageSystem* g);
extern "C" void func_020bbd9c();
extern "C" void func_020c52e8();
extern "C" void func_020c5414();
extern "C" void func_020c57d4(int, int, int, int, void*);
extern "C" void func_020444e0(Struct_020444e0* arg0);
extern "C" void func_ov019_0218c178(void* arg0);
extern "C" void func_0203bd88(void* arg0);
extern "C" void func_0204359c(void* arg0, int arg1);
extern "C" void func_0203bdb0(Struct_0203bdb0* arg0);
extern "C" void func_020439b0(Struct_02021b84* arg0, int arg1);
extern "C" void func_02012da4(AllocatorUnion* arg0, void* arg1);
extern "C" void func_0200fb94(char* arg0, unsigned char arg1);
extern "C" void func_02012010(void* arg0, int arg1);

void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);

#if defined(jpn)
#define data_ov019_0218c2c0 data_ov019_0218cea0
#define data_ov019_0218c2d4 data_ov019_0218ceb4
#define data_ov019_0218c294 data_ov019_0218ce7c
#define data_ov019_0218c2a0 data_ov019_0218ce88
#define data_ov019_0218c2fe data_ov019_0218ced3
#endif
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
extern AllocatorUnion data_02114e20;
extern char data_02109bf4[];
extern char data_ov019_0218c2c0[];
extern char data_ov019_0218c2d4[];
extern char data_ov019_0218c2d8[];
extern char data_ov019_0218c2ed[];
extern char data_ov019_0218c2fe[];
extern Vector3fix data_ov019_0218c294;
extern Vector3fix data_ov019_0218c2a0;

#if defined(jpn)
struct Struct_02072a68_2;
struct Struct_020727d8;
struct Struct_02013fb4;
extern "C" void* func_02072a68(struct Struct_02072a68_2* arg0, int arg1);
extern "C" void func_020727d8(struct Struct_020727d8* arg0);
extern "C" void func_020728ac(int arg0, int arg1, struct Struct_02013fb4* arg2, int arg3, int arg4, unsigned short arg5, unsigned char arg6);
extern char data_ov019_0218ceb8[];
enum { Enum_ov019_0218b5a8_24 = 0x8, Enum_ov019_0218b5a8_728 = 0x228 };
#else
enum { Enum_ov019_0218b5a8_24 = 0x18, Enum_ov019_0218b5a8_728 = 0x2d8 };
#endif

struct Struct_ov019_0218b5a8 {
    char unknown_0_[0x28];
    unsigned char unknown_28_;
    char unknown_29_[0x2c - 0x29];
    char unknown_2c_[0x34 - 0x2c];
    char unknown_34_[Enum_ov019_0218b5a8_24];
    int unknown_4c_;
    int unknown_50_;
    char unknown_54_[0x90 - 0x54];
    Struct_02043368* unknown_90_;
    Struct_02043368_2* unknown_94_;
    char unknown_98_[0xa0 - 0x98];
    short unknown_a0_;
    char unknown_a2_[0xa4 - 0xa2];
    unsigned char unknown_a4_;
    char unknown_a5_[0xa8 - 0xa5];
    Struct_02043368_2 unknown_a8_[14];
    Struct_02043368 unknown_2d8_;
};

static inline void inline_ov019_0218b5a8(Struct_02021b84* arg0, Struct_ov019_0218b5a8* arg1, int arg2) {
#if defined(jpn)
    func_0204500c(arg0, (const char*)func_02072a68((struct Struct_02072a68_2*)arg1->unknown_34_, arg2), 0);
#else
    func_0204500c(g, KeyTable_Get((Container020e0310*)self->texts, id), 0, 0xe3);
#endif
}

static inline void inline_ov016_0218b5c4(int arg0) {
    unsigned int var0 = DISPCNT;
    DISPCNT = (var0 & ~0x7000000) | (arg0 << 24);
}

static inline void inline_ov016_0218b5c4_2(int arg0) {
    unsigned int var0 = DISPCNT;
    DISPCNT = (var0 & ~0x38000000) | (arg0 << 27);
}

static inline void inline_ov017_021a86d0_2(int arg0) {
    unsigned int var0 = DISPCNT;
    DISPCNT = (var0 & ~0x1f00) | (arg0 << 8);
}

static inline void inline_ov019_0218b5a8_2(int arg0) {
    unsigned int var0 = DISPCNT;
    DISPCNT = (var0 & 0xffcfffef) | arg0;
}

static inline void inline_ov017_021c0850(int arg0) {
    *(volatile unsigned short*)0x4000304 = (unsigned short)((*(volatile unsigned short*)0x4000304 & ~0x8000) | (arg0 << 15));
}

static inline void inline_ov019_0218b5a8_3(int arg0) {
    BG0CNT = (unsigned short)((BG0CNT & ~3) | arg0);
}

static inline void inline_ov019_0218b5a8_4(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, void* arg7) {
    func_020c5770(arg0, arg1, arg2, arg3, arg4, arg5, arg6, 1, arg7);
}

static inline void inline_ov019_0218b5a8_5(int arg0) {
    GXFIFO_MATRIX_STORE = arg0;
}

static inline void inline_ov019_0218b5a8_6(int arg0, int arg1, int arg2, int arg3) {
    *(volatile unsigned int*)0x4000580 = arg0 | (arg1 << 8) | (arg2 << 16) | (arg3 << 24);
}

static inline void inline_ov019_0218b5a8_7() {
    DISPCNTSUB |= 0x10000;
}

static inline void inline_ov019_0218b5a8_8(int arg0) {
    GXFIFO_MATRIX_MODE = arg0;
}

static inline void inline_ov019_0218b5a8_9(Vector3fix* arg0, Vector3fix* arg1, Vector3fix* arg2, void* arg3) {
    func_020c57d4((int)arg0, (int)arg1, (int)arg2, 1, arg3);
}

// USA: func_ov019_0218b5a8
extern "C" ARM void func_ov019_0218b5a8(TitleScene0218b5a8* self) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned int* inputFlags = GetDataPtr02114e04_020d6c00();
    DispatchWithGlobalContext020daf9c(0, 0, 1, 0);
    self->flags = 0;
    self->loadCount = 0;
    SpriteContext_Init(self->icons);
    for (int i = 0; i < 14; i++) {
        Sprite_Init(&self->entries[i]);
    }
    func_0205a234(&arg0->unknown_2d8_);
    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
    func_0200fb84((int*)var0, (int)arg0);
    var1->MaybeReset();
    func_0203b634(func_0203b628());
    void* var4 = func_0203bd08();
    func_0203bd24((char*)var4);
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
    func_020c391c(1, 0, 1);
    MapVRAMBanksToMainObj(0x20);
    inline_ov019_0218b5a8_2(0x10);
    inline_ov017_021c0850(0);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    Finish3DRendering();
    func_020c51dc();
    func_020c537c();
    inline_ov019_0218b5a8_3(0);
    func_020c5588(0, 0x1f, 0x7fff, 0, 0);
    inline_ov019_0218b5a8_4(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, NULL);
    inline_ov019_0218b5a8_5(0);
    inline_ov019_0218b5a8_6(0, 0, 255, 191);
    func_020bb48c(4, 1);
    func_020bb780((void*)0x4000, 1);

    char tables[0x70];
    char savedTables[0x70];
    VramState_Reserve(tables, 0x4000, 0x20);
    VramState_Reserve(savedTables, 0x4000, 0x20);
    MessageSystem* g = GetGlobalField0x1c020421a0();
    func_02042c68(g);
    func_02043124(g);
    SetField0x1e28_02042b30(g, tables);
    CopyInternalFields0207df50((Foo0207df50*)tables);
    VramState_Restore(tables);
    func_020432c4(g);
    VramState_Save(tables);

    unsigned int var8;
    BackgroundLoader::AddLockGlobal();
    if (LoadFileIntoMemory(data_ov019_0218c2c0, data_0211e33c, &var8) == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    void* buffer = AllocateAligned4_02012d88(&data_02114e20, 0x19000);
    SafeAllocator alloc;
    alloc.ResetAllocatorPointer();
    alloc.CreateTypeA(buffer, 0x19000);
    NarcHandle narc;
    if (narc.Initialize(data_ov019_0218c2d4, data_0211e33c)) {
        VramState_Restore(savedTables);
        CallFunc0202f310AtField0x19e0_020440b8((char*)g, &alloc, data_0211e33c);
        VramState_Save(savedTables);
        narc.Destroy();
    }
    func_0202ad30();
    func_0202adf0();
    *(int*)((char*)var7 + Enum_ov019_0218b5a8_728) = 0;
#if defined(jpn)
    if (LoadFileIntoMemory(data_ov019_0218ceb8, data_0211e33c, &var8) == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    func_020727d8((struct Struct_020727d8*)arg0->unknown_34_);
    func_020728ac((int)arg0->unknown_34_, (int)&var10, (struct Struct_02013fb4*)data_0211e33c, var8, 0, 0, 0);
#else
    void* var12 = ExtractFileFromGP2(data_ov019_0218c2d8, data_ov019_0218c2ed, &var8);
    if (var12 == NULL) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    KeyTable_Reset((Struct020dfc40*)self->texts);
    KeyTable_Load(self->texts, &alloc, strings, size);
#endif
    BackgroundLoader::RemoveLockGlobal();

    int var13 = 0;
    unsigned char var14 = var0->unknown_5cc8_;
    if (var14 == 0) {
        inline_ov019_0218b5a8(var7, arg0, 0);
    } else if (var14 == 1) {
        inline_ov019_0218b5a8(var7, arg0, 1);
    } else if (var14 == 2) {
        inline_ov019_0218b5a8(var7, arg0, 2);
        var13 = 1;
    } else if (var14 == 4) {
        inline_ov019_0218b5a8(var7, arg0, 10);
    } else {
        inline_ov019_0218b5a8(var7, arg0, 8);
        var13 = 8;
    }
    var7->unknown_998_ = 1;
    func_020d86d0(0, 1);
    func_020c9820();
    func_020bbcb4();
    UnlockAndSetMainBrightness((GameResources*)arg0, 0, 5);
    UnlockAndSetSubBrightness((GameResources*)arg0, -16, 1);
    UpdateAndApplyBrightness((GameResources*)arg0);
    func_020c38d4();
    inline_ov019_0218b5a8_7();

    Vector3fix var15 = data_ov019_0218c294;
    Vector3fix var16;
    __clear(&var16, sizeof(var16));
    Vector3fix var17 = data_ov019_0218c2a0;
    int var18 = 1;
    unsigned long long var19 = GetCurrentTimestamp();

    for (;;) {
        func_02012efc();
        switch (var13) {
        case 1:
            if (var7->unknown_998_ == 0) {
                if (func_020457e0(var7) == 0) {
                    func_020466e4(var2, 0x80);
                    inline_ov019_0218b5a8(var7, arg0, 5);
                    func_020a9ea4((Struct_020a9ea4*)arg0->unknown_2c_);
                    var13 = 3;
                } else if (func_020457e0(var7) == 1) {
                    inline_ov019_0218b5a8(var7, arg0, 3);
                    var13 = 2;
                }
                var7->unknown_998_ = 1;
            }
            break;
        case 2:
            if (var7->unknown_998_ == 0) {
                if (func_020457e0(var7) == 0) {
                    inline_ov019_0218b5a8(var7, arg0, 4);
                    var13 = 9;
                } else if (func_020457e0(var7) == 1) {
                    inline_ov019_0218b5a8(var7, arg0, 2);
                    var13 = 1;
                }
                var7->unknown_998_ = 1;
            }
            break;
        case 3:
            if (var7->unknown_9a0_ == 4) {
                BackgroundLoader::AddLockGlobal();
                BackgroundLoader::FreeAllocationsGlobal();
                if (arg0->unknown_50_ == 0) {
                    if (LoadFileIntoMemory(data_ov019_0218c2fe, data_0211e33c, &var8) == NULL) {
                        BackgroundLoader::RemoveLockGlobal();
                        return;
                    }
                    SpriteContext_Init(self->icons);
                    for (int i = 0; i < 14; i++) {
                        Sprite_Init(&self->entries[i]);
                    }
                    ClearField0And40205a234(&self->tail);
                    self->iconByte = 0;
                    self->iconEntries = self->entries;
                    self->iconCount = 14;
                    self->iconTail = &self->tail;
                    void* data = data_0211e33c;
                    int count = Pac_CountFiles((ActiveEntry02046900*)data);
                    for (int i = 0; i < count; i++) {
                        void* field;
                        int recSize;
                        void* rec = Pac_GetFile((Rec020467f0*)data, i, &field, &recSize);
                        SpriteContext_LoadFile(self->icons, rec, recSize, &alloc);
                    }
                    arg0->unknown_4c_ |= 1;
                    arg0->unknown_50_++;
                } else if (arg0->unknown_50_ == 1) {
                    int var27 = func_020ab7a8(arg0->unknown_2c_, 1);
                    if (var27 == 1) {
                        inline_ov019_0218b5a8(var7, arg0, 0);
                        var7->unknown_998_ = 1;
                        func_020466f4((Struct_02038598_4*)var2, 0x80);
                        arg0->unknown_4c_ &= ~1;
                        var13 = 0;
                    } else if (var27 == 2) {
                        inline_ov019_0218b5a8(var7, arg0, 1);
                        var7->unknown_998_ = 1;
                        func_020466f4((Struct_02038598_4*)var2, 0x80);
                        arg0->unknown_4c_ &= ~1;
                        var13 = 0;
                    } else if (var27 == 3) {
                        func_020466f4((Struct_02038598_4*)var2, 0x80);
                        var13 = 6;
                    } else if (var27 == 5) {
                        func_020466f4((Struct_02038598_4*)var2, 0x80);
                        var13 = 4;
                    }
                    BackgroundLoader::RemoveLockGlobal();
                }
            }
            break;
        case 4:
            arg0->unknown_4c_ &= ~1;
            if (var7->unknown_998_ == 0) {
                inline_ov019_0218b5a8(var7, arg0, 7);
                var7->unknown_998_ = 1;
                func_0209c6d8(data_02109bf4, 0x35);
                var13 = 5;
            }
            break;
        case 5:
            if (var7->unknown_998_ == 0) {
                var18 = 0;
            }
            break;
        case 6:
            arg0->unknown_4c_ &= ~1;
            if (var7->unknown_998_ == 0) {
                if (var0->unknown_5cc8_ == 0) {
                    inline_ov019_0218b5a8(var7, arg0, 0);
                    var13 = 0;
                } else {
                    inline_ov019_0218b5a8(var7, arg0, 6);
                    func_0209c6d8(data_02109bf4, 0x3d);
                    var13 = 7;
                }
                var7->unknown_998_ = 1;
            }
            break;
        case 7:
            arg0->unknown_4c_ &= ~1;
            if (var7->unknown_998_ == 0) {
                inline_ov019_0218b5a8(var7, arg0, 4);
                var13 = 9;
                var7->unknown_998_ = 1;
            }
            break;
        case 9:
            if (var7->unknown_998_ == 0) {
                var18 = 0;
            }
            break;
        case 8:
            arg0->unknown_4c_ &= ~1;
            if (var7->unknown_9a0_ == 3 && func_ov019_0218c240(arg0) != 0) {
                if (func_020aba5c(1) == 0) {
                    inline_ov019_0218b5a8(var7, arg0, 1);
                    var13 = 0;
                } else {
                    inline_ov019_0218b5a8(var7, arg0, 9);
                    var13 = 9;
                }
            }
            break;
        }
        if (!var18) {
            break;
        }
        UpdateAndApplyBrightness((GameResources*)arg0);
        var1->RemoveAllLocks();
        if (!(arg0->unknown_4c_ & 1)) {
            func_02043368(var7);
        }
        if (var7->unknown_9a0_ != 3 && !(var13 == 3 && var7->unknown_9a0_ == 4)) {
            var7->func_020444d4(1);
        }
        func_020bbd9c();
        func_020c52e8();
        func_020c5414();
        RenderConfig::Reset();
        DISP3DCNT = (DISP3DCNT & ~0x3000) | 8;
        DISP3DCNT = (DISP3DCNT & ~0x3000) | 0x10;
        inline_ov019_0218b5a8_8(0);
        inline_ov019_0218b5a8_9(&var16, &var17, &var15, NULL);
        inline_ov019_0218b5a8_4(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, NULL);
        inline_ov019_0218b5a8_8(2);
        func_020444e0((Struct_020444e0*)var7);
        func_ov019_0218c178(arg0);
        func_0203bd88(var4);
        func_0204359c(var7, 0x10);
        func_020d86d0(0, 1);
        arg0->unknown_28_ = 1;
        func_020c9820();
        func_0203bdb0((Struct_0203bdb0*)var4);
        func_020439b0(var7, 1);
        var0->CalculateDeltaTime((GetCurrentTimestamp() - var19) * 64 * 1000 / 33514);
        var19 = GetCurrentTimestamp();
    }

    var10.Destroy();
    func_02012da4(&data_02114e20, var9);
    func_0200fb94((char*)var0, 6);
    func_02012010(var0, 0);
}
