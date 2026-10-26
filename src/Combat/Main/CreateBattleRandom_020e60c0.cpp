#pragma define_section initcode ".init" RX
#include <globaldefs.h>
#include "Util/Random.h"

extern char data_020f0d66;

// USA: func_020e60c0
extern "C" __declspec(initcode) ARM void __sinit_020e60c0(void) {
    CreateRandom(&data_02108ddc, &data_020f0d66, 1);
}
