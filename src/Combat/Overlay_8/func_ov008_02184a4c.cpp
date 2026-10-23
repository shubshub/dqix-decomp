#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
#define REGION_VALUE(j,u) j
#define data_ov008_0218b3e4 data_ov008_0218c064
#define data_ov008_0218b400 data_ov008_0218c080
#define data_ov008_0218b41d data_ov008_0218c09d
#define data_ov008_0218b328 data_ov008_0218bf60
#define data_ov008_0218b334 data_ov008_0218bf6c
#define data_ov008_0218b31c data_ov008_0218bf78
#define data_ov008_0218b3e0 data_ov008_0218c060
#define data_ov008_0218b48f data_ov008_0218c0f0
#define func_ov008_02188d74 func_ov008_02189a9c
#define func_ov008_0218712c func_ov008_02188008
#define func_ov008_02187f6c func_ov008_02188ccc
#else
#define REGION_VALUE(j,u) u
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" int sprintf(char* arg0, const char* arg1, ...);
extern "C" void* __clear(void* arg0, int arg1);

extern const char data_ov008_0218b3e4[];
extern const char data_ov008_0218b400[];
extern const char data_ov008_0218b41d[];
extern const char data_ov008_0218b43c[];
extern const char data_ov008_0218b455[];
extern const char data_ov008_0218b3e0[];
extern const char data_ov008_0218b465[];
extern const char data_ov008_0218b47c[];
extern const char data_ov008_0218b48f[];
extern char data_0211e33c[];
extern int data_02109bf4;

struct Struct_ov008_0218b31c { int unknown_0_; int unknown_4_; int unknown_8_; };
extern const Struct_ov008_0218b31c data_ov008_0218b328;
extern const Struct_ov008_0218b31c data_ov008_0218b334;
extern const Struct_ov008_0218b31c data_ov008_0218b31c;

extern "C" int func_020d2ff0(const char* arg0);

struct Struct_ov008_02184a4c {
    void* unknown_0_;
    short unknown_4_;
    short unknown_6_;
};

struct Struct_ov008_02184a4c_2 {
    char unknown_0_[REGION_VALUE(0x27c, 0x2cc)];
    char unknown_2cc_[0x87c - REGION_VALUE(0x27c, 0x2cc)];
};

struct Struct_ov008_02184a4c_3 {
    char unknown_0_[0x10];
    unsigned int unknown_10_0_ : 23;
    unsigned int unknown_12_7_ : 9;
    char unknown_14_[0xc];
    unsigned int inline_ov008_02184a4c() { return unknown_12_7_; }
};
struct Struct_ov008_02184a4c_4 {
    char unknown_0_[0x90];
    Struct_ov008_02184a4c_3 unknown_90_;
    Struct_ov008_02184a4c_3* inline_ov008_02184a4c_2() { return &unknown_90_; }
};

static inline char* inline_ov008_02184a4c_3(GameState* arg0) { return (char*)arg0 + REGION_VALUE(0x2c4, 0x104); }
static inline char* inline_ov008_02184a4c_4(char* arg0) { return arg0 + REGION_VALUE(0x7000, 0x7400); }
static inline Struct_ov008_02184a4c_4* inline_ov008_02184a4c_5(GameState* arg0) {
    return (Struct_ov008_02184a4c_4*)(inline_ov008_02184a4c_4(inline_ov008_02184a4c_3(arg0)) + 0x3c);
}

struct Struct_ov008_02184a4c_5 {
    char unknown_0_[0x68];
    short unknown_68_;
    short unknown_6a_[1];
};

struct Struct_ov008_02184a4c_6 {
    unsigned int unknown_0_;
    const char* unknown_4_;
    int unknown_8_;
};
struct Struct_ov008_02184a4c_7 {
    unsigned int unknown_0_0_ : 9;
    unsigned int unknown_1_1_ : 9;
    unsigned int unknown_2_2_ : 9;
    unsigned int unknown_3_3_ : 3;
    unsigned int unknown_3_6_ : 2;
    char* unknown_4_;
    int unknown_8_;
    char unknown_c_[0x38];
    char unknown_44_[REGION_VALUE(0x118, 0x200)];

};

struct Struct_ov008_02184a4c_8 { char unknown_0_[0x28]; };

struct Struct_ov008_02184a4c_9 {
    char unknown_0_[0x3c];
    void* unknown_3c_;
    struct Struct_ov008_02184a4c_8* unknown_40_;
    char unknown_44_[0x4c - 0x44];
    short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
    void inline_ov008_02184a4c_6(struct Struct_ov008_02184a4c_8* arg0, int arg1) {
        unknown_40_ = arg0;
        unknown_4c_ = arg1;
    }
};

struct Struct_ov008_02184a4c_10 {
    char unknown_0_[0xc2];
    short unknown_c2_;
};

struct Struct_01ff91ac_35 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
    unsigned char unknown_49c_1_ : 7;
};
struct Struct_ov008_02184a4c_11 {
    char unknown_0_[REGION_VALUE(0x144, 0x150)];
    Struct_01ff91ac_35* unknown_150_;
    int inline_ov008_02184a4c_7() { return unknown_150_->unknown_49c_0_; }
};

struct Struct_01ff91ac_36 {
    char unknown_0_[0x44];
    Struct_ov008_0218b31c unknown_44_;
    void inline_ov008_02184a4c_8(const Struct_ov008_0218b31c* arg0) { *(Vector3i*)&unknown_44_ = *(Vector3i const*)arg0; }
};

struct Struct_ov008_02184a4c_12 {
    SafeAllocator unknown_0_;
#if defined(jpn)
    SafeAllocator unknown_14_;
#else
    char unknown1_14_[0x28 - 0x14];
#endif
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    char unknown_50_[0x64 - 0x50];
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    char unknown_8c_[0xa0 - 0x8c];
    char unknown_a0_[0xb8 - 0xa0];
    char* unknown_b8_;
    char unknown_bc_[0xd0 - 0xbc];
    char unknown_d0_[0xec - 0xd0];
    unsigned char unknown_ec_0_ : 4;
    unsigned char unknown_ec_4_ : 4;
    char unknown_ed_[0x130 - 0xed];
    char unknown_130_[0x730 - 0x130];
    Struct_ov008_02184a4c_9* unknown_730_;
    Struct_ov008_02184a4c_8* unknown_734_;
    void* unknown_738_;
    char unknown_73c_[0x790 - 0x73c];
    Struct_01ff91ac_36 unknown_790_;
    Struct_ov008_0218b31c unknown_7e0_;
    char unknown_7ec_[0x83c - 0x7ec];
    char unknown_83c_[0xb04 - 0x83c];
    Struct_ov008_02184a4c_5* unknown_b04_;
    int unknown_b08_;
    Struct_ov008_02184a4c_7* unknown_b0c_;
    unsigned char unknown_b10_;
    unsigned char unknown_b11_;
    char unknown_b12_[2];
    short unknown_b14_;
    short unknown_b16_;
    unsigned int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;

    Struct_01ff91ac_36* inline_ov008_02184a4c_9() { return &unknown_790_; }
    Struct_ov008_02184a4c_8* inline_ov008_02184a4c_10() { return unknown_734_; }
    Struct_ov008_02184a4c_9* inline_ov008_02184a4c_11() { return unknown_730_; }
    int inline_ov008_02184a4c_12(unsigned int arg0) volatile { return (unknown_b18_ & arg0) != 0; }
};

extern "C" void* func_0202ae18(void);
extern "C" char* func_0205ec34(void);
extern "C" int _Z27TestBitInByteArray_0206dfb0iPhi(char* unused, char* arr, int index);
int LoadBattleBlock020ac4c0(void* dst);
extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);
struct List020727d8;
void ResetListHeader020727d8(List020727d8*);
void SubmitScriptFromFile020727f8(void* list, const char* path, int id, void* out, unsigned char mode);
void Reset0209fe9c(char*);
struct Obj0209fee4;
void InitManagerAndAllocateBuffers0209fee4(Obj0209fee4*, SafeAllocator*, int, int);
struct IntField0x60_0209ff64;
void SetIntAt0x60(IntField0x60_0209ff64*, int);
struct TaskState0209ff6c;
void PollOv017Task0209ff6c(TaskState0209ff6c*);
extern "C" int func_ov008_02185964(void* obj);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* outSize);
extern "C" void KeyTable_Load(void* container, SafeAllocator* alloc, void* data, unsigned int size);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void* obj, int a);
struct Obj0204b5e8;
void Background_SetScroll(Obj0204b5e8*, int, int);
struct AllocTarget0204b12c;
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
struct Container020e0310;
const char* KeyTable_Get(Container020e0310*, int);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900*);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
extern "C" void Background_LoadFile(void* obj, void* rec, SafeAllocator* alloc, int size);
struct Obj0204b8d0;
void Background_DrawScreen(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8*, void*);
extern "C" int func_ov008_02188a54(Obj02184a4c* obj, int a);
void SpriteContext_Init(char*);
struct Struct0205a198;
void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(ClearTarget0205a234*);
extern "C" int SpriteContext_LoadFile(void* obj, void* data, int size, SafeAllocator* alloc);
extern "C" int func_ov008_02188d74(Obj02184a4c* obj);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
int LoadFileIntoMemory(const char* path, void* dst, unsigned int* outSize);
struct ObjectArchiveLoadInfo;
struct Vector3i;
void InitCombatController020a2010(void* obj);
struct Vec3Target0202e5c0;
void Camera_SetPosition(Vec3Target0202e5c0*, int, int, int);
void Camera_SetTarget(unsigned char*, int, int, int);
void SetField0x238False_020a27a0(void* obj);
void SetField0x3b0Value_020100c4(GameState*, int);
struct S020a13c4;
void ClearStruct020a13c4(S020a13c4*);
void SetupGlobalAndRunScript020a13e4(void* a, void* b, int c, unsigned short d, unsigned char e);
extern "C" int func_ov023_021ed724(void* obj, short* ids, int count);
struct Array020a15bc;
MessageSrc02184a4c* FindElementByField020a15bc(Array020a15bc*, int);
extern "C" void func_020e046c(char* buf, void* b, unsigned int c, int idx);
int GetField5cbcValue_0201081c(char*);
int CompareStrings_020d3018(const char* a, const char* b);
int CheckField0NonZero_0202b7d8(int*);
extern "C" void func_ov008_0218712c(Obj02184a4c* obj, int a);
struct Manager02187664;
void InitConfig02187664(Manager02187664*, int);
extern "C" void func_ov008_02187a70(Obj02184a4c* obj, int a);
extern "C" void func_ov008_02187f6c(Obj02184a4c* obj, int a);
struct Struct_0205d81c;
extern "C" Struct_ov008_02184a4c_10* func_0205d81c(Struct_0205d81c*, int);
extern "C" char* func_020421a0(void);
extern "C" void func_020432c4(char* arg0);
struct Struct_0209c3b4_2;
extern "C" void func_0209c3b4(Struct_0209c3b4_2*, int);
extern "C" void func_ov008_02186964(Struct_ov008_02184a4c_12* arg0);

struct Struct_ov008_02184a4c_14 {
    int unknown_0_;
    const void* unknown_4_;
    int unknown_8_;
    SafeAllocator* unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
};

#if defined(jpn)
extern const char data_ov008_0218c0bc[];
extern const char data_ov008_0218c0d5[];
extern "C" void func_020e2168(char*, const char*, int, int, int);
#endif

// USA: func_ov008_02184a4c
extern "C" ARM void func_ov008_02184a4c(Struct_ov008_02184a4c_12* arg0) {
#if defined(jpn)
    Struct_ov008_02184a4c_2* var1;
    GameState* var0 = GameState::GetInstance();
    var1 = (Struct_ov008_02184a4c_2*)GetGameResources();
#else
    GameState* var0 = GameState::GetInstance();
    Struct_ov008_02184a4c_2* var1 = (Struct_ov008_02184a4c_2*)GetGameResources();
#endif
    BackgroundLoader* var2 = BackgroundLoader::GetInstance();
    void* var3 = func_0202ae18();

    unsigned char var4 = arg0->unknown_b11_;
    if (var4 == 0) {
        arg0->unknown_b18_ |= 0x200000;
        char* var5 = func_0205ec34();
        int var6 = func_0206dfb0(var5, var5 + 0x8c, 0x113b);
        if (var6 != 0) {
            arg0->unknown_b18_ |= 0x80;
            arg0->unknown_b18_ &= ~1;
        }
        Struct_ov008_02184a4c_4 var7;
        func_020ac4c0(&var7);
        Struct_ov008_02184a4c_4* var8 = &var7;
        unsigned int var9 = var8->inline_ov008_02184a4c_2()->inline_ov008_02184a4c();
        if (var9 == 0) {
            if (func_0206dfb0(var5, var5 + 0x8c, 0x796) != 0) {
                if (func_0202c508(var3) != 0) {
                    arg0->unknown_b18_ |= 2;
                }
            }
        } else if (var9 != 0) {
            arg0->unknown_b18_ |= 4;
        }
        if (!arg0->inline_ov008_02184a4c_12(1)) {
            if (var6 == 0) {
                arg0->unknown_b18_ |= 0x20000;
            }
            arg0->unknown_b11_ = 2;
            if (arg0->unknown_b24_ == 1) {
                arg0->unknown_b11_ = 3;
            }
        } else {
            if (arg0->inline_ov008_02184a4c_12(2)) {
                arg0->unknown_b20_ = var2->QueueLoadFile(data_ov008_0218b3e4, NULL);
            } else {
                char var10[0x80];
                __clear(var10, 0x80);
                Struct_ov008_02184a4c var11;
                func_020727d8((Struct_020727d8*)&var11);
                func_020727f8(&var11, data_ov008_0218b400, 1000, var10, REGION_VALUE(1, 2));
                arg0->unknown_b20_ = var2->QueueLoadFile(var10, NULL);
                arg0->unknown_b18_ |= 0x400;
            }
            arg0->unknown_b11_++;
        }
    } else if (var4 == 1) {
        if (var2->GetTaskStatus(arg0->unknown_b20_) != 0) {
            void* var12;
            unsigned int var13;
            var2->GetLoadedFileByID(arg0->unknown_b20_, &var12, &var13);
            arg0->unknown_78_.Reset();
            arg0->unknown_b04_ = (Struct_ov008_02184a4c_5*)arg0->unknown_78_.Allocate(0xd0);
            func_0209fe9c((char*)arg0->unknown_b04_);
            func_0209fee4((Struct_0209fee4*)arg0->unknown_b04_, &arg0->unknown_78_, (int)var12, var13);
            func_0209ff64((Struct_0209ff64*)arg0->unknown_b04_, 100);
            do {
                func_0209ff6c((Struct_0209ff6c*)arg0->unknown_b04_);
            } while (func_ov008_02185964(arg0->unknown_b04_) == 0);
            var2->RemoveTask(arg0->unknown_b20_);
            arg0->unknown_b20_ = -1;
            arg0->unknown_b11_++;
        }
    } else if (var4 == 2) {
        if (arg0->inline_ov008_02184a4c_12(0x400)) {
            if (arg0->unknown_b04_->unknown_68_ > 0) {
                arg0->unknown_b14_ = arg0->unknown_b04_->unknown_6a_[0];
                arg0->unknown_b16_ = 1000;
                arg0->unknown_78_.Reset();
                arg0->unknown_b04_ = NULL;
                arg0->unknown_b18_ &= ~1;
                arg0->unknown_b18_ &= ~0x400;
            } else {
                arg0->unknown_78_.Reset();
                arg0->unknown_b04_ = NULL;
                arg0->unknown_b18_ &= ~0x400;
                arg0->unknown_b20_ = var2->QueueLoadFile(data_ov008_0218b41d, NULL);
                arg0->unknown_b11_ = 1;
                return;
            }
        }
        Struct_0208cb08* var14 = func_02094a00();
        func_02094b40(var14);
        func_02094b34(var14, 0x6b, 0x1fc, 0, 0);
        arg0->unknown_b11_++;
    } else if (var4 == 3) {
        if (func_02094b4c(func_02094a00()) != 0) {
#if defined(jpn)
            obj->alloc14.Reset();
            void* data = obj->alloc14.Allocate(0x2000);
            unsigned int size;
            LoadFileIntoMemory(data_ov008_0218c0bc, data, &size);
            obj->alloc28.Reset();
            KeyTable_Load(obj->container, &obj->alloc28, data, size);
            obj->alloc14.Reset();
#else
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            unsigned int size;
            void* data = ExtractFileFromGP2(data_ov008_0218b43c, data_ov008_0218b455, &size);
            obj->alloc28.Reset();
            KeyTable_Load(obj->container, &obj->alloc28, data, size);
            BackgroundLoader::RemoveLockGlobal();
#endif
            if (arg0->unknown_b24_ != 0) {
                arg0->unknown_b11_ = 5;
            } else {
                Background_SetMapSize((unsigned char*)obj->list, 0);
                obj->ecLo = 0;
                obj->ecHi = 1;
                Background_SetPriority(obj->list, 3);
                Background_SetScroll((Obj0204b5e8*)obj->list, 0, 0);
                Background_AllocateMap((AllocTarget0204b12c*)obj->list, &obj->alloc00);
                Background_AllocateScreens((Foo0204af38*)obj->list, 1, &obj->alloc00);
                obj->taskId = loader->QueueLoadFile(KeyTable_Get((Container020e0310*)obj->container, 0), NULL);
                obj->b11++;
            }
        }
    } else if (state == 4) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* rec;
            void* data;
            unsigned int size;
            int recSize;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            int count = Pac_CountFiles((ActiveEntry02046900*)data);
            for (int i = 0; i < count; i++) {
                void* found = Pac_GetFile((Rec020467f0*)data, i, &rec, &recSize);
                if (found != NULL) {
                    Background_LoadFile(obj->list, found, &obj->alloc00, recSize);
                }
            }
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            Background_DrawScreen((Obj0204b8d0*)obj->list, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            Background_UploadMap((List0204b0e8*)obj->list, NULL);
            obj->b11++;
        }
    } else if (state == 5) {
        if (func_ov008_02188a54(obj, 0) != 0) {
            if (obj->b24 == 0) {
                SpriteContext_Init((char*)obj->table);
                obj->table->f50 = 0;
                Entry0205a198* entries = obj->GetEntries();
                obj->GetTable()->SetEntries(entries, 0x12);
                obj->table->tail = obj->tail;
                for (int i = 0; i < 0x12; i++) {
                    Sprite_Init((Struct0205a198*)&obj->entries[i]);
                }
                func_0205a234((Struct_02043368*)arg0->unknown_738_);
#if defined(jpn)
                obj->taskId = loader->QueueLoadFile(KeyTable_Get((Container020e0310*)obj->container, 3), NULL);
#else
                const char* inner = KeyTable_Get((Container020e0310*)obj->container, 6);
                obj->taskId = loader->QueueLoadFileInGP2(KeyTable_Get((Container020e0310*)obj->container, 5), inner, NULL);
#endif
                arg0->unknown_b11_++;
            } else {
                arg0->unknown_b11_ = 0xff;
            }
        }
    } else if (state == 6) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* rec;
            void* data;
            unsigned int size;
            int recSize;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            int count = Pac_CountFiles((ActiveEntry02046900*)data);
            obj->alloc3c.Reset();
            for (int i = 0; i < count; i++) {
                void* found = Pac_GetFile((Rec020467f0*)data, i, &rec, &recSize);
                if (found != NULL) {
                    SpriteContext_LoadFile(obj->table, found, recSize, &obj->alloc3c);
                }
            }
            arg0->unknown_b18_ |= 0x80000;
            var2->RemoveTask(arg0->unknown_b20_);
            arg0->unknown_b20_ = -1;
            arg0->unknown_b11_++;
        }
    } else if (var4 == 7) {
        if (func_ov008_02188d74(arg0) != 0) {
            if (arg0->inline_ov008_02184a4c_12(0x80)) {
                arg0->unknown_b11_ = 9;
            } else {
                arg0->unknown_b11_++;
            }
        }
    } else if (state == 8) {
        char* stage = ov17->stage;
        CopyInternalFields0207df50((Foo0207df50*)(stage + 0x230));
        VramState_Restore(stage + 0x230);
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        if (LoadFileIntoMemory(KeyTable_Get((Container020e0310*)obj->container, 10), data_0211e33c, &size) != 0) {
            ArchiveInfo02184a4c info;
            info.unk_0 = 0;
            info.unk_14 = 0;
            info.unk_18 = 0;
            info.packageID = 0;
            info.allocator = &obj->alloc64;
            info.fileData = data_0211e33c;
            info.size = size;
            info.unk_10 = 1;
            ((Object3D*)&obj->model)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&info, (int (*)(BCFG::AnimationRecord*))NULL);
            Vec3i02184a4c scale = data_ov008_0218b328;
            ((Object3D*)&obj->model)->SetScale((Vector3i const*)&scale);
            Vec3i02184a4c pos = data_ov008_0218b334;
            obj->GetModel()->SetPosition(&pos);
            Vec3i02184a4c rot = data_ov008_0218b31c;
            *(Vector3i*)&obj->modelRot = *(Vector3i const*)&rot;
            ((Object3D*)&obj->model)->MaybeSetBCFGAnimation(0, 0);
        }
        BackgroundLoader::RemoveLockGlobal();
        VramState_Save(stage + 0x230);
        InitCombatController020a2010(obj->controller);
        Camera_SetPosition((Vec3Target0202e5c0*)obj->controller, 0, 0x8000, 0x40000);
        Camera_SetTarget((unsigned char*)obj->controller, 0, 0, 0);
        SetField0x238False_020a27a0(obj->controller);
        SetField0x3b0Value_020100c4(gs, (int)obj->controller);
        obj->b11++;
    } else if (state == 9) {
        if (!obj->HasFlag(1)) {
            obj->b11 = 0xff;
        } else if (func_ov008_02185964(obj->poller) != 0) {
            if (obj->poller->count > 0) {
                ClearStruct020a13c4((S020a13c4*)obj->script);
                SetupGlobalAndRunScript020a13e4(obj->script, obj->scriptArg8c, 0, 0, 1);
                short ids[50];
                int count = obj->poller->count;
                for (int i = 0; i < count; i++) {
                    ids[i] = obj->poller->ids[i];
                }
                if (func_ov023_021ed724(arg0->unknown_bc_, var42, var43) & 1) {
                    arg0->unknown_b18_ |= 0x8000;
                }
                if (arg0->inline_ov008_02184a4c_12(2)) {
                    inline_ov008_02184a4c_5(var0)->inline_ov008_02184a4c_2()->unknown_12_7_ = var42[0];
                    arg0->unknown_b18_ |= 4;
                    arg0->unknown_b16_ = 0x3e9;
                } else {
                    arg0->unknown_b16_ = 1000;
                }
                arg0->unknown_b14_ = var42[0];
                arg0->unknown_78_.Reset();
                arg0->unknown_b04_ = NULL;
                arg0->unknown_b0c_ = (Struct_ov008_02184a4c_7*)arg0->unknown_78_.Allocate(REGION_VALUE(0x15c, 0x244));
                Struct_ov008_02184a4c_7* var45 = arg0->unknown_b0c_;
                var45->unknown_0_0_ = 0;
                var45->unknown_1_1_ = 0;
                var45->unknown_2_2_ = 0;
                var45->unknown_3_3_ = 0;
                var45->unknown_3_6_ = 0;
                var45->unknown_4_ = NULL;
                var45->unknown_8_ = 0;
                memset(var45->unknown_c_, 0, 0x38);
                memset(var45->unknown_44_, 0, REGION_VALUE(0x118, 0x200));
                var45->unknown_4_ = var45->unknown_44_;
                Struct_ov008_02184a4c_6* var46 = func_020a15bc((Struct_020a15bc*)arg0->unknown_bc_, var42[0]);
                var45 = arg0->unknown_b0c_;
                if (var46 != NULL) {
                    *(unsigned int*)var45 = var46->unknown_0_;
                    var45->unknown_4_ = (char*)var46->unknown_4_;
                    var45->unknown_8_ = var46->unknown_8_;
                    var45->unknown_4_ = var45->unknown_44_;
                    const char* var47 = var46->unknown_4_;
                    if (var47 != NULL) {
                        memset(var45->unknown_44_, 0, REGION_VALUE(0x118, 0x200));
                        sprintf(var45->unknown_44_ + func_020d2ff0(var45->unknown_44_), data_ov008_0218b3e0, var47);
                    }
                }
                Struct_ov008_02184a4c_11* var48 = (Struct_ov008_02184a4c_11*)GameState::GetInstance()->GetProtagonist();
#if defined(jpn)
                int var49 = var48->inline_ov008_02184a4c_7();
                func_020e2168(arg0->unknown_b0c_->unknown_c_, data_ov008_0218c0d5, var42[0], var49, 1);
#else
                BackgroundLoader::AddLockGlobal();
                unsigned int var50 = 0;
                char var51[0x40];
                __clear(var51, 0x40);
                char var52[0x20];
                __clear(var52, 0x20);
                int var53 = var48->inline_ov008_02184a4c_7();
                sprintf(var51, data_ov008_0218b465, var53);
                sprintf(var52, data_ov008_0218b47c, var48->inline_ov008_02184a4c_7());
                void* var54 = ExtractFileFromGP2(var51, var52, &var50);
                if (var54 != NULL) {
                    func_020e046c(arg0->unknown_b0c_->unknown_c_, var54, var50, var42[0]);
                }
                BackgroundLoader::RemoveLockGlobal();
#endif
            } else {
                arg0->unknown_78_.Reset();
                arg0->unknown_b04_ = NULL;
            }
            if (arg0->unknown_b14_ <= 0) {
                int var55 = func_0201081c((char*)var0);
                if (func_0202c540(var3) != 0) {
                    arg0->unknown_b18_ |= 0x100;
                    var55 = 0x3eb;
                }
                memset(arg0->unknown_b8_, 0, REGION_VALUE(0x800, 0x960));
                Struct_ov008_02184a4c var56;
                func_020727d8((Struct_020727d8*)&var56);
                func_020727f8(&var56, data_ov008_0218b400, (short)var55, arg0->unknown_b8_, REGION_VALUE(1, 2));
                if (func_020d3018(arg0->unknown_b8_, data_ov008_0218b48f) == 0) {
                    arg0->unknown_b11_ = 0xff;
                } else {
                    arg0->unknown_b20_ = var2->QueueLoadFile(arg0->unknown_b8_, NULL);
                    arg0->unknown_b11_++;
                }
            } else {
                arg0->unknown_b11_ = 0xff;
            }
        }
    } else if (var4 == 10) {
        if (var2->GetTaskStatus(arg0->unknown_b20_) != 0) {
            void* var57;
            unsigned int var58;
            var2->GetLoadedFileByID(arg0->unknown_b20_, &var57, &var58);
            arg0->unknown_78_.Reset();
            arg0->unknown_b04_ = (Struct_ov008_02184a4c_5*)arg0->unknown_78_.Allocate(0xd0);
            func_0209fe9c((char*)arg0->unknown_b04_);
            func_0209fee4((Struct_0209fee4*)arg0->unknown_b04_, &arg0->unknown_78_, (int)var57, var58);
            func_0209ff64((Struct_0209ff64*)arg0->unknown_b04_, 100);
            do {
                func_0209ff6c((Struct_0209ff6c*)arg0->unknown_b04_);
            } while (func_ov008_02185964(arg0->unknown_b04_) == 0);
            var2->RemoveTask(arg0->unknown_b20_);
            arg0->unknown_b20_ = -1;
            arg0->unknown_b11_++;
        }
    } else if (var4 == 11) {
        if (arg0->unknown_b04_->unknown_68_ > 0) {
            arg0->unknown_b14_ = arg0->unknown_b04_->unknown_6a_[0];
            arg0->unknown_b16_ = func_0201081c((char*)var0);
            if (arg0->inline_ov008_02184a4c_12(0x100)) {
                arg0->unknown_b18_ &= ~0x100;
                arg0->unknown_b16_ = 0x3ea;
                if (func_0202c540(var3) != 0) {
                    arg0->unknown_b16_ = 0x3eb;
                }
            }
            arg0->unknown_78_.Reset();
            arg0->unknown_b04_ = NULL;
            arg0->unknown_b11_ = 0xff;
        } else if (arg0->inline_ov008_02184a4c_12(0x100)) {
            arg0->unknown_b18_ &= ~0x100;
            arg0->unknown_b11_ = 0xff;
        } else {
            void* var59 = func_0202ae18();
            int var60 = 0x3ea;
            if (func_0202b7d8((int*)var59) != 0) {
                if (func_0202c540(var59) != 0) {
                    var60++;
                }
            }
            memset(arg0->unknown_b8_, 0, REGION_VALUE(0x800, 0x960));
            Struct_ov008_02184a4c var61;
            func_020727d8((Struct_020727d8*)&var61);
            func_020727f8(&var61, data_ov008_0218b400, var60, arg0->unknown_b8_, REGION_VALUE(1, 2));
            arg0->unknown_b20_ = var2->QueueLoadFile(arg0->unknown_b8_, NULL);
            arg0->unknown_b11_ = 10;
            arg0->unknown_b18_ |= 0x100;
        }
    } else if (var4 == 0xff) {
        func_ov008_0218712c(arg0, 0);
        func_ov008_02187664((Struct_ov008_02184a4c_13*)arg0, 0);
        func_ov008_02187a70(arg0, 0);
        func_ov008_02187f6c(arg0, 0);
        for (int var62 = 0; var62 < 6; var62++) {
            Struct_ov008_02184a4c_10* var63 = func_0205d81c((Struct_0205d81c*)arg0->unknown_130_, (unsigned char)var62);
            if (var63 != NULL) {
                if (!(var62 != 4 && var62 != 5)) {
                    var63->unknown_c2_ = 1;
                } else {
                    var63->unknown_c2_ = 0;
                }
            }
        }
        if (obj->b24 == 0) {
            char* stage = ov17->stage;
            char* presenter = GetGlobalField0x1c020421a0();
            CopyInternalFields0207df50((Foo0207df50*)(stage + 0x5b0));
            VramState_Restore(stage + 0x5b0);
            func_020432c4(presenter);
            VramState_Save(stage + 0x5b0);
            SetStateAndDispatch0209c3b4((Actor0209c3b4*)&data_02109bf4, 0x29);
            obj->b10 = 3;
            obj->b11 = 0;
            if (obj->message == NULL) {
                obj->flags &= ~0x200000;
                func_ov008_02186964(obj);
            }
        } else {
            arg0->unknown_b18_ &= ~0x200000;
            arg0->unknown_b10_ = 4;
            arg0->unknown_b11_ = 0;
        }
    }
}
