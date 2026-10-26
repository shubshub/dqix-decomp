#include <globaldefs.h>

extern "C" int func_ov011_02184324(int);

struct Struct_ov011_02184354 { char pad[0x1c]; int next; };

// USA: func_ov011_02184354
extern "C" ARM int func_ov011_02184354(Struct_ov011_02184354* obj, int val) {
    int next = obj->next;
    if (next == 0) {
        obj->next = val;
        return (int)obj;
    }
    return func_ov011_02184324(next);
}
