#include <globaldefs.h>
#include "Resource/Script.h"



extern "C" void* Scenario_GetInstance(void);
struct Variant02030b0c;

struct Struct_0205faf4_13;
extern "C" int func_0206e2dc(struct Struct_0205faf4_13* arg0, int arg1);
struct Struct_0206e2a0;
extern "C" void func_0206e2a0(struct Struct_0206e2a0* arg0, int arg1);

extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);

struct Struct_ov023_021f5a1c {
    unsigned short unknown_0_0_ : 13;
    unsigned short unknown_1_5_ : 3;
};
struct Struct_ov023_021f5a1c_2 {
    char unknown_0_[0x10c];
    struct Struct_ov023_021f5a1c unknown_10c_;
};
struct Struct_ov023_021fff08_7 {
    char unknown_0_[0xc];
    struct Struct_ov023_021f5a1c_2* unknown_c_;
};
extern struct Struct_ov023_021fff08_7 data_ov023_021fff08;

// USA: func_ov023_021f5a1c
extern "C" ARM int func_ov023_021f5a1c(struct Variant02030b0c* list, int count) {
    void* obj = Scenario_GetInstance();
    for (int i = 0; i < count; i++) {
        int v = ((Script::Parameter*)list)->ToInt();
        list = (struct Variant02030b0c*)((char*)list + 8);
        int flag = GetPackedNibbleFlag0x8((struct PackedNibbleArray0206e2dc*)obj, v);
        if (flag == 0) {
            SetPackedNibbleFlag0x8((struct PackedNibbleArray0206e2a0*)obj, v);
            data_ov023_021fff08.ptr->bits.low13 |= 0x40;
            Scenario_SetFlag(obj, (unsigned char*)((char*)obj + 0x8c), 0x797, 1);
        }
    }
    return 1;
}
