#include <globaldefs.h>

struct Flags021ea9b0 {
    char pad[0xc];
    unsigned char low : 4;
    unsigned char flag : 1;
};

struct Owner021ea9b0 {
    char pad[0x8];
    Flags021ea9b0* flags;
};

extern "C" Owner021ea9b0* Zone3D_GetInstance(void);
extern "C" void func_ov017_021d6134(void* obj, int enable);

// USA: func_ov023_021ea9b0  (semantic: Trans_021ea9b0)
extern "C" ARM int func_ov023_021ea9b0(void* obj) {
    func_ov017_021d6134(obj, Zone3D_GetInstance()->flags->flag);
    return 1;
}
