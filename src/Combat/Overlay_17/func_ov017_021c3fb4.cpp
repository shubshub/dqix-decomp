#include <globaldefs.h>
#include "GameState/GameState.h"

struct Field150Holder02052e14;
short* GetField150Ptr0x488(struct Field150Holder02052e14* obj);
void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c3fb4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned char unknown_4_0_ : 4;
    unsigned char unknown_4_4_ : 1;
    unsigned char unknown_5_[5];
    short unknown_a_[5];
};

// USA: func_ov017_021c3fb4
extern "C" ARM void func_ov017_021c3fb4(int arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = func_0200ff1c(var0, arg0);
    if (var1 == NULL) return;

    short* var2 = func_02052e14((struct Struct_02052e14*)var1);
    if (var2 == NULL) return;

    void* data = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021c3fb4 var4;
    var4.unknown_0_ = 2;
    var4.unknown_4_0_ = arg0;

    var4.unknown_5_[0] = 0;
    var4.unknown_a_[0] = var2[0];
    var4.unknown_5_[1] = 1;
    var4.unknown_a_[1] = var2[1];
    var4.unknown_5_[2] = 2;
    var4.unknown_a_[2] = var2[2];
    var4.unknown_5_[3] = 3;
    var4.unknown_a_[3] = var2[3];
    var4.unknown_5_[4] = 4;
    var4.unknown_a_[4] = var2[4];
    var4.unknown_4_4_ = 0;
    func_0205e330(var3, &var4, 0);

    var4.unknown_5_[0] = 5;
    var4.unknown_a_[0] = var2[5];
    var4.unknown_5_[1] = 6;
    var4.unknown_a_[1] = var2[6];
    var4.unknown_5_[2] = 7;
    var4.unknown_a_[2] = var2[7];
    var4.unknown_5_[3] = 8;
    var4.unknown_a_[3] = var2[8];
    var4.unknown_5_[4] = 9;
    var4.unknown_a_[4] = var2[9];
    var4.unknown_4_4_ = arg1;
    func_0205e330(var3, &var4, 0);
}
