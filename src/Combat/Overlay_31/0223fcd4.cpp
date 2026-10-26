typedef void* (*Type_ov031_022128fc)(unsigned int, unsigned int);
typedef void (*Type_ov031_022128fc_2)(void*);
struct Struct_ov031_02290fbc {
    int active;
    int error;
    Type_ov031_022128fc unknown_8_;
    Type_ov031_022128fc_2 unknown_c_;
    int field10;
    int field14;
    void* buffer;
    int field1c;
    int field20;
};
extern Struct_ov031_02290fbc data_ov031_02290fbc;
extern "C" int func_ov031_022402f4(void);
extern "C" void func_ov031_0224030c(void);
extern "C" int func_ov031_02240338(int, int);

// USA: func_ov031_0223fcd4
extern "C" int func_ov031_0223fcd4(Type_ov031_022128fc arg0, Type_ov031_022128fc_2 arg1, int argument) {
    data_ov031_02290fbc.unknown_8_ = arg0;
    data_ov031_02290fbc.unknown_c_ = arg1;
    data_ov031_02290fbc.error = 0;
    data_ov031_02290fbc.field1c = 0;
    data_ov031_02290fbc.field20 = 0;
    data_ov031_02290fbc.field10 = 0;
    data_ov031_02290fbc.field14 = 0;
    switch (func_ov031_022402f4()) {
    case 0:
        data_ov031_02290fbc.error = 9;
        return 0;
    default: break;
    }
    void* buffer = data_ov031_02290fbc.unknown_8_(0x2000, 8);
    data_ov031_02290fbc.buffer = buffer;
    if (!buffer) {
        data_ov031_02290fbc.error = 1;
        func_ov031_0224030c();
        return 0;
    }
    if (func_ov031_02240338(argument, (int)buffer)) {
        data_ov031_02290fbc.active = 1;
        return 1;
    }
    data_ov031_02290fbc.error = 9;
    data_ov031_02290fbc.unknown_c_(data_ov031_02290fbc.buffer);
    func_ov031_0224030c();
    return 0;
}
