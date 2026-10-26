#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct Struct_ov031_02244ad0 {
    unsigned char reserved : 3;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 3;
    unsigned char capacity;
    unsigned char unknown_2_;
};
struct Struct_ov031_02244ad0_2 {
    unsigned char unknown_0[0x7ff0];
    Struct_ov031_02244ad0 unknown_7ff0_;
};
struct Struct_ov031_02244ad0_3 {
    int reserved;
    void* (*unknown_4_)(int, unsigned int);
    void (*unknown_8_)(int, void*);
    int enabled;
    unsigned int address[5];
    unsigned char unknown_24_[8];
    int unknown_2c_;
    int unknown_30_;
    unsigned char unknown_34_[0x58 - 0x34];
};
struct Struct_02245528 {
    unsigned char unknown_0[0x34];
    unsigned char mode;
    unsigned char state;
    unsigned char unknown_36_[0x391 - 0x36];
    unsigned char unknown_391_;
    unsigned char unknown_392_[0x3a8 - 0x392];
    unsigned long long unknown_3a8_;
    unsigned long long unknown_3b0_;
    unsigned char unknown_3b8_[0x3d4 - 0x3b8];
    Struct_ov031_02244ad0_3 config;
};
struct Struct_ov031_022495d4 { unsigned int words[31]; };
struct Struct_ov031_02245fb0 { unsigned char value[6]; };
unsigned char data_ov031_02291e04;
extern SafeAllocator data_ov031_02291e3c;
extern const Struct_ov031_022495d4 data_ov031_022495d4;
extern Struct_ov031_02245fb0 data_ov031_02245fb0;
extern Struct_ov031_022495d4 data_ov031_02291ea8;
extern const Struct_ov031_02245fb0 data_ov031_0224957c;
extern int data_ov031_0224e1c8;
extern "C" int func_ov031_0220d540();
extern "C" void func_ov031_02245858(int, unsigned char);
extern "C" void func_ov031_0224586c(int);
extern "C" void func_ov031_0224587c(Struct_ov031_022495d4*);
unsigned long long GetCurrentTimestamp();
extern "C" int func_ov031_0220f368(unsigned char*, unsigned char*);
extern "C" void func_ov031_0220eb88(int);
extern "C" unsigned int func_ov031_0224598c();
extern "C" void func_ov031_02245938();
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" void func_ov031_0220764c(Struct_ov031_02244ad0_3*);
extern "C" void func_ov031_022077c0();
extern "C" int func_ov031_02207500();
extern "C" void func_ov031_02245528(Struct_02245528*, int);
extern "C" void* func_ov031_02243450(int, unsigned int);
extern "C" void func_ov031_02243484(int, void*);

// USA: func_ov031_02244ad0
extern "C" ARM void func_ov031_02244ad0(Struct_02245528* self) {
    static unsigned char initialized = 0;
    GameState* game = GameState::GetInstance();
    Struct_ov031_02244ad0_2* settings = (Struct_ov031_02244ad0_2*)game;
    switch (self->state) {
    case 0:
        switch (func_ov031_0220d540()) {
        case 0:
            if (!initialized) {
                int capacity = 22;
                if (settings->unknown_7ff0_.unknown_0_3_) capacity = settings->unknown_7ff0_.capacity;
                func_ov031_02245858((int)data_ov031_02291e3c.Allocate(capacity * 208 + 0x230c), capacity);
                Struct_ov031_022495d4 initial = data_ov031_022495d4;
                memcpy(&data_ov031_02291ea8, &initial, sizeof(initial));
                func_ov031_0224586c(1);
                func_ov031_0224587c(&data_ov031_02291ea8);
                if (settings->unknown_7ff0_.unknown_0_4_)
                    self->unknown_3a8_ = GetCurrentTimestamp() + ((33514000ULL * (unsigned int)settings->unknown_7ff0_.unknown_2_) >> 6);
                else self->unknown_3a8_ = GetCurrentTimestamp() + 2618281ULL;
                Struct_ov031_02245fb0 var4 = data_ov031_0224957c;
                func_ov031_0220f368(data_ov031_02245fb0.value, var4.value);
                self->unknown_3b0_ = GetCurrentTimestamp();
                initialized = 1;
            }
            break;
        case 6:
            func_ov031_0220eb88(1);
            if (func_ov031_0224598c() <= 1) {
                func_ov031_0220eb88(0);
                return;
            }
            func_ov031_0220eb88(0);
            break;
        case 9:
            GetCurrentTimestamp();
            self->state = 3;
            break;
        }
        if (GetCurrentTimestamp() <= self->unknown_3a8_) return;
        if (settings->unknown_7ff0_.unknown_0_4_ && !settings->unknown_7ff0_.unknown_2_) return;
        func_ov031_02245938();
        self->state = 5;
        return;
    case 3:
        VectorizedMemset(&self->config, 0, sizeof(self->config));
        self->config.enabled = 1;
        self->config.unknown_4_ = func_ov031_02243450;
        self->config.unknown_8_ = func_ov031_02243484;
        data_ov031_0224e1c8 = 0;
        func_ov031_0220764c(&self->config);
        if (settings->unknown_7ff0_.unknown_0_4_)
            self->unknown_3a8_ = GetCurrentTimestamp() + ((33514000ULL * (unsigned int)settings->unknown_7ff0_.unknown_2_) >> 6);
        else self->unknown_3a8_ = GetCurrentTimestamp() + 2618281ULL;
        self->state = 4;
        GetCurrentTimestamp();
        return;
    case 4:
        if (GetCurrentTimestamp() > self->unknown_3a8_) {
            if (settings->unknown_7ff0_.unknown_0_4_ && !settings->unknown_7ff0_.unknown_2_) goto checkProgress;
            func_ov031_022077c0();
            self->state = 5;
            return;
        }
checkProgress:
        if (func_ov031_02207500()) {
            GetCurrentTimestamp();
            func_ov031_02245528(self, 6);
        }
        return;
    case 5:
        func_ov031_02245938();
        self->state = 6;
        return;
    case 6:
        if (!func_ov031_0220d540()) {
            func_ov031_02245528(self, 0);
            self->unknown_391_ = 1;
        }
        return;
    default:
        return;
    }
}
