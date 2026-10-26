#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" int func_01ff85b8(void* buf, int size);

struct Struct_020a94f8 {
    unsigned char unknown_0_[4];
    char unknown_4_[12];
};
struct Struct_020a94f8_2 {
    int unknown_0_;
    Struct_020a94f8 payload;
};
extern char data_020f1be8;

// USA: func_020a94f8
extern "C" ARM int func_020a94f8(struct Struct_020a94f8_2* header, int arg1) {
    int offset = arg1 ? 0x8010 : 0x10;
    if (!func_02075910(offset, header, sizeof(*header), 0)) {
        return 0;
    }
    GameState* save = GameState::GetInstance();
    if (strcmp(header->payload.unknown_4_, &data_020f1be8) == 0) {
        save->unknown_5cc8_ = arg1 ? 3 : 2;
        return 0;
    }
    if (func_01ff85b8(&header->payload, sizeof(header->payload)) != header->unknown_0_) {
        save->unknown_5cc8_ = arg1 ? 3 : 2;
        return 0;
    }
    return 1;
}
