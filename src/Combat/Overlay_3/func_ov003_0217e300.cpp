#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance(void);
struct Struct_ov003_0217e300;
extern "C" void func_ov003_0217e334(struct Struct_ov003_0217e300* self);
struct TailNode020469b4;
struct TailList020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov003_0217e300
extern "C" ARM void func_ov003_0217e300(char* obj) {
    GameState::GetInstance()->GetProtagonist();
    MessageSystem_GetInstance();
#if defined(jpn)
    enum { Enum_ov003_0217e300_14128 = 0x3520, listOffset = 0x34ec };
#else
    enum { Enum_ov003_0217e300_14128 = 0x3730, listOffset = 0x36fc };
#endif
    func_ov003_0217e334(*(struct Struct_ov003_0217e300**)(obj + Enum_ov003_0217e300_14128));
    func_020469b4(*(struct TailList020469b4**)(obj + listOffset), *(struct TailNode020469b4**)(obj + Enum_ov003_0217e300_14128));
}
