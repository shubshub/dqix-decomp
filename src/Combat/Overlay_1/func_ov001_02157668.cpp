#include <globaldefs.h>

struct Struct_ov001_02157570_2 {
    unsigned char pad0[0x38c];
    int x;
    int y;
    int z;
    int unknown_398_;
};
struct Struct_ov001_02157570 {
    int x;
    int y;
    int z;
};

extern "C" void func_ov001_02157570(struct Struct_ov001_02157570_2* src, struct Struct_ov001_02157570* dst);

extern "C" int Vector3fix_Distance(struct Struct_ov001_02157570* a, struct Struct_ov001_02157570* b);
extern "C" int fix32_Divide(int num, int arg1);
extern "C" int func_ov001_021573c0(void* path);
extern "C" void func_ov001_02156c14(void* path, void* points, int* arg2, int count, int speed);

struct Struct_ov001_02157668 {
    struct Struct_ov001_02157570 unknown_0_[16];
    struct Struct_ov001_02157570 unknown_c0_[16];
    int count;
    int duration;
    struct Struct_ov001_02157570_2 unknown_188_;
    struct Struct_ov001_02157570_2 unknown_524_;
};

// USA: func_ov001_02157668
extern "C" ARM int func_ov001_02157668(struct Struct_ov001_02157668* self) {
    int var0[16];
    int dist[16];
    struct Struct_ov001_02157570 var2;
    struct Struct_ov001_02157570 var3;
    struct Struct_ov001_02157570 var4;
    struct Struct_ov001_02157570 var5;
    int i;
    int total;

    if (self->count <= 0) {
        return 1;
    }

    total = 0;
    for (i = 0; i < self->count - 1; i++) {
        dist[i] = Vector3fix_Distance(&self->unknown_0_[i], &self->unknown_0_[i + 1]);
        total += dist[i];
    }
    for (i = 0; i < self->count - 1; i++) {
        var0[i] = self->duration / (self->count - 1);
    }
    func_ov001_02156c14(&self->unknown_188_, self->unknown_0_, var0, self->count, 0);

    total = 0;
    while (1) {
        func_ov001_02157570(&self->unknown_188_, &var2);
        if (func_ov001_021573c0(&self->unknown_188_) != 0) {
            break;
        }
        func_ov001_02157570(&self->unknown_188_, &var3);
        total += Vector3fix_Distance(&var2, &var3);
    }
    func_ov001_02156c14(&self->unknown_188_, self->unknown_0_, var0, self->count, fix32_Divide(total, self->duration << 12));

    total = 0;
    for (i = 0; i < self->count - 1; i++) {
        dist[i] = Vector3fix_Distance(&self->unknown_c0_[i], &self->unknown_c0_[i + 1]);
        total += dist[i];
    }
    for (i = 0; i < self->count - 1; i++) {
        var0[i] = self->duration / (self->count - 1);
    }
    func_ov001_02156c14(&self->unknown_524_, self->unknown_c0_, var0, self->count, 0);

    total = 0;
    while (1) {
        func_ov001_02157570(&self->unknown_524_, &var4);
        if (func_ov001_021573c0(&self->unknown_524_) != 0) {
            break;
        }
        func_ov001_02157570(&self->unknown_524_, &var5);
        total += Vector3fix_Distance(&var4, &var5);
    }
    func_ov001_02156c14(&self->unknown_524_, self->unknown_c0_, var0, self->count, fix32_Divide(total, self->duration << 12));

    return 0;
}
