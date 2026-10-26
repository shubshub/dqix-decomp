#include <globaldefs.h>

#include "Combat/BufferedScriptResult.h"

struct Struct_ov017_021b7284 {
    short unknown_0_[3];
    unsigned char pad[2];
    unsigned char bytes[3];
};

// USA: func_ov017_021b8abc
extern "C" ARM int func_ov017_021b8abc(int id, Struct_ov017_021b7284* out) {
    Struct_02074060 buf;
    if (id <= -1) {
        goto fail;
    }
    if (!func_02074114(&buf, id)) {
        goto fail;
    }
    for (int i = 0; i < 3; i++) {
        out->unknown_0_[i] = buf.values[i];
        out->bytes[i] = (unsigned char)buf.attributes[i];
    }
    return 1;
fail:
    return 0;
}
