#include <globaldefs.h>

extern "C" void func_ov031_0223e348(void);
extern "C" void func_ov031_0223fa08(void);
extern "C" void func_ov031_0223fa5c(void);

struct Struct_ov031_02290da0_3 {
    void (*field0)(void);
    unsigned char pad1[4];
    void* field8;
    unsigned char pad2[4];
    void* field10;
    unsigned char pad3[0xc];
    void (*field20)(void*);
};
extern struct Struct_ov031_02290da0_3 data_ov031_02290da0;

// USA: func_ov031_0223e868
extern "C" ARM void func_ov031_0223e868(void) {
    func_ov031_0223e348();
    func_ov031_0223fa08();
    func_ov031_0223fa5c();
    data_ov031_02290da0.field20(data_ov031_02290da0.field8);
    data_ov031_02290da0.field20(data_ov031_02290da0.field10);
    data_ov031_02290da0.field0();
}
