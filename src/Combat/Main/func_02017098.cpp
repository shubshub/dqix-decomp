#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/LootableContainer.h"

struct ActorListManager;
struct SelfObj792c;
struct Struct020478bc;
struct SePlayer;

extern "C" struct Struct_02017098_4* func_0201777c(struct Struct_02017098* arg0, int arg1);
extern "C" void func_0204792c(struct Struct_02017098_2* arg0, char* arg1);
extern "C" void func_020478bc(struct Struct_02017098_3* arg0, int arg1);
extern "C" float _fflt(int value);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);
void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern char data_020ef222[];
extern int g_sePlayer;

struct Struct_02017098_5 {
    char unknown_0_[0x1c];
    Vector3i unknown_1c_;
    char unknown_28_[0x88 - 0x1c - 0xc];
};

struct Struct_02017098_4 {
    unsigned short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0x24 - 0x06];
    Vector3i unknown_24_;
    char unknown_30_[0x118 - 0x30];
    struct Struct_02017098_5 unknown_118_[4];
    Vector3i unknown_338_[4];
};

// USA: func_02017098
extern "C" ARM void func_02017098(struct Struct_02017098* arg0, int arg1) {
    struct Struct_02017098_4* var0 = func_0201777c(arg0, arg1);
    if (var0 == NULL) return;

    var0->unknown_2_ = 3;
    func_0204792c((struct Struct_02017098_2*)((char*)var0 + 8), data_020ef222);
    func_020478bc((struct Struct_02017098_3*)((char*)var0 + 0x90), 1);

    fix32_t var1 = 0x4b5c;
    for (int var2 = 0; var2 < 4; var2++) {
        struct Struct_02017098_5* var3 = &var0->unknown_118_[var2];
        var3->unknown_1c_ = var0->unknown_24_;
        int var4 = FIX32_MULTIPLY(fix32sin(var1), 0x80);
        int var5 = _ffix(_fmul(4.0f, _fflt(0x80)));
        int var6 = FIX32_MULTIPLY(fix32cos(var1), 0x80);
        func_020130a8(&var0->unknown_338_[var2], var4, var5, var6);
        var1 = fix32ReduceAngle0To2Pi(var1 + 0x1922);
    }

    LootableContainerManager::Container* container =
        LootableContainerManager::GetMainInstance()->GetContainerByID(e->id, NULL);
    if (container != NULL) {
        if (container->containerType == 1) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x10, 0);
        } else if (container->containerType == 2) {
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x11, 0);
        }
    }

    var0->unknown_4_ = 0;
}
