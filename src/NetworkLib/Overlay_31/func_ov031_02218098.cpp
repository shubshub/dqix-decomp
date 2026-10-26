#include <globaldefs.h>
#include <std_library_functions.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/Mutex.h"
#include "NitroSDK/Timing.h"

struct Struct_ov031_02218098_2 {
    unsigned char payload[0x800];
    int handle;
    unsigned char unknown_804_[0xc];
    int (*callback)(int);
    unsigned char unknown_814_[0x1c];
};

struct Struct_ov031_02218098_3 {
    char* start;
    char* current;
    char* limit;
    int capacity;
    Mutex unknown_10_;
    int unknown_28_;
    int unknown_2c_;
};

struct Struct_ov031_02218098_4 {
    unsigned char padding0[0xc];
    Struct_ov031_02218098_2* request;
    unsigned char unknown_10_[0x54];
};

struct Struct_ov031_02218098_5 {
    unsigned char padding0[0x1c];
    int unknown_1c_;
    int status;
    unsigned char unknown_24_[0x100];
    int handle;
    unsigned char unknown_128_[4];
    unsigned int address;
    int mode;
    unsigned short unknown_134_;
    unsigned short unknown_136_;
    Struct_ov031_02218098_4 unknown_138_;
    Struct_ov031_02218098_2 request;
    unsigned char unknown_9cc_[0x2c];
    char* unknown_9f8_;
    unsigned char unknown_9fc_[0xc];
    Struct_ov031_02218098_3 response;
};

struct Struct_ov031_02218098 {
    unsigned char prefix[0x1000];
    Struct_ov031_02218098_5 unknown_1000_;
};

extern "C" void func_ov031_02217f44(void*);
extern "C" int func_ov031_02217f9c(void*);
extern "C" void func_ov031_0220321c();
extern "C" int func_ov031_02218798(int);
extern "C" void func_ov031_02207d60(void*, void*);
extern "C" void func_ov031_0220aa68(unsigned char);
extern "C" void func_ov031_022031bc(int, unsigned short, unsigned int);
extern "C" int func_ov031_02203358();
extern "C" void func_ov031_02203250();
extern "C" void func_ov031_02203178();
extern "C" int func_ov031_02203a84(void*, int);
extern "C" void func_ov031_02203b8c();
extern "C" int func_ov031_02217ecc(char*);
extern "C" int func_ov031_02203b1c();
extern "C" int func_ov031_0220357c(unsigned int*);
extern "C" int func_ov031_02217fb0(void*);
extern "C" void func_ov031_02203670(int);
extern "C" void func_ov031_022033e8();
extern "C" void func_ov031_02203424();
extern char data_ov031_02249d84[];
extern int data_ov031_0224c9d0;

// USA: func_ov031_02218098
extern "C" ARM void func_ov031_02218098(Struct_ov031_02218098* state) {
    Struct_ov031_02218098_3* response;
    int var1 = state->unknown_1000_.unknown_1c_;
    Struct_ov031_02218098_4* var2 = &state->unknown_1000_.unknown_138_;
    Struct_ov031_02218098_2* request = &state->unknown_1000_.request;
    response = &state->unknown_1000_.response;
    int var4 = 0;
    if (var1 <= 0)
        var1 = 60000;
    func_ov031_02217f44(state);
    unsigned int address = func_ov031_02217f9c(state);
    if (!address) {
        state->unknown_1000_.status = 2;
        return;
    }
    state->unknown_1000_.address = address;
    func_ov031_0220321c();
    int var6;
    if (state->unknown_1000_.mode == 1) {
        VectorizedMemset(request, 0, 0x830);
        request->callback = func_ov031_02218798;
        request->handle = state->unknown_1000_.handle;
        var2->request = request;
        func_ov031_02207d60(data_ov031_02249d84, (void*)12);
        func_ov031_0220aa68(1);
    }
    func_ov031_022031bc(0, state->unknown_1000_.unknown_134_, address);
    if (func_ov031_02203358()) {
        state->unknown_1000_.status = 3;
        func_ov031_02203250();
        func_ov031_02203178();
        return;
    }
    char* var7 = state->unknown_1000_.unknown_9f8_;
    var6 = func_ov031_02203a84(var7, strlen(var7));
    if (var6 <= 0) {
        state->unknown_1000_.status = 5;
        goto cleanup;
    }
    func_ov031_02203b8c();
    if (!func_ov031_02217ecc((char*)state)) {
        state->unknown_1000_.status = 7;
        goto cleanup;
    }
    response->current = response->start;
    response->limit = response->start + response->capacity;
    unsigned long long var8 = GetCurrentTimestamp();
    while (true) {
        if (!data_ov031_0224c9d0) {
            state->unknown_1000_.status = 5;
            goto cleanup;
        }
        var6 = func_ov031_02203b1c();
        if (var6 < 0)
            break;
        if (var6 > 0) {
            var8 = GetCurrentTimestamp();
            int var9 = func_ov031_0220357c((unsigned int*)&var6);
            if (!var9)
                break;
            int count = var6;
            int available = response->limit - 1 - response->current;
            if (count >= available)
                count = available;
            VectorizedInvertedMemcpy((void*)var9, response->current, count);
            response->current += count;
            *response->current = 0;
            if (var4 == 1) {
                LockMutex(&state->unknown_1000_.response.unknown_10_);
                state->unknown_1000_.response.unknown_2c_ += count;
                UnlockMutex(&state->unknown_1000_.response.unknown_10_);
            } else {
                var4 = func_ov031_02217fb0(state);
            }
            if ((unsigned int)var6 > (unsigned int)count) {
                func_ov031_02203670(var6);
                break;
            }
            func_ov031_02203670(count);
        }
        if (state->unknown_1000_.response.unknown_28_ >= 0 && state->unknown_1000_.response.unknown_2c_ >= state->unknown_1000_.response.unknown_28_)
            break;
        if (((GetCurrentTimestamp() - var8) << 6) / 33514 > (unsigned long long)var1) {
            state->unknown_1000_.status = 6;
            goto cleanup;
        }
        if (!func_ov031_02217ecc((char*)state)) {
            state->unknown_1000_.status = 7;
            goto cleanup;
        }
    }
    func_ov031_022033e8();
    func_ov031_02203424();
    func_ov031_02203250();
    func_ov031_02203178();
    state->unknown_1000_.status = 8;
    return;
cleanup:
    func_ov031_022033e8();
    func_ov031_02203424();
    func_ov031_02203250();
    func_ov031_02203178();
}
