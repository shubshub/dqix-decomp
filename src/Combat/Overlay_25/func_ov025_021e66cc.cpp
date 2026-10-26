#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct Struct_ov025_021e66cc {
    char pad0[0x20];
    unsigned short id;
};

struct Struct_ov025_021e66cc_2 {
    char pad0[0x10];
    struct Struct_ov025_021e66cc* head;
};

struct Struct_ov025_021e66cc_3 {
    char pad0[8];
    unsigned int unknown_8_0_ : 4;
    unsigned int kind : 5;
};

struct Struct_ov025_021e267c_3 {
    unsigned char type;
    unsigned char priority;
    unsigned short id2;
    unsigned short unknown_4_;
    struct Struct_ov025_021e267c_3* next;
};

struct Struct_ov025_021ef988_11 {
#if defined(jpn)
    char pad0[4];
    char* battle;
    char pad10[0x18];
#else
    char pad0[0xc];
    char* battle;
    char pad10[0x10];
#endif
    int state;
    int objectId;
    int taskId;
};

struct Struct_ov025_021ef9a8 { int a; int b; int c; int d; int e; int f; };

struct Struct_02054000;
struct Struct_ov025_021e267c_2;
struct Struct_203dafc;

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int id);
extern "C" Struct_ov025_021e66cc_3* func_02054000(struct Struct_02054000* p);
extern "C" void func_ov025_021e3158(struct Struct_ov025_021ef9a8* p);
extern "C" int func_ov025_021e2628(int a, int b);
extern "C" SafeAllocator* func_ov025_021e8a54(char* obj);
extern "C" void func_ov025_021e8bac(struct Struct_ov025_021e267c_2* obj, struct Struct_ov025_021e267c_3* node);
extern "C" void func_0203dafc(struct Struct_203dafc* obj);

extern struct Struct_ov025_021ef988_11 data_ov025_021ef988;
extern struct Struct_ov025_021ef9a8 data_ov025_021ef9a8;
extern char data_ov025_021ef7be[];
extern char data_ov025_021ef811[];
extern char data_ov025_021ef81e[];

// USA: func_ov025_021e66cc
extern "C" ARM int func_ov025_021e66cc(void* unused, struct Struct_ov025_021e66cc_2* slot) {
    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (data_ov025_021ef988.state == 0) {
        GameObject* c = func_0200ff1c(gs, slot->head->id);
        if (c == NULL) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        Struct_ov025_021e66cc_3* sub = func_02054000((struct Struct_02054000*)c);
        if (sub == NULL) {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        if (sub->kind == 4) {
            data_ov025_021ef988.taskId = func_ov025_021e2628((int)data_ov025_021ef7be, (int)data_ov025_021ef811);
        } else if (sub->kind == 0xb) {
            data_ov025_021ef988.taskId = func_ov025_021e2628((int)data_ov025_021ef7be, (int)data_ov025_021ef81e);
        } else {
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        data_ov025_021ef988.state++;
        return 0;
    }

    if (data_ov025_021ef988.state == 1) {
        int taskId = data_ov025_021ef988.taskId;
        if (loader->GetTaskStatus(taskId) == 0) {
            return 0;
        }
        if (loader->GetDetailedTaskStatus(taskId) != 2) {
            loader->RemoveTask(taskId);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }

        unsigned int length;
        void* fileData;
        loader->GetLoadedFileByID(taskId, &fileData, &length);

        GameObject* holder = gs->GetGameObjectByIndex(200);
        if (holder == NULL) {
            loader->RemoveTask(taskId);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }

        SafeAllocator* allocator = func_ov025_021e8a54(data_ov025_021ef988.battle);
        Struct_ov025_021e267c_3* node = (Struct_ov025_021e267c_3*)allocator->Allocate(sizeof(Struct_ov025_021e267c_3));
        if (node == NULL) {
            loader->RemoveTask(taskId);
            func_ov025_021e3158(&data_ov025_021ef9a8);
            return 1;
        }
        node->type = 0;
        node->id2 = 200;
        node->unknown_4_ = 0;
        func_ov025_021e8bac((struct Struct_ov025_021e267c_2*)data_ov025_021ef988.battle, node);

        ObjectArchiveLoadInfo info;
        func_0203dafc((struct Struct_203dafc*)&info);
        info.fileData = fileData;
        info.fileSize = length;
        info.unk_10 = 1;
        info.allocator = allocator;
        holder->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
        loader->RemoveTask(taskId);
        func_ov025_021e3158(&data_ov025_021ef9a8);
        return 1;
    }

    return 0;
}
