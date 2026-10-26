#include <globaldefs.h>

extern "C" int func_020d2718(unsigned int x);
extern "C" int func_020d22f4(int);
extern "C" void func_020d2880(void);

// USA: func_020d2680
extern "C" ARM void func_020d2680(unsigned int seq) {
    if (func_020d2718(seq)) return;
    while (func_020d22f4(0) != 0) {
    }
    if (func_020d2718(seq)) return;
    func_020d2880();
    if (func_020d2718(seq)) return;
    do {
        func_020d22f4(1);
    } while (!func_020d2718(seq));
}
