#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vector3i;

struct Struct_020a7eb8 {
    int x;
    int y;
    int z;
};

struct Obj020a7eb8 {
    char unk0[0x44];
    struct Struct_020a7eb8 pos;
    char unknown_50_[0x140 - 0x50];
    int unknown_140_;
};

extern "C" void GameObject_Draw(struct Obj020a7eb8* obj, int a1, int a2);

// USA: func_020a7eb8
extern "C" ARM void func_020a7eb8(struct Obj020a7eb8* obj) {
    GameState::GetInstance();
    struct Struct_020a7eb8 tmp = obj->pos;
    tmp.y += obj->unknown_140_;
    *(Vector3i*)((int*)&obj->pos) = *(Vector3i const*)((int*)&tmp);
    GameObject_Draw(obj, 1, 0);
    *(Vector3i*)((int*)&tmp) = *(Vector3i const*)((int*)&obj->pos);
    tmp.y -= obj->unknown_140_;
    *(Vector3i*)((int*)&obj->pos) = *(Vector3i const*)((int*)&tmp);
}
