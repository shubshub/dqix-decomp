#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
struct Struct_ov024_021ed9dc { void* field0; };
extern "C" int func_ov024_021ed9dc(struct Struct_ov024_021ed9dc* holder, int id);

struct Struct_ov024_021fef0c { short v[8]; };
extern struct Struct_ov024_021fef0c data_ov024_021fef0c;

// USA: func_ov024_021f10e0
extern "C" ARM int func_ov024_021f10e0(struct Struct_ov024_021ed9dc* holder, int unused1, int arg2, int* outCount, void* outBuf) {
    struct Struct_ov024_021fef0c buf = data_ov024_021fef0c;
    int count = func_ov000_0215e9fc((int)holder->field0, buf.v, 4, 1);
    if (count <= 0) return 0;

    int found = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (func_ov024_021ed9dc(holder, buf.v[i])) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;

    *outCount = count;
    memcpy(outBuf, buf.v, 0x10);
    return 1;
}
