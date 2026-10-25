#include <globaldefs.h>

extern "C" void Zone3D_GetInstance(void* obj);

struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);

struct Obj02076d34 {
    char pad[0xb2];
    unsigned short field0xb2;
};

// USA: func_02076d34
ARM int ResetField0xb2SetState5(struct Obj02076d34* p) {
    Zone3D_GetInstance(p);
    p->field0xb2 = 0;
    SetByte0xbeShiftPrev((struct Bytes02033b88*)p, 5);
    return 1;
}
