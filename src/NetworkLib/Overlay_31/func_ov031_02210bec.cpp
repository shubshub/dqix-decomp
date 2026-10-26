#include <globaldefs.h>

struct Struct_ov031_02210bec_2 {
    unsigned int length;
    unsigned int magic;
    unsigned int command;
    int code;
    int unknown_10;
    int unknown_14_;
    char name[0x3fc];
};

struct Struct_ov031_02210bec {
    char unknown_0_[0x28];
    int unknown_28_;
    int unknown_2c_;
    void (*callback)(int);
    char unknown_34_[0xc];
    int state;
    char unknown_44_[0x45];
    char name[0x12c];
    char unknown_1b5_;
};

extern Struct_ov031_02210bec* data_ov031_0224e588;
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
extern "C" int STD_GetStringLength(const char* s);
extern "C" int func_020d2f28(char* dst, const char* src, int n);
extern "C" int func_ov031_0221042c(unsigned char* buf);
extern "C" int func_ov031_022104e4(unsigned char* buf);
extern "C" void func_ov031_02210358(int a, int b);
extern "C" void func_ov031_022103f8(void* value);
extern "C" void func_ov031_022103dc(void* value);

// USA: func_ov031_02210bec
extern "C" ARM void func_ov031_02210bec(void) {
    int len;
    unsigned int length;
    unsigned char buffer[0x414];
    Struct_ov031_02210bec_2* msg = (Struct_ov031_02210bec_2*)buffer;
    unsigned int var4;

    if (data_ov031_0224e588->state != 3) {
        func_ov031_022103f8((void*)5);
        return;
    }
    data_ov031_0224e588->unknown_1b5_ = 0;
    len = STD_GetStringLength(data_ov031_0224e588->name);
    length = len + 0x19;
    VectorizedMemset(buffer, 0, sizeof(buffer));
    msg->length = length;
    msg->magic = 0x44535359;
    msg->command = 0xd3;
    msg->code = 0;
    msg->unknown_10 = data_ov031_0224e588->unknown_28_;
    msg->unknown_14_ = data_ov031_0224e588->unknown_2c_;
    func_020d2f28(msg->name, data_ov031_0224e588->name, len + 1);
    if (func_ov031_0221042c(buffer) != length) {
        func_ov031_022103f8((void*)5);
        return;
    }
    var4 = func_ov031_022104e4(buffer);
    if (var4 < 0xc || var4 != msg->length) {
        func_ov031_022103f8((void*)5);
        return;
    }
    switch (msg->command) {
    case 0xca:
        switch (msg->code) {
        case 0x15:
            func_ov031_02210358(2, -2);
            break;
        case 0x18:
            func_ov031_02210358(6, -0x14);
            break;
        case 0x1b:
            func_ov031_02210358(2, -2);
            break;
        case 0x1d:
            data_ov031_0224e588->state = 0;
            VectorizedMemset(&data_ov031_0224e588->unknown_44_, 0, 0x174);
            func_ov031_022103dc((void*)5);
            return;
        }
        func_ov031_022103f8((void*)5);
        return;
    case 0xd4:
        if (data_ov031_0224e588->unknown_2c_ == 0) {
            int code = msg->code;
            data_ov031_0224e588->unknown_2c_ = code;
            if (data_ov031_0224e588->callback != NULL) {
                data_ov031_0224e588->callback(code);
            }
        }
        func_ov031_022103dc((void*)7);
        return;
    }
    func_ov031_02210358(2, -0x28);
    func_ov031_022103f8((void*)5);
}
