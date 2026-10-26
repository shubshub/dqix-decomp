#include <globaldefs.h>

extern signed char data_020e8b37[];
extern signed char data_020e8b36[];

// USA: func_0208555c
extern "C" ARM int func_0208555c(unsigned char* actor) {
    int i = 0;
    signed char var1;
    while ((var1 = data_020e8b36[i * 2]) != -1) {
        signed char id = data_020e8b37[i + i];
        if (*(short*)(actor + (id << 5) + 0x1ac) > 0) {
            int v = *(int*)(actor + var1 * 0x2c + 0x2f4);
            if ((unsigned int)(v << 10) >> 31) {
                return 1;
            }
        }
        i++;
    }
    return 0;
}
