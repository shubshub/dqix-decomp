#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" void __clear(void* ptr, int size);
extern "C" float _ffltu(unsigned int v);
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);
short fix32sin(int x);
short fix32cos(int x);

struct Struct_02096a20 {
    char pad[0x220];
    unsigned char startX;
    unsigned char startY;
    unsigned char x;
    unsigned char y;
    char pad2[4];
    short unknown_228_;
    short unknown_22a_;
    short unknown_22c_;
    short angle;
};

extern const int data_0210a05c[256];

// USA: func_02096a20
extern "C" ARM void func_02096a20(struct Struct_02096a20* self) {
    struct Vec3 delta;
    struct Vec3 var1;

    __clear(&delta, 0xc);
    delta.x = (int)(((float)self->x - (float)self->startX > 0.0f)
                    ? 0.5f + 4096.0f * ((float)self->x - (float)self->startX)
                    : 4096.0f * ((float)self->x - (float)self->startX) - 0.5f);
    delta.z = (int)(((float)self->y - (float)self->startY > 0.0f)
                    ? 0.5f + 4096.0f * ((float)self->y - (float)self->startY)
                    : 4096.0f * ((float)self->y - (float)self->startY) - 0.5f);
    Vector3fix_Normalize(&delta, &delta);

    const int* g = (const int*)&data_0210a05c;
    __clear(&var1, 0xc);
    var1.x = g[6];
    var1.z = g[8];
    Vector3fix_Normalize(&var1, &var1);

    short var3 = (short)fix32ReduceAngle0To2Pi(fix32_Atan2(delta.x, delta.z));
    short var4 = (short)fix32ReduceAngle0To2Pi(-fix32_Atan2(var1.x, var1.z));

    self->angle = (short)fix32ReduceAngle0To2Pi(var3 + var4);
    self->unknown_228_ = fix32sin(self->angle);
    self->unknown_22a_ = 0;
    self->unknown_22c_ = fix32cos(self->angle);
}
