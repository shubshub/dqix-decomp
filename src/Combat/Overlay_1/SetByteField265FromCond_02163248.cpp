#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_02163248
ARM int SetByteField265FromCond_02163248(void* obj) {
    unsigned char* battleStruct = (unsigned char*)GameState::GetInstance()->GetCamera();
    if (battleStruct == NULL) return 1;
    *(unsigned char*)((char*)battleStruct + 0x265) = (func_ov017_021d60f4(obj) == 0);
    return 1;
}
