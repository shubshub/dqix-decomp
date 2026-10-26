#include <globaldefs.h>

#if defined(jpn)
enum { kListOffset = 0x34ec, Enum_020ad4c4_10164 = 0x27f4 };
#else
enum { kListOffset = 0x36fc, Enum_020ad4c4_10164 = 0x27b4 };
#endif

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" int func_0201bd74(void* obj, int threshold, int zero);

struct Struct_020ad4c4 {
    unsigned short field0;
};

// USA: func_020ad4c4
extern "C" ARM int func_020ad4c4(struct Struct_020ad4c4* obj) {
    GameState* battleStruct = GameState::GetInstance();
    int base = ((int)GetGameResources());
    struct ListHead02046b60* list = *(struct ListHead02046b60**)(base + kListOffset);
    if (func_02046b60(list, 4)) {
        return 0;
    }

    int mode = 0;
    int threshold = 0;
    if (obj->field0 == 0x1198) {
        mode = 1;
        threshold = 7;
    } else if (obj->field0 == 0x1198 - 0xcb) {
        mode = 3;
        threshold = 2;
    } else if (obj->field0 == 0x1198 - 0x68) {
        if (GameState_GetStoryChapter((char*)battleStruct) >= 0x13) {
            return 0;
        }
        mode = 5;
        threshold = 0x17;
    }

    if (mode == 0 || threshold == 0) {
        goto ret0;
    }
    if (*(unsigned short*)((char*)obj + Enum_020ad4c4_10164) == mode) {
        return (func_0201bd74(obj, threshold, 0) == 0) ? 1 : 0;
    }
    return func_0201bd74(obj, threshold, 0);

ret0:
    return 0;
}
