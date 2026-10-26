#include <globaldefs.h>
#include "GameState/GameState.h"

struct Param021e8100 {
    char pad[0x8];
    unsigned short duration;
    short strength;
};

void Camera_Shake(unsigned char* obj, int a, int b);

// USA: func_ov025_021e8100  (semantic: Trans_021e8100)
extern "C" ARM int func_ov025_021e8100(Param021e8100* p) {
    unsigned char* camera = (unsigned char*)GameState::GetInstance()->GetCamera();
    if (camera != 0) {
        Camera_Shake(camera, p->strength, p->duration);
    }
    return 1;
}
