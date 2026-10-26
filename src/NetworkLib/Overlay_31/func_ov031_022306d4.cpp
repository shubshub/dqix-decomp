#include <globaldefs.h>

extern "C" void func_ov031_0223521c();
extern "C" void func_ov031_02235204();
extern "C" void func_ov031_022238cc();
extern "C" int FastIntModulus(int, int);
extern "C" void func_ov031_02230120();
extern "C" void func_ov031_0222f9ec();
extern "C" void func_ov031_022351f8(int);
extern "C" void func_ov031_022308d4();
extern "C" void func_ov031_0223e2c0(int, void*);

struct Struct_ov031_022306d4 { char pad[0x38]; int field38; };
struct Struct_ov031_02290ca0_18 { unsigned char state, field1, field2, unknown_3_; unsigned short timer; unsigned short field6; Struct_ov031_022306d4* work; };
extern Struct_ov031_02290ca0_18 data_ov031_02290ca0;

// USA: func_ov031_022306d4
extern "C" ARM void func_ov031_022306d4(void* argument) {
    func_ov031_0223521c();
    func_ov031_022238cc();
    data_ov031_02290ca0.timer += 6;
    int var0 = FastIntModulus(data_ov031_02290ca0.timer, 29);
    if (var0 >= 6) {
        func_ov031_02230120();
        return;
    }
    data_ov031_02290ca0.timer -= var0;
    func_ov031_0222f9ec();
    func_ov031_022351f8(data_ov031_02290ca0.timer * 55 / 145);
    func_ov031_02235204();
    func_ov031_022308d4();
    data_ov031_02290ca0.work->field38 = 0;
    func_ov031_0223e2c0(0, argument);
}
