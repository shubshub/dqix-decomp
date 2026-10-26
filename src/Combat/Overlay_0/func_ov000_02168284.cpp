#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x79de
#define REGION_OFFSET_1 0x79c6
#else
#define REGION_OFFSET_0 0x77ee
#define REGION_OFFSET_1 0x77d6
#endif

#include "Filesystem/BackgroundLoader.h"

struct Struct_ov000_02168284 { short field0; short unknown_2_; short unknown_4_; };

// USA: func_ov000_02168284
extern "C" ARM void func_ov000_02168284(void* obj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int i = 0;
    while (i < ((unsigned char*)obj)[REGION_OFFSET_0]) {
        struct Struct_ov000_02168284* entries = (struct Struct_ov000_02168284*)((unsigned char*)obj + REGION_OFFSET_1);
        struct Struct_ov000_02168284* e = &entries[i];
        if (e->unknown_2_ >= 0) loader->RemoveTask(e->unknown_2_);
        if (e->unknown_4_ >= 0) loader->RemoveTask(e->unknown_4_);
        i++;
    }
}
