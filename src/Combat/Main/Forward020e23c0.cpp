#include <globaldefs.h>

extern "C" int Canvas_FillRect(void* a, int b, int c, short d, short e, int f);

struct Level2_020e23c0 {
    char pad[4];
    void* field4;
};
struct Level1_020e23c0 {
    char pad[4];
    struct Level2_020e23c0* field4;
};

// USA: func_020e23c0
ARM int Forward020e23c0(struct Level1_020e23c0* p0, int p1, int p2, int p3, short p4, short p5) {
    return Canvas_FillRect(p0->field4->field4, p2, p3, p4, p5, p1);
}
