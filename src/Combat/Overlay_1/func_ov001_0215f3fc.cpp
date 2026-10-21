#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Combat/WorkRecord.h>
#include <std_library_functions.h>

#if defined(jpn)
#define data_ov001_021657ad data_ov001_02166d71
#define data_ov001_021657be data_ov001_02166d82
#define data_ov001_021657ce data_ov001_02166d92
#define data_ov001_021657d1 data_ov001_02166d95
#endif

struct Struct_0203e03c;
struct Struct_0203dd10;
struct Struct_0203d028_19;
struct Struct_ov001_0215f3fc_3
{
    int unknown_0_;
    int unknown_4_;
};
struct Struct_0203d028_14
{
    void* unknown_0_;
    char unknown_4_[0x4c];
    unsigned int unknown_50_;
};
struct Struct_ov001_0215f3fc_4
{
    char unknown_0_[8];
    void* unknown_8_;
    Struct_0206bf2c* unknown_c_;
    char unknown_10_[4];
    Struct_0203d028_14* unknown_14_;
    char unknown_18_[8];
};
struct Struct_ov001_0215f3fc_5
{
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
#if defined(jpn)
    char unknown1_4_[0xc];
#endif
    char unknown_4_[16];
};
struct Struct_ov001_0215f3fc
{
    char unknown_0_[0x70];
};
struct Struct_ov001_0215f3fc_2
{
#if defined(jpn)
    char unknown_0_[0x27c];
#else
    char unknown1_0_[0x2cc];
#endif
    Struct_ov001_0215f3fc unknown_2cc_[33];
};
void* GetGlobalPtr021075f4_0203cf4c();
extern "C" const char* func_ov017_021d612c(void*);
extern "C" int func_0203e03c(Struct_0203e03c*);
extern "C" void func_ov017_021d6134(void*, int);
extern "C" unsigned int func_ov001_0215a750(const char*, void**);
extern "C" int func_ov017_021d60f4(Struct_ov001_0215f3fc_3*);
extern "C" void func_020404c0(int*);
extern "C" void func_0203c794(void*);
extern "C" void* func_0203d004(void*);
extern "C" void func_02040530(int*, int);
extern "C" void func_02040520(int*, int);
extern "C" void func_0203f02c(Struct_0203d028_14*, int, int, char*, int, int);
extern "C" void func_0203f138(Struct_0203d028_14*, int);
extern "C" void func_020408c8(Struct_0203d028_19*, short, short, short);
extern "C" void func_0203dd10(Struct_0203dd10*, unsigned int, int);
extern const char data_ov001_021657ad[];
extern const char data_ov001_021657b2[];
extern const char data_ov001_021657be[];
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_021657ce[];
extern const char data_ov001_021657d1[];

// USA: func_ov001_0215f3fc
extern "C" ARM int func_ov001_0215f3fc(Struct_ov001_0215f3fc_3* arg0, int arg1)
{
    GameState* game = GameState::GetInstance();
    void* list = GetGlobalPtr021075f4_0203cf4c();
    StreamResources0215f3fc* resources = (StreamResources0215f3fc*)game->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!resources)
    {
        return 0;
    }
    const char* var4 = func_ov017_021d612c(arg0++);
    int var5 = func_0203e03c((Struct_0203e03c*)var1);
    if (var5 == -1)
    {
        return 0;
    }
    func_ov017_021d6134(arg0++, var5);
    if (var5 >= 32)
    {
        return 0;
    }
    char var6[80];
    if (strstr(var4, data_ov001_021657ad))
    {
        sprintf(var6, data_ov001_021657b2, var4);
    }
    else
    {
        sprintf(var6, data_ov001_021657be, var4);
    }
    void* var7;
    unsigned int var8;
    int var9 = 0;
    var3->GetLoadedFileByName(var6, &var7, &var8);
    if (!var7)
    {
        BackgroundLoader::AddLockGlobal();
        var9 = 1;
        if (!func_ov001_0215a750(var6, &var7))
        {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    int var10 = 0;
    if (arg1 >= 3)
    {
        var10 = func_ov017_021d60f4(arg0++);
    }
    SafeAllocator* var11 = data_ov001_021658b8[var10];
    int var12 = 27;
    if (arg1 >= 4)
    {
        var12 = func_ov017_021d60f4(arg0);
    }
    Struct_ov001_0215f3fc_4* var13 = (Struct_ov001_0215f3fc_4*)var11->Allocate(0x20);
    if (!var13)
    {
        if (var9)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    func_020404c0((int*)var13);
    Struct_0206bf2c* var14 = (Struct_0206bf2c*)var11->Allocate(0x78);
    if (!var14)
    {
        if (var9)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    func_0206bf2c(var14);
#if defined(jpn)
    enum { Enum_ov001_0215f3fc_20 = 0x20 };
#else
    enum { Enum_ov001_0215f3fc_20 = 0x14 };
#endif
    Struct_ov001_0215f3fc_5* var15 = (Struct_ov001_0215f3fc_5*)var11->Allocate(Enum_ov001_0215f3fc_20);
    if (!var15)
    {
        if (var9)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    memset(var15, 0, Enum_ov001_0215f3fc_20);
    var13->unknown_14_ = (Struct_0203d028_14*)var11->Allocate(0x9c);
    if (!var13->unknown_14_)
    {
        if (var9)
        {
            BackgroundLoader::RemoveLockGlobal();
        }
        return 0;
    }
    func_0203c794(var13->unknown_14_);
    void* var16 = func_0203d004(var1);
    if (var13->unknown_14_)
    {
        var13->unknown_14_->unknown_0_ = var16;
    }
    var15->unknown_2_ = 3;
    if (strstr(var4, data_ov001_021657ad))
    {
        int var17 = 5;
        if (strstr(var4, data_ov001_021657ce))
        {
            var17 = 7;
            var13->unknown_14_->unknown_50_ |= 8;
        }
        memcpy(var15->unknown_4_, var4, var17);
        var15->unknown_4_[var17] = 0;
    }
    else
    {
        sprintf(var15->unknown_4_, data_ov001_021657d1, var4);
    }
    func_02040530((int*)var13, (int)var14);
    func_02040520((int*)var13, (int)var15);
    Struct_ov001_0215f3fc* var18 = var2->unknown_2cc_;
    char* var19 = var18[var12].unknown_0_;
    unsigned int var20 = var8;
    void* var21 = var7;
    if (var13->unknown_14_)
    {
        func_0203f02c(var13->unknown_14_, (int)(var6 + 9), (int)var11,
            var19, (int)var21, var20);
    }
    if (var13->unknown_14_)
    {
        func_0203f138(var13->unknown_14_, 1);
    }
    if (var9)
    {
        BackgroundLoader::RemoveLockGlobal();
    }
    func_020408c8((Struct_0203d028_19*)var13, 0x8f, 0x8f, 0x8f);
    func_0203dd10((Struct_0203dd10*)var1, var5, (int)var13);
    return 1;
}
