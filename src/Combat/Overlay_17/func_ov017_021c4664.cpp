#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c4664 {
    short mapId;
    short x;
    short y;
    short z;
    short param;
    float dayTimer;
};

struct Struct_ov017_021c4664_2 {
    unsigned char tag;
    unsigned char pad1[3];
    Struct_ov017_021c4664 payload;
};

// USA: func_ov017_021c4664
extern "C" ARM void func_ov017_021c4664(int mapId, Vector3i pos, short param) {
    GameState* battleStruct = GameState::GetInstance();
    void* data = LinkMessageQueue_GetInstance();
    Struct_ov017_021c4664_2 evt;
    Struct_ov017_021c4664* p = &evt.payload;
    evt.tag = 0x36;
    p->mapId = mapId;
    p->x = pos.x >> 10;
    p->y = pos.y >> 10;
    p->z = pos.z >> 10;
    p->param = param;
    p->dayTimer = battleStruct->GetDayTimer();
    func_0205e330(data, &evt, 0);
}
