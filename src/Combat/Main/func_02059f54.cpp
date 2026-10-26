#include <globaldefs.h>

#include "Combat/DistanceSort.h"
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"

struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
extern "C" void func_02059f38(struct Struct_02059cfc_2* dst, struct Struct_02059cfc_3* src);

struct Struct_0202e5d8_2;
struct Struct_0202e5d8_3;

extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);

struct Struct_02059f54 { int x; int y; int z; };

struct Struct_02059f54_2 {
    char pad0[0xcc];
    unsigned char bit0:1;
    unsigned char unknown_cc_1_:1;
    unsigned char bit2:1;
    unsigned char unknown_cc_3_:1;
    unsigned char unknown_cc_4_:1;
    unsigned char unknown_cc_5_:1;
    unsigned char unknown_cc_6_:1;
    unsigned char unknown_cc_7_:1;
};

// USA: func_02059f54
extern "C" ARM void func_02059f54(unsigned char* p, int combatantId) {
    short* var0 = (short*)(p + 0xb0);
    if (*var0 > 0) {
        return;
    }

    GameState* bs = GameState::GetInstance();
    if (bs->GetGameObjectByIndex(combatantId) == 0) {
        return;
    }

    struct Struct_02059f54 var2 = *(struct Struct_02059f54*)(p + 0x44);
    struct Struct_02059f54_2* flags = (struct Struct_02059f54_2*)p;

    if (flags->unknown_cc_3_) {
        struct Struct_02059f54 vec = *(struct Struct_02059f54*)(p + 0x44);
        void* m = (void*)RenderConfig::GetInverseViewMatrix();
        Mat4x3_ApplyToVector((const Vector3fix*)((struct Struct_0202e5d8_2*)&vec), (const Matrix4x3*)((struct Struct_0202e5d8_3*)m), (Vector3fix*)((struct Struct_0202e5d8_2*)&vec));
        func_02059f38((struct Struct_02059cfc_2*)p, (struct Struct_02059cfc_3*)&vec);
    }

    if (*(int*)(p + 0xac) == 0) {
        _ZN8Object3D4DrawEb(p, flags->bit2);
    } else {
        func_0205578c((int*)p);
    }

    if (flags->unknown_cc_3_) {
        func_02059f38((struct Struct_02059cfc_2*)p, (struct Struct_02059cfc_3*)&var2);
    }
}
