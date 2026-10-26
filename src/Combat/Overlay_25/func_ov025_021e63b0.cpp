#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

struct Struct_ov025_021e63b0_2 { unsigned char padding0[0x20]; unsigned short id; };
struct Struct_ov025_021e63b0_3 { unsigned char padding0[0x10]; Struct_ov025_021e63b0_2* head; };
struct Struct_ov025_021ef988_23 {
#if defined(jpn)
    unsigned char padding0[4];
    char* context;
    unsigned char unknown_8_[4];
    unsigned int flags;
    unsigned char unknown_10_[0x10];
#else
    unsigned char padding0[0xc];
    char* context;
    unsigned char unknown1_10_[0xc];
    unsigned int flags;
#endif
    int state;
    int field24;
    int task;
};
struct Struct_ov025_021ef9a8;
struct Struct_02054000;
struct Struct_ov025_021e267c_2;
struct Struct_ov025_021e267c_3 {
    unsigned char kind;
    unsigned char field1;
    unsigned short id;
    unsigned int field4;
    Struct_ov025_021e267c_3* next;
};
#if defined(jpn)
struct Struct_ov025_021e63b0_4 { unsigned char padding0[0x71c6]; unsigned short source; };
#else
struct Struct_ov025_021e63b0_4 { unsigned char padding0[0x6fd6]; unsigned short source; };
#endif
struct Struct_ov025_021e63b0 { unsigned char padding0[0x14]; unsigned int flags; };
extern Struct_ov025_021ef988_23 data_ov025_021ef988;
extern Struct_ov025_021ef9a8 data_ov025_021ef9a8;
extern char data_ov025_021ef809[];
extern char data_ov025_021ef791[];
extern "C" void func_ov025_021e3158(Struct_ov025_021ef9a8*);
extern "C" void* func_02054000(Struct_02054000*);
extern "C" void func_02072e94(char*, int, int, void*, int);
extern "C" int func_ov025_021e2628(int, int);
extern "C" SafeAllocator* func_ov025_021e8a54(char*);
extern "C" char* func_ov025_021e8a64(char*);
extern "C" void func_ov025_021e8bac(Struct_ov025_021e267c_2*, Struct_ov025_021e267c_3*);
extern "C" void VramState_Restore(char*);
extern "C" void VramState_Save(char*);
extern "C" void func_0200fd38(GameState*, int, GameObject*);
extern "C" Struct_ov025_021e63b0_4* func_ov000_02160130();
extern "C" void func_ov017_02191aac(GameResources*, int, int, int);

// USA: func_ov025_021e63b0
extern "C" ARM int func_ov025_021e63b0(void* unused, Struct_ov025_021e63b0_3* targets) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (data_ov025_021ef988.state == 0) {
        if (!targets->head) return 1;
        int id = targets->head->id;
        GameObject* source = func_0200ff1c(game, id);
        if (!source) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        void* model = func_02054000((Struct_02054000*)source);
        if (!model) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        char path[0x50];
        func_02072e94(path, id, 8, model, 0);
        char* extension = strrchr(path, '.');
        if (extension) sprintf(extension, data_ov025_021ef809);
        if (!(data_ov025_021ef988.flags & 0x2000)) {
            loader->AddFence();
            data_ov025_021ef988.flags |= 0x2000;
        }
        data_ov025_021ef988.task = func_ov025_021e2628((int)data_ov025_021ef791, (int)path);
        data_ov025_021ef988.state++;
    } else if (data_ov025_021ef988.state == 1) {
        int task = data_ov025_021ef988.task;
        if (!loader->GetTaskStatus(task)) return 0;
        if (loader->GetDetailedTaskStatus(task) != 2) {
            loader->RemoveTask(task);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        unsigned int size;
        void* file;
        loader->GetLoadedFileByID(task, &file, &size);
        SafeAllocator* allocator = func_ov025_021e8a54(data_ov025_021ef988.context);
        char* tables = func_ov025_021e8a64(data_ov025_021ef988.context);
        Object3D* var12 = (Object3D*)allocator->Allocate(sizeof(Object3D));
        if (!var12) {
            loader->RemoveTask(task);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        Struct_ov025_021e267c_3* node = (Struct_ov025_021e267c_3*)allocator->Allocate(sizeof(Struct_ov025_021e267c_3));
        if (!node) {
            loader->RemoveTask(task);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        node->kind = 4;
        node->id = 0xc8;
        func_ov025_021e8bac((Struct_ov025_021e267c_2*)data_ov025_021ef988.context, node);
        var12->Initialize();
        VramState_Restore(tables);
        var12->SetModelFromFileCopy(allocator, file, size, Model3D::TextureStagingMode_Normal);
        VramState_Save(tables);
        func_0200fd38(game, 0xc8, (GameObject*)var12);
        var12->MakeHidden();
        int var14 = targets->head->id;
        Struct_ov025_021e63b0_4* work = func_ov000_02160130();
        if (work) work->source = var14;
        GameObject* source = func_0200ff1c(game, var14);
        if (source) {
            var12->position_ = source->obj3D_.position_;
            var12->rotation_ = source->obj3D_.rotation_;
            var12->SetScale(&source->obj3D_.GetScale());
            var12->unknown_2_ = var14;
            if (((Struct_ov025_021e63b0*)source->currentStats_)->flags & 0x8000000) {
                GameResources* resources = GetGameResources();
                var12->SetAlphaScaleFactor(0);
                func_ov017_02191aac(resources, 1, var14, 2);
            }
        }
        loader->RemoveTask(task);
        func_ov025_021e3158(&data_ov025_021ef9a8);
        return 1;
    }
    return 0;
}
