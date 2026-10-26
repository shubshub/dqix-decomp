#include <globaldefs.h>

extern int* data_ov031_02250bf0;

extern "C" void func_ov031_0223ba20(int a);

// USA: func_ov031_022238cc
extern "C" ARM void func_ov031_022238cc(void) {
    int i = 0;
    do {
        if (data_ov031_02250bf0[i] != 0) {
            func_ov031_0223ba20(data_ov031_02250bf0[i]);
            data_ov031_02250bf0[i] = 0;
        }
        i++;
    } while (i < 4);
}
