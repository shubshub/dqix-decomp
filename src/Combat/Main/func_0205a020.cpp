#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

struct Struct_ov001_021592bc { int x; int y; int z; };
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
extern "C" void func_02059f38(struct Struct_02059cfc_2* dst, struct Struct_02059cfc_3* src);

struct Struct_02059cfc_4;

extern "C" void func_02059cc8(unsigned char* obj);

struct Struct_02057334_2;
extern "C" int func_02057854(struct Struct_02057334_2* node);

extern "C" int func_02055774(int* obj);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern int g_sePlayer;

// USA: func_0205a020
extern "C" ARM void func_0205a020(unsigned char* p, int arg1) {
    GameState::GetInstance();

    short* var0 = (short*)(p + 0xb0);
    if (*var0 > 0) {
        *var0 -= arg1;
        return;
    }

    if (*(int*)(p + 0xac) == 0) {
        if (*(int*)(p + 0xb8) > 0) {
            int f28 = *(int*)(p + 0x28);
            int var2 = *(int*)(p + 0xbc);
            if (f28 <= var2) {
                int f24 = *(int*)(p + 0x24);
                if (var2 < f24) {
                    SePlayer_Play((struct SePlayer*)&g_sePlayer, *(int*)(p + 0xb8), 0);
                }
            }
        }

        struct Struct_0205a020 { char pad[0x44]; struct Vec3 pos; };
        struct Vec3 pos = ((struct Struct_0205a020*)p)->pos;

        struct Vec3 var5;
        Vector3fixMultiplyScalar((Vector3i const*)(p + 0xc0), arg1 << 12, (Vector3i*)&var5);
        Vector3fix_Add((const Vector3fix*)&pos, (const Vector3fix*)&var5, (Vector3fix*)&pos);
        func_02059f38((struct Struct_02059cfc_2*)p, (struct Struct_02059cfc_3*)&pos);

        ((Object3D*)p)->AdvanceEffects();

        if (p[0x19] & 1) {
            if (((Object3D*)((struct Struct_02059cfc_4*)p))->HasAnimationStopped()) {
                func_02059cc8(p);
            }
        }

        short* var6 = (short*)(p + 0xb6);
        if (*var6 > 0) {
            *var6 -= arg1;
            if (*var6 <= 0) {
                func_02059cc8(p);
            }
        }
    } else {
        if (func_02057854(*(struct Struct_02057334_2**)(p + 0x4)) == 1) {
            func_02059cc8(p);
        } else {
            func_02055774((int*)p);
        }
    }
}
