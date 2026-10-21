#include <globaldefs.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Struct_ov003_021594c4 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov006_02158478 {
    char unknown_0_[4];
    Struct_ov003_021594c4* unknown_4_;
    char unknown_8_[0xe0 - 8];
};

struct Struct_ov009_02185634_3 {
    char unknown_0_[0x98];
    Struct_ov003_021594c4* unknown_98_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Struct_ov008_02184a4c_8 { char unknown_0_[0x28]; };

#if defined(jpn)
struct Struct_ov009_02185634_4 { signed char unknown_0_[10]; };
#endif
struct Struct_ov009_02185634_5 {
    char unknown_0_[0x3c];
    void* unknown_3c_;
    Struct_ov008_02184a4c_8* unknown_40_;
    char unknown_44_[0x4c - 0x44];
    short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
#if defined(jpn)
    void inline_ov009_02185634(unsigned char arg0) { unknown_50_ = arg0; }
    void inline_ov009_02185634_2(Struct_ov008_02184a4c_8* arg0, short arg1)
    {
        unknown_40_ = arg0;
        unknown_4c_ = arg1;
    }
#endif
};

struct Struct_ov009_02185634 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    short unknown_a_;
    short unknown_c_;
    short unknown_e_;
    short unknown_10_;
    short unknown_12_;
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
};

struct Struct_ov008_02187f6c_3 {
    char unknown_0_[0x488];
    Struct_ov009_02185634 unknown_488_;
    char unknown_4a4_[0x568 - 0x4a4];
    short unknown_568_;
};

struct Struct_ov009_0218aa40 { short unknown_0_[10]; };
struct Struct_ov003_02154af4_3 {
    char unknown_0_[0x800];
    char unknown_800_[0xc58 - 0x924];
};

struct Struct_ov009_02185634_2 {
    char unknown_0_[4];
    void* unknown_4_;
};

struct Struct_ov009_021842a0_2 {
#if defined(jpn)
    SafeAllocator unknown_0_[8];
    SafeAllocator* unknown_b4_;
    char unknown_a4_[0xa8 - 0xa4];
    char unknown_c8_[0xc0 - 0xa8];
    char unknown_e0_[0xd8 - 0xc0];
    int unknown_d8_;
    char unknown_dc_[0xee - 0xdc];
    short unknown_ee_;
    char unknown_f0_[0xf8 - 0xf0];
    SafeAllocator* unknown_f8_;
#else
    SafeAllocator unknown_0_[9];
    SafeAllocator* unknown_b4_;
    char unknown_b8_[0xc0 - 0xb8];
    Struct_ov009_02185634_2* unknown_c0_;
    void* unknown_c4_;
    char unknown_c8_[0xe0 - 0xc8];
    char unknown_e0_[0xf8 - 0xe0];
    int unknown1_f8_;
    char unknown_fc_[0x138 - 0xfc];
#endif
    Struct_ov003_021594c4 unknown_138_[6];
    Struct_ov009_02185634_3 unknown_1f8_;
    Struct_ov009_02185634_3 unknown_2b4_;
    Struct_ov006_02158478 unknown_370_[1];
    Struct_ov006_02158478 unknown_450_[4];
    void* unknown_7d0_;
    void* unknown_7d4_;
    Struct_ov009_02185634_5* unknown_7d8_;
    Struct_ov008_02184a4c_8* unknown_7dc_;
    void* unknown_7e0_;
    Struct_ov009_02185634_5* unknown_7e4_;
    Struct_ov008_02184a4c_8* unknown_7e8_;
    void* unknown_7ec_;
    void* unknown_7f0_[2];
    void* unknown_7f8_;
    void* unknown_7fc_;
    char unknown1_800_[0x808 - 0x800];
    char unknown_808_[0x878 - 0x808];
    char unknown_878_[0x924 - 0x878];
    char unknown_800_[0xc58 - 0x924];
    signed char unknown_c58_;
    unsigned char unknown_c59_;
    char unknown_c5a_[0xc68 - 0xc5a];
    char unknown_c68_[0xd88 - 0xc68];
    Struct_ov008_02187f6c_3* unknown_d88_;
    char unknown_d8c_[0xd90 - 0xd8c];
    int unknown_d90_;
    unsigned char unknown_d94_;
    unsigned char unknown_d95_;
    char unknown_d96_[0xd9c - 0xd96];
    unsigned int unknown_d9c_;
    char unknown_da0_[0xda2 - 0xda0];
    unsigned char unknown_da2_;
    unsigned char unknown_da3_;
    unsigned char unknown_da4_[2];
    unsigned char unknown_da6_[2];
    unsigned char unknown_da8_[2];
    unsigned char unknown_daa_[2];
    unsigned char unknown_dac_[2];
    unsigned char unknown_dae_[2];
#if defined(jpn)
    char unknown_d74_[0xb];
    char unknown_d7f_[0xb];
    char unknown_d8a_;
    char unknown_d8b_;
#endif
};

struct Struct_02020cb8;
struct Struct_02020cb8_5;
struct Struct_0204b12c;
struct Struct_0204af38;
struct Struct_02020aec;
struct Struct_02020cb8_4;
struct Struct_0204b8d0;
struct Struct_02020cb8_2;
struct Struct_0204c7a8;
struct Struct_0205cf78;
struct Struct_0205cf78_2;
struct Struct_0205d81c;
struct Struct_0201099c_3;
struct Struct_0203d028;

struct GameResources;
GameResources* GetWord0x0_0200fb8c(int* gameState);
char* GetGlobalField0x1c020421a0();
void ZeroInit020de848(void* obj);
extern "C" void func_020de9a4(void* list, SafeAllocator* alloc, void* data, unsigned int size, const void* entries, int count);
extern "C" void func_020dfec0(void* container, SafeAllocator* alloc, void* data, unsigned int size);
void InitTenAllocatorsAndClearFields_021e4e8c(void* model);
void CreateTenAndOne_021e4f64(void* model, SafeAllocator* alloc);
void InitBlockArray_021e4fd8(void* model);
void SetIntC0C_021e6198(void* model, int value);
const char* GetFieldByKey020e0434(Container020e0310* c, int key);
extern "C" void func_0207de48(void* p, int a, int b);
void CopyInternalFields0207df50(Foo0207df50* p);
void RestorePairTables0207df90(char* p);
void BackupPairTables0207dfac(char* p);
void InitCombatController020a2010(void* camera);
struct Vec3Target0202e5c0;
void SetVec3At0x4(Vec3Target0202e5c0* camera, int x, int y, int z);
void SetFields0x10To0x18_0202e5c8(unsigned char* camera, int a, int b, int c);
extern "C" void func_0202e0a4(void* camera);
void SetField0x238False_020a27a0(void* camera);
void SetField0x3b0Value_020100c4(GameState* gs, int camera);
void CharacterCreationUI_GetBodyDimensions(unsigned char* base, int idx, short* out0, short* out1);
extern "C" int CharacterCreationUI_SlotToStyleIndex(void* self, int type, int idx);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void setCharacterScale(void* model, short a, short b);
void SetByteC11_021e6150(void* model, unsigned char value);
void ResetList0204af64(List0204af64* background);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* background, int value);
extern "C" void func_0204b5b4(BackgroundGraphics* background, int screen);
void DispatchViaTable0204b5e8(Obj0204b5e8* background, int a, int b);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* background, SafeAllocator* allocator);
void AllocateArray0204af38(Foo0204af38* background, int count, SafeAllocator* allocator);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void func_0204b174(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
void DispatchEntry0204b8d0(Obj0204b8d0* background, unsigned int a, int b, int c, short d, short e, short f, short g,
                           unsigned short h);
void FlushAndDispatchList0204b0e8(List0204b0e8* background, void* a);
extern "C" void func_0204bc74(BackgroundGraphics* background, int a, int b, int c, int d, int e, int f);
extern "C" void func_ov023_021da274(void* self);
void AllocateBuffer0204c7a8(Obj0204c7a8* obj, SafeAllocator* alloc, int buffer, unsigned int len);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78* list, Elem_0205cf78* elems, unsigned char count);
void InitStruct0205a444(char* table);
struct Struct0205a198;
void Init0205a198(Struct0205a198* entry);
struct ClearTarget0205a234;
void ClearField0And40205a234(ClearTarget0205a234* tail);
extern "C" void func_0205a528(Table0205a444* table, void* file, int size, SafeAllocator* alloc);
extern "C" void func_ov003_0215e6f8(void* obj, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void func_ov003_0215f41c(Ov3Obj* obj, const char* name);
extern "C" unsigned char* func_ov003_0215f4fc(Ov3Obj* obj, const char* name);
void InitWordsQuad_021e60e0(void* model, unsigned int angle);
extern "C" void func_ov023_021e5974(void* model, Hero* hero, short a, int b, int c);
extern "C" void func_ov023_021d99a4(void* self);
void SetupTag021d9c7c(void* self);
void SetupTag021d9da4(void* self);
void SetElementFieldC2_0205deb4(Struct_0205d81c* s, int key, int value);
void SetStatValue021855dc(unsigned char* self, int val);

#if defined(jpn)
#define data_ov009_0218acb0 data_ov009_0218bc25
#define data_ov009_0218ab48 data_ov009_0218bab0
#define data_ov009_0218acd9 data_ov009_0218bc3e
#define data_ov009_0218a9bc data_ov009_0218b998
#define data_ov009_0218aa40 data_ov009_0218ba1c
#define data_ov009_0218a96c data_ov009_0218b978
#define data_ov009_0218a994 data_ov009_0218b95c
#define data_ov009_0218a998 data_ov009_0218b968
#define data_ov009_0218a99c data_ov009_0218b952
#define data_ov009_0218a9a4 data_ov009_0218b990
#endif

extern const char data_ov009_0218acb0[];
extern const char data_ov009_0218acc9[];
extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern const char data_ov009_0218ab48[];

extern const char data_ov009_0218acd9[];
extern signed char data_ov009_0218a9bc[10];
extern const Struct_ov009_0218aa40 data_ov009_0218aa40;
extern const unsigned char data_ov009_0218a96c[];
extern const unsigned char data_ov009_0218a994[];
extern const signed char data_ov009_0218a998[];
extern const signed char data_ov009_0218a99c[];
extern const unsigned short data_ov009_0218a9a4[];
extern const char data_ov009_0218acf4[];
extern const char data_ov009_0218ad0d[];
extern const char data_ov009_0218ad26[];
extern const char data_ov009_0218ad28[];

#if defined(jpn)
#define func_ov009_021855dc func_ov009_021867bc
extern "C" void func_020e0484(void* arg0, SafeAllocator* arg1, const char* arg2, const void* arg3, int arg4, int arg5);
extern "C" void func_ov009_02185888(void* arg0);
extern "C" void func_ov009_02185850(void* arg0);
extern "C" int func_ov009_02185c58(void* arg0);
extern "C" void func_ov009_021867bc(unsigned char* arg0, int arg1);
#define MODEL0 arg0->unknown_7f0_[0]
#define MODEL1 arg0->unknown_7f0_[1]
#define TABLE_A arg0->unknown_7d8_
#define TABLE_B arg0->unknown_7e4_
#else
#define MODEL0 var10
#define MODEL1 var11
#define TABLE_A var57
#define TABLE_B var58
#endif

enum Enum_ov009_02185634 { Enum_ov009_02185634_3072 = 0xc00 };
enum Enum_ov009_02185634_B { Enum_ov009_02185634_B_48 = 0x30 };

// USA: func_ov009_02185634
extern "C" ARM void func_ov009_02185634(Struct_ov009_021842a0_2* arg0)
{
    unsigned int var0;
    GameState* var1 = GameState::GetInstance();
    func_0200fb8c((int*)var1);
    BackgroundLoader* var2 = BackgroundLoader::GetInstance();
    unsigned char var3 = arg0->unknown_c59_;
    if (var3 == 0)
    {
#if defined(jpn)
        arg0->unknown_0_[1].Reset();
        void* var4 = arg0->unknown_0_[1].Allocate(0x1800);
        unsigned int var5;
        LoadFileIntoMemory(data_ov009_0218acb0, var4, &var5);
        arg0->unknown_0_[5].Reset();
        func_020dfec0(arg0->unknown_e0_, &arg0->unknown_0_[5], var4, var5);
        arg0->unknown_d8_ = *(int*)(func_020421a0() + 0x28);
        func_020de848(arg0->unknown_c8_);
        func_020e0484(arg0->unknown_c8_, &arg0->unknown_0_[4], data_020f2a38, data_ov009_0218ab48, 0x29, 1);
#else
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        unsigned int var6;
        void* var7 = ExtractFileFromGP2(data_ov009_0218acb0, data_ov009_0218acc9, &var6);
        arg0->unknown_0_[5].Reset();
        func_020dfec0(arg0->unknown_e0_, &arg0->unknown_0_[5], var7, var6);
        BackgroundLoader::RemoveLockGlobal();
        arg0->unknown1_f8_ = *(int*)(func_020421a0() + 0x5c);
        func_020de848(arg0->unknown_c8_);
        BackgroundLoader::AddLockGlobal();
        unsigned int var8;
        void* var9 = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &var8);
        if (var9 != NULL)
            func_020de9a4(arg0->unknown_c8_, &arg0->unknown_0_[4], var9, var8, data_ov009_0218ab48, 0x29);
        BackgroundLoader::RemoveLockGlobal();
#endif

        arg0->unknown_7f0_[0] = arg0->unknown_0_[3].Allocate(0xc20);
#if !defined(jpn)
        void* var10 = arg0->unknown_7f0_[0];
#endif
        func_ov023_021e4e8c(MODEL0);
        func_ov023_021e4f64(MODEL0, &arg0->unknown_0_[3]);
        func_ov023_021e4fd8(MODEL0);
        func_ov023_021e6198(MODEL0, (int)arg0->unknown_c8_);
        arg0->unknown_7f0_[1] = arg0->unknown_0_[3].Allocate(0xc20);
#if !defined(jpn)
        void* var11 = arg0->unknown_7f0_[1];
#endif
        func_ov023_021e4e8c(MODEL1);
        func_ov023_021e4f64(MODEL1, &arg0->unknown_0_[3]);
        func_ov023_021e4fd8(MODEL1);
        func_ov023_021e6198(MODEL1, (int)arg0->unknown_c8_);

        if (arg0->unknown_d95_ == 0)
        {
#if defined(jpn)
            Enum_ov009_02185634 var17 = Enum_ov009_02185634_3072;
            Enum_ov009_02185634_B var18 = Enum_ov009_02185634_B_48;
#endif
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            GPCReadPair var12;
            GPCReadPair* var13 = &var12;
            unsigned int var14 = 0;
            unsigned char* var15 = data_0211e33c;
            int var16 = 0x30000;
            ZeroInitGPCPointer(&var13->pGPCFile);
            var13->ZeroInitializeMachine();
            if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&var12.pGPCFile, var12.machine, data_ov009_0218acd9, var15,
                                                           var14, var16, false, 0))
            {
                var0 = var14;
                var16 -= var0;
#if !defined(jpn)
                Enum_ov009_02185634 var17 = Enum_ov009_02185634_3072;
                Enum_ov009_02185634_B var18 = Enum_ov009_02185634_B_48;
#endif
                if (DecompressFileFromGPCByName(var12.pGPCFile, var12.machine, var15 + var0, var14, var16,
                                                func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 0x7d0)))
                {
                    func_0207de48(arg0->unknown_808_, var17, var18);
                    func_0207df50((Struct_0203d028*)arg0->unknown_808_);
                    func_0207df90(arg0->unknown_808_);
                    ((Object3D*)arg0->unknown_878_)->SetModelFromFileCopy(arg0->unknown_b4_, var15 + var0, var14,
                                                       Model3D::TextureStagingMode_Normal);
                    func_0207dfac(arg0->unknown_808_);
                }
            }
            BackgroundLoader::RemoveLockGlobal();
            func_0207de48(arg0->unknown_c68_, 0x1a00, 0x20);
            var12.Reset();
            ZeroDestroyGPCPointer(&var12.pGPCFile);
        }

#if defined(jpn)
        Struct_ov009_021842a0_2* var19 = arg0;
#else
        Struct_ov003_02154af4_3* var19 = (Struct_ov003_02154af4_3*)((char*)arg0 + 0x124);
#endif
        func_020a2010(var19->unknown_800_);
        func_0202e5c0((Struct_0202e5c0*)var19->unknown_800_, 0xd000, 0xf800, 0x42ccc);
        func_0202e5c8((unsigned char*)var19->unknown_800_, 0xd000, 0xf800, 0);
        func_0202e0a4(var19->unknown_800_);
        func_020a27a0(var19->unknown_800_);
        func_020100c4(var1, (int)var19->unknown_800_);

        arg0->unknown_da3_ = 0;
        arg0->unknown_da4_[0] = 2;
        arg0->unknown_da4_[1] = 2;
        arg0->unknown_da6_[0] = 0;
        arg0->unknown_da6_[1] = 0;
        arg0->unknown_da8_[0] = 0;
        arg0->unknown_da8_[1] = 5;
        arg0->unknown_daa_[0] = 3;
        arg0->unknown_daa_[1] = 3;
        arg0->unknown_dac_[0] = 0;
        arg0->unknown_dac_[1] = 0;
        arg0->unknown_dae_[0] = 0;
        arg0->unknown_dae_[1] = 3;
        if (arg0->unknown_d95_ == 1)
        {
            arg0->unknown_da6_[0] = 1;
            arg0->unknown_da6_[1] = 1;
            arg0->unknown_dac_[1] = 1;
            arg0->unknown_da8_[1] = 0;
            arg0->unknown_dae_[1] = 0;
        }
#if defined(jpn)
        memcpy(arg0->unknown_d74_, func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 0x4272), 0xb);
        arg0->unknown_d8a_ = 0;
        memcpy(arg0->unknown_d7f_, func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 0x4272), 0xb);
        arg0->unknown_d8b_ = 0;
#endif

        Struct_ov009_0218aa40 var20;
        Struct_ov003_021594c4* var21[4];
        Struct_ov009_02185634* var22 = &arg0->unknown_d88_->unknown_488_;
        var22->unknown_14_0_ = arg0->unknown_da3_;
        var22->unknown_14_1_ = arg0->unknown_daa_[arg0->unknown_da3_];
        int var23 = arg0->unknown_da8_[arg0->unknown_da3_];
        {
#if defined(jpn)
            Struct_ov009_02185634_4 var24 = *(Struct_ov009_02185634_4*)data_ov009_0218a9bc;
#else
            signed char var25[10];
            int var26;
            unsigned char* var27;
            unsigned char* var28 = (unsigned char*)data_ov009_0218a9bc;
            var27 = (unsigned char*)var25;
            var26 = 10;
            do {
                unsigned char var29 = *var28;
                var28++;
                *var27 = var29;
                var27++;
            } while (--var26);
#endif
        }
        var22->unknown_14_4_ = var23;
        {
            signed char var30[10];
            int var31;
            unsigned char* var32;
            unsigned char* var33;
            int var34 = arg0->unknown_dae_[arg0->unknown_da3_];
            var33 = (unsigned char*)data_ov009_0218a9bc;
            var32 = (unsigned char*)var30;
            var31 = 10;
            do {
                unsigned char var35 = *var33;
                var33++;
                *var32 = var35;
                var32++;
            } while (--var31);
            var22->unknown_15_0_ = var34;
        }
        CharacterCreationUI_GetBodyDimensions((unsigned char*)self, self->unk_da4[self->sex_], &look->unk_18, &look->unk_1a);
        short top = CharacterCreationUI_SlotToStyleIndex(self, 5, self->unk_da6[self->sex_]) + 0x233c;
        short bottom = CharacterCreationUI_SlotToStyleIndex(self, 3, self->unk_dac[self->sex_]) + 0x2328;
        defaults = data_ov009_0218aa40;
        defaults.unk[2] = top;
        defaults.unk[3] = bottom;
        memcpy(look, &defaults, 0x14);
        look->unk_16 = -1;
        setCharacterScale(MODEL0, look->unk_18, look->unk_1a);
        setCharacterScale(MODEL1, look->unk_18, look->unk_1a);

        if (arg0->unknown_da2_ != 0)
        {
            func_ov023_021e6150(MODEL0, 1);
            func_ov023_021e6150(MODEL1, 1);
            switch (arg0->unknown_da2_)
            {
            case 1:
            case 7:
            case 8:
                var22->unknown_e_ = 0x4e24;
                break;
            case 2:
            case 9:
                var22->unknown_e_ = 0x5014;
                break;
            case 3:
            case 10:
                var22->unknown_e_ = 0x4fb3;
                break;
            case 4:
                var22->unknown_e_ = 0x5078;
                break;
            case 6:
            case 11:
                var22->unknown_e_ = 0x4e84;
                break;
            case 5:
                var22->unknown_e_ = 0x4a6a;
                break;
            case 12:
                var22->unknown_e_ = 0x50dc;
                break;
            }
            var22->unknown_0_ = 0x32cd;
            var22->unknown_16_ = 0x36b5;
            var22->unknown_2_ = 0x3f55;
            var22->unknown_a_ = 0x43fe;
        }
        if (arg0->unknown_d95_ == 0)
        {
            var22->unknown_0_ = 0x32cf;
            var22->unknown_16_ = 0x36b7;
            var22->unknown_2_ = 0x3f57;
            var22->unknown_a_ = 0x42e0;
        }

        var21[0] = &arg0->unknown_138_[0];
        var21[1] = &arg0->unknown_138_[1];
        var21[2] = &arg0->unknown_138_[2];
        var21[3] = &arg0->unknown_138_[5];
        for (int var38 = 0; var38 < 4; var38++)
        {
            Struct_ov003_021594c4* var39 = var21[var38];
            SafeAllocator* var40 = &arg0->unknown_0_[0];
            if (var38 == 3)
                var40 = &arg0->unknown_0_[2];
            func_0204af64((Struct_02020cb8*)var39);
            func_0204b11c((unsigned char*)var39, 0);
            unsigned char var41 = data_ov009_0218a96c[var38];
            var39->unknown_1c_0_ = var41;
            var39->unknown_1c_4_ = data_ov009_0218a994[var38];
            func_0204b5b4(var39, data_ov009_0218a998[var38]);
            func_0204b5e8((Struct_02020cb8_5*)var39, 0, 0);
            func_0204b12c((Struct_0204b12c*)var39, var40);
            if (data_ov009_0218a99c[var38] > 0)
                func_0204af38((Struct_0204af38*)var39, (unsigned char)data_ov009_0218a99c[var38], var40);
        }

#if defined(jpn)
        arg0->unknown_d90_ = var2->QueueLoadFile(func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, arg0->unknown_c58_), NULL);
#else
        signed char var42 = arg0->unknown_c58_;
        const char* var43 = func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, (short)(var42 + 0x32));
        arg0->unknown_d90_ = var2->QueueLoadFileInGP2(func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, var42),
                                                 var43, NULL);
#endif
        arg0->unknown_c59_++;
    }
    else if (var3 == 1)
    {
        if (var2->GetTaskStatus(arg0->unknown_d90_) != 0)
        {
            char var44[4];
            void* var45;
            unsigned int var46;
            int var47;
            var2->GetLoadedFileByID(arg0->unknown_d90_, &var45, &var46);
            int var48 = func_02046900((Struct_02020cb8_4*)var45);
            if (arg0->unknown_d95_ == 1)
                var48--;
            for (int var49 = 0; var49 < var48; var49++)
            {
                void* var50 = func_020467f0((Struct_02020aec*)var45, var49, (void**)var44, &var47);
                if (var50 != NULL)
                {
                    if (var49 == 0)
                    {
                        func_0204b174(&arg0->unknown_138_[2], var50, &arg0->unknown_0_[0], var47);
                        func_0204b174(&arg0->unknown_138_[5], var50, &arg0->unknown_0_[2], var47);
                    }
                    else if (var49 <= 3)
                    {
                        func_0204b174(&arg0->unknown_138_[0], var50, &arg0->unknown_0_[0], var47);
                    }
                    else
                    {
                        func_0204b174(&arg0->unknown_138_[1], var50, &arg0->unknown_0_[0], var47);
                    }
                }
            }
            var2->RemoveTask(arg0->unknown_d90_);
            arg0->unknown_d90_ = -1;
            int var51 = 1;
            if (arg0->unknown_d95_ == 1)
                var51 = 0;
            func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_138_[0], var51, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_138_[0], 0);
            func_0204bc74(&arg0->unknown_138_[1], 0, 0, 0, 0x20, 0x19, 0);
            func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_138_[1], 0);
            func_0204bc74(&arg0->unknown_138_[2], 0, 0, 0, 0x20, 0x19, 0);
            func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_138_[2], 0);
            func_0204bc74(&arg0->unknown_138_[5], 0, 0, 0, 0x20, 0x19, 0);
            func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_138_[5], 0);
            arg0->unknown_d9c_ |= 0x1000;
            func_ov023_021da274(arg0);
            func_0204b0e8((Struct_02020cb8_2*)&arg0->unknown_138_[1], 0);
            arg0->unknown_d9c_ &= ~0x1000;

            arg0->unknown_7d0_ = arg0->unknown_0_[0].Allocate(0x1000);
            Struct_ov006_02158478* var52;
            unsigned int var53 = 0x200;
            for (int var54 = 0; var54 < 1; var54++)
            {
                var52 = &arg0->unknown_370_[var54];
                func_0204c7a8((Struct_0204c7a8*)var52, &arg0->unknown_0_[0], (int)arg0->unknown_7d0_, var53);
                var52->unknown_4_ = &arg0->unknown_138_[2];
            }
            arg0->unknown_1f8_.unknown_98_ = &arg0->unknown_138_[2];
            arg0->unknown_1f8_.unknown_b2_ = 1;
            func_0205cf78((Struct_0205cf78*)&arg0->unknown_1f8_, (Struct_0205cf78_2*)arg0->unknown_370_, 1);

            arg0->unknown_7d4_ = arg0->unknown_0_[2].Allocate(0x400);
            for (int var55 = 0; var55 < 4; var55++)
            {
                var52 = &arg0->unknown_450_[var55];
                func_0204c7a8((Struct_0204c7a8*)var52, &arg0->unknown_0_[2], (int)arg0->unknown_7d4_,
                                       data_ov009_0218a9a4[var55]);
                var52->unknown_4_ = &arg0->unknown_138_[5];
            }
            arg0->unknown_2b4_.unknown_98_ = &arg0->unknown_138_[5];
            arg0->unknown_2b4_.unknown_b2_ = 1;
            func_0205cf78((Struct_0205cf78*)&arg0->unknown_2b4_, (Struct_0205cf78_2*)arg0->unknown_450_, 4);

            int var56;
#if !defined(jpn)
            Struct_ov009_02185634_5* var57 = arg0->unknown_7d8_;
#endif
            func_0205a444((char*)TABLE_A);
            TABLE_A->unknown_50_ = 0;
#if defined(jpn)
            TABLE_A->inline_ov009_02185634_2(arg0->unknown_7dc_, 6);
#else
            TABLE_A->unknown_40_ = arg0->unknown_7dc_;
            TABLE_A->unknown_4c_ = 6;
#endif
            TABLE_A->unknown_3c_ = arg0->unknown_7e0_;
            for (var56 = 0; var56 < 6; var56++)
                func_0205a198((Struct_02043368_2*)&arg0->unknown_7dc_[var56]);
            func_0205a234((Struct_02043368*)arg0->unknown_7e0_);

#if !defined(jpn)
            Struct_ov009_02185634_5* var58 = arg0->unknown_7e4_;
#endif
            func_0205a444((char*)TABLE_B);
#if defined(jpn)
            TABLE_B->inline_ov009_02185634(1);
#else
            TABLE_B->unknown_50_ = 1;
#endif
#if defined(jpn)
            TABLE_B->inline_ov009_02185634_2(arg0->unknown_7e8_, 0x19);
#else
            TABLE_B->unknown_40_ = arg0->unknown_7e8_;
            TABLE_B->unknown_4c_ = 0x19;
#endif
            TABLE_B->unknown_3c_ = arg0->unknown_7ec_;
            for (int var59 = 0; var59 < 0x19; var59++)
                func_0205a198((Struct_02043368_2*)&arg0->unknown_7e8_[var59]);
            func_0205a234((Struct_02043368*)arg0->unknown_7ec_);

#if defined(jpn)
            arg0->unknown_d90_ = var2->QueueLoadFile(func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 1000), NULL);
#else
            const char* var60 = func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 0x41a);
            arg0->unknown_d90_ = var2->QueueLoadFileInGP2(func_020e0434((Struct_0201099c_3*)arg0->unknown_e0_, 1000),
                                                     var60, NULL);
#endif
            arg0->unknown_c59_++;
        }
    }
    else if (var3 == 2)
    {
        if (var2->GetTaskStatus(arg0->unknown_d90_) != 0)
        {
            char var61[4];
            void* var62;
            unsigned int var63;
            int var64;
            var2->GetLoadedFileByID(arg0->unknown_d90_, &var62, &var63);
            int var65 = func_02046900((Struct_02020cb8_4*)var62);
            arg0->unknown_0_[6].Reset();
            for (int var66 = 0; var66 < var65; var66++)
            {
                void* var67 = func_020467f0((Struct_02020aec*)var62, var66, (void**)var61, &var64);
                if (var67 != NULL)
                {
                    if (var66 < 4)
                        func_0205a528(arg0->unknown_7d8_, var67, var64, &arg0->unknown_0_[6]);
                    else
                        func_0205a528(arg0->unknown_7e4_, var67, var64, &arg0->unknown_0_[6]);
                }
            }
            var2->RemoveTask(arg0->unknown_d90_);
            arg0->unknown_d90_ = -1;
            arg0->unknown_c59_++;
        }
    }
#if !defined(jpn)
    else if (var3 == 3)
    {
        if (arg0->unknown_d95_ == 0)
            arg0->unknown_d90_ = var2->QueueLoadFile(data_ov009_0218acf4, NULL);
        else
            arg0->unknown_d90_ = var2->QueueLoadFile(data_ov009_0218ad0d, NULL);
        arg0->unknown_c59_++;
    }
    else if (var3 == 4)
    {
        if (var2->GetTaskStatus(arg0->unknown_d90_) != 0)
        {
            void* var68;
            unsigned int var69;
            var2->GetLoadedFileByID(arg0->unknown_d90_, &var68, &var69);
            if (var68 != NULL && var69 != 0)
            {
                arg0->unknown_0_[8].Reset();
                func_ov003_0215e6f8(arg0->unknown_c4_, &arg0->unknown_0_[8], var68, var69);
                arg0->unknown_c0_->unknown_4_ = arg0->unknown_c4_;
                func_ov003_0215f41c(arg0->unknown_c0_, data_ov009_0218ad26);
                unsigned char* var70 = func_ov003_0215f4fc(arg0->unknown_c0_, data_ov009_0218ad28);
                if (var70 != NULL)
                    var70[0xf] = 1;
            }
            var2->RemoveTask(arg0->unknown_d90_);
            arg0->unknown_d90_ = -1;
            arg0->unknown_c59_++;
        }
    }
#endif
    else
    {
        func_ov023_021e60e0(arg0->unknown_7f0_[0], 0x1eb);
        func_ov023_021e60e0(arg0->unknown_7f0_[1], 0x1eb);
        func_ov023_021e5974(arg0->unknown_7f0_[0], arg0->unknown_d88_, arg0->unknown_d88_->unknown_568_, 0, 0);
        func_ov023_021e5974(arg0->unknown_7f0_[1], arg0->unknown_d88_, arg0->unknown_d88_->unknown_568_, 0, 0);
        arg0->unknown_7f8_ = arg0->unknown_7f0_[0];
        arg0->unknown_7fc_ = arg0->unknown_7f0_[1];
        func_ov023_021d99a4(arg0);
        func_ov023_021d9c7c(arg0);
        func_ov023_021d9da4(arg0);
        func_0205deb4((Struct_0205d81c*)&arg0->unknown_2b4_, 2, 0);
        func_0205deb4((Struct_0205d81c*)&arg0->unknown_2b4_, 3, 0);
#if defined(jpn)
        func_ov009_02185888(arg0->unknown_dc_);
        func_ov009_02185850(arg0->unknown_dc_);
        arg0->unknown_f8_ = &arg0->unknown_0_[7];
        arg0->unknown_ee_ = 1;
        func_ov009_02185c58(arg0->unknown_dc_);
#endif
        func_ov009_021855dc((unsigned char*)arg0, 1);
    }
}
