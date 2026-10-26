#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
#else
enum { kRegionValue998_868 = 0x998 };
#endif

extern "C" void* MessageSystem_GetInstance(void);
struct Entry_0205d6a0;
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
struct Container020e0310;
extern "C" void* KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void func_ov017_021d243c(int);
extern "C" void Party_ReformLine(int, int, int, int, int);

// USA: func_ov003_0215af00
extern "C" ARM void func_ov003_0215af00(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();
    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        Window_ClosePane((Entry_0205d6a0*)(s + 0xf4), 1);
        void* val = KeyTable_Get((Container020e0310*)(s + 0x64), 0x442);
        func_ov003_02159250(self, val);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (!(state == 1 && *(int*)(g + kRegionValue998_868) == 0)) return;

    func_ov017_021d243c(0);
    int r = (int)GetGameResources();
    Party_ReformLine(r, 1, 1, 1, 1);

    *(unsigned char*)(s + 0x588) = 0xb;
    *(unsigned char*)(s + 0x580) = 0;
}
