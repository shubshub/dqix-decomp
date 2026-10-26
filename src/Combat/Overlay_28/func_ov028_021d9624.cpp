#include <globaldefs.h>

extern "C" ARM int func_ov028_021d9624(void* p);

extern unsigned int data_ov028_021d9b14;

// USA: func_ov028_021d9734
extern "C" ARM int func_ov028_021d9734() {
    return func_ov028_021d9624(&data_ov028_021d9b14);
}
