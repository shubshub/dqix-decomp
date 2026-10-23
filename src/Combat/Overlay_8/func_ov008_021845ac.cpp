#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <Filesystem/BackgroundLoader.h>

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_01ff8b48_13 {
    char unknown_0_[0x18];
};

struct Struct_ov003_021594c4 {
    char unknown_0_[0x20];
};

struct Struct_02081870_2 {
    char unknown_0_[0xbc];
};

struct Struct_ov006_02158478 {
    char unknown_0_[0xe0];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x10];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    SafeAllocator unknown_8c_;
    Struct_01ff8b48_13 unknown_a0_;
    char* unknown_b8_;
    char unknown_bc_[0x14];
    Struct_ov003_021594c4 unknown_d0_[3];
    Struct_02081870_2 unknown_130_;
    Struct_ov006_02158478 unknown_1ec_[6];
    void* unknown_72c_;
    void* unknown_730_;
    void* unknown_734_;
    void* unknown_738_;
    void* unknown_73c_;
    void* unknown_740_;
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    Struct_ov009_02186e00_2 unknown_750_;
    Object3D unknown_790_;
    char unknown_83c_[0x2c8];
    void* unknown_b04_;
    void* unknown_b08_;
    void* unknown_b0c_;
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int unknown_b2c_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* unknown_b3c_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

struct Struct_02021b84 {
    char unknown_0_[R(0x228, 0x2d8)];
    void* unknown_2d8_;
    void* unknown_2dc_;
    void* unknown_2e0_;
};

struct Struct_02045cac;
struct Struct_0204b010;
struct Struct_02020cb8_3;
struct Struct_02038598_4;

void EmptyDestructor0205a494(void* renderer);
MessageSystem* GetGlobalField0x1c020421a0();
void InitCombatSlots02045cac(CombatSlots02045cac* messages);
void ReinitController02043204(char* messages);
void Background_ClearMap(Obj0204b010* background, void* value);
void ResetRecordList0204afb4(List0204afb4* background);
void SetFlagBytes02017d68(void* unused);
void* GetDataPtr02114e04_020d6c00();
void ClearFlags020466f4(FlagWord020466f4* field, unsigned int bits);

extern "C" {
void func_ov023_021eb26c(void* guide);
void func_02043124(MessageSystem* messages);
void Background_FlushMap(BackgroundGraphics* background, int value);
void Background_TransferMap(BackgroundGraphics* background, int value);
unsigned int GetMainBGAssignedVRAMSize();
void func_020ca458(int value, void* destination, unsigned int size);
void func_0205d048(Struct_02081870_2* arg0);
void* func_02012fe4();
}

// USA: func_ov008_021845ac
extern "C" ARM void func_ov008_021845ac(Struct_ov008_021842a0_2* arg0)
{
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    if (arg0->unknown_b20_ >= 0)
    {
        var0->RemoveTask(arg0->unknown_b20_);
        arg0->unknown_b20_ = -1;
    }
    if (arg0->unknown_730_ != NULL)
        func_0205a494(arg0->unknown_730_);
    if (arg0->unknown_73c_ != NULL)
        func_0205a494(arg0->unknown_73c_);
    if (arg0->unknown_b08_ != NULL)
        func_ov023_021eb26c(arg0->unknown_b08_);
    Struct_02021b84* var1 = func_020421a0();
    func_02045cac((Struct_02045cac*)var1);
    func_02043204((char*)var1);
    func_02043124(var1);
    var1->unknown_2d8_ = NULL;
    var1->unknown_2dc_ = NULL;
    var1->unknown_2e0_ = NULL;
    Struct_ov003_021594c4* var2[3] = {&arg0->unknown_d0_[0], &arg0->unknown_d0_[1], &arg0->unknown_d0_[2]};
    for (int var3 = 0; var3 < 3; var3++)
    {
        BackgroundGraphics* background = backgrounds[i];
        Background_ClearMap((Obj0204b010*)background, 0);
        Background_FlushMap(background, 0);
        Background_TransferMap(background, 0);
        ResetRecordList0204afb4((List0204afb4*)background);
    }
    func_020ca458(0, (void*)0x06000000, GetMainBGAssignedVRAMSize());
    func_0205d048(&arg0->unknown_130_);
    arg0->unknown_790_.Destroy();
    arg0->unknown_b8_ = NULL;
    arg0->unknown_72c_ = NULL;
    SafeAllocator* var5[8] = {&arg0->unknown_0_,      &arg0->unknown_14_, &arg0->unknown_28_,
                                    &arg0->unknown_3c_, &arg0->unknown_50_,       &arg0->unknown_64_,
                                    &arg0->unknown_78_,  &arg0->unknown_8c_};
    for (int var6 = 0; var6 < 7; var6++)
        var5[var6]->Destroy();
    if (arg0->unknown_b13_ == 0)
    {
        if (arg0->unknown_b24_ == 0)
        {
            func_02017d68(func_02012fe4());
        }
        func_020466f4((Struct_02038598_4*)func_020d6c00(), 0xf);
    }
}
