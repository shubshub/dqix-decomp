#include <globaldefs.h>
#include "Resource/GameResources.h"

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" int _s32_div_f(int a, int b);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);

// USA: func_ov011_02187854
extern "C" ARM int func_ov011_02187854(struct TaggedNumber02184c30* arg0) {
    GameResources* target = GetGameResources();
    int value = func_ov011_02184c30(arg0);
    struct TaggedNumber02184c30* second = (struct TaggedNumber02184c30*)((char*)arg0 + 0x8);
    int frames = _s32_div_f(func_ov011_02184c30(second), 0x22);
    SetMainBrightness(target, value, frames);
    return 1;
}
