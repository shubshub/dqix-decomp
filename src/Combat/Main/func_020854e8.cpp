#include <globaldefs.h>

extern signed char data_020e8bb5[];
extern signed char data_020e8bb4[];

// USA: func_020854e8
extern "C" ARM int func_020854e8(unsigned char* actor) {
    int i = 0;
    signed char var1;
    while ((var1 = data_020e8bb4[i * 2]) != -1) {
        signed char id = data_020e8bb5[i + i];
        if (*(short*)(actor + (id << 5) + 0x1ac) > 0) {
            int v = *(int*)(actor + var1 * 0x2c + 0x2f4);
            if ((unsigned int)(v << 11) >> 31) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
