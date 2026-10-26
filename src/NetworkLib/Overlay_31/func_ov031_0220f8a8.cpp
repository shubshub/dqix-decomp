#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_ov031_0220f8a8_3 {
    int type;
    int parameter;
    int unknown_8_;
    const unsigned char* source;
    int unknown_10_;
    unsigned int length;
    unsigned int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    unsigned int unknown_24_;
};
struct Struct_ov031_0220f8a8 {
    char padding[0x24];
    Struct_ov031_0220f8a8_3* request;
};
struct Struct_ov031_0220f8a8_2 {
    unsigned int size;
    unsigned int signature;
    int command;
    int parameter;
    unsigned int length;
    unsigned char payload[0x400];
};
extern Struct_ov031_0220f8a8* data_ov031_0224e580;
extern "C" int func_ov031_0220fe44(int (*)(int*));
extern "C" int func_ov031_0220ff34(int*);
extern "C" int func_ov031_0220ff18(void*);
extern "C" void func_ov031_0220fea0();
extern "C" void func_ov031_0220fed8();

// USA: func_ov031_0220f8a8
extern "C" ARM void func_ov031_0220f8a8() {
    unsigned char storage[sizeof(Struct_ov031_0220f8a8_2)];
    Struct_ov031_0220f8a8_2* message = (Struct_ov031_0220f8a8_2*)storage;
    const unsigned char* source = data_ov031_0224e580->request->source;
    unsigned int var3 = data_ov031_0224e580->request->length;
    if (var3 > 0x400) var3 = 0x400;
    message->size = var3 + 20;
    message->signature = 0x44535359;
    message->command = 0xcd;
    message->length = data_ov031_0224e580->request->length;
    message->parameter = data_ov031_0224e580->request->parameter;
    VectorizedInvertedMemcpy(source, message->payload, var3);
    if (func_ov031_0220fe44(func_ov031_0220ff34)) {
        if (func_ov031_0220ff18(storage)) {
            int last = 1;
            if (var3 < data_ov031_0224e580->request->length) do {
                unsigned int amount = data_ov031_0224e580->request->length - var3;
                last = 1;
                if (amount > 0x400) { amount = 0x400; last = 0; }
                message->signature = 0x44535359;
                message->command = 0xcf;
                message->size = amount + 20;
                message->parameter = !last;
                message->length = amount;
                VectorizedInvertedMemcpy(source + var3, message->payload, amount);
                if (!func_ov031_0220ff18(storage)) break;
                var3 += amount;
                data_ov031_0224e580->request->unknown_18_ = var3;
            } while (var3 < data_ov031_0224e580->request->length);
            if (last) {
                func_ov031_0220fea0();
                Struct_ov031_0220f8a8_3* request = data_ov031_0224e580->request;
                if (var3 != request->unknown_24_) request->unknown_20_ = 0;
            }
        }
    }
    func_ov031_0220fed8();
}
