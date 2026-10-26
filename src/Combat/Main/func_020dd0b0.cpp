#include <globaldefs.h>
#include "Resource/KeyTable.h"

extern "C" void* KeyTable_Construct(void* p);
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);

extern "C" int func_020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);

extern const char data_020f29cc[];
extern const char data_020f29b8[];

// USA: func_020dd0b0
extern "C" ARM void func_020dd0b0(int len, char* buf) {
    const char* innerFile;
    const char* archive;
    if (len >= 0 && buf != NULL) {
        struct Struct020dfc40 s;
        archive = data_020f29b8;
        innerFile = data_020f29cc;
        buf[0] = 0;
        KeyTable_Construct(&s);
        KeyTable_Reset(&s);
    } else {
        return;
    }
    func_020e04f4((int)buf, (void*)innerFile, len, 0, 1, (int)archive);
}
