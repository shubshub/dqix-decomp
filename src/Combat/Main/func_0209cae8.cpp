#include <globaldefs.h>

struct ShortField0xb8_0209cae8 {
    char pad[0xb8];
    short value;
};

// USA: func_0209cae8
extern "C" ARM short func_0209cae8(struct ShortField0xb8_0209cae8* obj) {
    return obj->value;
}
