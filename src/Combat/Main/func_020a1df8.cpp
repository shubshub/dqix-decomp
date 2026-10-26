#include <globaldefs.h>


extern "C" void HaltSystem(void);
extern "C" void Overlay_Load(int);
struct Struct_02109da4 {
    unsigned char countA;
    unsigned char countB;
    signed char unknown_2_[8];
    signed char unknown_a_[8];
};
extern Struct_02109da4 data_02109da4;
extern signed char data_020f1962[];

// USA: func_020a1df8
extern "C" ARM void func_020a1df8(int id) {
    if (data_02109da4.countA >= 8) HaltSystem();
    if ((unsigned int)id >= 7) return;
    Overlay_Load(data_020f1962[id]);
    data_02109da4.unknown_a_[data_02109da4.countA] = id;
    data_02109da4.countA++;
}
