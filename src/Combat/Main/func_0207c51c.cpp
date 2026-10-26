#include <globaldefs.h>

// USA: func_0207c51c
extern "C" ARM int func_0207c51c(unsigned char* base, int key) {
    int found;
    int i;
    short* p;
    signed char* q;
    int limit;
    int var5;
    int j;

    found = -1;
    for (i = 0; i < 8; i++) {
        if (key == *(base + i + 0xc20)) {
            found = i;
            break;
        }
    }
    if (found == -1) return 0;

    p = *(short**)(base + found * 4 + 0xbd0);
    q = *(signed char**)(base + found * 4 + 0xbf0);
    limit = *(short*)(base + found * 2 + 0xc10);

    var5 = 0;
    for (j = 0; j < limit; j++) {
        if (var5 == j) {
            if (p[j] < 0) var5 = j;
            else var5 = var5 + 1;
        } else if (var5 != j && p[j] >= 0) {
            p[var5] = p[j];
            q[var5] = q[j];
            p[j] = -1;
            q[j] = 0;
            do {
                var5++;
            } while (p[var5] >= 0);
        }
    }
    return 1;
}
