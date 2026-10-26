#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

extern "C" SafeAllocator* func_ov025_021e8a54(char* obj);
struct Struct_ov025_021e27c8;
extern "C" void func_ov025_021eb084(struct Struct_ov025_021e27c8* obj, int val);
struct Struct_203dafc;
extern "C" void func_0203dafc(struct Struct_203dafc* obj);
extern "C" void GameState_SetCamera(GameState* battleStruct, int value);

struct Struct_0204a120;
extern "C" void func_0204a120(struct Struct_0204a120* obj);
struct Struct_0204a3f0_2;
struct Struct_0204a3f0;
extern "C" void func_0204a3f0(struct Struct_0204a3f0_2* owner, struct Struct_0204a3f0* h);
extern "C" void func_0204a440(char* obj, const char* src);
extern "C" void func_0204a464(char* obj, const char* src);

struct Struct_ov025_021e267c_3 {
    unsigned char type;
    unsigned char priority;
    unsigned short id2;
    unsigned short unknown_4_;
    struct Struct_ov025_021e267c_3* next;
};
struct Struct_ov025_021e267c_2;
extern "C" void func_ov025_021e8bac(struct Struct_ov025_021e267c_2* obj, struct Struct_ov025_021e267c_3* node);

struct Struct_ov025_021ef988_11 {
#if defined(jpn)
    char pad0[4];
#else
    char pad0[0xc];
#endif

    char* battle;
};

struct Struct_ov025_021e4be4 {
    char pad0[8];
    char* fileName;
};

extern struct Struct_ov025_021ef988_11 data_ov025_021ef988;
extern char data_ov025_021eef78[];
extern const char data_ov025_021ef7f7[];
extern const char data_ov025_021ef7fb[];

// USA: func_ov025_021e4be4
extern "C" ARM int func_ov025_021e4be4(struct Struct_ov025_021e4be4* p) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* allocator = func_ov025_021e8a54(data_ov025_021ef988.battle);

    char path[0x28];
    int n = 0x28;
    unsigned char* d = (unsigned char*)path;
    unsigned char* s = (unsigned char*)data_ov025_021eef78;
    do {
        *d = *s;
        d++;
        s++;
    } while (--n);
    strcat(path, p->fileName);

    void* fileData;
    unsigned int length;
    int taskId = loader->GetLoadedFileByName(path, &fileData, &length);
    if (fileData == NULL) {
        if (taskId >= 0) {
            loader->RemoveTask(taskId);
            func_ov025_021eb084((struct Struct_ov025_021e27c8*)data_ov025_021ef988.battle, taskId);
        }
        return 1;
    }

    Object3D* model = (Object3D*)allocator->Allocate(sizeof(Object3D));
    if (model == NULL) {
        loader->RemoveTask(taskId);
        func_ov025_021eb084((struct Struct_ov025_021e27c8*)data_ov025_021ef988.battle, taskId);
        return 1;
    }

    Struct_ov025_021e267c_3* node = (Struct_ov025_021e267c_3*)allocator->Allocate(sizeof(Struct_ov025_021e267c_3));
    if (node == NULL) {
        loader->RemoveTask(taskId);
        func_ov025_021eb084((struct Struct_ov025_021e27c8*)data_ov025_021ef988.battle, taskId);
        return 1;
    }

    model->Initialize();
    ObjectArchiveLoadInfo info;
    func_0203dafc((struct Struct_203dafc*)&info);
    info.fileData = fileData;
    info.fileSize = length;
    info.allocator = allocator;
    info.unk_10 = 1;
    if (!model->LoadFromCHRArchive(&info)) {
        loader->RemoveTask(taskId);
        func_ov025_021eb084((struct Struct_ov025_021e27c8*)data_ov025_021ef988.battle, taskId);
        return 1;
    }
    loader->RemoveTask(taskId);
    func_ov025_021eb084((struct Struct_ov025_021e27c8*)data_ov025_021ef988.battle, taskId);

    char* state = (char*)allocator->Allocate(0x268);
    if (state == NULL) {
        loader->RemoveTask(taskId);
        func_ov025_021eb084((struct Struct_ov025_021e27c8*)data_ov025_021ef988.battle, taskId);
        return 1;
    }

    func_0204a120((struct Struct_0204a120*)state);
    func_0204a3f0((struct Struct_0204a3f0_2*)state, (struct Struct_0204a3f0*)model);
    func_0204a440(state, data_ov025_021ef7f7);
    func_0204a464(state, data_ov025_021ef7fb);
    GameState_SetCamera(gs, (int)state);
    node->type = 3;
    func_ov025_021e8bac((struct Struct_ov025_021e267c_2*)data_ov025_021ef988.battle, node);
    return 1;
}
