#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);

class Struct_ov004_0216b20c {
public:
    virtual void v00(); virtual void inline_ov004_0216b20c_2(); virtual void inline_ov004_0216b20c_3(); virtual void inline_ov004_0216b20c_4();
    virtual void v04(); virtual void inline_ov004_0216b20c_6(); virtual void inline_ov004_0216b20c_7(); virtual void inline_ov004_0216b20c_8();
    virtual void v08(); virtual void inline_ov004_0216b20c_10(); virtual void v10(); virtual void inline_ov004_0216b20c_12();
    virtual void inline_ov004_0216b20c_13(); virtual void inline_ov004_0216b20c_14(); virtual void v14(); virtual void inline_ov004_0216b20c_16();
    virtual void inline_ov004_0216b20c_17();
    virtual void inline_ov004_0216b20c_18(int arg);
    virtual void v18(); virtual void inline_ov004_0216b20c_20(); virtual void v20(); virtual void inline_ov004_0216b20c_22();
    virtual void inline_ov004_0216b20c_23(); virtual void inline_ov004_0216b20c_24(); virtual void v24(); virtual void inline_ov004_0216b20c_26();
    virtual void inline_ov004_0216b20c_27(); virtual void inline_ov004_0216b20c_28(); virtual void v28(); virtual void inline_ov004_0216b20c_30();
    virtual void v30();
    virtual void inline_ov004_0216b20c_32(int arg);
};
extern "C" Struct_ov004_0216b20c* func_ov023_021f6880(void*, int);

// USA: func_ov004_0216b20c
extern "C" ARM void func_ov004_0216b20c(void* a0, int key, int b, int c) {
    Struct_ov004_0216b20c* obj = func_ov023_021f6880(func_ov011_021849c8(a0), key);
    if (!obj) return;
    if (c != 0) goto merge;
    if (b > 0xc8) goto big;
    if (b >= 0xc8) goto is200;
    if (b > 0x64) goto mid;
    if (b == 0x64) b = 0x15;
    goto merge;
mid:
    if (b > 0x97) goto merge;
    if (b < 0x96) goto merge;
    if (b == 0x96) goto is150;
    if (b == 0x97) b = 0x17;
    goto merge;
big:
    if (b > 0xc9) goto is300;
    if (b == 0xc9) b = 0x19;
    goto merge;
is300:
    if (b == 0x12c) b = 0x1a;
    goto merge;
is150:
    b = 0x16;
    goto merge;
is200:
    b = 0x18;
merge:
    obj->inline_ov004_0216b20c_18(b);
    obj->inline_ov004_0216b20c_32(b);
}
