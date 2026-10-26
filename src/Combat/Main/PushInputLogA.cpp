#include <globaldefs.h>


extern "C" void HaltSystem(void);
extern "C" void Overlay_Load(int);
struct InputLog {
    unsigned char countA;
    unsigned char countB;
    signed char logB[8];
    signed char logA[8];
};
extern InputLog data_02109da4;
extern signed char data_020f1962[];

// USA: _Z22PushInputLogA_020a1df8i
ARM void PushInputLogA_020a1df8(int id) {
    if (data_02109da4.countA >= 8) HaltSystem();
    if ((unsigned int)id >= 7) return;
    Overlay_Load(data_020f1962[id]);
    data_02109da4.logA[data_02109da4.countA] = id;
    data_02109da4.countA++;
}
