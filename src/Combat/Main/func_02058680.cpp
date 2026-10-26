#include <globaldefs.h>

// USA: func_02058680
extern "C" ARM int func_02058680(char* base, int value, void** out, int limit) {
    int count = 0;
    if (limit == 0) {
        int i;
        for (i = 0; i < 0x10; i++) {
            if (value == *(int*)(base + i * 0xd4 + 0xd8)) count++;
        }
    } else {
        int j;
        for (j = 0; j < 0x10; j++) {
            int off = j * 0xd4;
            if (value == *(int*)(base + off + 0xd8)) {
                if (count < limit) {
                    out[count++] = (base + 8) + off;
                }
            }
        }
    }
    return count;
}
