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


extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" void* __clear(void* dst, int count);

extern const char data_ov008_0218b3e4[];
extern const char data_ov008_0218b400[];
extern const char data_ov008_0218b41d[];
extern const char data_ov008_0218b43c[];
extern const char data_ov008_0218b455[];
extern const char data_ov008_0218b3e0[];
extern const char data_ov008_0218b465[];
extern const char data_ov008_0218b47c[];
extern const char data_ov008_0218b48f[];
extern char g_fileLoadBuffer[];
extern int g_bgmPlayer;

struct Struct_ov008_0218b31c { int x; int y; int z; };
extern const Struct_ov008_0218b31c data_ov008_0218b328;
extern const Struct_ov008_0218b31c data_ov008_0218b334;
extern const Struct_ov008_0218b31c data_ov008_0218b31c;

extern "C" int STD_GetStringLength(const char* s);

struct Struct_ov008_02184a4c {
    void* entries;
    short capacity;
    short count;
};

struct Struct_ov008_02184a4c_2 {
    char pad0[REGION_VALUE(0x27c, 0x2cc)];
    char stage[0x87c - REGION_VALUE(0x27c, 0x2cc)];
};

struct Struct_ov008_02184a4c_3 {
    char pad0[0x10];
    unsigned int lo : 23;
    unsigned int scriptId : 9;
    char unknown_14_[0xc];
    unsigned int inline_ov008_02184a4c() { return scriptId; }
};
struct Struct_ov008_02184a4c_4 {
    char pad0[0x90];
    Struct_ov008_02184a4c_3 tail;
    Struct_ov008_02184a4c_3* inline_ov008_02184a4c_2() { return &tail; }
};

static inline char* inline_ov008_02184a4c_3(GameState* gs) { return (char*)gs + REGION_VALUE(0x2c4, 0x104); }
static inline char* inline_ov008_02184a4c_4(char* arg0) { return arg0 + REGION_VALUE(0x7000, 0x7400); }
static inline Struct_ov008_02184a4c_4* inline_ov008_02184a4c_5(GameState* gs) {
    return (Struct_ov008_02184a4c_4*)(inline_ov008_02184a4c_4(inline_ov008_02184a4c_3(gs)) + 0x3c);
}

struct Struct_ov008_02184a4c_5 {
    char pad0[0x68];
    short count;
    short ids[1];
};

struct Struct_ov008_02184a4c_6 {
    unsigned int word0;
    const char* text;
    int f8;
};
struct Struct_ov008_02184a4c_7 {
    unsigned int a : 9;
    unsigned int b : 9;
    unsigned int c : 9;
    unsigned int d : 3;
    unsigned int e : 2;
    char* text;
    int f8;
    char name[0x38];
    char buf[REGION_VALUE(0x118, 0x200)];

};

struct Struct_ov008_02184a4c_8 { char pad0[0x28]; };

struct Struct_ov008_02184a4c_9 {
    char pad0[0x3c];
    void* tail;
    struct Struct_ov008_02184a4c_8* entries;
    char unknown_44_[0x4c - 0x44];
    short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
    void inline_ov008_02184a4c_6(struct Struct_ov008_02184a4c_8* list, int count) {
        entries = list;
        unknown_4c_ = count;
    }
};

struct Struct_ov008_02184a4c_10 {
    char pad0[0xc2];
    short unknown_c2_;
};

struct Struct_01ff91ac_35 {
    char pad0[0x49c];
    unsigned char bit0 : 1;
    unsigned char hi : 7;
};
struct Struct_ov008_02184a4c_11 {
    char pad0[REGION_VALUE(0x144, 0x150)];
    Struct_01ff91ac_35* unknown_150_;
    int inline_ov008_02184a4c_7() { return unknown_150_->bit0; }
};

struct Struct_01ff91ac_36 {
    char pad0[0x44];
    Struct_ov008_0218b31c pos;
    void inline_ov008_02184a4c_8(const Struct_ov008_0218b31c* v) { *(Vector3i*)&pos = *(Vector3i const*)v; }
};

struct Struct_ov008_02184a4c_12 {
    SafeAllocator alloc00;
#if defined(jpn)
    SafeAllocator unknown_14_;
#else
    char unknown1_14_[0x28 - 0x14];
#endif
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    char unknown_50_[0x64 - 0x50];
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    char unknown_8c_[0xa0 - 0x8c];
    char container[0xb8 - 0xa0];
    char* pathBuf;
    char script[0xd0 - 0xbc];
    char list[0xec - 0xd0];
    unsigned char unknown_ec_0_ : 4;
    unsigned char unknown_ec_4_ : 4;
    char unknown_ed_[0x130 - 0xed];
    char elems[0x730 - 0x130];
    Struct_ov008_02184a4c_9* table;
    Struct_ov008_02184a4c_8* entries;
    void* tail;
    char unknown_73c_[0x790 - 0x73c];
    Struct_01ff91ac_36 model;
    Struct_ov008_0218b31c unknown_7e0_;
    char unknown_7ec_[0x83c - 0x7ec];
    char controller[0xb04 - 0x83c];
    Struct_ov008_02184a4c_5* unknown_b04_;
    int unknown_b08_;
    Struct_ov008_02184a4c_7* message;
    unsigned char b10;
    unsigned char unknown_b11_;
    char unknown_b12_[2];
    short b14;
    short unknown_b16_;
    unsigned int flags;
    int unknown_b1c_;
    int taskId;
    int unknown_b24_;

    Struct_01ff91ac_36* inline_ov008_02184a4c_9() { return &model; }
    Struct_ov008_02184a4c_8* GetEntries() { return entries; }
    Struct_ov008_02184a4c_9* inline_ov008_02184a4c_11() { return table; }
    int inline_ov008_02184a4c_12(unsigned int mask) volatile { return (flags & mask) != 0; }
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" char* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(char* unused, char* arr, int index);
extern "C" int func_020ac4c0(void* dst);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int LinkSession_IsGuest(void* obj);
struct Struct_020727d8;
extern "C" void func_020727d8(Struct_020727d8*);
extern "C" void func_020727f8(void* list, const char* path, int id, void* out, unsigned char mode);
extern "C" void func_0209fe9c(char*);
struct Struct_0209fee4;
extern "C" void func_0209fee4(Struct_0209fee4*, SafeAllocator*, int, int);
struct Struct_0209ff64;
extern "C" void func_0209ff64(Struct_0209ff64*, int);
struct Struct_0209ff6c;
extern "C" void func_0209ff6c(Struct_0209ff6c*);
extern "C" int func_ov008_02185964(void* obj);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* outSize);
extern "C" void KeyTable_Load(void* container, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void* obj, int a);
struct BackgroundGraphics;
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
struct Container020e0310;
extern "C" const char* KeyTable_Get(Container020e0310*, int);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_LoadFile(void* obj, void* rec, SafeAllocator* alloc, int size);
extern "C" void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" int func_ov008_02188a54(Struct_ov008_02184a4c_12* obj, int a);
extern "C" void SpriteContext_Init(char*);
struct Struct0205a198;
extern "C" void Sprite_Init(Struct0205a198*);
struct ClearTarget0205a234;
extern "C" void func_0205a234(ClearTarget0205a234*);
extern "C" int SpriteContext_LoadFile(void* obj, void* data, int size, SafeAllocator* alloc);
extern "C" int func_ov008_02188d74(Struct_ov008_02184a4c_12* obj);
struct Foo0207df50;
extern "C" void VramState_Rewind(Foo0207df50*);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
int LoadFileIntoMemory(const char* path, void* dst, unsigned int* outSize);
struct ObjectArchiveLoadInfo;
struct Vector3i;
extern "C" void func_020a2010(void* obj);
struct Camera;
extern "C" void Camera_SetPosition(Camera*, int, int, int);
extern "C" void Camera_SetTarget(struct Camera*, int, int, int);
extern "C" void FollowCamera_DisableFollow(void* obj);
extern "C" void GameState_SetCamera(GameState*, int);
struct Struct_020a13c4;
extern "C" void func_020a13c4(Struct_020a13c4*);
extern "C" void func_020a13e4(void* a, void* b, int c, unsigned short d, unsigned char e);
extern "C" int func_ov023_021ed724(void* obj, short* ids, int count);
struct Struct_020a15bc;
extern "C" Struct_ov008_02184a4c_6* func_020a15bc(Struct_020a15bc*, int);
extern "C" void func_020e046c(char* buf, void* b, unsigned int c, int idx);
extern "C" int func_0201081c(char*);
extern "C" int STD_CompareString(const char* a, const char* b);
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_ov008_0218712c(Struct_ov008_02184a4c_12* obj, int a);
struct Struct_ov008_02184a4c_13;
extern "C" void func_ov008_02187664(Struct_ov008_02184a4c_13*, int);
extern "C" void func_ov008_02187a70(Struct_ov008_02184a4c_12* obj, int a);
extern "C" void func_ov008_02187f6c(Struct_ov008_02184a4c_12* obj, int a);
struct Struct_0205d81c;
extern "C" Struct_ov008_02184a4c_10* func_0205d81c(Struct_0205d81c*, int);
extern "C" char* MessageSystem_GetInstance(void);
extern "C" void func_020432c4(char* obj);
struct Actor0209c3b4;
extern "C" void func_0209c3b4(Actor0209c3b4*, int);
extern "C" void func_ov008_02186964(Struct_ov008_02184a4c_12* obj);

struct Struct_ov008_02184a4c_14 {
    int unk_0;
    const void* fileData;
    int size;
    SafeAllocator* allocator;
    int unk_10;
    int unk_14;
    int unknown_18_;
    int packageID;
};

#if defined(jpn)
extern const char data_ov008_0218c0bc[];
extern const char data_ov008_0218c0d5[];
extern "C" void func_020e2168(char*, const char*, int, int, int);
#endif

// USA: func_ov008_02184a4c
extern "C" ARM void func_ov008_02184a4c(Struct_ov008_02184a4c_12* obj) {
#if defined(jpn)
    Struct_ov008_02184a4c_2* ov17;
    GameState* gs = GameState::GetInstance();
    ov17 = (Struct_ov008_02184a4c_2*)GetGameResources();
#else
    GameState* gs = GameState::GetInstance();
    Struct_ov008_02184a4c_2* ov17 = (Struct_ov008_02184a4c_2*)GetGameResources();
#endif
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* scene = LinkSession_GetInstance();

    unsigned char state = obj->unknown_b11_;
    if (state == 0) {
        obj->flags |= 0x200000;
        char* save = Scenario_GetInstance();
        int seen = Scenario_TestFlag(save, save + 0x8c, 0x113b);
        if (seen != 0) {
            obj->flags |= 0x80;
            obj->flags &= ~1;
        }
        Struct_ov008_02184a4c_4 block;
        func_020ac4c0(&block);
        Struct_ov008_02184a4c_4* pb = &block;
        unsigned int scriptId = pb->inline_ov008_02184a4c_2()->inline_ov008_02184a4c();
        if (scriptId == 0) {
            if (Scenario_TestFlag(save, save + 0x8c, 0x796) != 0) {
                if (LinkSession_IsHostOrSolo(scene) != 0) {
                    obj->flags |= 2;
                }
            }
        } else if (scriptId != 0) {
            obj->flags |= 4;
        }
        if (!obj->inline_ov008_02184a4c_12(1)) {
            if (seen == 0) {
                obj->flags |= 0x20000;
            }
            obj->unknown_b11_ = 2;
            if (obj->unknown_b24_ == 1) {
                obj->unknown_b11_ = 3;
            }
        } else {
            if (obj->inline_ov008_02184a4c_12(2)) {
                obj->taskId = loader->QueueLoadFile(data_ov008_0218b3e4, NULL);
            } else {
                char path[0x80];
                __clear(path, 0x80);
                Struct_ov008_02184a4c list;
                func_020727d8((Struct_020727d8*)&list);
                func_020727f8(&list, data_ov008_0218b400, 1000, path, REGION_VALUE(1, 2));
                obj->taskId = loader->QueueLoadFile(path, NULL);
                obj->flags |= 0x400;
            }
            obj->unknown_b11_++;
        }
    } else if (state == 1) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            obj->unknown_78_.Reset();
            obj->unknown_b04_ = (Struct_ov008_02184a4c_5*)obj->unknown_78_.Allocate(0xd0);
            func_0209fe9c((char*)obj->unknown_b04_);
            func_0209fee4((Struct_0209fee4*)obj->unknown_b04_, &obj->unknown_78_, (int)data, size);
            func_0209ff64((Struct_0209ff64*)obj->unknown_b04_, 100);
            do {
                func_0209ff6c((Struct_0209ff6c*)obj->unknown_b04_);
            } while (func_ov008_02185964(obj->unknown_b04_) == 0);
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            obj->unknown_b11_++;
        }
    } else if (state == 2) {
        if (obj->inline_ov008_02184a4c_12(0x400)) {
            if (obj->unknown_b04_->count > 0) {
                obj->b14 = obj->unknown_b04_->ids[0];
                obj->unknown_b16_ = 1000;
                obj->unknown_78_.Reset();
                obj->unknown_b04_ = NULL;
                obj->flags &= ~1;
                obj->flags &= ~0x400;
            } else {
                obj->unknown_78_.Reset();
                obj->unknown_b04_ = NULL;
                obj->flags &= ~0x400;
                obj->taskId = loader->QueueLoadFile(data_ov008_0218b41d, NULL);
                obj->unknown_b11_ = 1;
                return;
            }
        }
        FontBankLoader* global = FontBankLoader_GetInstance();
        func_02094b40(global);
        func_02094b34(global, 0x6b, 0x1fc, 0, 0);
        obj->unknown_b11_++;
    } else if (state == 3) {
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
#if defined(jpn)
            obj->unknown_14_.Reset();
            void* data = obj->unknown_14_.Allocate(0x2000);
            unsigned int size;
            LoadFileIntoMemory(data_ov008_0218c0bc, data, &size);
            obj->alloc28.Reset();
            KeyTable_Load(obj->container, &obj->alloc28, data, size);
            obj->unknown_14_.Reset();
#else
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            unsigned int size;
            void* data = ExtractFileFromGP2(data_ov008_0218b43c, data_ov008_0218b455, &size);
            obj->alloc28.Reset();
            KeyTable_Load(obj->container, &obj->alloc28, data, size);
            BackgroundLoader::RemoveLockGlobal();
#endif
            if (obj->unknown_b24_ != 0) {
                obj->unknown_b11_ = 5;
            } else {
                Background_SetMapSize((unsigned char*)obj->list, 0);
                obj->unknown_ec_0_ = 0;
                obj->unknown_ec_4_ = 1;
                Background_SetPriority(obj->list, 3);
                Background_SetScroll((BackgroundGraphics*)obj->list, 0, 0);
                Background_AllocateMap((BackgroundGraphics*)obj->list, &obj->alloc00);
                Background_AllocateScreens((BackgroundGraphics*)obj->list, 1, &obj->alloc00);
                obj->taskId = loader->QueueLoadFile(KeyTable_Get((Container020e0310*)obj->container, 0), NULL);
                obj->unknown_b11_++;
            }
        }
    } else if (state == 4) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* rec;
            void* data;
            unsigned int size;
            int recSize;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            int count = Pac_CountFiles((PacRecord*)data);
            for (int i = 0; i < count; i++) {
                void* found = Pac_GetFile((PacRecord*)data, i, &rec, &recSize);
                if (found != NULL) {
                    Background_LoadFile(obj->list, found, &obj->alloc00, recSize);
                }
            }
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            Background_DrawScreen((BackgroundGraphics*)obj->list, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            Background_UploadMap((BackgroundGraphics*)obj->list, NULL);
            obj->unknown_b11_++;
        }
    } else if (state == 5) {
        if (func_ov008_02188a54(obj, 0) != 0) {
            if (obj->unknown_b24_ == 0) {
                SpriteContext_Init((char*)obj->table);
                obj->table->unknown_50_ = 0;
                Struct_ov008_02184a4c_8* entries = obj->GetEntries();
                obj->inline_ov008_02184a4c_11()->inline_ov008_02184a4c_6(entries, 0x12);
                obj->table->tail = obj->tail;
                for (int i = 0; i < 0x12; i++) {
                    Sprite_Init((Struct0205a198*)&obj->entries[i]);
                }
                func_0205a234((ClearTarget0205a234*)obj->tail);
#if defined(jpn)
                obj->taskId = loader->QueueLoadFile(KeyTable_Get((Container020e0310*)obj->container, 3), NULL);
#else
                const char* inner = KeyTable_Get((Container020e0310*)obj->container, 6);
                obj->taskId = loader->QueueLoadFileInGP2(KeyTable_Get((Container020e0310*)obj->container, 5), inner, NULL);
#endif
                obj->unknown_b11_++;
            } else {
                obj->unknown_b11_ = 0xff;
            }
        }
    } else if (state == 6) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* rec;
            void* data;
            unsigned int size;
            int recSize;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            int count = Pac_CountFiles((PacRecord*)data);
            obj->alloc3c.Reset();
            for (int i = 0; i < count; i++) {
                void* found = Pac_GetFile((PacRecord*)data, i, &rec, &recSize);
                if (found != NULL) {
                    SpriteContext_LoadFile(obj->table, found, recSize, &obj->alloc3c);
                }
            }
            obj->flags |= 0x80000;
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            obj->unknown_b11_++;
        }
    } else if (state == 7) {
        if (func_ov008_02188d74(obj) != 0) {
            if (obj->inline_ov008_02184a4c_12(0x80)) {
                obj->unknown_b11_ = 9;
            } else {
                obj->unknown_b11_++;
            }
        }
    } else if (state == 8) {
        char* stage = ov17->stage;
        VramState_Rewind((Foo0207df50*)(stage + 0x230));
        VramState_Restore(stage + 0x230);
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        if (LoadFileIntoMemory(KeyTable_Get((Container020e0310*)obj->container, 10), g_fileLoadBuffer, &size) != 0) {
            Struct_ov008_02184a4c_14 info;
            info.unk_0 = 0;
            info.unk_14 = 0;
            info.unknown_18_ = 0;
            info.packageID = 0;
            info.allocator = &obj->unknown_64_;
            info.fileData = g_fileLoadBuffer;
            info.size = size;
            info.unk_10 = 1;
            ((Object3D*)&obj->model)->LoadFromCCHROrCMOTArchive((ObjectArchiveLoadInfo*)&info, (int (*)(BCFG::AnimationRecord*))NULL);
            Struct_ov008_0218b31c scale = data_ov008_0218b328;
            ((Object3D*)&obj->model)->SetScale((Vector3i const*)&scale);
            Struct_ov008_0218b31c pos = data_ov008_0218b334;
            obj->inline_ov008_02184a4c_9()->inline_ov008_02184a4c_8(&pos);
            Struct_ov008_0218b31c rot = data_ov008_0218b31c;
            *(Vector3i*)&obj->unknown_7e0_ = *(Vector3i const*)&rot;
            ((Object3D*)&obj->model)->SetAnimationByIndex(0, 0);
        }
        BackgroundLoader::RemoveLockGlobal();
        VramState_Save(stage + 0x230);
        func_020a2010(obj->controller);
        Camera_SetPosition((Camera*)obj->controller, 0, 0x8000, 0x40000);
        Camera_SetTarget((struct Camera*)obj->controller, 0, 0, 0);
        FollowCamera_DisableFollow(obj->controller);
        GameState_SetCamera(gs, (int)obj->controller);
        obj->unknown_b11_++;
    } else if (state == 9) {
        if (!obj->inline_ov008_02184a4c_12(1)) {
            obj->unknown_b11_ = 0xff;
        } else if (func_ov008_02185964(obj->unknown_b04_) != 0) {
            if (obj->unknown_b04_->count > 0) {
                func_020a13c4((Struct_020a13c4*)obj->script);
                func_020a13e4(obj->script, obj->unknown_8c_, 0, 0, 1);
                short ids[50];
                int count = obj->unknown_b04_->count;
                for (int i = 0; i < count; i++) {
                    ids[i] = obj->unknown_b04_->ids[i];
                }
                if (func_ov023_021ed724(obj->script, ids, count) & 1) {
                    obj->flags |= 0x8000;
                }
                if (obj->inline_ov008_02184a4c_12(2)) {
                    inline_ov008_02184a4c_5(gs)->inline_ov008_02184a4c_2()->scriptId = ids[0];
                    obj->flags |= 4;
                    obj->unknown_b16_ = 0x3e9;
                } else {
                    obj->unknown_b16_ = 1000;
                }
                obj->b14 = ids[0];
                obj->unknown_78_.Reset();
                obj->unknown_b04_ = NULL;
                obj->message = (Struct_ov008_02184a4c_7*)obj->unknown_78_.Allocate(REGION_VALUE(0x15c, 0x244));
                Struct_ov008_02184a4c_7* msg = obj->message;
                msg->a = 0;
                msg->b = 0;
                msg->c = 0;
                msg->d = 0;
                msg->e = 0;
                msg->text = NULL;
                msg->f8 = 0;
                memset(msg->name, 0, 0x38);
                memset(msg->buf, 0, REGION_VALUE(0x118, 0x200));
                msg->text = msg->buf;
                Struct_ov008_02184a4c_6* src = func_020a15bc((Struct_020a15bc*)obj->script, ids[0]);
                msg = obj->message;
                if (src != NULL) {
                    *(unsigned int*)msg = src->word0;
                    msg->text = (char*)src->text;
                    msg->f8 = src->f8;
                    msg->text = msg->buf;
                    const char* text = src->text;
                    if (text != NULL) {
                        memset(msg->buf, 0, REGION_VALUE(0x118, 0x200));
                        sprintf(msg->buf + STD_GetStringLength(msg->buf), data_ov008_0218b3e0, text);
                    }
                }
                Struct_ov008_02184a4c_11* hero = (Struct_ov008_02184a4c_11*)GameState::GetInstance()->GetProtagonist();
#if defined(jpn)
                int female = hero->inline_ov008_02184a4c_7();
                func_020e2168(obj->message->name, data_ov008_0218c0d5, ids[0], female, 1);
#else
                BackgroundLoader::AddLockGlobal();
                unsigned int size = 0;
                char gp2[0x40];
                __clear(gp2, 0x40);
                char inner[0x20];
                __clear(inner, 0x20);
                int female = hero->inline_ov008_02184a4c_7();
                sprintf(gp2, data_ov008_0218b465, female);
                sprintf(inner, data_ov008_0218b47c, hero->inline_ov008_02184a4c_7());
                void* data = ExtractFileFromGP2(gp2, inner, &size);
                if (data != NULL) {
                    func_020e046c(obj->message->name, data, size, ids[0]);
                }
                BackgroundLoader::RemoveLockGlobal();
#endif
            } else {
                obj->unknown_78_.Reset();
                obj->unknown_b04_ = NULL;
            }
            if (obj->b14 <= 0) {
                int id = func_0201081c((char*)gs);
                if (LinkSession_IsGuest(scene) != 0) {
                    obj->flags |= 0x100;
                    id = 0x3eb;
                }
                memset(obj->pathBuf, 0, REGION_VALUE(0x800, 0x960));
                Struct_ov008_02184a4c list;
                func_020727d8((Struct_020727d8*)&list);
                func_020727f8(&list, data_ov008_0218b400, (short)id, obj->pathBuf, REGION_VALUE(1, 2));
                if (STD_CompareString(obj->pathBuf, data_ov008_0218b48f) == 0) {
                    obj->unknown_b11_ = 0xff;
                } else {
                    obj->taskId = loader->QueueLoadFile(obj->pathBuf, NULL);
                    obj->unknown_b11_++;
                }
            } else {
                obj->unknown_b11_ = 0xff;
            }
        }
    } else if (state == 10) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            obj->unknown_78_.Reset();
            obj->unknown_b04_ = (Struct_ov008_02184a4c_5*)obj->unknown_78_.Allocate(0xd0);
            func_0209fe9c((char*)obj->unknown_b04_);
            func_0209fee4((Struct_0209fee4*)obj->unknown_b04_, &obj->unknown_78_, (int)data, size);
            func_0209ff64((Struct_0209ff64*)obj->unknown_b04_, 100);
            do {
                func_0209ff6c((Struct_0209ff6c*)obj->unknown_b04_);
            } while (func_ov008_02185964(obj->unknown_b04_) == 0);
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            obj->unknown_b11_++;
        }
    } else if (state == 11) {
        if (obj->unknown_b04_->count > 0) {
            obj->b14 = obj->unknown_b04_->ids[0];
            obj->unknown_b16_ = func_0201081c((char*)gs);
            if (obj->inline_ov008_02184a4c_12(0x100)) {
                obj->flags &= ~0x100;
                obj->unknown_b16_ = 0x3ea;
                if (LinkSession_IsGuest(scene) != 0) {
                    obj->unknown_b16_ = 0x3eb;
                }
            }
            obj->unknown_78_.Reset();
            obj->unknown_b04_ = NULL;
            obj->unknown_b11_ = 0xff;
        } else if (obj->inline_ov008_02184a4c_12(0x100)) {
            obj->flags &= ~0x100;
            obj->unknown_b11_ = 0xff;
        } else {
            void* scene2 = LinkSession_GetInstance();
            int id = 0x3ea;
            if (LinkSession_IsActive((int*)scene2) != 0) {
                if (LinkSession_IsGuest(scene2) != 0) {
                    id++;
                }
            }
            memset(obj->pathBuf, 0, REGION_VALUE(0x800, 0x960));
            Struct_ov008_02184a4c list;
            func_020727d8((Struct_020727d8*)&list);
            func_020727f8(&list, data_ov008_0218b400, id, obj->pathBuf, REGION_VALUE(1, 2));
            obj->taskId = loader->QueueLoadFile(obj->pathBuf, NULL);
            obj->unknown_b11_ = 10;
            obj->flags |= 0x100;
        }
    } else if (state == 0xff) {
        func_ov008_0218712c(obj, 0);
        func_ov008_02187664((Struct_ov008_02184a4c_13*)obj, 0);
        func_ov008_02187a70(obj, 0);
        func_ov008_02187f6c(obj, 0);
        for (int i = 0; i < 6; i++) {
            Struct_ov008_02184a4c_10* elem = func_0205d81c((Struct_0205d81c*)obj->elems, (unsigned char)i);
            if (elem != NULL) {
                if (!(i != 4 && i != 5)) {
                    elem->unknown_c2_ = 1;
                } else {
                    elem->unknown_c2_ = 0;
                }
            }
        }
        if (obj->unknown_b24_ == 0) {
            char* stage = ov17->stage;
            char* presenter = MessageSystem_GetInstance();
            VramState_Rewind((Foo0207df50*)(stage + 0x5b0));
            VramState_Restore(stage + 0x5b0);
            func_020432c4(presenter);
            VramState_Save(stage + 0x5b0);
            func_0209c3b4((Actor0209c3b4*)&g_bgmPlayer, 0x29);
            obj->b10 = 3;
            obj->unknown_b11_ = 0;
            if (obj->message == NULL) {
                obj->flags &= ~0x200000;
                func_ov008_02186964(obj);
            }
        } else {
            obj->flags &= ~0x200000;
            obj->b10 = 4;
            obj->unknown_b11_ = 0;
        }
    }
}
