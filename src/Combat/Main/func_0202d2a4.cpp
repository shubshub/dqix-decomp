#include <globaldefs.h>
struct Struct_021015a0_3 { unsigned short value; char pad2[14]; int state; char unknown_14_[24]; int field2c; char unknown_30_[8]; int field38; };
struct Struct_0202d2a4 { unsigned short field0, status, field4, field6, command, value; };
extern Struct_021015a0_3 data_021015a0;
extern char data_02101f80[], data_021017a0[];
extern "C" void func_0202d3e0();
extern "C" void func_0202c848(int);
extern "C" int func_020d5898(int, int, int, int, unsigned short, unsigned short);
// USA: func_0202d2a4
extern "C" ARM void func_0202d2a4(Struct_0202d2a4* input) {
    if (input->status) {
        func_0202c848(input->status);
        if (input->status == 12) data_021015a0.state = 9;
        else if (input->status == 11) data_021015a0.state = 9;
        else if (input->status == 1) data_021015a0.state = 8;
        else data_021015a0.state = 9;
    } else {
        if (input->command == 8) {}
        else if (input->command == 7) {
            data_021015a0.state = 4;
            int result = func_020d5898((int)func_0202d3e0, (int)data_02101f80, (unsigned short)data_021015a0.field2c, (int)data_021017a0, (unsigned short)data_021015a0.field38, 1);
            if (result == 2) result = 1;
            else { func_0202c848(result); result = 0; }
            if (result == 0) data_021015a0.state = 3;
            else data_021015a0.value = input->value;
        }
        else if (input->command == 6) {}
        else if (input->command == 9) { func_0202c848(20); data_021015a0.state = 9; }
        else if (input->command != 26) data_021015a0.state = 9;
    }
}
