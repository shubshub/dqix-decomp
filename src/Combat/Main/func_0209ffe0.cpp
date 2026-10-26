#include <globaldefs.h>

struct Struct_0209ffe0 {
    char pad[0x68];
    short count;
    unsigned short items[0x32];
};

// USA: func_0209ffe0
extern "C" ARM void func_0209ffe0(Struct_0209ffe0* s, short value) {
    short count = s->count;
    if (count < 0x32) {
        s->count = count + 1;
        s->items[count] = value;
    }
}
