#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094;

extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
extern "C" int func_ov017_02191b58(void*, int);
typedef int (*Type_ov025_021e8670)(void*, int);
extern "C" void func_ov017_0219230c(void* a, int b, int c);
extern "C" void func_ov017_02192400(void* a, int b);

// USA: func_ov025_021e8670
extern "C" ARM int func_ov025_021e8670(void* unused0, struct Struct_ov000_0215440c_2* list) {
    void* w = GetGameResources();
    struct Struct_ov000_02160094* node = func_ov000_02160094(list, 0);
    int lvl = *(unsigned short*)((char*)node + 0x20);
    int inRange = (lvl >= 0 && lvl <= 3);
    if (inRange && (((Type_ov025_021e8670)&func_ov017_02191b58)(w, lvl) & 2)) {
        func_ov017_0219230c(w, lvl, 8);
        return 1;
    }
    func_ov017_02192400(w, lvl);
    return 1;
}
