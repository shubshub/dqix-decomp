#include <globaldefs.h>

struct Struct_ov031_02290ca0_5 {
    unsigned char idx;
    unsigned char pad[7];
    unsigned char* ptr;
};
extern struct Struct_ov031_02290ca0_5 data_ov031_02290ca0;
extern "C" char* func_ov031_02235c70(void);
extern "C" void func_ov031_02235c84(unsigned char);
extern "C" void func_ov031_02235c98(unsigned char);
extern "C" void func_ov031_0222f9ec(void);

// USA: func_ov031_0222f38c
extern "C" ARM void func_ov031_0222f38c(unsigned char id) {
    char* base = func_ov031_02235c70();
    if ((unsigned char)base[0xf5] == id) return;
    unsigned char flag;
    if (id != 0) {
        if (data_ov031_02290ca0.ptr[0x43] != 0) {
            flag = 1;
        } else {
            flag = 0;
        }
    } else {
        data_ov031_02290ca0.ptr[0x43] = *(unsigned char*)(base + 0xf6);
        flag = 0;
    }
    func_ov031_02235c84(id);
    func_ov031_02235c98(flag);
    func_ov031_0222f9ec();
}
