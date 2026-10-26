#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" ARM int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" void* func_ov017_021b2164(void);
extern "C" void func_ov011_02184a40(void* a, int b);

// USA: func_ov011_02186808
extern "C" ARM int func_ov011_02186808(struct TaggedNumber02184c30* v) {
    int count = func_ov011_02184c30(v);
    if (count <= 0) return 0;
    func_ov011_02184a40(func_ov017_021b2164(), count);
    return 1;
}
