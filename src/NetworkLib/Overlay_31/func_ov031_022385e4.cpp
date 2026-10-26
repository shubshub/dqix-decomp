#include <globaldefs.h>

struct Struct_ov031_02226d48;
struct Struct_ov031_022385e4 {
    void* header;
    void* unknown_4_;
    void* entries[2];
    Struct_ov031_02226d48* object;
    void* callback;
    unsigned char padding[4];
    unsigned char mode;
};
extern "C" Struct_ov031_022385e4* data_ov031_02290d10;
namespace DuplicatePool {
    extern "C" Struct_ov031_022385e4* data_ov031_02290d10;
}
extern unsigned char data_ov031_02249394[];
extern "C" void func_ov031_0223ba20(void*);
extern "C" void func_ov031_0223c534(Struct_ov031_02226d48*);
extern "C" void func_ov031_0223e2c0(int, int);
extern "C" void func_ov031_0223cf70(Struct_ov031_022385e4**);
#define REG_DISPLAY_CONTROL (*(volatile unsigned int*)0x04000000)

// USA: func_ov031_022385e4
extern "C" ARM void func_ov031_022385e4(int callback) {
    REG_DISPLAY_CONTROL &= ~0xe000;
    func_ov031_0223ba20(data_ov031_02290d10->header);
    func_ov031_0223ba20(data_ov031_02290d10->unknown_4_);
    int index = 0;
    if (index < data_ov031_02249394[data_ov031_02290d10->mode]) do {
        if (data_ov031_02290d10->entries[index] != 0)
            func_ov031_0223ba20(data_ov031_02290d10->entries[index]);
        index++;
    } while (index < data_ov031_02249394[data_ov031_02290d10->mode]);
    func_ov031_0223c534(data_ov031_02290d10->object);
    func_ov031_0223e2c0(1, callback);
    func_ov031_0223cf70(&DuplicatePool::data_ov031_02290d10);
}
