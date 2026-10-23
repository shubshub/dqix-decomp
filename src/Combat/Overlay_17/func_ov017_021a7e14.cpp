#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Resource/MessageSystem.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

struct Struct_02018300_3 {
    char unknown_0_[0xb2];
    short unknown_b2_;
};

struct Struct_0202b2f0;
struct Struct_0201099c_10;
struct Struct_0201099c_3;
struct Struct_0201099c_14;

struct Struct_020465c0 {
#if defined(jpn)
    char unknown_0_[0x28];
    char* unknown_5c_;
    char unknown_2c_[0x868 - 0x2c];
#else
    void* unknown1_0_;
    char unknown_4_[0x14];
    void* unknown_18_;
    char unknown_1c_[0xc];
    void* unknown_28_;
    char unknown1_2c_[0x30];
    char* unknown_5c_;
    char unknown_60_[0x998 - 0x60];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x19ae - 0x9a4];
#endif
    unsigned char unknown_19ae_;
};

struct Struct_ov017_021a7e14_6 {
    char unknown_0_[0x950];
    int unknown_950_;
};

struct Struct_ov017_021a7e14 {
    char unknown_0_[0x150];
    Struct_ov017_021a7e14_6* unknown_150_;
};

struct Struct_ov017_021a7e14_2 {
    char* unknown_0_;
    char* unknown_4_;
    int unknown_8_;
};

struct Struct_ov017_021a7e14_3 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
};

struct Struct_ov017_021a7e14_4 {
    SafeAllocator unknown_0_;
    char unknown_14_[0x18];
    Struct_0201099c_10* unknown_2c_;
    int unknown_30_;
    int unknown_34_;
};

struct Struct_ov017_021a7e14_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    SafeAllocator unknown_8_;
    Struct_0201099c_3* unknown_1c_;
    char* unknown_20_;
    int unknown_24_;
    int unknown_28_;
    Struct_0201099c_10* unknown_2c_;
    short unknown_30_;
    short unknown_32_;
    int unknown_34_;
    short unknown_38_;
    unsigned short unknown_3a_;
#if !defined(jpn)
    Struct_ov017_021a7e14_2* unknown_3c_;
    void* unknown_40_;
    void* unknown_44_;
    char* unknown_48_;
    char* unknown_4c_;
#endif
};

extern "C" Struct_020465c0* func_020421a0();
extern "C" Struct_0202b2f0* func_0202ae18();
extern "C" int func_020100a8(GameState* arg0);
extern "C" void func_020397cc(Struct_02018300_3* arg0, int arg1);
extern "C" void func_020a0cc4(unsigned int arg0);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_020a0c0c();
#if defined(jpn)
#define func_ov017_021a7dd8 func_ov017_021a8754
#endif
extern "C" void func_ov017_021a7dd8(Obj021a7e14* self);
void KeyTable_Reset(Struct020dfc40* p);
extern "C" void KeyTable_Load(void* dest, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
void ItemTable_Init(void* p);
void BuildDescriptorFlag1_020de980(void* dest, void* alloc, void* data, int size, int key);
void Clear12Bytes020e46c4(void* p);
extern "C" void* memset(void* dst, int c, unsigned int n);
void DispatchIfCountPositive020dcf7c(int key, void* p);
Element021a7e14* FindElementByKey020dedd0(Container020dedd0* c, int key);
void EnqueueEventTag170_021d0198(int a, int b, int c, int d);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
char* CallFunc020e0434With02153694_020e51cc(int value);
extern "C" void func_020e4b34(void* obj, char* name, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
extern "C" void func_02046380(StoreStruct* g);
void StoreInArray0x8b0_020465c0(StoreStruct* g, int a, int b);
void SetByteInRange_020465f0(unsigned char* p, int a, unsigned char b);
char* KeyTable_Get(Container020e0310* c, int key);
void AppendString02042058(char* dst, const char* src);
int SumKeyedLookups02086bf4(char* p, int key);
extern "C" int func_020457e0(StoreStruct* g);
int TestFlagBitAt0xe_0202c578(SearchStruct* s, int id);
int DecrementField38Clamped_021a85e8(unsigned char* obj, int amount);
void* ZeroInitReturn020de824(void* p);
void InitStruct0207cbe8(char* p);
extern "C" void func_0207cf30(void* ctx, int key, int amount, int arg);
void ReinitController02043204(char* g);
void SetByteField0x253_020397c0(void* obj);

extern AllocatorUnion data_02114e20;
#if defined(jpn)
extern const char data_ov017_021d7bf0[];
extern "C" void func_020de968(int, char*);
extern "C" void* func_020e08f0(int, unsigned int*);
extern "C" void __clear(void*, int);
struct Struct_02046574_2;
extern "C" void func_02046574(Struct_02046574_2*, int, char*);
#else
extern const char data_ov017_021d77c4[];
extern const char data_ov017_021d77de[];
extern const char* data_020f2a18;
extern const char* data_020f2a0c;
#endif

// USA: func_ov017_021a7e14
// JPN: func_ov017_021a8790
extern "C" ARM void func_ov017_021a7e14(Struct_ov017_021a7e14_5* arg0) {
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    Struct_020465c0* var2 = func_020421a0();
    Struct_0208cb08* var3 = func_02094a00();
    GetGameResources();
    Struct_0202b2f0* var4 = func_0202ae18();
    Struct_02018300_3* var5 = (Struct_02018300_3*)var0->GetUnknownGameObject();
    int var6 = func_020100a8(var0);
    func_020397cc(var5, 1);
    int var7 = 0;
    var5->unknown_b2_ = 0;

    if (arg0->unknown_24_ == 0) {
        func_020a0cc4(0x2000);
        void* var8 = func_02012d88(&data_02114e20, 0x2000);
        if (var8 == NULL) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var8, 0x2000);
        arg0->unknown_8_.Reset();
        arg0->unknown_1c_ = (Struct_0201099c_3*)arg0->unknown_8_.Allocate(0x18);
        if (arg0->unknown_1c_ == NULL) {
            func_ov017_021a7dd8(arg0);
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
#if defined(jpn)
        arg0->unknown_28_ = var1->QueueLoadFile(data_ov017_021d7bf0, NULL);
#else
        arg0->unknown_28_ = var1->QueueLoadFileInGP2(data_ov017_021d77c4, data_ov017_021d77de, NULL);
#endif
        self->state = 1;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(self->taskId, &data, &length);
            self->strings = (Container020e0310*)self->alloc.Allocate(0x18);
            KeyTable_Reset((Struct020dfc40*)self->strings);
            KeyTable_Load(self->strings, &self->alloc, data, length);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->message = g->message;
#if defined(jpn)
            func_02094b40(var3);
            func_02094b30(var3, 0x208, 0);
#endif
            arg0->unknown_24_ = 2;
        }
    } else if (arg0->unknown_24_ == 2) {
#if defined(jpn)
        if (!func_02094b4c(var3)) return;
        char var11[0x40];
#endif
        BackgroundLoader::AddLockGlobal();
        unsigned int var12;
#if defined(jpn)
        void* var13 = func_020e08f0(8, &var12);
#else
        void* var13 = ExtractFileFromGP2(data_020f2a18, data_020f2a0c, &var12);
#endif
        self->container = (Container020dedd0*)self->alloc.Allocate(0x18);
        ItemTable_Init(self->container);
        if (file != NULL) {
            BuildDescriptorFlag1_020de980(self->container, &self->alloc, file, size, self->key);
        }
#if defined(jpn)
        __clear(var11, sizeof(var11));
        func_020de968(arg0->unknown_30_, var11);
#else
        arg0->unknown_3c_ = (Struct_ov017_021a7e14_2*)arg0->unknown_8_.Allocate(0xc);
        arg0->unknown_48_ = (char*)arg0->unknown_8_.Allocate(0x40);
        arg0->unknown_4c_ = (char*)arg0->unknown_8_.Allocate(0x40);
        if (arg0->unknown_3c_ != NULL && arg0->unknown_48_ != NULL && arg0->unknown_4c_ != NULL) {
            func_020e46c4(arg0->unknown_3c_);
            memset(arg0->unknown_48_, 0, 0x40);
            memset(arg0->unknown_4c_, 0, 0x40);
            arg0->unknown_3c_->unknown_0_ = arg0->unknown_48_;
            arg0->unknown_3c_->unknown_4_ = arg0->unknown_4c_;
            func_020dcf7c(arg0->unknown_30_, arg0->unknown_3c_);
        }
#endif
        BackgroundLoader::RemoveLockGlobal();
#if !defined(jpn)
        arg0->unknown_40_ = arg0->unknown_8_.Allocate(0xc);
        arg0->unknown_44_ = arg0->unknown_8_.Allocate(0xc);
#endif
        Struct_ov017_021a7e14* var14 = (Struct_ov017_021a7e14*)func_0200ff1c(var0, arg0->unknown_34_);
        if (func_020dedd0(arg0->unknown_2c_, arg0->unknown_30_) == NULL || var14 == NULL
#if !defined(jpn)
            || arg0->unknown_3c_ == NULL || arg0->unknown_48_ == NULL || arg0->unknown_4c_ == NULL ||
            arg0->unknown_40_ == NULL || arg0->unknown_44_ == NULL
#endif
        ) {
            func_ov017_021d0198(5, arg0->unknown_34_, var6, arg0->unknown_30_);
            arg0->unknown_24_ = 7;
            return;
        }
#if defined(jpn)
        func_02046380(var2);
        func_02046574((Struct_02046574_2*)var2, 0, ((GameObject*)var14)->baseStats_->unk);
        func_02046574((Struct_02046574_2*)var2, 1, var11);
#else
        func_020e46c4(arg0->unknown_40_);
        func_020e4bf4(arg0->unknown_40_, arg0->unknown_34_);
        func_020e46c4(arg0->unknown_44_);
        char* var15 = func_020e51cc((short)var14->unknown_150_->unknown_950_);
        func_020e4b34(arg0->unknown_44_, var15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        func_02046380(var2);
        func_020465c0(var2, 0, 1);
        func_020465f0((unsigned char*)var2, 0, 1);
        var2->unknown1_0_ = arg0->unknown_40_;
        var2->unknown_18_ = arg0->unknown_3c_;
        var2->unknown_28_ = arg0->unknown_44_;
#endif
        char* var16 = var2->unknown_5c_;
#if defined(jpn)
        memset(var16, 0, 0x800);
#else
        memset(var16, 0, 0x960);
#endif
        AppendString02042058(message, (char*)KeyTable_Get(self->strings, 0x64));
        AppendString02042058(message, (char*)KeyTable_Get(self->strings, 0x78));
        if (SumKeyedLookups02086bf4((char*)GetPtrField0x2a04_02010828(gs), self->key) == 0x63) {
            AppendString02042058(message, (char*)KeyTable_Get(self->strings, 0x70));
            self->flags |= 1;
        } else {
            AppendString02042058(message, (char*)KeyTable_Get(self->strings, 0x6e));
        }
        var2->unknown_998_ = 1;
#if defined(jpn)
        func_0204500c((Struct_02021b84*)var2, var16, 0);
#else
        func_0204500c((Struct_02021b84*)var2, var16, 0, 0xe3);
#endif
        arg0->unknown_24_ = 3;
    } else if (arg0->unknown_24_ == 3) {
        if (var2->unknown_9a0_ == 3 || var2->unknown_9a0_ == 0) {
            var2->unknown_19ae_ = 0;
            int var17 = func_020457e0(var2);
            if (var17 == 0) {
                if (arg0->unknown_3a_ & 1) {
                    func_ov017_021d0198(8, arg0->unknown_34_, var6, arg0->unknown_30_);
                    arg0->unknown_3a_ &= ~1;
                    arg0->unknown_24_ = 7;
                } else {
                    func_ov017_021d0198(6, arg0->unknown_34_, var6, arg0->unknown_30_);
                    arg0->unknown_24_ = 4;
                    arg0->unknown_38_ = 0xe10;
                }
            } else if (var17 == 1) {
                func_ov017_021d0198(7, arg0->unknown_34_, var6, arg0->unknown_30_);
                arg0->unknown_24_ = 7;
            }
        }
    } else if (arg0->unknown_24_ == 4) {
        var2->unknown_19ae_ = 0;
        if (func_0202c578(var4, 0) || func_0202c578(var4, arg0->unknown_34_)) {
            var7 = 1;
        }
        int var18 = var0->GetTickCount();
        if (var18 == 0) {
            var18 = 1;
        }
        if (func_ov017_021a85e8((unsigned char*)arg0, var18) == 0) {
            var7 = 1;
        }
        if (var7) {
#if defined(jpn)
            func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0);
#else
            func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0, 0xe3);
#endif
            arg0->unknown_24_ = 7;
        }
    } else if (arg0->unknown_24_ == 5) {
        var2->unknown_19ae_ = 0;
        int var19 = var0->GetTickCount();
        if (var19 == 0) {
            var19 = 1;
        }
        if (func_ov017_021a85e8((unsigned char*)arg0, var19) == 0 && var2->unknown_9a0_ == 3) {
            if (func_0202c578(var4, 0) || func_0202c578(var4, arg0->unknown_34_)) {
#if defined(jpn)
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0);
#else
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x71), 0, 0xe3);
#endif
                arg0->unknown_24_ = 7;
            } else {
                Struct_ov017_021a7e14_3* var20 = func_020dedd0(arg0->unknown_2c_, arg0->unknown_30_);
                Struct_ov017_021a7e14_4 var21;
                var21.unknown_0_.ResetAllocatorPointer();
                func_020de824(var21.unknown_14_);
                func_0207cbe8((char*)&var21);
                func_0207cbe8((char*)&var21);
                var21.unknown_2c_ = arg0->unknown_2c_;
                if ((unsigned char)var20->unknown_8_0_ == 8) {
                    func_0207cf30(&var21, arg0->unknown_30_, 1, 0);
                }
#if !defined(jpn)
                func_02046380(var2);
                func_020465c0(var2, 0, 1);
                func_020465f0((unsigned char*)var2, 0, 1);
                var2->unknown1_0_ = arg0->unknown_40_;
                var2->unknown_18_ = arg0->unknown_3c_;
                var2->unknown_28_ = arg0->unknown_44_;
#endif
#if defined(jpn)
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x6f), 0);
#else
                func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x6f), 0, 0xe3);
#endif
                arg0->unknown_24_ = 7;
            }
        }
    } else if (arg0->unknown_24_ == 6) {
        func_02043204((char*)var2);
        var2->unknown_998_ = 1;
#if defined(jpn)
        func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x65), done);
#else
        func_0204500c((MessageSystem*)g, (char*)KeyTable_Get(self->strings, 0x65), done, 0xe3);
#endif
        arg0->unknown_24_ = 7;
    } else if (arg0->unknown_24_ == 7) {
        if (var2->unknown_998_ == 0) {
            var7 = 1;
        }
        if (var7) {
            func_02043204((char*)var2);
            func_020397c0(var5);
            func_ov017_021a7dd8(arg0);
            func_020a0c0c();
            arg0->unknown_1_ = 1;
        }
    }
}
