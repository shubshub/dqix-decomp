#include <globaldefs.h>
#include "GameState/GameState.h"

int MessageSystem_GetInstance(void);
struct Obj0217e334;
void InitObj0217e334(struct Obj0217e334* self);
struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

// USA: func_ov003_0217e300  (semantic: InitAndAppendNode_0217e300)
extern "C" ARM void func_ov003_0217e300(char* obj) {
    GameState::GetInstance()->GetProtagonist();
    MessageSystem_GetInstance();
#if defined(jpn)
    enum { nodeOffset = 0x3520, listOffset = 0x34ec };
#else
    enum { nodeOffset = 0x3730, listOffset = 0x36fc };
#endif
    InitObj0217e334(*(struct Obj0217e334**)(obj + nodeOffset));
    AppendNodeToTail(*(struct TailList020469b4**)(obj + listOffset), *(struct TailNode020469b4**)(obj + nodeOffset));
}
