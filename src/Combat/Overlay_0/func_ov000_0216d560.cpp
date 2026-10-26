#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Flags0202ecfc;
extern "C" void Camera_DisableTransform(struct Flags0202ecfc* p);

struct Struct_0202ecc8 { unsigned int v[12]; };
struct Struct_0202ecc8_2;
extern "C" void func_0202ecc8(struct Struct_0202ecc8_2* dst, struct Struct_0202ecc8* src);

extern "C" void func_ov000_0216d234(void* a, void* b, void* c);

struct Struct_ov000_0216d560 { unsigned int v[3]; };
struct Struct_ov000_0216d560_2 { int x, y, z; };
struct Struct_ov000_0216d560_3 { int x, y, z; };

struct Struct_ov000_0216d560_4 {
    char pad[0x224];
    int unknown_224_;
};

// USA: func_ov000_0216d560
extern "C" ARM void func_ov000_0216d560(struct Struct_ov000_0216d560_4* obj, int id) {
    GameObject* c = GameState::GetInstance()->GetGameObjectByIndex(id);
    if (!c) {
        obj->unknown_224_ = -1;
        Camera_DisableTransform((struct Flags0202ecfc*)obj);
    } else {
        struct Struct_ov000_0216d560 fieldA = *(struct Struct_ov000_0216d560*)((char*)c + 0x44);
        struct Struct_ov000_0216d560_2 fieldB = *(struct Struct_ov000_0216d560_2*)((char*)c + 0x50);
        struct Struct_ov000_0216d560_3 tbl;
        struct Struct_0202ecc8 block;
        tbl.x = fix32sin(fieldB.y);
        tbl.y = 0;
        tbl.z = fix32cos(fieldB.y);
        func_ov000_0216d234(&tbl, &fieldA, &block);
        func_0202ecc8((struct Struct_0202ecc8_2*)obj, &block);
    }
}
