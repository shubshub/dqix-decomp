#include <globaldefs.h>

extern "C" int func_020d4aa8();
extern "C" void func_ov031_022393e4(int);
extern "C" void func_ov031_02239368(int);
extern "C" void func_ov031_02239d70(void*);
extern "C" int func_ov031_02239e48(int, short);
typedef int (*Type_ov031_02239cd4)(int, unsigned short);

// USA: func_ov031_02239cd4
extern "C" ARM unsigned short func_ov031_02239cd4(unsigned short slot) {
    int mask = func_020d4aa8();
    if (mask == 0x8000) {
        func_ov031_022393e4(3);
        func_ov031_02239368(9);
        return 3;
    }
    if (mask == 0) {
        func_ov031_022393e4(22);
        func_ov031_02239368(9);
        return 24;
    }
    if (!(mask & (1 << (slot - 1)))) {
        do {
            ++slot;
            if (slot > 16) return 24;
        } while (!(mask & (1 << (slot - 1))));
    }
    return reinterpret_cast<Type_ov031_02239cd4>(func_ov031_02239e48)(reinterpret_cast<int>(func_ov031_02239d70), slot);
}
