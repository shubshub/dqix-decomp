#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if defined(jpn)
enum { Enum_ov017_021a7378_5120 = 0x1000 };
#else
enum { Enum_ov017_021a7378_5120 = 0x1400 };
#endif
#include "Resource/FontBankLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Matrix.h"
#include "NitroSDK/Graphics.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "Resource/GameResources.h"

struct Struct_ov000_0217964c_3 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
    char unknown_99c_[0x9a0 - 0x99c];
    int unknown_9a0_;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x19ae - 0x9a4];
#endif
    unsigned char unknown_19ae_;
    char unknown_19af_[0x19b2 - 0x19af];
    unsigned char unknown_19b2_;
};

struct Struct_ov017_021a7378_4 {
#if defined(jpn)
    char unknown_0_[0x27f8];
#else
    char unknown1_0_[0x27b8];
#endif
    Vector3i unknown_27b8_;
    char unknown_27c4_[0x27d0 - 0x27c4];
    unsigned char unknown_27d0_;
};

struct Struct_ov001_02158ae4_3 {
    char unknown_0_[0x44];
    Vector3i unknown_44_;
    char unknown_50_[0x13c - 0x50];
    int unknown_13c_;
};

struct Struct_ov017_021a7378 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_[2];
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_[0x10 - 0x8];
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    unsigned short unknown_1c_;
    unsigned char unknown_1e_[0x61 - 0x1e];
    unsigned char unknown_61_;
};

struct Struct_0201bdac_2;
struct Struct_0201bdac;

struct Struct_ov017_021a7378_2 {
    char unknown_0_[4];
    unsigned short unknown_4_;
};

struct Struct_0201099c_3;
struct Struct_0200ffd0;
struct Struct_020d7aa0_2;
struct Struct_0204bef4;
struct Struct_0205faf4_7;

struct Struct_ov017_021a7378_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[0x8 - 0x2];
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    unsigned int unknown_1c_;
    int unknown_20_;
#if defined(jpn)
    unsigned char unknown_24_[0x1ec - 0x24];
#else
    unsigned char unknown_24_[0x25c - 0x24];
#endif
    SafeAllocator unknown_25c_;
    char unknown_270_[0x10];
};

unsigned char* GetFieldIfFlag4_020100f8(char* obj);
MessageWindow* GetGlobalField0x1c020421a0();
extern "C" FieldGlobals* func_02012fe4(void);
CameraState* GetPointerAt0x330_0200ffd0(PointerField330_ffd0* obj);
void SetupAndDispatch0205c904(unsigned char* obj, int value);
void* GetGlobalResetObj020d7a50(void);
void TeardownAndResetState020d7aa0(Obj020d7aa0* obj);
extern "C" void func_020a0cc4(unsigned int size);
void ClearByteFlagAt0x19c_020ae38c(unsigned char* obj);
void SetByteFlagAt0x19c_020ae380(unsigned char* obj);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern "C" void KeyTable_Load(void* dest, SafeAllocator* allocator, void* fileData, unsigned int size);
int KeyTable_Get(Container020e0310* c, int key);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
extern "C" int func_020457e0(MessageWindow* window);
CameraParams* GetField0x3f8Address_0200fd0c(GameState* gs);
void InitStruct02070378(char* obj);
void* GetPtrField0x114_02033fa0(void* obj);
int CheckBits5To9NonZero0204bedc(unsigned short* obj);
int ConvertColorToDecimalOffset20000(ColorHolder0204bef4* obj);
void InitAndResetHeader_0219e310(unsigned char* obj, int flag);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void InitAndAppendState61_021a65c4(void* scene, unsigned char kind, int arg);
extern "C" void func_ov017_021baedc(TailNode020469b4* node, int flag);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char a, unsigned short b);
void EnqueueEventTagB5_021d1dc0(unsigned short, int, int*, int, int);
void* GetGlobal02109418_02094d6c(void);
EntryCounter* FindEntryById02096134(FindEntryById02096134Table* table, int id);
void ReinitController02043204(char* obj);
void SetupGlobalObjType3AndInitSelfPointer_0205ce50(unsigned char* obj);
extern "C" void func_ov017_021a79f0(BattleIntro* self);

extern AllocatorUnion data_02114e20;
#if defined(jpn)
extern const char data_ov017_021d7bd4[];
#else
extern const char data_ov017_021d7798[];
extern const char data_ov017_021d77b2[];
#endif

// USA: func_ov017_021a7378
// JPN: func_ov017_021a7d20
extern "C" ARM void func_ov017_021a7378(Struct_ov017_021a7378_3* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    unsigned char* var1 = func_020100f8((char*)var0);
    Struct_ov000_0217964c_3* var2 = func_020421a0();
    Struct_ov017_021a7378_4* var3 = func_02012fe4();
    Struct_ov001_02158ae4_3* var4 = func_0200ffd0((Struct_0200ffd0*)var0);
    func_0205c904(arg0->unknown_24_, var0->GetTickCount());

    if (arg0->unknown_8_ == 0) {
        func_020d7aa0((Struct_020d7aa0_2*)func_020d7a50());
        arg0->unknown_1c_ = (DISPCNT & 0x1f00) >> 8;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1100;
        func_020a0cc4(Enum_ov017_021a7378_5120);
        func_020ae38c((unsigned char*)func_0200ffd0((Struct_0200ffd0*)var0));
        Struct_0208cb08* var5 = func_02094a00();
        func_02094b30(var5, 0x205, 0);
        if (func_02094b4c(var5)) {
#if defined(jpn)
            arg0->unknown_20_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d7bd4, NULL);
#else
            arg0->unknown_20_ = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d7798, data_ov017_021d77b2, NULL);
#endif
            arg0->unknown_25c_.CreateTypeA(func_02012d88(&data_02114e20, Enum_ov017_021a7378_5120), Enum_ov017_021a7378_5120);
            arg0->unknown_8_ = 1;
        }
    } else if (self->state == 1) {
        BackgroundLoader* bl = BackgroundLoader::GetInstance();
        if (bl->GetTaskStatus(self->taskId)) {
            void* fileData;
            unsigned int size;
            bl->GetLoadedFileByID(self->taskId, &fileData, &size);
            self->allocator.Reset();
            KeyTable_Load(self->container, &self->allocator, fileData, size);
            bl->RemoveTask(self->taskId);
            self->taskId = -1;
            if (self->mode == 0) {
#if defined(jpn)
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x23), 0);
#else
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x23), 0, 0xe3);
#endif
                arg0->unknown_8_ = 0xc8;
            } else {
#if defined(jpn)
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x24), 0);
#else
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x24), 0, 0xe3);
#endif
                arg0->unknown_8_ = 0x12c;
            }
            var2->unknown_19b2_ = 0;
            var2->unknown_998_ = 1;
            func_020a28a0(var1, 2);
        }
    } else if (arg0->unknown_8_ == 0xc8) {
        if (var2->unknown_9a0_ == 0) {
            func_020a28b0(var1, 2);
            if (func_020457e0(var2) == 0) {
                Struct_ov017_021a7378* var9 = func_0200fd0c(var0);
                func_02070378((char*)var9);
                var9->unknown_2_ = 1;
                var9->unknown_7_ = 1;
                var9->unknown_5_ = 1;
                var9->unknown_0_ = 0x1901;
                var9->unknown_1c_ = 0x25c2;
                var9->unknown_10_ = 0x3800;
                var9->unknown_14_ = 0x999;
                var9->unknown_18_ = -0x3800;
                arg0->unknown_8_ = 0x64;
                func_ov017_021a7378(arg0, arg1);
            } else {
                arg0->unknown_8_ = 0x64;
                func_ov017_021a7378(arg0, arg1);
            }
        }
    } else if (arg0->unknown_8_ == 0x12c) {
        if (var2->unknown_9a0_ == 0) {
            func_020a28b0(var1, 2);
            if (func_020457e0(var2) == 0) {
                void* var10 = func_02033fa0(var4);
                if (var10 != NULL && func_0204bedc((unsigned short*)var10)) {
                    arg0->unknown_18_ = 0;
                    arg0->unknown_8_ = 0x62;
                    var4->unknown_13c_ = 1;
                    func_ov017_021a7378(arg0, arg1);
                } else {
                    var2->unknown_998_ = 1;
#if defined(jpn)
                    func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x26), 0);
#else
                    func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x26), 0, 0xe3);
#endif
                    arg0->unknown_8_ = 0x12d;
                    func_020a28a0(var1, 2);
                }
            } else {
                var2->unknown_998_ = 1;
#if defined(jpn)
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x25), 0);
#else
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x25), 0, 0xe3);
#endif
                arg0->unknown_8_ = 0x12d;
                func_020a28a0(var1, 2);
            }
        }
    } else if (arg0->unknown_8_ == 0x12d) {
        if (var2->unknown_9a0_ == 0) {
            func_020a28b0(var1, 2);
            if (func_020457e0(var2) == 0) {
                arg0->unknown_18_ = 3;
                var4->unknown_13c_ = 2;
                arg0->unknown_8_ = 0x63;
            } else {
                arg0->unknown_8_ = 0x64;
                func_ov017_021a7378(arg0, arg1);
            }
        }
    } else if (arg0->unknown_8_ == 0x62) {
        if (++arg0->unknown_10_ > 0xf) {
            arg0->unknown_8_ = 0x63;
        }
    } else if (arg0->unknown_8_ == 0x63) {
        GameResources* var11 = GetGameResources();
        Struct_ov017_021a7378* var12;
        Struct_0201bdac_2* var13 = (Struct_0201bdac_2*)var11->unknown_ptr_array_36fc[0];
        Struct_0201bdac* var14 = (Struct_0201bdac*)var11->unknown_ptr_array_371c[6];
        var12 = func_0200fd0c(var0);
        func_02070378((char*)var12);
        var12->unknown_7_ = 1;
        void* var15 = func_02033fa0(var4);
        switch (arg0->unknown_18_) {
        case 0: {
            var12->unknown_61_ = 1;
            var12->unknown_0_ = func_0204bef4((Struct_0204bef4*)var15);
            var12->unknown_1c_ = 0;
            var12->unknown_10_ = 0x100000;
            var12->unknown_14_ = 0;
            var12->unknown_18_ = 0x100000;
            var3->unknown_27b8_ = var4->unknown_44_;
            func_0200fcfc(var0, var12);
            Struct_0201bdac* var16 = (Struct_0201bdac*)var11->unknown_ptr_array_36fc[4];
            func_ov017_0219e310((unsigned char*)var16, 0);
            func_020469b4(var13, var16);
            func_ov017_021a65c4(var11, 1, 0);
            break;
        }
        case 3:
            var4->unknown_13c_ = 2;
            func_ov017_021baedc(var14, 1);
            *(unsigned short*)((char*)var14 + 8) = 0x7346;
            func_020469b4(var13, var14);
            break;
        }
        Vector3i var17;
        if (arg0->unknown_18_ == 3) {
            func_ov017_021d1c2c(3, 0);
            func_ov017_021d1dc0(3, 0, (int*)&var17, 0x7346, 0);
        } else {
            var17 = var4->unknown_44_;
            func_ov017_021d1c2c(0, 0);
            func_ov017_021d1dc0(0, var12->unknown_0_, (int*)&var17, 0, 0);
        }
        if (var3->unknown_27d0_ < 0xff) {
            var3->unknown_27d0_++;
        }
        Struct_ov017_021a7378_2* var18 = func_02096134((Struct_0205faf4_7*)func_02094d6c(), 0xbc);
        if (var18 != NULL && var18->unknown_4_ < 10) {
            var18->unknown_4_++;
        }
        arg0->unknown_8_ = 0x64;
        func_02043204((char*)var2);
    } else if (arg0->unknown_8_ == 0x64) {
        var2->unknown_19ae_ = 0;
        if (var2->unknown_9a0_ == 0) {
            func_02043204((char*)var2);
            func_0205ce50(arg0->unknown_24_);
            func_020ae380((unsigned char*)func_0200ffd0((Struct_0200ffd0*)var0));
            func_ov017_021a79f0(arg0);
            arg0->unknown_1_ = 1;
        }
    }
}
