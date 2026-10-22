#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
int fix32sin(int);
extern int g_sePlayer;

struct Struct_02015ae4 {
    char unknown_0_[0xe];
    unsigned short unknown_e_;
    unsigned short unknown_10_;
};

// USA: func_02015ae4
extern "C" ARM int func_02015ae4(Obj02015ae4* self) {
    unsigned short counter = self->counter;
    int firstDuration = 0xbff4;
    if ((float)counter <= (float)firstDuration / 4096.0f) {
        if (counter == 0) SePlayer_Play((SePlayer*)&g_sePlayer, 13, 0);
        else if (counter == 16) SePlayer_Play((SePlayer*)&g_sePlayer, 14, 0);
        unsigned int currentCounter = self->counter;
        int square = (self->counter * currentCounter) << 12;
        int coefficient = fix32_Divide(-7290, 0x8fee0);
        self->angle = FIX32_MULTIPLY(coefficient, square) + 0x647a;
        self->counter = self->counter + 1;
    } else {
        unsigned int var5 = arg0->unknown_10_;
        int var6 = 0xbff4;
        int var7 = (int)(4096.0f * ((float)arg0->unknown_10_ - (float)var6 / 4096.0f));
        int var8 = 0x17fe8;
        if ((float)var5 <= (float)var8 / 4096.0f) {
            int var9 = 0x1000 - fix32_Divide(var7, 0x17fe8);
            int var10 = fix32_Divide(0xc90f, 0x17fe8);
            int var11 = FIX32_MULTIPLY(var10, var7);
            if (var11 > 0x647a) var11 = 0x647a;
            int var12 = FIX32_MULTIPLY(fix32sin(var11), -0x101);
            arg0->unknown_e_ = FIX32_MULTIPLY(var12, var9) + 0x4800;
            arg0->unknown_10_ = arg0->unknown_10_ + 1;
        } else {
            arg0->unknown_e_ = 0x4800;
            return 1;
        }
    }
    return 0;
}
