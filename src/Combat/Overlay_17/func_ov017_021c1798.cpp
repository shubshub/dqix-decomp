#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void func_ov017_021c17cc(void* obj);
struct Node02046a3c;
struct List02046a3c;
extern "C" void func_02046a3c(struct List02046a3c* list, struct Node02046a3c* node);

// USA: func_ov017_021c1798
extern "C" ARM void func_ov017_021c1798(GameResources* self, unsigned char value) {
#if defined(jpn)
    enum { regionalOffset0 = 0x934, regionalOffset1 = 0x4ec };
#else
    enum { regionalOffset0 = 0xb54, regionalOffset1 = 0x6fc };
#endif
    func_ov017_021c17cc(*(void**)((char*)self + 0x3000 + regionalOffset0));
    (*(unsigned char**)((char*)self + 0x3000 + regionalOffset0))[0x1d] = value;
    func_02046a3c(*(struct List02046a3c**)((char*)self + 0x3000 + regionalOffset1),
                         *(struct Node02046a3c**)((char*)self + 0x3000 + regionalOffset0));
}
