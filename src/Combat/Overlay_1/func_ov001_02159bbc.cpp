#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov001_02164808(int, int, void*);
extern int data_ov001_02165884;

struct Struct_ov001_02159bbc { int x, y, z; };
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Struct_ov001_02159b94 { int c, d, e; };
extern "C" int func_ov001_02159b94(int a, int b, struct Struct_ov001_02159b94 t);

struct Struct_ov001_02159bbc_2 { int pad0; Struct_ov001_02159bbc pos; int scale; };
struct Struct_ov001_02159bbc_3 { char pad0[0x5c]; int counter; char pad1[0x70 - 0x60]; int unknown_70_; char pad2[0x108 - 0x74]; Struct_ov001_02159bbc unknown_108_; };

// USA: func_ov001_02159bbc
extern "C" ARM int func_ov001_02159bbc(struct Struct_ov001_02159bbc_2* a, struct Struct_ov001_02159bbc_3* b) {
    void* battle = GameState::GetInstance();
    unsigned int var1 = ((GameState*)battle)->GetTickCount() << 12;
    int counter = b->counter;
    if (counter >= a->scale * 2) {
        b->counter = 0;
        return 0;
    }
    if (counter <= 0) {
        Struct_ov001_02159bbc var3;
        Struct_ov001_02159bbc var4;
        func_ov001_02164808(data_ov001_02165884, b->unknown_70_, &var4);
        int var5 = a->scale << 12;
        Vector3fix_Subtract((const Vector3fix*)&a->pos, (const Vector3fix*)&var4, (Vector3fix*)&var3);
        b->unknown_108_.x = fix32_Divide((fix32_t)var3.x, (fix32_t)var5);
        b->unknown_108_.y = fix32_Divide((fix32_t)var3.y, (fix32_t)var5);
        b->unknown_108_.z = fix32_Divide((fix32_t)var3.z, (fix32_t)var5);
    } else {
        Struct_ov001_02159bbc tmp = b->unknown_108_;
        int var7 = fix32_Divide((fix32_t)var1, (fix32_t)(0x2000));
        Vector3fixMultiplyScalar((Vector3i const*)&tmp, var7, (Vector3i*)&tmp);
        Struct_ov001_02159bbc sum;
        func_ov001_02164808(data_ov001_02165884, b->unknown_70_, &sum);
        Vector3fix_Add((const Vector3fix*)&sum, (const Vector3fix*)&tmp, (Vector3fix*)&sum);
        struct Struct_ov001_02159b94 t = *(struct Struct_ov001_02159b94*)&sum;
        func_ov001_02159b94(data_ov001_02165884, b->unknown_70_, t);
    }
    b->counter += ((GameState*)battle)->GetTickCount();
    return 1;
}
