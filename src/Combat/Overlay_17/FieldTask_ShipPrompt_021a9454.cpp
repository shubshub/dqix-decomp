#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { TextBufferPointer = 0x28, MessageStatus = 0x868, PendingMessage = 0x870, MessageFlag = 0x7e2 };
#else
enum { TextBufferPointer = 0x5c, MessageStatus = 0x998, PendingMessage = 0x9a0, MessageFlag = 0x9b2 };
#endif

struct PointerField32c_ffc0;
struct ResetObj020d7a5c;
struct Obj020d7aa0;

struct ZoneTransitionMessageController {
    char unknown0[TextBufferPointer];
    char* textBuffer;
    char unknownAfterBuffer[MessageStatus - TextBufferPointer - sizeof(char*)];
    int status;
    int mode;
    int pendingMessage;
    char unknownAfterPending[0x1000 + MessageFlag - PendingMessage - sizeof(int)];
    unsigned char messageFlag;
};

struct ZoneTransitionRequest {
    unsigned char unknown0;
    unsigned char done;
    char unknown2[6];
    int state;
    int zoneId;
    int alternateDestination;
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

ZoneTransitionMessageController* MessageSystem_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
int GetFieldIfFlag4_020100f8(char* obj);
struct ResetObj020d7a5c* TextQueue_GetInstance(void);
void TextQueue_Reset(struct Obj020d7aa0* obj);
void* GetPointerAt0x32c_0200ffc0(struct PointerField32c_ffc0* obj);
void ClearByteFlagAt0x154_020a7f40(unsigned char* obj);
int StandardStrings_Get(int value);
extern "C" int sprintf(char* dst, const char* fmt, ...);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
extern char data_ov017_021d7c28;
extern char data_ov017_021d7c49;
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
extern "C" int func_020457e0(void* obj);
void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);
extern "C" void VectorizedMemset(void*, int, int);
void MessageSystem_Reset(char* obj);
void SetByteFlagAt0x154_020a7f34(unsigned char* obj);

// Overlay 17, originally func_ov017_021a9454 (USA/EUR 0x021a9454, JPN 0x021a9c34)
extern "C" ARM void FieldTask_ShipPrompt(ZoneTransitionRequest* request) {
    GameState* battleStruct = GameState::GetInstance();
    ZoneTransitionMessageController* controller = MessageSystem_GetInstance();
    Zone3D_GetInstance();
    int field = GetFieldIfFlag4_020100f8((char*)battleStruct);
    int status = request->state;

    if (status == 0) {
        struct ResetObj020d7a5c* reset = TextQueue_GetInstance();
        TextQueue_Reset((struct Obj020d7aa0*)reset);
        void* p = GetPointerAt0x32c_0200ffc0((struct PointerField32c_ffc0*)battleStruct);
        ClearByteFlagAt0x154_020a7f40((unsigned char*)p);

        int flag10 = request->alternateDestination;
        char* buf = controller->textBuffer;
        if (flag10 == 0) {
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
        controller->messageFlag = 0;
        controller->status = 1;
        SetFlagsAt0x244_020a28a0((unsigned char*)field, 2);
        request->state = 1;
        return;
    }

    if (status != 1 || controller->pendingMessage != 0) return;

    ClearFlagBits_020a28b0((unsigned char*)field, 2);
    if (func_020457e0(controller) == 0) {
        GetPointerAt0x32c_0200ffc0((struct PointerField32c_ffc0*)battleStruct);
        ZoneTransitionSettings* settings = (ZoneTransitionSettings*)GetField0x3f8Address_0200fd0c(battleStruct);
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

        if (request->alternateDestination == 0) {
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
    void* p = GetPointerAt0x32c_0200ffc0((struct PointerField32c_ffc0*)battleStruct);
    SetByteFlagAt0x154_020a7f34((unsigned char*)p);
    request->done = 1;
}
