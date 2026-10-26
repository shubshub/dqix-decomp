#include <globaldefs.h>

struct Struct_020e8b6c {
    signed char unknown_0_;
    signed char unknown_1_;
};
extern struct Struct_020e8b6c data_020e8b6c[];

// USA: func_0208538c
extern "C" ARM int func_0208538c(unsigned char* obj) {
    int i;
    signed char var1;
    for (i = 0; (var1 = data_020e8b6c[i].unknown_0_) != -1; i++) {
        signed char var2 = data_020e8b6c[i].unknown_1_;
        if (*(short*)(obj + var2 * 0x20 + 0x100 + 0xac) > 0) {
            int field = *(int*)(obj + var1 * 0x2c + 0x2f4);
            if (((unsigned int)field << 15) >> 31) {
                return 1;
            }
        }
    }
    return 0;
}
