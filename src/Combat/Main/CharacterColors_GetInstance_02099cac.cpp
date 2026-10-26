#include <globaldefs.h>

extern unsigned short data_02109928[10][2];

// USA: CharacterColors_GetInstance
extern "C" ARM unsigned short (*CharacterColors_GetInstance(void))[2] {
    return data_02109928;
}
