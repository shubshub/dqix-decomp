#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define REGION_FLAG(obj,flag) ((obj)->unknown_b18_ & (flag))
#define REGION_MESSAGE(obj,shown) (!((obj)->unknown_b18_ & 0x200))
#define data_ov008_0218b400 data_ov008_0218c080
#else
#define REGION_LAYOUT(j,u) u
#define REGION_FLAG(obj,flag) ((obj)->inline_ov008_02185a70(flag))
#define REGION_MESSAGE(obj,shown) (!(shown))
#endif

#include <Memory/SafeAllocator.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/MessageSystem.h"
#include "Input/Input.h"

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov008_021843f8_3 {
    int unknown_0_[0xb0 / 4];
};

struct Struct_01ff8b48_13 {
    int unknown_0_[0x18 / 4];
};

struct Struct_ov008_02185dc0 {
    int unknown_0_[2];
};

struct Struct_ov003_021594c4 {
    int unknown_0_[0x20 / 4];
};

struct Struct_02081870_2 {
    int unknown_0_[0xbc / 4];
};

struct Struct_ov006_02158478 {
    int unknown_0_[0xe0 / 4];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x40 / 4];
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

    int inline_ov008_02185a70(int arg0)
    {
#if defined(jpn)
        return unknown_b18_ & arg0 ? 1 : 0;
#else
        return *(int*)&unknown_b18_ & arg0 ? 1 : 0;
#endif
    }
};

struct Struct_ov000_02171ffc_2 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov000_02179cdc_4 : GameObject {
    char unknown_13c_[REGION_LAYOUT(0x144, 0x150) - 0x13c];
    Struct_ov000_02171ffc_2* unknown_150_;
};

struct Struct_020a05d8;
struct Struct_020727d8;
struct Struct_02013fb4;
struct Struct_0201099c_3;
struct Struct_0205bb84;
struct Struct_02108760;

extern char data_ov008_0218b400[] __attribute__((aligned(4)));
extern unsigned char data_0211e33c[];
extern Struct_02108760 data_02108760;

MessageSystem* GetGlobalField0x1c020421a0();
void SetBrightness(GameResources* resources, int screen, int brightness);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_020ac4c0(void* arg0);
extern "C" void func_020a05d8(Struct_020a05d8* arg0, unsigned int arg1);
extern "C" void func_020ac494(void* arg0);
void* LoadFileIntoMemory(const char* path, void* archive, unsigned int* size);
void ResetListHeader020727d8(List020727d8* list);
extern "C" void _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(void* list, StreamHeader* file, int size, int id, void* output, int female);
int GetField0x3acValue_020100a8(GameState* gameState);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void AppendString02042058(char* text, const char* append);
int GridCursor_GetSelectedIndex(Struct_0205bb84* cursor);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int effect, int value);

extern "C" {
void* ExtractFileFromGP2(char* arg0, char* arg1, unsigned int* arg2);
void func_ov008_02186964(Struct_ov008_021842a0_2* arg0);
int func_ov008_02186a30(Struct_ov008_021842a0_2* arg0, int arg1);
void* func_0202ae18();
int func_0202c540(void* arg0);
}

#if defined(jpn)
extern "C" void func_020727f8(void*, const char*, int, void*, int);
#endif

// USA: func_ov008_02185dc0
extern "C" ARM void func_ov008_02185dc0(Struct_ov008_021842a0_2* arg0, unsigned int arg1)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = gameState->GetResources();
    MessageSystem* messages = GetGlobalField0x1c020421a0();
    if (messages->active != NULL)
        messages->b19ae = 0;
    signed char step = self->step_;
    if (step == 0)
    {
        func_ov008_02186964(arg0);
        arg0->unknown_b11_++;
    }
    if (var3 == 1)
    {
        if (REGION_FLAG(arg0, 0x20000) && REGION_FLAG(arg0, 0x200))
        {
            if (var2->unknown_9a0_ != 3)
                return;
            arg0->unknown_b18_ &= ~0x20000;
        }
        if (REGION_FLAG(arg0, 0x20000))
            var3++;
        else
            SetBrightness(var1, 0, 0xf);
        arg0->unknown_b11_++;
    }
    if (var3 == 2)
    {
        if (IsBrightnessTransitionActive(var1))
            return;
        if (!REGION_FLAG(arg0, 0x80))
        {
#if !defined(jpn)
            int var4 = 1;
#endif
            var2->unknown_998_ = 1;
            if (arg0->unknown_b14_ > 0)
            {
#if !defined(jpn)
                if (!(arg0->unknown_b18_ & 0x200))
                    var4 = 0;
#endif
                if (REGION_MESSAGE(arg0, var4))
                {
                    if (REGION_FLAG(arg0, 1) && !REGION_FLAG(arg0, 0x8000))
                    {
                        Struct_ov008_021843f8_3 var5;
                        func_020ac4c0(&var5);
                        func_020a05d8((Struct_020a05d8*)&var5, 1);
                        func_020ac494(&var5);
                    }
                    memset(arg0->unknown_b8_, 0, REGION_LAYOUT(0x800, 0x960));
#if defined(jpn)
                    char* var6 = arg0->unknown_b8_;
                    char* var12 = var6 + 0x80;
                    Struct_ov008_02185dc0 var7;
                    func_020727d8((Struct_020727d8*)&var7);
                    func_020727f8(&var7, data_ov008_0218b400, arg0->unknown_b16_, var6, 0);
                    Struct_ov000_02179cdc_4* var8 = (Struct_ov000_02179cdc_4*)func_0200ff1c(var0, func_020100a8(var0));
                    func_020727d8((Struct_020727d8*)&var7);
                    int var9 = var8->unknown_150_->unknown_49c_0_;
                    func_020727f8(&var7, var6, arg0->unknown_b14_, var12, var9);
#else
                    char* var10 = arg0->unknown_b8_;
                    char* var11 = var10 + 0x80;
                    char* var12 = var10 + 0x100;
                    BackgroundLoader::AddLockGlobal();
                    Struct_ov008_02185dc0 var13;
                    unsigned int var14;
                    void* var15 = LoadFileIntoMemory(data_ov008_0218b400, data_0211e33c, &var14);
                    if (var15 != NULL)
                    {
                        func_020727d8((Struct_020727d8*)&var13);
                        func_02072928(&var13, (Struct_02013fb4*)var15, var14, arg0->unknown_b16_, var10, 0);
                        func_020727d8((Struct_020727d8*)&var13);
                        func_02072928(&var13, (Struct_02013fb4*)var15, var14, arg0->unknown_b16_, var11, 1);
                    }
                    var15 = ExtractFileFromGP2(var10, var11, &var14);
                    if (var15 != NULL)
                    {
                        Struct_ov000_02179cdc_4* var16 = (Struct_ov000_02179cdc_4*)func_0200ff1c(var0, func_020100a8(var0));
                        func_020727d8((Struct_020727d8*)&var13);
                        int var17 = var16->unknown_150_->unknown_49c_0_;
                        func_02072928(&var13, (Struct_02013fb4*)var15, var14, arg0->unknown_b14_, var12, var17);
                    }
                    BackgroundLoader::RemoveLockGlobal();
#endif
                    func_02042058(var12, func_020e0434((Struct_0201099c_3*)&arg0->unknown_a0_, 1000));
#if defined(jpn)
                    func_0204500c(var2, var12, 0);
#else
                    func_0204500c(var2, var12, 0, 0xe3);
#endif
                    var2->unknown_19b2_ = 1;
                    var2->unknown_19c8_ = 1;
                    var2->unknown_99c_ = 2;
                    if (arg0->unknown_b0c_ != NULL)
                    {
                        arg0->unknown_b18_ |= 0x200;
                        arg0->unknown_b10_ = 2;
                        arg0->unknown_b11_ = 0;
                        return;
                    }
                }
            }
            else
            {
#if !defined(jpn)
                if (!(arg0->unknown_b18_ & 0x200))
                    var4 = 0;
#endif
                if (REGION_MESSAGE(arg0, var4))
                {
#if defined(jpn)
                    func_0204500c(var2, func_020e0434((Struct_0201099c_3*)&arg0->unknown_a0_, 10000), 0);
#else
                    func_0204500c(var2, func_020e0434((Struct_0201099c_3*)&arg0->unknown_a0_, 10000), 0, 0xe3);
#endif
                    var2->unknown_19b2_ = 1;
                    var2->unknown_19c8_ = 1;
                    var2->unknown_99c_ = 2;
                }
            }
            if (REGION_FLAG(arg0, 0x20000))
            {
                var2->unknown_19c5_ = 1;
                var2->unknown_19b2_ = 0;
                arg0->unknown_b18_ |= 0x200;
                arg0->unknown_b11_ = 1;
                return;
            }
            arg0->unknown_b18_ |= 0x20;
        }
        arg0->unknown_b18_ |= 8;
        arg0->unknown_b11_++;
    }
    if (var3 == 3)
    {
        int result = func_ov008_02186a30(self, ticks);
        int selected = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->cursor_);
#if defined(jpn)
        int var20 = 5;
        int var21 = arg0->unknown_b29_;
        var20 += var21;
        if (var19 > var20)
            arg0->unknown_b29_ = var19 - 5;
        else if (var19 < var21)
            arg0->unknown_b29_ = var19;
#else
        if (var19 > arg0->unknown_b29_ + 5)
            arg0->unknown_b29_ = var19 - 5;
        else if (var19 < arg0->unknown_b29_)
            arg0->unknown_b29_ = var19;
#endif
        unsigned char var22 = arg0->unknown_744_[var19];
        if (g_keyManager.TestKeysPressed(0x401) || var18 == 1)
        {
            if (!func_0202c540(func_0202ae18()) || var22 != 5)
            {
                func_0205eaa0(&data_02108760, 1, 0);
                arg0->unknown_b10_ = var22 + 5;
                arg0->unknown_b11_ = 0;
                arg0->unknown_b18_ &= ~8;
                arg0->unknown_b18_ &= ~0x20;
                return;
            }
        }
        else if (g_keyManager.TestKeysPressed(0x806) || var18 == -2)
        {
            arg0->unknown_b10_ = 13;
            arg0->unknown_b11_ = 0;
            arg0->unknown_b18_ &= ~8;
            arg0->unknown_b18_ &= ~0x20;
        }
    }
}
