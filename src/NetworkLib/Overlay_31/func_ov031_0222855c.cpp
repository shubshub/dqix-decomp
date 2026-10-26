#include <globaldefs.h>

struct Struct_ov031_02248d8c {
    unsigned char values[2];
};

struct Struct_ov031_02290c50_2 {
    unsigned char selected;
    unsigned char padding[3];
    int buffer;
};

extern const Struct_ov031_02248d8c data_ov031_02248d8c;
extern Struct_ov031_02290c50_2 data_ov031_02290c50;
extern "C" void func_ov031_02234ff8(int, int, int);

// USA: func_ov031_0222855c
extern "C" ARM void func_ov031_0222855c() {
    Struct_ov031_02248d8c sizes = data_ov031_02248d8c;
    unsigned char size = sizes.values[data_ov031_02290c50.selected];
    func_ov031_02234ff8(data_ov031_02290c50.buffer, size, size);
}
