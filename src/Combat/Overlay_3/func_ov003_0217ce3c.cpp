#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_0217ce3c_20 = 0x10 };
enum { Enum_ov003_0217ce3c_144 = 0x8c };
enum { Enum_ov003_0217ce3c_24 = 0x14 };
#else
enum { Enum_ov003_0217ce3c_20 = 0x14 };
enum { Enum_ov003_0217ce3c_144 = 0x90 };
enum { Enum_ov003_0217ce3c_24 = 0x18 };
#endif

struct Struct6_0217dc94;
extern "C" void func_ov003_0217dc94(Struct6_0217dc94* obj);
extern "C" int Window_Update(void* p, int val);

struct Block10Words0217ce3c { unsigned int w[10]; };
extern struct Block10Words0217ce3c data_ov003_0217fbc8;
struct Pair0217ce3c { unsigned int a; unsigned int b; };
extern struct Pair0217ce3c __ptmf_null;
struct DispatchEntry0217ce3c { unsigned int fn; unsigned int locator; };

struct Struct_ov003_0217ce3c_3 {
    char unknown_0_[4];
    signed char unknown_4_;
    char unknown_5_[8 - 5];
    unsigned short unknown_8_;
    char unknown_a_[Enum_ov003_0217ce3c_20 - 0xa];
    int unknown_14_;
    char unknown_18_[Enum_ov003_0217ce3c_144 - Enum_ov003_0217ce3c_24];
    void* unknown_90_;
};

// USA: func_ov003_0217ce3c
extern "C" ARM int func_ov003_0217ce3c(struct Struct_ov003_0217ce3c_3* arg0) {
    GameState* var0 = GameState::GetInstance();
    func_ov003_0217dc94((struct Struct_ov003_0217ce3c*)arg0);
    if (arg0->unknown_8_ & 1) return 1;

    unsigned int scaleCount = bs->GetTickCount();
    if (obj->field90 != 0) {
        obj->field14 = Window_Update(obj->field90, scaleCount);
    }

    struct Block10Words0217ce3c buf;
    buf = data_ov003_0217fbc8;
    struct Pair0217ce3c* pr = &__ptmf_null;
    unsigned int tmp1 = pr->b;
    unsigned int tmp0 = pr->a;
    ((struct DispatchEntry0217ce3c*)&buf)[4].locator = tmp1;
    ((struct DispatchEntry0217ce3c*)&buf)[4].fn = tmp0;

    signed char var6 = arg0->unknown_4_;
    struct Struct_ov003_0217ce3c_2* var7 = (struct Struct_ov003_0217ce3c_2*)&var2;
    if (var7[var6].unknown_0_ == 0) return 0;
    struct Struct_ov003_0217ce3c_2* var8 = &var7[var6];
    void* var9 = (char*)arg0 + ((int)var8->unknown_4_ >> 1);
    void (*var10)(void*);
    if (var8->unknown_4_ & 1) {
        var10 = (void(*)(void*))(*(void**)((char*)*(void**)var9 + var8->unknown_0_));
    } else {
        var10 = (void(*)(void*))var8->unknown_0_;
    }
    var10(var9);
    return 1;
}
