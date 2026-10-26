#include <globaldefs.h>

// USA: func_0200d958
extern "C" ARM void* func_0200d958(void* ptr, int* arg1) {
    unsigned char* data = (unsigned char*)ptr;
    int first = *(signed char*)data;
    switch (first & 1) {
    case 0:
        *arg1 = first >> 1;
        return data + 1;
    default:
        unsigned int second = data[1];
        switch (first & 2) {
        case 0:
            *arg1 = second | ((first >> 2) << 8);
            return data + 2;
        default:
            unsigned int third = data[2];
            switch (first & 4) {
            case 0:
                *arg1 = third | (((first >> 3) << 16) | (second << 8));
                return data + 3;
            default:
                unsigned int var4 = data[3];
                *arg1 = var4 | (((first >> 3) << 24) | (second << 16) | (third << 8));
                return data + 4;
            }
        }
    }
}
