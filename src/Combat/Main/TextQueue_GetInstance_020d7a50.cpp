#include <globaldefs.h>

struct ResetObj020d7a5c;
extern struct ResetObj020d7a5c data_0214e34c;

// Main, originally GetGlobalResetObj020d7a50 (USA 0x020d7a50, EUR 0x020d7a60, JPN 0x020d9458)
ARM struct ResetObj020d7a5c* TextQueue_GetInstance() {
    return &data_0214e34c;
}
