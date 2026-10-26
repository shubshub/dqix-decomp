#include <globaldefs.h>

typedef void* (*Type_ov031_022128fc)(unsigned int, unsigned int);
typedef void (*Type_ov031_022128fc_2)(void*);
struct Struct_ov031_02290da0_2 {
    int field0;
    int handle;
    void* unknown_8_;
    Type_ov031_022128fc unknown_c_;
    void* identity;
    int active;
    void* callback;
    int error;
    Type_ov031_022128fc_2 unknown_20_;
    int state;
    int field28, field2c, unknown_30_;
};
extern Struct_ov031_02290da0_2 data_ov031_02290da0;
extern unsigned char data_ov031_02290de0[], data_ov031_02290dd4[], data_ov031_02290e0c[], data_ov031_02290df4[];
extern char data_ov031_02290e28[];
extern "C" void func_ov031_0223fae8(void*);
extern "C" int func_ov031_0223ea60(char*);
extern "C" void* func_ov031_0223e674(const char*);
extern "C" int func_ov031_0223e454(void*, const void*, int);
extern "C" int func_ov031_0223fa34();
extern "C" int func_ov031_0223f9f0();
extern "C" int func_ov031_0223fcd4(Type_ov031_022128fc, Type_ov031_022128fc_2, int);
extern "C" int func_ov031_0223e8d4(void*);
extern "C" void func_ov031_0223fa08();

// USA: func_ov031_0223e6c0
extern "C" ARM int func_ov031_0223e6c0(Type_ov031_022128fc arg0, Type_ov031_022128fc_2 arg1, const char* identity, const char* arg3, const void* arg4, const void* token, void* callback) {
    data_ov031_02290da0.unknown_c_ = arg0;
    data_ov031_02290da0.unknown_20_ = arg1;
    data_ov031_02290da0.callback = callback;
    data_ov031_02290da0.error = 0;
    data_ov031_02290da0.field28 = 0;
    data_ov031_02290da0.field2c = 0;
    data_ov031_02290da0.unknown_30_ = 0;
    data_ov031_02290da0.handle = 0;
    data_ov031_02290da0.state = -1;
    data_ov031_02290da0.unknown_8_ = 0;
    data_ov031_02290da0.identity = 0;
    func_ov031_0223fae8(data_ov031_02290de0);
    func_ov031_0223ea60(data_ov031_02290e28);
    if ((data_ov031_02290da0.identity = func_ov031_0223e674(identity)) &&
        (data_ov031_02290da0.unknown_8_ = func_ov031_0223e674(arg3))) {
        int length = func_ov031_0223e454(data_ov031_02290dd4, arg4, 4);
        data_ov031_02290dd4[length] = 0;
        length = func_ov031_0223e454(data_ov031_02290e0c, token, 16);
        data_ov031_02290e0c[length] = 0;
        if (func_ov031_0223fa34() && func_ov031_0223f9f0()) {
            if (func_ov031_0223fcd4(arg0, arg1, 10)) {
                data_ov031_02290da0.handle = func_ov031_0223e8d4(data_ov031_02290df4);
                data_ov031_02290da0.active = 1;
                return 1;
            }
            func_ov031_0223fa08();
        }
        data_ov031_02290da0.unknown_20_(data_ov031_02290da0.unknown_8_);
        data_ov031_02290da0.unknown_20_(data_ov031_02290da0.identity);
        data_ov031_02290da0.error = 8;
        return 0;
    }
    if (data_ov031_02290da0.unknown_8_) data_ov031_02290da0.unknown_20_(data_ov031_02290da0.unknown_8_);
    if (data_ov031_02290da0.identity) data_ov031_02290da0.unknown_20_(data_ov031_02290da0.identity);
    data_ov031_02290da0.error = 1;
    return 0;
}
