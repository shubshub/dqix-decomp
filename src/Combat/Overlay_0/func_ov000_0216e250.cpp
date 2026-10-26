#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Util/Random.h"

extern "C" void __clear(void* arg0, int arg1);
extern "C" void func_ov000_0216d370(void* arg0, int arg1, int arg2, int arg3);
extern "C" void Vector3fix_Add(const Vector3fix* arg0, const Vector3fix* arg1, Vector3fix* arg2);

struct Struct_ov000_0216e250 {
    int unknown_0_, unknown_4_, unknown_8_;
};
struct Obj02049b54;
struct Triple0216e250 GetSubTriple02049b54(struct Obj02049b54* obj);
void Camera_SetOrbitVector(void* obj, int* vec);

extern int data_ov000_0218323c[];
extern int data_ov000_02183244[];
extern int data_ov000_0218324c[];
extern int data_ov000_02183254[];

struct Struct_ov000_0216e250_2 {
    char unknown_0_[0x10];
    Vector3i unknown_10_;
    char unknown_1c_[0x21c - 0x1c];
    struct Random* unknown_21c_;
    char unknown_220_[0x238 - 0x220];
    int unknown_238_;
};

// USA: func_ov000_0216e250
extern "C" ARM void func_ov000_0216e250(struct Struct_ov000_0216e250_2* arg0, int* arg1, int arg2) {
    if (arg2 <= 0) return;

    func_ov000_0216d370(arg0, 1, 1, 1);
    GameState* var0 = GameState::GetInstance();
    Vector3i var1;
    __clear(&var1, sizeof(var1));
    for (int var2 = 0; var2 < arg2; var2++) {
        GameObject* var3 = var0->GetCombatantByIndex(arg1[var2]);
        if (var3 != NULL) {
            struct Struct_ov000_0216e250 var4 = func_02049b54((struct Struct_02049b54_2*)var3);
            Vector3fix_Add(&var1, (Vector3fix*)&var4, &var1);
        }
    }
    Vector3fixMultiplyScalar(&var1, (int)(4096.0f * (1.0f / (float)arg2)), &var1);
    var1.y += 0x18cc;

    int var5 = 0;
    if (var0->GetCombatantByIndex(arg1[0])->obj3D_.unknown_0_ & 0x400) var5 = 1;
    int var6;
    int var7;
    if (var5 == 0) {
        int var8 = NextRandomMax(arg0->unknown_21c_, 2);
        var6 = data_ov000_02183244[var8];
        var7 = data_ov000_0218324c[var8];
    } else {
        int var9 = NextRandomMax(arg0->unknown_21c_, 2);
        var6 = data_ov000_02183254[var9];
        var7 = data_ov000_0218323c[var9];
    }
    int vec[3];
    vec[0] = a;
    vec[1] = 0;
    vec[2] = 0x9000;
    obj->position = center;
    Camera_SetOrbitVector(obj, vec);
    obj->field238 = b;
}
