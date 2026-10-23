#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_020c9be0 func_020cb6ac
#endif

#if defined(jpn)
enum { Enum_020e081c_1900 = 0x6c0, Enum_020e081c_1904 = 0x6c4, Enum_020e081c_1908 = 0x6c8,
       Enum_020e081c_2498 = 0x916, Enum_020e081c_2499 = 0x917, Enum_020e081c_2556 = 0x950, Enum_020e081c_2568 = 0x95c,
       Enum_020e081c_13312 = 0x2500, Enum_020e081c_600 = 0x200, Enum_020e081c_1288 = 0x608 };
#define data_020f2b78 data_020f2cd0
extern const char data_020f2ce8[];
#else
enum { Enum_020e081c_1900 = 0x76c, Enum_020e081c_1904 = 0x770, Enum_020e081c_1908 = 0x774,
       Enum_020e081c_2498 = 0x9c2, Enum_020e081c_2499 = 0x9c3, Enum_020e081c_2556 = 0x9fc, Enum_020e081c_2568 = 0xa08,
       Enum_020e081c_13312 = 0x3400, Enum_020e081c_600 = 0x258, Enum_020e081c_1288 = 0x508 };
extern const char data_020f2b90[];
extern const char data_020f2ba2[];
#endif

struct Struct_02043368_2 { char unknown_0_[0x28]; };
struct Struct_02020aec;
struct Struct_020213fc;
struct Struct_02021410;
struct Struct_020e081c {
    char unknown_0_[0x40];
    Struct_02043368_2* unknown_40_;
    char unknown_44_[8];
    unsigned short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
    char unknown_51_[3];
};

extern "C" void* func_02012fe4();
extern "C" char* func_0203bd08();
extern "C" char* func_0203b628();
extern "C" void func_020213fc(Struct_020213fc*, int);
extern "C" void func_02021428(void*, int);
void InitSubScreenDisplay_020209d0(void* context);
void TailForward0203b66c(char*);
void InitBattleContext0203bd24(char*);
void Sprite_Init(Struct0205a198*);
void SpriteContext_Init(char*);
int ProcessRecords0205a498(void*, Rec020467f0*, int, void*);
void* GetGlobalPtr02105244_0203bd14();
extern "C" void* func_0203be4c(char*);
extern "C" void func_020c9be0();
extern "C" void func_020c9820();
#if defined(jpn)
extern "C" void func_02020cb8(void*, int);
#else
extern "C" void func_02020cb8(void*, int*);
#endif
extern "C" void func_02022b90(void*, int*);
extern "C" void func_02021410(Struct_02021410*, int, int);
extern const char data_020f2b78[];

static inline SafeAllocator* inline_02021578(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

// KEEP-NAME: func_020e081c is the shared regional export.
// USA: func_020e081c
extern "C" ARM void func_020e081c(char* arg0) {
    GameState::GetInstance();
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    func_02012fe4();
    GameResources* resources = GetGameResources();
    char* battle = func_0203bd08();
    char* table = GetData02105254_0203b628();
    SafeAllocator* allocator = GetResourceAllocator(resources, 12);
    if (*(signed char*)(self + kStage) == 0) {
        SetFlag0x9c6_020213fc((SetFlagStruct*)self, 0);
        func_02021428(self, 0x19);
        InitSubScreenDisplay_020209d0(self);
        allocator->Reset();
        TailForward0203b66c(table);
        InitBattleContext0203bd24(battle);
        for (int i = 0; i < 28; ++i)
            Sprite_Init(&((Struct0205a198*)(self + 0xe8))[i]);
        SpriteContext_Init(self + 0x94);
        Script020e081c* script = (Script020e081c*)(self + 0x94);
        script->active = 1;
        script->records = (Struct0205a198*)(self + 0xe8);
        script->count = 5;
        loader->AddFence();
        *(int*)(self + kBaseTask) = loader->QueueLoadFile(data_020f2b78, 0);
#if defined(jpn)
        *(int*)(arg0 + Enum_020e081c_2568) = var0->QueueLoadFile(data_020f2ce8, 0);
#else
        *(int*)(arg0 + Enum_020e081c_2568) = var0->QueueLoadFileInGP2(data_020f2b90, data_020f2ba2, 0);
#endif
        ++*(signed char*)(arg0 + Enum_020e081c_2498);
    } else if (*(signed char*)(arg0 + Enum_020e081c_2498) == 1) {
        if (!var0->GetTaskStatus(*(int*)(arg0 + Enum_020e081c_2556))) return;
        if (!var0->GetTaskStatus(*(int*)(arg0 + Enum_020e081c_2568))) return;
        func_02021428(arg0, 0x19);
        if (IsBrightnessWithinValidRange((GameResources*)var1, true)) return;
        void* var7 = 0;
        unsigned int var8 = 0;
        var0->GetLoadedFileByID(*(int*)(arg0 + Enum_020e081c_2568), &var7, &var8);
        func_0205a498(arg0 + 0x94, (Struct_02020aec*)var7, var8, var4);
        *(int*)((char*)func_0203bd14() + Enum_020e081c_1288) = 0x2800;
        void* var9 = (char*)func_0203be4c(func_0203bd08()) + Enum_020e081c_600;
        *(void**)func_0203bd14() = var9;
        if (!*(SafeAllocator**)(arg0 + Enum_020e081c_1900)) func_020c9be0();
        if (*(SafeAllocator**)(arg0 + Enum_020e081c_1900) && *(void**)(arg0 + Enum_020e081c_1904))
            (*(SafeAllocator**)(arg0 + Enum_020e081c_1900))->Free(*(void**)(arg0 + Enum_020e081c_1904));
        *(unsigned int*)(arg0 + Enum_020e081c_1908) = Enum_020e081c_13312;
        *(void**)(arg0 + Enum_020e081c_1904) = (*(SafeAllocator**)(arg0 + Enum_020e081c_1900))->Allocate(*(unsigned int*)(arg0 + Enum_020e081c_1908));
        VectorizedInvertedMemcpy((const void*)0x06600000, *(void**)(arg0 + Enum_020e081c_1904), *(unsigned int*)(arg0 + Enum_020e081c_1908));
        func_020c9820();
#if defined(jpn)
        func_02020cb8(arg0, *(int*)(arg0 + Enum_020e081c_2556));
#else
        func_02020cb8(arg0, (int*)(arg0 + Enum_020e081c_2556));
#endif
        func_02022b90(arg0, (int*)(arg0 + Enum_020e081c_2568));
        func_02021410((Struct_02021410*)arg0, 1, 3);
        *(unsigned char*)(arg0 + Enum_020e081c_2499) = 0;
        ++*(signed char*)(arg0 + Enum_020e081c_2498);
    }
}
