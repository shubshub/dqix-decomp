#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov025_021e75a4_2 { int x; int y; int z; };
struct Vec3;
struct Struct_01ff8b48_2;

extern "C" void* __clear(void* dst, int count);
struct Vector3i;
void Vector3fixDivideScalar(Vector3i const*, int, Vector3i*);
extern "C" void func_ov025_021de110(void* obj);
struct Struct_ov025_021dcf14_7;
struct Struct_ov025_021dcf14_8;
extern "C" void func_ov025_021eee48(struct Struct_ov025_021dcf14_7* obj, struct Struct_ov025_021dcf14_8* src);
extern char data_ov025_021ef834[];

struct Struct_ov025_021e75a4 {
    int f0;
    int f4;
    short id;
    short val;
    int unknown_c_[3];
    void* next;
};

// USA: func_ov025_021e75a4
extern "C" ARM int func_ov025_021e75a4(void* unused0, void* unused1, struct Struct_ov025_021dcf14_7* obj) {
    GameState* battle = GameState::GetInstance();
    void* arr[8];
    int var2;
    void** slot;
    int i;

    slot = arr;
    var2 = 0;
    struct Struct_ov025_021e75a4_2 accum;
    __clear(&accum, 0xc);
    for (int j = var2; j < 8; slot++, j++) {
        GameObject* c = battle->GetGameObjectByIndex(j + 0xc0);
        *slot = c;
        if (c) {
            struct Struct_ov025_021e75a4_2 tmp = *(struct Struct_ov025_021e75a4_2*)((char*)c + 0x44);
            Vector3fix_Add((const Vector3fix*)((struct Vec3*)&accum), (const Vector3fix*)((struct Vec3*)&tmp), (Vector3fix*)((struct Vec3*)&accum));
            var2++;
        }
    }
    Vector3fixDivideScalar((Vector3i const*)&accum, var2 << 0xc, (Vector3i*)&accum);

    slot = arr;
    for (i = 0; i < var2; slot++, i++) {
        void* c = *slot;
        if (c) {
            struct Struct_ov025_021e75a4_2* var10 = (struct Struct_ov025_021e75a4_2*)((char*)c + 0x44);
            struct Struct_ov025_021e75a4_2 var11 = *var10;
            var11.x = var11.x - accum.x;
            *(Vector3i*)((int*)var10) = *(Vector3i const*)((int*)&var11);
        }
    }

    accum.x = 0;
    struct Struct_ov025_021e75a4 entry;
    for (i = 0; i < 8; i++) {
        short id = (short)(i + 0xc0);
        void* c = battle->GetGameObjectByIndex(id);
        if (!c) {
            continue;
        }
        func_ov025_021de110(&entry);
        entry.f0 = 0;
        entry.f4 = 0x12c;
        entry.id = id;
        entry.val = 0x12c;
        *(Vector3i*)((int*)entry.unknown_c_) = *(Vector3i const*)((int*)&accum);
        func_ov025_021eee48(obj, (struct Struct_ov025_021dcf14_8*)&entry);
        ((Object3D*)c)->SetAnimationByName((char const*)data_ov025_021ef834, 0);
    }
    return 1;
}
