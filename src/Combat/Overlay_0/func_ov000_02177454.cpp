#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov000_0217c638(void* obj, int a, int b);
extern "C" void func_ov000_021775a4(void* obj, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov000_02177454 {
    char pad[0x44];
    int x;
    int y;
};

// USA: func_ov000_02177454
extern "C" ARM void func_ov000_02177454(void* objRaw, struct Struct_ov000_02177454* in, int arg2, int arg3) {
    char* obj = (char*)objRaw;
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    func_ov000_0217c638(obj, arg2, arg3);
    char* s = obj + 0x188;
    *(short*)(s + 0xa0) = 0xa;
    *(short*)(s + 0xa2) = 7;
    *(short*)(s + 0xa4) = (x >> 3) + 9;
    *(short*)(s + 0xa6) = (y >> 3) + 1;
    *(short*)(s + 0xa8) = 0xc;
    *(short*)(s + 0xaa) = 7;
    *(short*)(s + 0xac) = 0xa;
    *(short*)(s + 0xae) = 0xd;
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        if (GameState_GetProtagonistIndex(GameState::GetInstance()) == 0) {
            *(short*)(s + 0xa8) = 0xc;
            *(short*)(s + 0xaa) = 4;
            *(short*)(s + 0xac) = 0xa;
            *(short*)(s + 0xae) = 0xb;
        }
    }
    *(unsigned char*)(s + 0xb1) = 2;
#if defined(jpn)
    void* buf = *(void**)((char*)MessageSystem_GetInstance() + 0x28);
#else
    void* buf = *(void**)((char*)MessageSystem_GetInstance() + 0x5c);
#endif
#if defined(jpn)
    memset(buf, 0, 0x800);
#else
    memset(buf, 0, 0x960);
#endif
    func_ov000_021775a4(obj, buf);
#if defined(jpn)
    Window_OpenPane(s, buf, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(s, buf, 0, 1, 0, 1, 0, 0);
#endif
}
