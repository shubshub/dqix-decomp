#include <globaldefs.h>
#include "Resource/UiArrayEntry.h"

extern Struct_ov031_022276b4* data_ov031_02290c4c;

extern "C" void* func_ov031_0223c560(int a, int b);
extern "C" int func_ov031_022236d0(void);
extern "C" void func_ov031_0223c980(void* obj, int a, int b, int c, int d, int e, int f, int g);
extern "C" void func_ov031_0223caec(void* ptr);

// USA: func_ov031_022235a0
extern "C" ARM void func_ov031_022235a0(void* arg) {
    void* obj = func_ov031_0223c560(0, 0);
    int lookup = func_ov031_022276b4(data_ov031_02290c4c, (unsigned int)arg);
    int entry = func_ov031_022236d0();
    func_ov031_0223c980(obj, 0xd, 0x28, 0xe6, 0x70, 2, entry, lookup);
    func_ov031_0223caec(obj);
}
