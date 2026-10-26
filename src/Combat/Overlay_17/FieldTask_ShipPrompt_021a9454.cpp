#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov017_021a9454_92 = 0x28, Enum_ov017_021a9454_2456 = 0x868, Enum_ov017_021a9454_2464 = 0x870, Enum_ov017_021a9454_2482 = 0x7e2 };
#else
enum { Enum_ov017_021a9454_92 = 0x5c, Enum_ov017_021a9454_2456 = 0x998, Enum_ov017_021a9454_2464 = 0x9a0, Enum_ov017_021a9454_2482 = 0x9b2 };
#endif

struct PointerField32c_ffc0;
struct ResetObj020d7a5c;
struct Obj020d7aa0;

struct ZoneTransitionMessageController {
    char unknown0[Enum_ov017_021a9454_92];
    char* textBuffer;
    char unknown_60_[Enum_ov017_021a9454_2456 - Enum_ov017_021a9454_92 - sizeof(char*)];
    int status;
    int mode;
    int unknown_9a0_;
    char unknown_9a4_[0x1000 + Enum_ov017_021a9454_2482 - Enum_ov017_021a9454_2464 - sizeof(int)];
    unsigned char unknown_19b2_;
};

struct ZoneTransitionRequest {
    unsigned char unknown0;
    unsigned char done;
    char unknown2[6];
    int state;
    int zoneId;
    int unknown_10_;
};

struct ZoneTransitionSettings {
    short zoneId;
    unsigned char unknown2;
    unsigned char unknown3;
    unsigned char unknown4;
    unsigned char unknown5;
    unsigned char unknown6;
    unsigned char applyPosition;
    unsigned char unknown8;
    unsigned char unknown9;
    unsigned char unknownA;
    signed char unknownB;
    unsigned char unknownC;
    char unknownD[3];
    Vector3i position;
    short heading;
    short unknown1E;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown2C;
    char unknown30[0x6c - 0x30];
    short nodeId;
    char unknown6E[2];
};

extern "C" ZoneTransitionMessageController* MessageSystem_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" struct ResetObj020d7a5c* TextQueue_GetInstance(void);
extern "C" void TextQueue_Reset(struct Obj020d7aa0* obj);
extern "C" void* GameState_GetShip(struct PointerField32c_ffc0* obj);
extern "C" void func_020a7f40(unsigned char* obj);
extern "C" int StandardStrings_Get(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
extern char data_ov017_021d7c28;
extern char data_ov017_021d7c49;
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void func_020a28b0(unsigned char* obj, int mask);
extern "C" int func_020457e0(void* obj);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" void VectorizedMemset(void*, int, int);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_020a7f34(unsigned char* obj);

// Overlay 17, originally func_ov017_021a9454 (USA/EUR 0x021a9454, JPN 0x021a9c34)
extern "C" ARM void FieldTask_ShipPrompt(ZoneTransitionRequest* request) {
    GameState* battleStruct = GameState::GetInstance();
    ZoneTransitionMessageController* controller = MessageSystem_GetInstance();
    Zone3D_GetInstance();
    int field = GameState_GetFollowCamera((char*)battleStruct);
    int status = request->state;

    if (status == 0) {
        struct ResetObj020d7a5c* reset = TextQueue_GetInstance();
        TextQueue_Reset((struct Obj020d7aa0*)reset);
        void* p = GameState_GetShip((struct PointerField32c_ffc0*)battleStruct);
        func_020a7f40((unsigned char*)p);

        int var6 = request->unknown_10_;
        char* buf = controller->textBuffer;
        if (var6 == 0) {
#if defined(jpn)
            sprintf(buf, &data_ov017_021d7c28);
#else
            sprintf(buf, (const char*)StandardStrings_Get(0x3a));
#endif
        } else {
#if defined(jpn)
            sprintf(buf, &data_ov017_021d7c49);
#else
            sprintf(buf, (const char*)StandardStrings_Get(0x3b));
#endif
            request->zoneId = 0x170c;
        }
#if defined(jpn)
        func_0204500c(controller, buf, 0);
#else
        func_0204500c(controller, buf, 0, 0xe3);
#endif
        controller->unknown_19b2_ = 0;
        controller->status = 1;
        func_020a28a0((unsigned char*)field, 2);
        request->state = 1;
        return;
    }

    if (status != 1 || controller->unknown_9a0_ != 0) return;

    func_020a28b0((unsigned char*)field, 2);
    if (func_020457e0(controller) == 0) {
        GameState_GetShip((struct PointerField32c_ffc0*)battleStruct);
        ZoneTransitionSettings* settings = (ZoneTransitionSettings*)GameState_GetZoneTransition(battleStruct);
        VectorizedMemset(settings, 0, sizeof(*settings));
        settings->unknown4 = 1;
        settings->unknown8 = 1;
        settings->unknown9 = 1;
        settings->unknownB = -1;
        settings->unknown20 = -1;
        settings->unknown24 = -1;
        settings->unknown28 = -1;
        settings->unknown2C = -1;
        settings->unknown1E = -1;
        settings->unknownC = 0;
        settings->nodeId = -1;
        settings->zoneId = (short)request->zoneId;
        settings->unknown2 = 1;
        settings->applyPosition = 1;

        if (request->unknown_10_ == 0) {
            settings->position.x = 0x100000;
            settings->position.y = 0;
            settings->position.z = 0x100000;
            settings->heading = 0;
        } else {
            settings->position.x = 0x5f0a;
            settings->position.y = 0x3614;
            settings->position.z = 0x570;
            settings->heading = 0x4b66;
        }
        MessageSystem_Reset((char*)controller);
        request->done = 1;
        return;
    }

    MessageSystem_Reset((char*)controller);
    void* p = GameState_GetShip((struct PointerField32c_ffc0*)battleStruct);
    func_020a7f34((unsigned char*)p);
    request->done = 1;
}
