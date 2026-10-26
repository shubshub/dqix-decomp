#include <globaldefs.h>

struct Struct_02085a80 {
    char pad0[0x2ac];
    short unknown_2ac_;
    char pad1[0x304 - 0x2ae];
    int unknown_304_;
};

// USA: func_02085a80
extern "C" ARM float func_02085a80(struct Struct_02085a80* actor) {
    if (actor->unknown_2ac_ <= 0) {
        return 1.0f;
    }
    return (float)((actor->unknown_304_ << 20) >> 26) / 10.0f;
}
