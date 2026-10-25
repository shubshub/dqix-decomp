#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov001_02158f64(void* arg0, Struct_ov001_02158efc arg1, Struct_ov001_02158efc arg2, int arg3, int arg4, int arg5);

struct Struct_ov001_02165880_33 { char unknown_0_[0x24]; void* unknown_24_; };
extern Struct_ov001_02165880_33 data_ov001_02165880 __attribute__((aligned(4)));

static inline int inline_ov001_0215dbd0(int arg0, int arg1) {
    return (int)(((long long)arg0 * arg1 + 0x800) >> 12);
}

// USA: func_ov001_0215dbd0
extern "C" ARM int func_ov001_0215dbd0(void* arg0) {
    GameState* var0 = GameState::GetInstance();
    Struct_ov001_02158efc var1;
    memset(&var1, 0, 0xc);
    Struct_ov001_02158efc var2;
    memset(&var2, 0, 0xc);
    var2.unknown_0_ = (int)(4096.0f * func_ov017_021d6110(arg0));
    var2.unknown_4_ = (int)(4096.0f * func_ov017_021d6110((char*)arg0 + 0x8));
    var2.unknown_8_ = (int)(4096.0f * func_ov017_021d6110((char*)arg0 + 0x10));

    Vector3fix polar = *(Vector3fix*)((char*)gs->GetCamera() + 0x70);
    Vector3fix offset;
    offset.x = 0;
    offset.y = polar.y;
    offset.z = fix32_Sqrt(FixedMulRound_0215dbd0(polar.z, polar.z) - FixedMulRound_0215dbd0(polar.y, polar.y));

    Matrix4x3 var5 = RotationMatrixY(var3.x);
    Mat4x3_ApplyToVector(&var4, &var5, &var4);
    Vector3fix_Add((Vector3fix*)&var2, &var4, (Vector3fix*)&var1);

    int var6 = func_ov017_021d60f4((char*)arg0 + 0x18);
    func_ov001_02158f64(data_ov001_02165880.unknown_24_, var1, var2, var6, 1, 0);
    return 1;
}
