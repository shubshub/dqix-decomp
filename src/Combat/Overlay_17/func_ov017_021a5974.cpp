#include <globaldefs.h>
#include "Resource/GameResources.h"

struct ListHead02046b60;
extern "C" int func_02046b60(struct ListHead02046b60* list, int id);
extern "C" void func_ov002_021556fc(int val);
extern "C" void func_020a1e54(int flag);
extern "C" void func_020a1f4c(int flag);
extern "C" void func_ov017_021a55b0(void* self);

extern int data_ov017_021d83ac;

// USA: func_ov017_021a5974
extern "C" ARM void func_ov017_021a5974(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x34ec};
#else
 enum {regionalOffset0=0x36fc};
#endif
    int val = data_ov017_021d83ac;
    if (val != 0) {
        func_ov002_021556fc(val);
        data_ov017_021d83ac = 0;
    }
    int base = (int)GetGameResources();
    struct ListHead02046b60* list = *(struct ListHead02046b60**)(base + regionalOffset0);
    if (list != NULL
        && (func_02046b60(list, 0x2) || func_02046b60(list, 0x2f) || func_02046b60(list, 0x2d)))
    {
        func_020a1e54(0);
        func_020a1f4c(0);
    } else {
        func_020a1e54(1);
        func_020a1f4c(1);
    }
    func_ov017_021a55b0(self);
    self[0x1] = 1;
}
