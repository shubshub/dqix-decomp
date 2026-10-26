#include <globaldefs.h>

#include "Resource/TextQueue.h"
#if defined(jpn)
enum { Enum_02052bfc_336 = 0x144, Enum_02052bfc_1788 = 0x4ec };
extern int data_020f0420[];
#else
enum { Enum_02052bfc_336 = 0x150, Enum_02052bfc_1788 = 0x6fc };
#endif

#if defined(jpn)
#define func_02052bfc func_02053fd8
#endif
#include "GameState/GameState.h"
#include "NitroSDK/Timing.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct ArrayContainsByteStruct;

struct Struct_0201bc94_2 {
    unsigned char unknown_0_0_ : 4;
    unsigned char flag4 : 1;
    unsigned char unknown_0_5_ : 3;
};

struct Struct0201bc94 {
    unsigned short field0;
    unsigned short field2;
    unsigned short field4;
    unsigned short field6;
    Struct_0201bc94_2* field8;
};

struct Struct_02052bfc {
    char pad0[0x480];
    uint64_t unknown_480_;
    char pad1[0x56c - 0x488];
    unsigned char unknown_56c_;
    unsigned char unknown_56d_;
};

struct Struct_02052bfc_2 {
    char pad0[4];
    short field4;
    char pad1[Enum_02052bfc_336 - 6];
    Struct_02052bfc* field150;
};

extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void* GameState_GetParty(GameState*);
extern "C" void* Zone3D_GetInstance(void);
extern "C" long long _ll_udiv(long long a, long long b);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" int func_0201bc94(Struct0201bc94* obj);
extern "C" int StandardStrings_Get(int value);
extern "C" void* TextQueue_GetInstance(void);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
extern "C" void func_ov017_021ce014(int a, unsigned short b, unsigned short c, unsigned short d);

// USA: func_02052bfc
extern "C" ARM void func_02052bfc(struct Struct_02052bfc_2* obj) {
    if (obj->field150 == NULL) return;

    GameState* gs = GameState::GetInstance();
    GameResources* ov = GetGameResources();
    void* list = *(void**)((char*)ov + 0x3000 + Enum_02052bfc_1788);
    ArrayContainsByteStruct* arr = (ArrayContainsByteStruct*)GameState_GetParty(gs);
    Struct0201bc94* entry = (Struct0201bc94*)Zone3D_GetInstance();
    unsigned char idx = obj->field4 & 0xff;

    if (!func_02086ef0(arr, idx)) return;
    if (obj->field150->unknown_56c_ == 0) return;

    uint64_t diff = GetCurrentTimestamp() - obj->field150->unknown_480_;
    long long elapsed = _ll_udiv(diff << 6, 0x1ff6210);

    if (!FieldTaskQueue_IsEmpty((void**)list)) return;
    if (elapsed < 0x12c && func_0201bc94(entry)) return;

    char buf[0x80];
    obj->field150->unknown_56c_ = 0;
    if (idx == *(short*)((char*)gs->GetLeader() + 4)) {
        if (obj->field150->unknown_56d_ != 0) {
            #if defined(jpn)
            strcpy(buf, (char*)data_020f0420[1]);
#else
            strcpy(buf, (char*)StandardStrings_Get(0x33));
#endif
        }
        else {
            #if defined(jpn)
            strcpy(buf, (char*)data_020f0420[5]);
#else
            strcpy(buf, (char*)StandardStrings_Get(0x32));
#endif
        }
        #if defined(jpn)
        TextQueue_Push(TextQueue_GetInstance(), buf, 0, 0, 1);
#else
        TextQueue_Push(TextQueue_GetInstance(), buf, 0, 0, 1, 1);
#endif
    }
    func_ov017_02191aac((char*)ov, 0, idx, 2);
    func_ov017_021ce014(0, 1, 0, idx);
}
