#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_0216d370(char* obj, int flagA, int flagB, int flagC);
void SetFlagOrState0216d530(void*, int);
void Camera_SetOrbitVector(void* obj, int* vec);

extern Vector3i data_ov000_02183280;

// USA: func_ov000_0216dbf0
extern "C" ARM void func_ov000_0216dbf0(char* arg0, int* arg1, int arg2, short arg3) {
    func_ov000_0216d370(arg0, 1, 1, 1);
    *(unsigned char*)(arg0 + 0x220) = 3;

    Vector3i var0 = data_ov000_02183280;
    Vector3i var1;
    var1.x = 0x5e38;

    GameState* var2 = GameState::GetInstance();

    int var3 = 0;
    int var4 = 0;
    int var5 = 0x2000;

    if (arg2 == 1) {
        GameObject* var6 = var2->GetGameObjectByIndex(*arg1);
        if (var6 != 0) {
            func_ov000_0216d530(arg0, *arg1);
            var4 = var6->obj3D_.GetRadius() >> 1;
            var5 = var6->obj3D_.GetHeight();
        }
    } else {
        for (int var7 = 0; var7 < arg2; var7++, arg1++) {
            GameObject* var8 = var2->GetGameObjectByIndex(*arg1);
            if (var8 != 0) {
                Vector3i var9 = var8->obj3D_.position_;
                int var10 = Vector3fix_Length(&var9);
                if (var3 < var10) {
                    var3 = var10;
                    var4 = var8->obj3D_.GetRadius() >> 1;
                }
                if (var5 < var8->obj3D_.GetHeight()) {
                    var5 = var8->obj3D_.GetHeight();
                }
            }
        }
    }

    var0.y = var5 >> 1;
    var1.y = 0x1000;
    int var11 = (int)((((unsigned long long)((long long)(var3 + var4) * 0x3000)) + 0x800ULL) >> 12);
    int var12 = (int)((((unsigned long long)((long long)var5 * 0x3000)) + 0x800ULL) >> 12);

    if (var12 < var11) {
        var1.z = var11;
    } else {
        var1.z = var12;
    }

    if (!(arg3 != 0)) {
        var1.y = 0x1000;
        if (var1.z < 0x7000) {
            var1.z = 0x7000;
        } else if (var1.z > 0x10000) {
            var1.y = var1.y + (var1.z - 0x10000) / 2;
        }
    } else {
        var0.y = 0xb85;
        var1.y = 0x3999;
        if (var1.z < 0xe000) {
            var1.z = 0xe000;
        }
    }

    *(Vector3i*)(self + 0x10) = c;
    Camera_SetOrbitVector(self, (int*)&v);
    *(int*)(self + 0x238) = 0x1c;
    *(int*)(self + 0x23c) = 0x14;
}
