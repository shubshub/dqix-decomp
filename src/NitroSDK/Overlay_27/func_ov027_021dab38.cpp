#include <globaldefs.h>

// USA: func_ov027_021dab38
extern "C" ARM unsigned short func_ov027_021dab38(unsigned short* data, int len) {
    unsigned int sum = 0;
    int count = len >> 1;
    if (count > 0) {
        do {
            sum += *data++;
        } while (--count > 0);
    }
    sum = (sum >> 16) + (unsigned short)sum;
    sum = sum + (sum >> 16);
    return (unsigned short)(sum ^ 0xffff);
}
