#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" int Zone3D_GetInstance(void);
void CopyToOffsetIfSrc02098efc(char* obj, int offset, const void* src, unsigned int length);
void* GetData02100044_0202ae24(void);
struct BitArrayObj0205e804;
void ClearBitInArray0x1524(struct BitArrayObj0205e804* obj, int index);

struct Struct_ov017_021d3dcc {
    char unknown_0_[0x11];
    unsigned char unknown_11_0_ : 4;
    unsigned char unknown_11_4_ : 3;
    unsigned char unknown_11_7_ : 1;
    unsigned short unknown_12_;
};

// USA: func_ov017_021d3dcc
extern "C" ARM void func_ov017_021d3dcc(int arg0, struct Struct_ov017_021d3dcc* arg1, GameState* arg2, int arg3, struct Struct_0202c1a4* arg4) {
#if defined(jpn)
 enum {Enum_ov017_021d3dcc_2112=0x860};
#else
 enum {Enum_ov017_021d3dcc_2112=0x840};
#endif
    if (func_0202c1a4(arg4) != arg1->unknown_11_4_) {
        return;
    }
    char* base = (char*)Zone3D_GetInstance();
    char* p1 = base + regionalOffset0;
    CopyToOffsetIfSrc02098efc(p1, evt->field12, (const void*)((char*)evt + 4), evt->lowNibble);
    if (!evt->topFlag) {
        return;
    }
    var1[0x1000 + 0xb62] = 1;
    struct Struct_0205e804* var2 = (struct Struct_0205e804*)func_0202ae24();
    func_0205e804(var2, 0xb9);
}
