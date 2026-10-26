#include <globaldefs.h>
#include <std_library_functions.h>
#include "NitroSDK/Mutex.h"

struct Struct_ov031_02217fb0_3 {
    char* start;
    char* end;
    unsigned char unknown[8];
    Mutex unknown_10_;
};
struct Struct_ov031_02217fb0 {
    unsigned char prefix[0xa08];
    Struct_ov031_02217fb0_3 buffer;
    int unknown_a30_;
    int unknown_a34_;
};
struct Struct_ov031_02217fb0_2 {
    unsigned char prefix[0x1000];
    Struct_ov031_02217fb0 response;
};
extern char data_ov031_02249df8[];
extern char data_ov031_02249e14[];
extern char data_ov031_02249e28[];
extern "C" int func_02005a94(signed char*);

// USA: func_ov031_02217fb0
extern "C" ARM int func_ov031_02217fb0(Struct_ov031_02217fb0_2* state) {
    char* text = state->response.buffer.start;
    Struct_ov031_02217fb0_3* buffer = &state->response.buffer;
    if (strstr(text, data_ov031_02249df8) == 0) return 0;
    char* body = strstr(text, data_ov031_02249df8) + 4;
    LockMutex(&state->response.buffer.unknown_10_);
    state->response.unknown_a34_ = buffer->end - body;
    UnlockMutex(&state->response.buffer.unknown_10_);
    char* value = strstr(buffer->start, data_ov031_02249e14);
    if (value == 0) return 1;
    int length = strlen(data_ov031_02249e14);
    char* end = strstr(value + length, data_ov031_02249e28);
    signed char saved = *end;
    *end = 0;
    LockMutex(&state->response.buffer.unknown_10_);
    state->response.unknown_a30_ = func_02005a94((signed char*)(value + length));
    UnlockMutex(&state->response.buffer.unknown_10_);
    *end = saved;
    return 1;
}
