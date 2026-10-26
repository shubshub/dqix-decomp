#include <globaldefs.h>

// Main, originally IsField0Null_02046b08 (USA 0x02046b08, EUR 0x02046b18, JPN 0x02047928)
ARM int FieldTaskQueue_IsEmpty(void** obj) {
    return obj[0] == 0;
}
