#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov025_021e5a6c_28629 = 0x71c5 };
#else
enum { Enum_ov025_021e5a6c_28629 = 0x6fd5 };
#endif

struct Vec3 { int x; int y; int z; };

struct Struct_ov025_021e5a6c {
    char pad0[8];
    Vec3 pos;
    unsigned char mode;
};

struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8;

extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
struct Vector3i;
extern "C" void* func_ov000_02160130(void);

// USA: func_ov025_021e5a6c
extern "C" ARM int func_ov025_021e5a6c(struct Struct_ov025_021e5a6c* obj, struct Struct_ov000_0215440c* list) {
    GameState* bs = GameState::GetInstance();
    void* f = bs->GetCamera();
    unsigned char mode = obj->mode;
    if (mode == 0) {
        if (f != 0) {
            *(Vector3i*)((int*)((char*)f + 0x10)) = *(Vector3i const*)((int*)&obj->pos);
        }
    } else if (mode == 2) {
        int height = 1;
        struct Struct_ov000_021600f8* node = func_ov000_021600f8(list, 0);
        if (node != 0) {
            GameObject* c = bs->GetCombatantByIndex(*(short*)((char*)node + 0xe));
            if (c != 0) {
                height = c->obj3D_.GetHeight();
            }
        }
        float scale = 1.0f;
        if (height >= 9420) {
            scale = 1.0f + 0.6f * ((float)height / 4096.0f - 2.3f) / 1.7f;
            if (scale >= 1.6f) {
                scale = 1.6f;
            }
        }
        float var7 = (float)obj->pos.y / 4096.0f;
        float var8 = (float)obj->pos.z / 4096.0f;
        var7 = var7 * scale;
        var8 = var8 * scale;
        obj->pos.y = (int)(4096.0f * var7);
        obj->pos.z = (int)(4096.0f * var8);
        if (f != 0) {
            *(Vector3i*)((int*)((char*)f + 0x10)) = *(Vector3i const*)((int*)&obj->pos);
        }
    } else {
        if (f != 0) {
            Vec3 sum = *(Vec3*)((char*)f + 0x10);
            Vec3 other = obj->pos;
            sum.x = sum.x + other.x;
            sum.y = sum.y + other.y;
            sum.z = sum.z + other.z;
            *(Vector3i*)((int*)((char*)f + 0x10)) = *(Vector3i const*)((int*)&sum);
        }
    }
    void* work = func_ov000_02160130();
    if (work != 0) {
        *(unsigned char*)((char*)work + Enum_ov025_021e5a6c_28629) = 1;
    }
    return 1;
}
