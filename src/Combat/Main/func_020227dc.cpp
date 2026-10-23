#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"
#include "Resource/Brightness.h"

extern "C" unsigned short* func_02012fe4(void);
extern "C" char* func_0203bd08(void);
extern "C" ARM void* func_0203b628(void);

extern "C" void func_02021428(void* arg0, int arg1);
extern "C" void func_020209d0(void* arg0);
extern "C" void func_0203b66c(char* arg0);
extern "C" void func_0203bd78(char* arg0);
extern "C" void func_0203bd24(char* arg0);

extern "C" int func_0203b784(int* arg0, int arg1, int arg2, int arg3, unsigned int arg4, unsigned int arg5);
extern "C" void func_0203b718(void* arg0, int arg1, int arg2, int arg3);
extern "C" void func_0203ba74(void* arg0);

void Sprite_Init(struct Struct0205a198* p);
void SpriteContext_Init(char* obj);

extern "C" void func_02020aa0(void* arg0);

struct Struct_02020fc4;
extern "C" void func_0203bb1c(struct Struct_02020fc4* arg0);

struct Struct_02020fc4_2;
extern "C" void func_0203bb3c(struct Struct_02020fc4_2* arg0, char* arg1, SafeAllocator* arg2, int arg3, unsigned short arg4);

struct Struct_02020fc4_3;
extern "C" void func_0203bcb8(struct Struct_02020fc4_3* arg0, int arg1, int arg2);

struct Struct_0201f040 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    char unknown_2c_[0x400];
    unsigned char unknown_42c_;
};

struct Struct_02013fb4;
struct Struct_0201f040_2;

struct Struct_0201f040_3;

extern "C" void func_0202445c(void* arg0);
extern "C" void func_ov017_02191234(void* arg0);
extern "C" void func_020c9820(void);
extern "C" void func_0202343c(void* arg0);
extern "C" void func_02026b7c(unsigned char* arg0);
extern "C" void func_02026bdc(void* arg0, int arg1);

extern char data_020ef67c;
extern int data_020ef460;
extern char data_020ef692;
extern char data_020ef69f;
extern int data_020ef498;
extern char data_020ef6b5;

#if defined(jpn)
enum { Enum_020227dc_172 = 0xac, Enum_020227dc_0_2 = 4 };
#else
enum { Enum_020227dc_0 = 0, Enum_020227dc_0_2 = 0 };
#endif

struct Struct_020fdc4c_7 {
    char unknown_0_[0x8 - Enum_020227dc_0_2];
    void* unknown_8_;
    char unknown_c_[0x10 - 0xc];
    void* unknown_10_;
};
extern struct Struct_020fdc4c_7 data_020fdc4c;

// USA: func_020227dc
extern "C" ARM void func_020227dc(Struct_02020554* arg0) {
    GameState::GetInstance();
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    unsigned short* var1 = func_02012fe4();
    char* var2 = ((char*)GetGameResources());
    char* var3 = func_0203bd08();
    void* var4 = func_0203b628();
    int var5;
    SafeAllocator* var6 = (SafeAllocator*)(var2 + 0x128);

    if (arg0->unknown_9c2_ == 0) {
        func_02021428(arg0, 0x19);
        var0->AddFence();
        arg0->unknown_a24_ = var0->QueueLoadFile(&data_020ef67c, 0);
        arg0->unknown_a20_ = var0->QueueLoadFileInGP2((const char*)(*(int*)((char*)&data_020ef460 + 8 - Enum_020227dc_0_2)), &data_020ef692, 0);
        arg0->unknown_a28_ = var0->QueueLoadFile(&data_020ef69f, 0);
        arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
        return;
    }

    if (arg0->unknown_9c2_ != 1) return;

    if (var0->GetTaskStatus(arg0->unknown_a24_) == 0) return;
    if (var0->GetTaskStatus(arg0->unknown_a20_) == 0) return;
    if (var0->GetTaskStatus(arg0->unknown_a28_) == 0) return;

    func_02021428(arg0, 0x19);
    if (IsBrightnessWithinValidRange((GameResources*)var2, true) != 0) return;

    func_02020720(arg0);
    func_020209d0(arg0);
    func_0203b66c((char*)var4);
    var6->Reset();
    func_0203bd78(var3);
    func_0203bd24(var3);

    char var7[0x20];
    memset(var7, 0, 0x20);
    func_0203b784((int*)var4, 1, 1, (int)var7, 0x20, 1);
    func_0203b718(var4, 1, 0, 0);
    func_0203b718(var4, 1, 1, 0);
    func_0203ba74(var4);

    for (i = 0; i < 0x1c; i++) {
        Sprite_Init(&ctx->records[i]);
    }

    SpriteContext_Init((char*)&ctx->entryList);
    ctx->entryList.active = 1;
    ctx->entryList.records = ctx->records;
    ctx->entryList.count = 0x1c;
    ctx->displayMode = 1;
#if defined(jpn)
    func_02020aec(arg0, arg0->unknown_a24_, var6);
#else
    func_02020aec(arg0, &arg0->unknown_a24_, var6);
#endif

    func_02020aa0(arg0);
    arg0->unknown_24_ = 1;
    arg0->unknown_30_ = 1;

    void* var8 = 0;
    unsigned int var9 = 0;
    var0->GetLoadedFileByID(arg0->unknown_a20_, &var8, &var9);

    arg0->unknown_20_ = (Struct_020210f8*)var6->Allocate(sizeof(Struct_020210f8));
    func_0203bb1c((struct Struct_02020fc4*)((char*)arg0->unknown_20_ + 8));

    func_0203bb3c((struct Struct_02020fc4_2*)((char*)arg0->unknown_20_ + 8), (char*)var8, var6, 1, 0);
    func_0203bcb8((struct Struct_02020fc4_3*)((char*)arg0->unknown_20_ + 8), 0, 0);

    BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_a20_);
    arg0->unknown_a20_ = -1;

    var0->GetLoadedFileByID(arg0->unknown_a28_, &var8, &var9);

    struct Struct_0201f040 var10;
    data_020fdc4c.unknown_10_ = arg0;
    data_020fdc4c.unknown_8_ = var6;
    ((Script*)&var10)->Initialize();
    ((Script*)&var10)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020ef498);
    ((Script*)((struct Struct_0201f040_2*)&var10))->Load((struct Struct_02013fb4*)var8, (int)var9);
    ((Script*)((struct Struct_0201f040_3*)&var10))->Execute();

    if (*var1 == 10000 || *var1 == 10100) {
        arg0->unknown_12_ = 1;
        arg0->unknown_779_ = 0;
        arg0->unknown_9ba_ = 0;
        strcpy(arg0->unknown_2_, &data_020ef6b5);
    }

    BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_a28_);
    arg0->unknown_a28_ = -1;

    func_0202445c(arg0);
    func_ov017_02191234(var2);
    arg0->unknown_55c_ = 1;
    arg0->unknown_9c4_ = 1;
    arg0->unknown_9c8_ = 0;
    arg0->unknown_9c3_ = 0;
    arg0->unknown_9c2_ = arg0->unknown_9c2_ + 1;
    func_020c9820();
    func_0202343c(arg0);
    func_02026b7c((unsigned char*)arg0);
    func_02026bdc(arg0, 0);
}
