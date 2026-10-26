#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void func_ov011_02184bf0(void*, int, int);

// USA: func_ov011_02187f04
extern "C" ARM int func_ov011_02187f04(struct TaggedNumber02184c30* a) {
    int x = func_ov011_02184c30(a);
    int y = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    func_ov011_02184bf0(func_ov017_021b2164(), x, y);
    return 1;
}
