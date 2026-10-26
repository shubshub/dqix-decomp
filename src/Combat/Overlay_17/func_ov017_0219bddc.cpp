#if defined(jpn)
enum { Enum_ov017_0219bddc_2112 = 0x860 };
#else
enum { Enum_ov017_0219bddc_2112 = 0x840 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"


extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
struct Struct_020ad4c4;
extern "C" int func_020ad4c4(struct Struct_020ad4c4* obj);
extern "C" int func_02098080(void* p);
struct U16Field0x6_020375f8;
extern "C" int func_0206e558(void* obj);
extern "C" int func_ov017_0219c774(int a, int b, int c);

// USA: func_ov017_0219bddc
extern "C" ARM int func_ov017_0219bddc(unsigned char* p0) {
    GetGameResources();
    GameState* bs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    void* obj8 = Scenario_GetInstance();
    void* obj4 = Zone3D_GetInstance();
    GameObject* var4 = bs->GetGameObjectByIndex(0);
    GameObject* c6 = bs->GetProtagonist();

    if (LinkSession_IsHostOrSolo(search) != 0) {
        return 0;
    }
    if (var4 == NULL) {
        return 0;
    }
    if (c6 == NULL) {
        return 0;
    }

    int result = 0;
    if (func_020ad4c4((struct Struct_020ad4c4*)obj4) != 0) {
        result = 1;
        goto end;
    }
    if (func_02098080((char*)obj4 + Enum_ov017_0219bddc_2112) != 0) {
        result = 1;
        p0[0] = (unsigned char)result;
        goto end;
    }

    unsigned short v1 = ((Object3D*)((struct U16Field0x6_020375f8*)var4))->GetField06();
    unsigned short v2 = ((Object3D*)((struct U16Field0x6_020375f8*)c6))->GetField06();
    if (v1 != v2) {
        return result;
    }

    if (func_0206e558(obj8) != 0) {
        result = 1;
    }
    if (func_ov017_0219c774(*(int*)((char*)obj4 + 8), 0, 0) != 0) {
        result = 1;
    }

end:
    return result;
}
