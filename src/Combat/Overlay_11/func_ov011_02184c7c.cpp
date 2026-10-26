#include <globaldefs.h>
#include "Resource/GameResources.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct GameResources;

void SetBrightness(struct GameResources* resources, int brightness, int duration);
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

// USA: func_ov011_02184c7c
extern "C" ARM int func_ov011_02184c7c(struct TaggedNumber02184c30* params, int count) {
    struct GameResources* resources = GetGameResources();
    int brightness = func_ov011_02184c30(&params[0]);
    SetBrightness(resources, brightness, func_ov011_02184c30(&params[1]) / 34);
    return 1;
}
