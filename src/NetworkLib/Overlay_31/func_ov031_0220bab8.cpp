#include <globaldefs.h>

// USA: func_ov031_0220bab8
extern "C" ARM void func_ov031_0220bab8(unsigned char *state, unsigned char *data, int len) {
    int k = 0;
    unsigned char i = state[0];
    unsigned char j = state[1];
    unsigned char *s = state + 2;

    if (len > 0) {
        do {
            i = i + 1;
            unsigned char var4 = s[i];
            j = j + var4;
            unsigned char var5 = s[j];
            s[i] = var5;
            s[j] = var4;
            data[k] ^= s[(unsigned char)(var4 + var5)];
            k = k + 1;
        } while (k < len);
    }

    state[0] = i;
    state[1] = j;
}
