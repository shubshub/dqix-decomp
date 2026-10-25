#include <globaldefs.h>

struct Struct_ov031_02210bec_2 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    char unknown_18_[0x3fc];
};

struct Struct_ov031_02210bec {
    char unknown_0_[0x28];
    int unknown_28_;
    int unknown_2c_;
    void (*unknown_30_)(int);
    char unknown_34_[0xc];
    int unknown_40_;
    char unknown_44_[0x45];
    char unknown_89_[0x12c];
    char unknown_1b5_;
};

extern Struct_ov031_02210bec* data_ov031_0224e588;
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
int STD_GetStringLength(const char* s);
int CopyStringBounded020d2f28(char* dst, const char* src, int n);
extern "C" int func_ov031_0221042c(unsigned char* buf);
extern "C" int func_ov031_022104e4(unsigned char* buf);
extern "C" void func_ov031_02210358(int a, int b);
void ResetFieldAndUnblock_022103f8(void* value);
void SetGlobal0224e588Deref_022103dc(void* value);

// USA: func_ov031_02210bec
extern "C" ARM void func_ov031_02210bec(void) {
    int var0;
    unsigned int var1;
    unsigned char var2[0x414];
    Struct_ov031_02210bec_2* var3 = (Struct_ov031_02210bec_2*)var2;
    unsigned int var4;

    if (data_ov031_0224e588->unknown_40_ != 3) {
        func_ov031_022103f8((void*)5);
        return;
    }
    data_ov031_0224e588->flag_1b5 = 0;
    len = STD_GetStringLength(data_ov031_0224e588->name);
    length = len + 0x19;
    VectorizedMemset(buffer, 0, sizeof(buffer));
    msg->length = length;
    msg->magic = 0x44535359;
    msg->command = 0xd3;
    msg->code = 0;
    msg->unknown_10 = data_ov031_0224e588->unknown_28;
    msg->unknown_14 = data_ov031_0224e588->unknown_2c;
    CopyStringBounded020d2f28(msg->name, data_ov031_0224e588->name, len + 1);
    if (func_ov031_0221042c(buffer) != length) {
        ResetFieldAndUnblock_022103f8((void*)5);
        return;
    }
    var4 = func_ov031_022104e4(var2);
    if (var4 < 0xc || var4 != var3->unknown_0_) {
        func_ov031_022103f8((void*)5);
        return;
    }
    switch (var3->unknown_8_) {
    case 0xca:
        switch (var3->unknown_c_) {
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
            data_ov031_0224e588->unknown_40_ = 0;
            VectorizedMemset(&data_ov031_0224e588->unknown_44_, 0, 0x174);
            func_ov031_022103dc((void*)5);
            return;
        }
        func_ov031_022103f8((void*)5);
        return;
    case 0xd4:
        if (data_ov031_0224e588->unknown_2c_ == 0) {
            int var5 = var3->unknown_c_;
            data_ov031_0224e588->unknown_2c_ = var5;
            if (data_ov031_0224e588->unknown_30_ != NULL) {
                data_ov031_0224e588->unknown_30_(var5);
            }
        }
        func_ov031_022103dc((void*)7);
        return;
    }
    func_ov031_02210358(2, -0x28);
    func_ov031_022103f8((void*)5);
}
