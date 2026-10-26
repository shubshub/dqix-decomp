#include <globaldefs.h>

struct Struct_01ffd34c;
struct Mutex;
void ZeroInitializeMutex(Mutex*);

struct Struct_ov031_0224e540 {
    unsigned char unknown_0_;
    char pad0[3];
    int field4;
    int field8;
    char pad1[0x24 - 0xc];
    int field24;
};

extern struct Struct_ov031_0224e540 data_ov031_0224e540;
extern struct Struct_01ffd34c data_ov031_0224e54c;

// USA: func_ov031_0220ef5c
extern "C" ARM void func_ov031_0220ef5c(void) {
    if (data_ov031_0224e540.unknown_0_ != 0) {
        return;
    }
    data_ov031_0224e540.unknown_0_ = 1;
    data_ov031_0224e540.field24 = 0;
    data_ov031_0224e540.field8 = 0;
    data_ov031_0224e540.field4 = 0;
    ZeroInitializeMutex((Mutex*)&data_ov031_0224e54c);
}
