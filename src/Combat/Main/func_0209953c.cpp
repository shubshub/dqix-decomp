#include <globaldefs.h>

#if defined(jpn)
#define data_021098f4 data_021095ac
#endif
extern unsigned short data_021098f4[];
extern "C" void func_02099554(unsigned short* arr, unsigned short value);

// USA: func_0209953c
extern "C" ARM void func_0209953c(unsigned short value) {
    func_02099554(data_021098f4, value);
}
