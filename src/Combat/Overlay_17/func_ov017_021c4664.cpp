#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c4664 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
    short unknown_8_;
    float unknown_c_;
};

struct Struct_ov017_021c4664_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021c4664 unknown_4_;
};

// USA: func_ov017_021c4664
extern "C" ARM void func_ov017_021c4664(int mapId, Vector3i pos, short param) {
    GameState* battleStruct = GameState::GetInstance();
    void* data = LinkMessageQueue_GetInstance();
    Evt021c4664 evt;
    Payload021c4664* p = &evt.payload;
    evt.tag = 0x36;
    p->mapId = mapId;
    p->x = pos.x >> 10;
    p->y = pos.y >> 10;
    p->z = pos.z >> 10;
    p->param = param;
    p->dayTimer = battleStruct->GetDayTimer();
    func_0205e330(data, &evt, 0);
}
