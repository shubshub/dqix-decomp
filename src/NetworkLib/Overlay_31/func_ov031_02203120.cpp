#include <globaldefs.h>
#include "Util/Random.h"

struct Struct_ov031_0224c980_5 { unsigned char pad[0x68]; struct Random rng; };
extern struct Struct_ov031_0224c980_5 data_ov031_0224c980;

// USA: func_ov031_02203120
extern "C" ARM unsigned int func_ov031_02203120(void) {
	data_ov031_0224c980.rng.lcg_state = data_ov031_0224c980.rng.lcg_multiplier * data_ov031_0224c980.rng.lcg_state + data_ov031_0224c980.rng.lcg_increment;
	return data_ov031_0224c980.rng.lcg_state >> 32u;
}
