#include <globaldefs.h>

extern "C" void func_0206e164(int base, int index, int value);

// USA: func_0206e100
extern "C" ARM void func_0206e100(int base, int index) {
    if (index >= 0xcc) {
        return;
    }
    if (index < 0) {
        return;
    }
    func_0206e164(base, index, 3);
}
