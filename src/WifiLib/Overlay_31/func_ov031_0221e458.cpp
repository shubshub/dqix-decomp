#include <globaldefs.h>


typedef int (*Type_ov031_0221e458)(int);
extern Type_ov031_0221e458 data_ov031_0224f4c0;

// USA: func_ov031_0221e458
extern "C" THUMB int func_ov031_0221e458(int unused, int amount) {
    if (amount > 0) {
        return data_ov031_0224f4c0(amount);
    }
    return 0;
}
