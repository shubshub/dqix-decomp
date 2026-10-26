#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"

extern "C" void* Zone3D_GetInstance(void* self);
extern "C" unsigned char* Zone3D_GetChest(unsigned char* p, int i);

struct Struct_ov017_021d6318 {
    unsigned char data[0xc0];
};

extern Struct_ov017_021d6318 data_ov017_021d6318;

struct Struct_ov017_02193290 {
    Struct_ov017_021d6318 header;
    unsigned char unknown_c0_[0x900 - 0xc0];
    int unknown_900_;
    int unknown_904_;
    Vector3i position;
    int unknown_914_;
    int unknown_918_;
    unsigned char unknown_91c_[0x980 - 0x91c];
};

struct Element02193290 {
    Vector3i position;
    short fieldC;
};

struct Owner02193290 {
#if defined(jpn)
    unsigned char pad[0x497];
#else
    unsigned char pad[0x477];
#endif
    unsigned char count;
};

extern "C" int func_ov017_02192b48(Struct_ov017_02193290* params, int a, int b, int c, int d, int e, Vector3i* pos, int f, int g, int h, int* out, int i, int index, int j);

static inline fix32_t inline_ov000_0216f3d4(fix32_t x) {
    return FIX32_MULTIPLY(x, x);
}

// USA: func_ov017_02193290
extern "C" ARM int func_ov017_02193290(int a, int b, int c, Vector3i* pos, int d, int e, int f) {
    Owner02193290* owner = (Owner02193290*)Zone3D_GetInstance(GameState::GetInstance());
    int total = 0;
    for (int i = 0; i < owner->count; i++) {
        Element02193290* elem = (Element02193290*)Zone3D_GetChest((unsigned char*)owner, i);
        if (elem == NULL) {
            continue;
        }
        Vector3i delta = *pos;
        Vector3i var5 = elem->position;
        if (fix32abs(delta.y - var5.y) > 0x1000) {
            continue;
        }
        delta.y = 0;
        var5.y = 0;
        Vector3fix_Subtract(&delta, &var5, &delta);
        if (inline_ov000_0216f3d4(delta.x) + inline_ov000_0216f3d4(delta.z) > 0x1000) {
            continue;
        }
        Struct_ov017_02193290 params;
        memset(&params, 0, sizeof(params));
        memcpy(&params.header, &data_ov017_021d6318, sizeof(Struct_ov017_021d6318));
        params.unknown_900_ = 8;
        params.unknown_904_ = 1;
        params.position = elem->position;
        params.unknown_918_ = elem->fieldC;
        int result = 0;
        total += func_ov017_02192b48(&params, a, 8, b, 1, c, pos, d, e, 1, &result, 0, i, f);
    }
    return total;
}
