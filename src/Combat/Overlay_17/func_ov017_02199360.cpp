#if defined(jpn)
enum { Enum_ov017_02199360_14008 = 0x34a8, Enum_ov017_02199360_14012 = 0x34ac, Enum_ov017_02199360_10100 = 0x27b4, Enum_ov017_02199360_10112 = 0x27c0, Enum_ov017_02199360_10120 = 0x27c8 };
#else
enum { Enum_ov017_02199360_14008 = 0x36b8, Enum_ov017_02199360_14012 = 0x36bc, Enum_ov017_02199360_10100 = 0x2774, Enum_ov017_02199360_10112 = 0x2780, Enum_ov017_02199360_10120 = 0x2788 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* state);
extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
struct PointerField32c_ffc0;
extern "C" void* GameState_GetShip(struct PointerField32c_ffc0* obj);
struct Vector3i;
extern "C" void func_02070378(char* obj);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);

// USA: func_ov017_02199360
extern "C" ARM void func_ov017_02199360(void* obj) {
    if (!*(unsigned char*)((char*)obj + Enum_ov017_02199360_14008)) return;

    GameState* battleStruct = GameState::GetInstance();
    void* state = LinkSession_GetInstance();
    void* base = Zone3D_GetInstance();
    void* src = *(void**)((char*)obj + Enum_ov017_02199360_14012);
    void* fieldPtr = GameState_GetZoneTransition(battleStruct);
    void* ptr32c = GameState_GetShip((struct PointerField32c_ffc0*)battleStruct);

    if (LinkSession_IsHostOrSolo(state)) {
        *(Vector3i*)((int*)((char*)base + Enum_ov017_02199360_10100)) = *(Vector3i const*)((int*)((char*)src + 0x40));
        *(int*)((char*)base + Enum_ov017_02199360_10112) = *(short*)((char*)src + 0x4c);
        func_02070378((char*)fieldPtr);
        *(short*)((char*)fieldPtr + 0x0) = 0x2710;
        ((char*)fieldPtr)[0x2] = 1;
        ((char*)fieldPtr)[0x7] = 1;
        *(Vector3i*)((int*)((char*)fieldPtr + 0x10)) = *(Vector3i const*)((int*)((char*)ptr32c + 0x44));
        *(short*)((char*)fieldPtr + 0x1c) = *(int*)((char*)ptr32c + 0x54);
        ((char*)base)[Enum_ov017_02199360_10120] = 1;
        func_ov017_021d1a18(1, -1, 1, 0);
    } else {
        func_02070378((char*)fieldPtr);
        *(short*)((char*)fieldPtr + 0x0) = 0x170c;
        ((char*)fieldPtr)[0x2] = 1;
        ((char*)fieldPtr)[0x7] = 1;
        *(int*)((char*)fieldPtr + 0x10) = -0x7000;
        *(int*)((char*)fieldPtr + 0x14) = 0x2e1;
        *(int*)((char*)fieldPtr + 0x18) = 0x5e66;
        *(short*)((char*)fieldPtr + 0x1c) = 0x3244;
    }
}
