#include <globaldefs.h>

struct Struct_0200eca0_2 {
    const char* unknown_0_;
    void* unknown_4_;
    unsigned int unknown_8_;
    void* unknown_c_;
    unsigned int unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
};

struct Struct_0200eca0 {
    unsigned int unknown_0_;
    void* header;
    void* cursor;
    void* unknown_c_;
    void* unknown_10_;
    unsigned int unknown14;
};

struct Struct_0200eca0_3 {
    int unknown_0_;
    const char* unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

extern "C" void* func_0200dad4(unsigned int, Struct_0200eca0*);
extern "C" void func_0200efb8();
extern "C" void func_0200f1fc(Struct_0200eca0_2*, Struct_0200eca0*);
extern "C" void* func_0200e830(Struct_0200eca0_2*, Struct_0200eca0*);
extern "C" unsigned char* func_0200ea68(Struct_0200eca0_2*, Struct_0200eca0*, Struct_0200eca0_3*);
extern "C" void* func_0200d9e4(void*, int*);
extern "C" void* func_0200d958(void*, int*);
extern "C" void func_0200df80(Struct_0200eca0_2*, Struct_0200eca0*, unsigned char*);
extern "C" void func_0200ec44(Struct_0200eca0_2*, int, int);
extern "C" void func_0200f2ec(Struct_0200eca0_2*, Struct_0200eca0*, unsigned int);

// USA: func_0200eca0
// KEEP-NAME
extern "C" ARM void func_0200eca0(Struct_0200eca0_2* context) {
    Struct_0200eca0 table;
    Struct_0200eca0_3 handler;
    func_0200dad4(context->unknown_10_, &table);
    if (!table.header) func_0200efb8();
    func_0200f1fc(context, &table);
    if (context->unknown_0_) context->unknown_c_ = 0;
    else {
        context->unknown_c_ = func_0200e830(context, &table);
        if (!context->unknown_c_) func_0200efb8();
    }
    unsigned char* record = func_0200ea68(context, &table, &handler);
    handler.unknown_4_ = (const char*)(record[1] | record[2] << 8 | record[3] << 16 | record[4] << 24);
    void* cursor = func_0200d9e4(record + 5, &handler.unknown_8_);
    func_0200d958(cursor, &handler.unknown_c_);
    func_0200df80(context, &table, record);
    func_0200ec44(context, handler.unknown_c_, handler.unknown_0_);
    func_0200f2ec(context, &table, table.unknown_0_ + handler.unknown_8_);
}
