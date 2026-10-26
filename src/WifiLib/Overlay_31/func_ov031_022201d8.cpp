#include <globaldefs.h>


// USA: func_ov031_022201d8
extern "C" THUMB unsigned char* func_ov031_022201d8(unsigned char* p, unsigned int* arg1, unsigned int* arg2) {
    unsigned short type = *(unsigned short*)(p + 0);
    unsigned int sum = 0;
    *arg1 = (unsigned short)((unsigned char)(type >> 8) | ((type << 8) & 0xff00));

    unsigned short len = *(unsigned short*)(p + 2);
    unsigned int var3 = (unsigned short)((unsigned char)(len >> 8) | ((len << 8) & 0xff00));
    *arg2 = var3;

    unsigned char* end = p + 6 + var3;
    unsigned char* cur = p;
    if (cur < end) {
        do {
            sum += *cur++;
        } while (cur < end);
    }
    unsigned short var6 = *(unsigned short*)end;
    unsigned short var7 = (unsigned short)((unsigned char)(var6 >> 8) | ((var6 << 8) & 0xff00));
    if ((unsigned short)sum != var7)
        return 0;
    return p + 6;
}
