#include <globaldefs.h>

struct Struct_020c2eb8 {
    volatile unsigned short cnt;
    unsigned char pad[6];
    volatile long long param;
};

// USA: func_020c2eb8
extern "C" ARM int Vector3fix_Length(int* v) {
    struct Struct_020c2eb8* var0 = (struct Struct_020c2eb8*)0x40002b0;
    long long sum = (long long)v[0] * v[0];
    sum = (long long)v[1] * v[1] + sum + (long long)v[2] * v[2];
    var0->cnt = 1;
    var0->param = sum << 2;
    while (var0->cnt & 0x8000) {}
    return (*(volatile int*)0x40002b4 + 1) >> 1;
}
