#include <globaldefs.h>

unsigned long long GetCurrentTimestamp(void);
extern "C" int memcmp(const void* a, const void* b, unsigned int len);
extern "C" void func_ov031_0223e2c0(int, void*);

typedef void (*Type_02001aec_2)(int);

struct Struct_02001aec_2 {
    char name[6];
    unsigned char inUse;
};

struct Struct_ov031_022379f0 {
    unsigned char unknown_0_[0x1300];
    Struct_02001aec_2 slots[16];
    Type_02001aec_2 callback;
    unsigned char unknown_1374_[0x814];
    unsigned long long unknown_1b88_;
    void* timer;
    unsigned char unknown_1b94_[2];
    unsigned char unknown_1b96_;
};

extern Struct_ov031_022379f0* data_ov031_02290d0c;
extern char data_ov031_02249280[];

// USA: func_ov031_022379f0
extern "C" ARM void func_ov031_022379f0(void* arg) {
    unsigned long long now = GetCurrentTimestamp();
    Struct_ov031_022379f0* state = data_ov031_02290d0c;
    int i;
    int used;
    int var4;
    char* name;
    char* entry;

    if (now < state->unknown_1b88_ + 0x17f898) {
        return;
    }
    var4 = 0;
    used = 0;
    i = 0;
    entry = (char*)state;
    name = (char*)state + 0x1300;
    do {
        if (memcmp(name, data_ov031_02249280, 6) != 0) {
            if (*(unsigned char*)(entry + 0x1306) != 0) {
                used = 1;
            } else {
                var4 = 1;
            }
        }
        i++;
        name += 7;
        entry += 7;
    } while (i < 16);
    if (used && var4) {
        if (state->callback != 0) {
            state->callback(2);
        }
    } else if (used) {
        if (state->callback != 0) {
            state->callback(1);
        }
    } else if (!var4) {
        if (state->callback != 0) {
            state->callback(0);
        }
    }
    data_ov031_02290d0c->timer = 0;
    data_ov031_02290d0c->unknown_1b96_ = 1;
    func_ov031_0223e2c0(0, arg);
}
