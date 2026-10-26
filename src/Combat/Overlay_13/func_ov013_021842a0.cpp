#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c*, int);

struct ShortArrays0204c610;
extern "C" void func_0204c610(struct ShortArrays0204c610* base, int index, short* out0, short* out1, short* out2, short* out3);

// USA: func_ov013_021842a0
extern "C" ARM int func_ov013_021842a0(void* obj, int index) {
    if (!g_touchInput.repeatFired_) goto fail;

    {
    Elem_0205d81c* elem = func_0205d81c((Struct_0205d81c*)obj, 0);
    if (elem == 0) goto fail;

    short var1 = *(short*)((char*)elem + 0xac);
    short var2 = *(short*)((char*)elem + 0xae);

    short out0, out1, out2, out3;
    func_0204c610((struct ShortArrays0204c610*)elem, (short)index, &out0, &out1, &out2, &out3);

    return g_touchInput.TestHoldInRectangle(out0 + (short)(var1 << 3), out1 + (short)(var2 << 3), out2, out3);
    }

fail:
    return 0;
}
