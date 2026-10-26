#include <globaldefs.h>
#include <NitroSDK/Matrix.h>
#include <std_library_functions.h>

struct Struct_ov001_02156ba0_2 {
    int start;
    int duration;
    int unknown_8_[3];
    int unknown_14_[3];
    int unknown_20_[3];
    int constant[3];
};
struct Struct_ov001_02156ba0 {
    Struct_ov001_02156ba0_2 entries[16];
    int count;
    int unknown_384_;
    int unknown_388_;
    Vector3fix initial;
    int mode;
};
extern "C" void func_ov001_02156ba0(Struct_ov001_02156ba0*);

static inline int MultiplyFixed(int value, int arg1) {
    return FIX32_MULTIPLY(value, arg1);
}

// USA: func_ov001_02156c14
extern "C" ARM void func_ov001_02156c14(Struct_ov001_02156ba0* self, const Vector3fix* points, const int* arg2, int count, int mode) {
    func_ov001_02156ba0(self);
    if (count > 0) {
        int index;
        Vector3fix positions[18];
        self->count = count;
        self->mode = mode;
        for (index = 0; index < self->count; ++index) memcpy(&positions[index], &points[index], sizeof(Vector3fix));
        memcpy(&positions[self->count], &points[self->count - 1], sizeof(Vector3fix));
        memcpy(&positions[self->count + 1], &points[self->count - 1], sizeof(Vector3fix));
        self->initial.x = points[0].x;
        self->initial.y = points[0].y;
        self->initial.z = points[0].z;
        for (index = 0; index < self->count; ++index) {
            if (index == 0) {
                self->entries[index].start = 0;
                self->entries[index].duration = arg2[index];
            } else if (index == self->count - 1) {
                self->entries[index].start = self->entries[index - 1].start + self->entries[index - 1].duration;
                self->entries[index].duration = 0;
            } else {
                self->entries[index].start = self->entries[index - 1].start + self->entries[index - 1].duration;
                self->entries[index].duration = arg2[index];
            }
        }
        for (index = 0; index < self->count; ++index) {
            for (int axis = 0; axis < 3; ++axis) {
                int var3;
                int previous;
                int current;
                int next;
                int var7;
                if (axis == 0) {
                    current = positions[index].x;
                    next = positions[index + 1].x;
                    var7 = positions[index + 2].x;
                    if (index > 0) previous = positions[index - 1].x;
                } else if (axis == 1) {
                    current = positions[index].y;
                    next = positions[index + 1].y;
                    var7 = positions[index + 2].y;
                    if (index > 0) previous = positions[index - 1].y;
                } else {
                    current = positions[index].z;
                    next = positions[index + 1].z;
                    var7 = positions[index + 2].z;
                    if (index > 0) previous = positions[index - 1].z;
                }
                if (index == 0) var3 = next - current;
                else {
                    int var8 = MultiplyFixed(current - previous, self->entries[index].duration << 12);
                    int var9 = MultiplyFixed(next - current, self->entries[index - 1].duration << 12);
                    var3 = fix32_Divide(var9 + var8, (self->entries[index - 1].duration + self->entries[index].duration) << 12);
                }
                int var10;
                if (index == self->count - 1) var10 = var7 - next;
                else {
                    int var11 = MultiplyFixed(next - current, self->entries[index + 1].duration << 12);
                    int var12 = MultiplyFixed(var7 - next, self->entries[index].duration << 12);
                    var10 = fix32_Divide(var12 + var11, (self->entries[index].duration + self->entries[index + 1].duration) << 12);
                }
                int var13 = MultiplyFixed(next, 0x2000);
                int var14 = MultiplyFixed(current, 0x2000);
                self->entries[index].unknown_8_[axis] = var14 - var13 + var3 + var10;
                int var15 = MultiplyFixed(next, 0x3000);
                int var16 = MultiplyFixed(current, -0x3000);
                int var17 = MultiplyFixed(var3, 0x2000);
                self->entries[index].unknown_14_[axis] = var16 + var15 - var17 - var10;
                self->entries[index].unknown_20_[axis] = var3;
                self->entries[index].constant[axis] = current;
            }
        }
    }
}
