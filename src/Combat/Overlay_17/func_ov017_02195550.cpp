#include <globaldefs.h>
#include "Combat/NameEntryQueue.h"

// USA: func_ov017_02195550
extern "C" ARM int func_ov017_02195550(unsigned char* resources) {
    Struct_ov017_02195250_2* queue = (Struct_ov017_02195250_2*)resources;
    if (queue->unknown_431e_ != 0) return 1;
    if (queue->active->state != 0) return 1;
    return queue->count != 0;
}
