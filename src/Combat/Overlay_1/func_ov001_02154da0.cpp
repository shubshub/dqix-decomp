#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_020708c8;

extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
extern "C" void* func_020704fc(void);
extern "C" void func_020708c8(struct Struct_020708c8* obj, unsigned int value);
struct GameResources;
void SetBrightness(GameResources*, int, int);

#if defined(jpn)
enum { Enum_ov001_02154da0_6590 = 0x17ee };
#else
enum { Enum_ov001_02154da0_6590 = 0x19be };
#endif

// USA: func_ov001_02154da0
extern "C" ARM void func_ov001_02154da0() {
    char* obj = (char*)MessageSystem_GetInstance();
    MessageSystem_Reset(obj);
    MessageSystem_Stop(obj);
    *(unsigned char*)(obj + Enum_ov001_02154da0_6590) = 0;
    func_020708c8((struct Struct_020708c8*)func_020704fc(), 0);
    SetBrightness(GetGameResources(), -16, 0);
}
