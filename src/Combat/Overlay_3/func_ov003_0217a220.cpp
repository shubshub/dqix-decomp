#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0217a220_4163 = 0xfbf };
enum { Enum_ov003_0217a220_2204 = 0x818 };
enum { Enum_ov003_0217a220_4110 = 0xf8a };
enum { Enum_ov003_0217a220_4154 = 0xfb6 };
#else
enum { Enum_ov003_0217a220_4163 = 0x1043 };
enum { Enum_ov003_0217a220_2204 = 0x89c };
enum { Enum_ov003_0217a220_4110 = 0x100e };
enum { Enum_ov003_0217a220_4154 = 0x103a };
#endif

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" short func_02080468(void* obj, int id);

// USA: func_ov003_0217a220
extern "C" ARM void func_ov003_0217a220(unsigned char* obj) {
    short result = -1;
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetPartyMemberByIndex(*(signed char*)(obj + Enum_ov003_0217a220_4163));
    if (c != NULL) {
        unsigned char* base = (unsigned char*)func_02053c6c((unsigned char*)c);
        short id = func_02080468(*(void**)(obj + Enum_ov003_0217a220_2204), 0x15);
        short diff = *(short*)(obj + Enum_ov003_0217a220_4110) - id;
        result = *(short*)(base + diff * 2 + 0x400 + 0x54);
    }
    *(short*)(obj + Enum_ov003_0217a220_4154) = result;
}
