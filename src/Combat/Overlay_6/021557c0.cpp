#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_020dbd9c {
    char unknown_0_[0x10];
    int unknown_10_;
    unsigned char unknown_14_;
};

struct Struct_ov006_02154614_2 {
    char unknown_0_[0x48];
    void* unknown_48_;
#if defined(jpn)
    char unknown_4c_[0x6f0 - 0x4c];
#else
    char unknown1_4c_[0x774 - 0x4c];
#endif
    unsigned short unknown_774_;
    unsigned char unknown_776_;
    char unknown_777_[0x6];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_ov006_02156e54 {
    char unknown_0_[0x7c];
};

struct Struct_ov006_021537d0 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_[3];
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 4;
    unsigned short unknown_b_0_ : 4;
    unsigned short unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 20;
    unsigned int unknown_e_4_ : 8;
    unsigned int unknown_f_4_ : 4;
};

struct Struct_ov006_021555b0 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char unknown_0_[3][0x80];
#endif
    SafeAllocator* unknown_180_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* unknown_1a0_;
    void* unknown_1a4_;
    unsigned char* unknown_1a8_;
    void* unknown_1ac_;
    void* unknown_1b0_;
    Struct_ov006_021537d0* unknown_1b4_;
    Struct_ov006_021537d0* unknown_1b8_;
    int unknown_1bc_;
    Struct_ov006_021555b0* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* unknown_1c8_;
    void* unknown_1cc_;
    void* unknown_1d0_;
    void* unknown_1d4_;
    void* unknown_1d8_;
    void* unknown_1dc_;
    void* unknown_1e0_;
    char unknown_1e4_[0x54];
    Object3D unknown_238_;
    Object3D unknown_2e4_;
    Object3D unknown_390_;
    Object3D unknown_43c_;
    Object3D unknown_4e8_;
    char unknown_594_[0x38];
    char unknown_5cc_[0x2c8];
    Struct_ov006_02156e54 unknown_894_[4];
    SafeAllocator unknown_a84_[4];
    int unknown_ad4_;
    int unknown_ad8_;
    unsigned char unknown_adc_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short unknown_ae2_;
    Struct_ov006_02154614_2 unknown_ae4_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char unknown_1288_[0x18];
    Struct_020dbd9c unknown_12a0_;
    short unknown_12b8_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};

struct Struct_ov000_02171c04 {
    unsigned char unknown_0_[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned char unknown_c_[0xc];
    short unknown_18_;
    unsigned char unknown_1a_[6];
};

struct Struct_ov000_02171c04_2 {
    unsigned char unknown_0_[0x194];
    Struct_ov000_02171c04 unknown_194_[8];
};

struct Struct_ov006_021557c0 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_0201099c_3;
struct Struct_0201099c_10;

extern "C" void __clear(void* dst, int size);
int KeyTable_Get(Container020e0310* texts, int id);
#if defined(jpn)
extern "C" int func_020e12ec(char* arg0, const char* arg1);
#define data_ov006_0215ff5c data_ov006_021612c0
#endif
void ItemTable_Init(void* obj);
int BuildDescriptorFlag1_020de980(void* obj, void* alloc, void* data, int size, int id);
void* FindElementByKey020dedd0(Container020dedd0* c, int key);
extern "C" void func_ov023_021dcd90(ItemInfoWindow* window, unsigned char inMenu);
extern "C" void func_ov023_021dcae0(ItemInfoWindow* window, int item);
extern "C" void func_ov023_021dced4(ItemInfoWindow* window, unsigned char multiplier);
const char** CallFunc020e52a0_020e5294(void* names, int item);
extern "C" void func_020e4864(const char* src, char* dst, int a, int b, int c, int d);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
void* GetPtrField0x2a04_02010828(GameState* gameState);
void SetFields_021dceac(char* window, int index, int name, unsigned char count, unsigned char maximum, unsigned char unk);

extern unsigned char data_ov006_0215ff5c[8];

// USA: func_ov006_021557c0
extern "C" ARM void func_ov006_021557c0(Struct_ov006_02154614* arg0) {
    if (!(arg0->unknown_ae2_ & 2) || arg0->unknown_ae4_.unknown_776_ == 0)
        return;
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    short var1 = arg0->unknown_12b8_;
    if (var1 > 0) {
        if (arg0->unknown_ade_ == 0) {
            short var2 = arg0->unknown_12ba_ + 0x26;
#if defined(jpn)
            const char* inner = (const char*)KeyTable_Get((Container020e0310*)self->texts_, innerKey);
            char path[0x40];
            func_020e12ec(path, inner);
            self->task_ = loader->QueueLoadGP1(path, 0);
#else
            short gp2Key = self->itemSprites_ + 0x64;
            const char* inner = (const char*)KeyTable_Get((Container020e0310*)self->texts_, innerKey);
            const char* gp2 = (const char*)KeyTable_Get((Container020e0310*)self->texts_, gp2Key);
            self->task_ = loader->QueueLoadFileInGP2(gp2, inner, 0);
#endif
            arg0->unknown_ade_++;
        }
        if (arg0->unknown_ade_ == 1) {
            if (var0->GetTaskStatus(arg0->unknown_ad4_) == 0)
                return;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &data, &size);
            self->nextItemAllocator_->Reset();
            short id = self->itemId_;
            ItemTable_Init(self->partNames_);
            BuildDescriptorFlag1_020de980(self->partNames_, self->nextItemAllocator_, data, size, id);
            self->window_.flags_ &= ~0x1000;
            self->window_.partNames_ = self->partNames_;
            func_ov023_021dcd90(&self->window_, 1);
            loader->RemoveTask(self->task_);
            self->nextItem_ = FindElementByKey020dedd0((Container020dedd0*)self->partNames_, id);
            self->flags_ &= ~2;
            self->flags_ |= 0x40;
            func_ov023_021dcae0(&self->window_, self->itemId_);
            return;
        }
    } else if (var1 == -1) {
        arg0->unknown_ae2_ &= ~2;
        arg0->unknown_ae2_ |= 0x40;
        arg0->unknown_ae4_.unknown_774_ &= ~0x1000;
        func_ov023_021dcd90(&arg0->unknown_ae4_, 1);
        func_ov023_021dcae0(&arg0->unknown_ae4_, arg0->unknown_12b8_);
        return;
    }

    if (arg0->unknown_ade_ == 0) {
#if defined(jpn)
        short innerKey = 0x26;
        innerKey += self->nextRecipe_->letter_;
        const char* inner = (const char*)KeyTable_Get((Container020e0310*)self->texts_, innerKey);
        char path[0x40];
        func_020e12ec(path, inner);
        self->task_ = loader->QueueLoadGP1(path, 0);
#else
        short gp2Key = 0x64;
        short innerKey = 0x26;
        gp2Key += self->nextRecipe_->letter_;
        innerKey += self->nextRecipe_->letter_;
        const char* inner = (const char*)KeyTable_Get((Container020e0310*)self->texts_, innerKey);
        const char* gp2 = (const char*)KeyTable_Get((Container020e0310*)self->texts_, gp2Key);
        self->task_ = loader->QueueLoadFileInGP2(gp2, inner, 0);
#endif
        arg0->unknown_ade_++;
    } else if (arg0->unknown_ade_ == 1) {
        if (var0->GetTaskStatus(arg0->unknown_ad4_) == 0)
            return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &data, &size);
        if (data != 0) {
            self->nextItemAllocator_->Reset();
            ItemTable_Init(self->partNames_);
            BuildDescriptorFlag1_020de980(self->partNames_, self->nextItemAllocator_, data, size, self->nextRecipe_->item_);
            self->nextItem_ = FindElementByKey020dedd0((Container020dedd0*)self->partNames_, self->nextRecipe_->item_);
        }
        var0->RemoveTask(arg0->unknown_ad4_);
        arg0->unknown_ad4_ = -1;
        arg0->unknown_ade_ = 3;
    } else if (arg0->unknown_ade_ == 3) {
        arg0->unknown_1b4_ = arg0->unknown_1b8_;
        SafeAllocator* var20 = arg0->unknown_184_;
        arg0->unknown_184_ = arg0->unknown_188_;
        arg0->unknown_188_ = var20;
        arg0->unknown_ae4_.unknown_48_ = arg0->unknown_1288_;
        func_ov023_021dcd90(&arg0->unknown_ae4_, 1);
        const char* var21[3] = {0};
        if (arg0->unknown_1ac_ != 0) {
#if defined(jpn)
            names[0] = (const char*)KeyTable_Get((Container020e0310*)self->itemNames_, self->nextRecipe_->ingredients_[0]);
            names[1] = (const char*)KeyTable_Get((Container020e0310*)self->itemNames_, self->nextRecipe_->ingredients_[1]);
            names[2] = (const char*)KeyTable_Get((Container020e0310*)self->itemNames_, self->nextRecipe_->ingredients_[2]);
#else
            memset(arg0->unknown_0_, 0, sizeof(arg0->unknown_0_));
            const char** var22 = func_020e5294(arg0->unknown_1ac_, arg0->unknown_1b8_->unknown_4_[0]);
            if (var22 != 0) {
                func_020e4864(*var22, arg0->unknown_0_[0], 1, 0, 0, 0);
                var21[0] = arg0->unknown_0_[0];
            }
            var22 = func_020e5294(arg0->unknown_1ac_, arg0->unknown_1b8_->unknown_4_[1]);
            if (var22 != 0) {
                func_020e4864(*var22, arg0->unknown_0_[1], 1, 0, 0, 0);
                var21[1] = arg0->unknown_0_[1];
            }
            var22 = func_020e5294(arg0->unknown_1ac_, arg0->unknown_1b8_->unknown_4_[2]);
            if (var22 != 0) {
                func_020e4864(*var22, arg0->unknown_0_[2], 1, 0, 0, 0);
                var21[2] = arg0->unknown_0_[2];
            }
#endif
        }
        unsigned char var23[3] = {0};
        GameState* var24 = GameState::GetInstance();
        Struct_ov006_021557c0* var25 = (Struct_ov006_021557c0*)func_02010828(var24);
        for (int var26 = 0; var26 < var25->unknown_f7c_; var26++) {
            char* var27 = (char*)func_0200ff1c(var24, var25->unknown_f78_[var26]);
            if (var27 != 0) {
                for (int var28 = 0; var28 < 8; var28++) {
                    Struct_ov000_02171c04_2* var29 = *(Struct_ov000_02171c04_2**)(var27
#if defined(jpn)
                        + 0x144
#else
                        + 0x150
#endif
                    );
                    Struct_ov000_02171c04* var30 = &var29->unknown_194_[data_ov006_0215ff5c[var28]];
                    if (var30 != 0) {
                        int var31 = var30->unknown_8_0_ <= 7;
                        if (var31) {
                            if (arg0->unknown_1b8_->unknown_4_[0] == var30->unknown_18_)
                                var23[0]++;
                            if (arg0->unknown_1b8_->unknown_4_[1] == var30->unknown_18_)
                                var23[1]++;
                            if (arg0->unknown_1b8_->unknown_4_[2] == var30->unknown_18_)
                                var23[2]++;
                        }
                    }
                }
            }
        }
        func_ov023_021dceac((char*)&arg0->unknown_ae4_, 0, (int)var21[0], arg0->unknown_1b8_->unknown_a_0_, arg0->unknown_1a8_[0], var23[0]);
        func_ov023_021dceac((char*)&arg0->unknown_ae4_, 1, (int)var21[1], arg0->unknown_1b8_->unknown_a_4_, arg0->unknown_1a8_[1], var23[1]);
        func_ov023_021dceac((char*)&arg0->unknown_ae4_, 2, (int)var21[2], arg0->unknown_1b8_->unknown_b_0_, arg0->unknown_1a8_[2], var23[2]);
        func_ov023_021dced4(&arg0->unknown_ae4_, 1);
        int var32 = 0;
        if (arg0->unknown_1c0_ != 0 && arg0->unknown_1c0_->unknown_2_0_)
            var32 = 1;
        if (var32)
            arg0->unknown_ae4_.unknown_774_ &= ~0x1000;
        else
            arg0->unknown_ae4_.unknown_774_ |= 0x1000;
        func_ov023_021dcae0(&arg0->unknown_ae4_, arg0->unknown_1b8_->unknown_2_);
        arg0->unknown_1d8_ = arg0->unknown_1dc_;
        arg0->unknown_1dc_ = 0;
        arg0->unknown_ade_ = 0;
        arg0->unknown_ae2_ &= ~2;
        arg0->unknown_ae2_ |= 0x44;
    }
}
