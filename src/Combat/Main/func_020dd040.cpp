#include <globaldefs.h>
#include "Resource/KeyTable.h"

extern "C" void* KeyTable_Construct(void* p);
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);

#if defined(jpn)
extern "C" int func_020e2168(char* destination, const char* arg1,
    int index, int variant, bool lock);
extern const char data_020f2b82[];
#else
extern "C" int func_020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);

extern const char data_020f2994[];
extern const char data_020f29a8[];
#endif

// JPN: func_020dea34
// USA: func_020dd040
extern "C" ARM void func_020dd040(int len, char* buf) {
    const char* innerFile;
#if !defined(jpn)
    const char* archive;
#endif
    if (len > 0 && buf != NULL) {
        struct Struct020dfc40 s;
#if defined(jpn)
        innerFile = data_020f2b82;
#else
        archive = data_020f2994;
        innerFile = data_020f29a8;
#endif
        buf[0] = 0;
        KeyTable_Construct(&s);
        KeyTable_Reset(&s);
    } else {
        return;
    }
#if defined(jpn)
    func_020e2168(buf, innerFile, len, 0, true);
#else
    func_020e04f4((int)buf, (void*)innerFile, len, 0, 1, (int)archive);
#endif
}
