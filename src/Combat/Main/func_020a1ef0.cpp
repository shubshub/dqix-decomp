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
extern signed char data_020f1977[];

// USA: func_020a1ef0
extern "C" ARM void func_020a1ef0(int id) {
    if (data_02109da4.countB >= 8) HaltSystem();
    if ((unsigned int)id >= 7) return;
    Overlay_Load(data_020f1977[id]);
    data_02109da4.unknown_2_[data_02109da4.countB] = id;
    data_02109da4.countB++;
}
