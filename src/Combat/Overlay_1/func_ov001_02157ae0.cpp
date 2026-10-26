#include <globaldefs.h>

struct Struct_ov001_02157570_2 {
    unsigned char pad0[0x38c];
    int x;
    int y;
    int z;
};
struct Struct_ov001_02157570 {
    int x;
    int y;
    int z;
};

struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" void func_ov001_02157570(struct Struct_ov001_02157570_2* src, struct Struct_ov001_02157570* dst);
extern "C" int func_ov001_021570b4(void* p);
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" int fix32_Atan2(int x, int z);

// USA: func_ov001_02157ae0
extern "C" ARM void func_ov001_02157ae0(char* obj, struct Struct_ov001_02157570* target, int* arg2) {
    if (*(int*)(obj + 0x464) == 0) {
        return;
    }
    if (*(int*)(obj + 0x468) != 0) {
        func_ov001_02157570((struct Struct_ov001_02157570_2*)(obj + 0xc8), target);
        *(int*)(obj + 0x464) = 0;
        *(int*)(obj + 0x468) = 0;
        return;
    }
    func_ov001_02157570((struct Struct_ov001_02157570_2*)(obj + 0xc8), target);
    if (func_ov001_021570b4(obj + 0xc8) != 0) {
        *(int*)(obj + 0x468) = 1;
    }
    struct Struct_ov001_02157570 local;
    struct Vec3 diff;
    func_ov001_02157570((struct Struct_ov001_02157570_2*)(obj + 0xc8), &local);
    Vector3fix_Subtract((struct Vec3*)&local, (struct Vec3*)target, &diff);
    if (diff.x == 0 && diff.z == 0) {
        return;
    }
    int angle = fix32_Atan2(diff.x, diff.z);
    int n = (int)((float)angle / 4096.0f / 6.2831855f);
    int var4 = angle - (int)((float)n * 2.0f * 3.1415927f * 4096.0f);
    if (var4 > 25735) {
        var4 -= 25735;
    }
    if (var4 <= 0) {
        var4 += 25735;
    }
    *arg2 = var4;
}
