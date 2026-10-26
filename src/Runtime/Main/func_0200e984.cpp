#include <globaldefs.h>

struct Struct_0200e984_2 {
    unsigned int a;
    unsigned char* pattern;
};

struct Struct_0200e984 {
    unsigned int count;
    char pad4[0xc - 0x4];
    unsigned char* entries;
};

extern "C" ARM int func_0200eff0(void* str, unsigned char* pattern, Struct_0200e984_2* state);

// USA: func_0200e984
extern "C" ARM int func_0200e984(void* str, Struct_0200e984* list) {
    unsigned char* entries = list->entries;
    unsigned int i = 0;
    if (i < list->count) {
        do {
            unsigned char* pattern = (unsigned char*)(entries[0] | (entries[1] << 8) | (entries[2] << 16) | (entries[3] << 24));
            Struct_0200e984_2 state;
            state.pattern = pattern;
            int result = func_0200eff0(str, pattern, &state);
            if (result != 0) return 1;
            i++;
            entries += 4;
        } while (i < list->count);
    }
    return 0;
}
