#include <globaldefs.h>

struct Struct_ov031_0222f9ec { char unknown_0_[8]; unsigned short* entries; char unknown_c_[8]; void* display; };
struct Struct_ov031_02290ca0_9 { char unknown_0_[4]; unsigned short position; char unknown_6_[2]; Struct_ov031_0222f9ec* list; };
extern Struct_ov031_02290ca0_9 data_ov031_02290ca0;
extern unsigned short data_ov031_02248f96[];
extern "C" int FastIntDivide(int, int);
extern "C" void func_ov031_0223ca40(void*, int);
extern "C" void func_ov031_0222faac(int, int);
extern "C" void func_ov031_02234f4c(unsigned short*, int, int, int);
extern "C" void func_ov031_0222fc48(int, int);
extern "C" void func_ov031_02234f34();
extern "C" void func_ov031_0223caec(void*);
extern "C" void func_ov031_02230120();

// USA: func_ov031_0222f9ec
extern "C" ARM void func_ov031_0222f9ec() {
    int first = FastIntDivide(data_ov031_02290ca0.position, 0x1d);
    func_ov031_0223ca40(data_ov031_02290ca0.list->display, 0);
    int entry = first;
    int row = 0;
    do {
        func_ov031_0222faac(entry, row);
        ++row;
        ++entry;
    } while (row < 5);
    func_ov031_02234f4c(data_ov031_02290ca0.list->entries + data_ov031_02248f96[first], 0, 0x1e, 0x13);
    int var3 = 0;
    do {
        func_ov031_0222fc48(first, var3);
        ++var3;
        ++first;
    } while (var3 < 5);
    func_ov031_02234f34();
    func_ov031_0223caec(data_ov031_02290ca0.list->display);
    func_ov031_02230120();
}
