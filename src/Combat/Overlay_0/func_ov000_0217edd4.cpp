#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" void* func_ov000_02161318(void* obj, int index);

struct Struct_ov000_02183650 {
    signed char ids[4];
};

extern Struct_ov000_02183650 data_ov000_02183650;

// USA: func_ov000_0217edd4
extern "C" ARM void func_ov000_0217edd4(void* obj, signed char* out, signed char* outCount) {
    Struct_ov000_02183650 list = data_ov000_02183650;
    signed char buf[4];
    int n = (signed char)GameState_GetPartyOrder((char*)GameState::GetInstance(), buf);
    memcpy(&list, buf, n);
    *outCount = 0;
    for (int i = 0; i < n; i++) {
        if (func_ov000_02161318(obj, list.ids[i]) != NULL) {
            out[*outCount] = list.ids[i];
            (*outCount)++;
        }
    }
}
