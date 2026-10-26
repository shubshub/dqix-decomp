#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02048cf0 { int x; int y; };
extern "C" struct Struct_02048cf0 func_ov000_0216f74c(int* in);

// USA: func_ov025_021e1540
extern "C" ARM unsigned char func_ov025_021e1540(int index) {
    GameObject* obj = GameState::GetInstance()->GetGameObjectByIndex(index);
    int var1 = 0;
    if (obj != NULL) {
        Vector3fix origin = obj->obj3D_.position_;
        origin.y = 0;
        fix32_t var3 = 0x400000;
        int cell;
        for (cell = 0; cell < 0x51; cell++) {
            if (cell % 18 == 17) {
                continue;
            }
            Struct_02048cf0 pos = func_ov000_0216f74c(&cell);
            Vector3fix target = {0};
            target.x = pos.x;
            target.z = pos.y;
            fix32_t dist = Vector3fix_Distance(&origin, &target);
            if (dist < var3) {
                var1 = cell;
                var3 = dist;
            }
        }
    }
    return var1;
}
