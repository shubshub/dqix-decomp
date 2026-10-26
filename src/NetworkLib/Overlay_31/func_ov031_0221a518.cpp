#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/ProcessorContext.h"
#include "std_library_functions.h"


struct Struct_ov031_0221a518 {
    void* allocator;
    void* unknown_4_;
    unsigned char unknown_8_[0x1b38];
    ProcessorContext context;
    unsigned char padding[0x1c1c - 0x1c00];
    void* work;
};
struct Struct_ov031_0221a518_2 {
    const char* name;
    int field4;
    unsigned int unknown_8_;
    void* allocator;
    void* unknown_10_;
    int unknown_14_;
    int unknown_18_;
};
extern Struct_ov031_0221a518* data_ov031_0224e69c;
extern const char* data_ov031_02249b54;
extern const char data_ov031_0224a264[];
extern const char data_ov031_0224a284[];
extern const char data_ov031_0224a28c[];
extern const char data_ov031_0224a294[];
extern "C" void HaltSystem();
extern "C" int func_ov031_02217c00(void*, Struct_ov031_0221a518_2*);
extern "C" int func_ov031_022178b4(void*, void*, int);
extern "C" void func_ov031_022183b4(void*);
extern "C" int func_ov031_02218604(void*, const char*, const void*, int);
extern "C" int func_ov031_02217d1c(void*);
extern "C" void func_ov031_02217db4(void*, int);
extern "C" int func_ov031_022175dc(void*);
bool IsContextInactive(ProcessorContext*);
extern "C" void func_ov031_02211b08(int, int);

// USA: func_ov031_0221a518
extern "C" ARM int func_ov031_0221a518(const void* value, void* work) {
    data_ov031_0224e69c->work = work;
    VectorizedMemset(work, 0, 0x174);
    if (data_ov031_0224e69c->context.uniqueID && !IsContextInactive(&data_ov031_0224e69c->context)) HaltSystem();
    Struct_ov031_0221a518_2 var0;
    Struct_ov031_0221a518* var1 = data_ov031_0224e69c;
    var0.name = data_ov031_02249b54;
    var0.field4 = 0;
    var0.unknown_8_ = 0x1000;
    var0.allocator = var1->allocator;
    var0.unknown_10_ = var1->unknown_4_;
    if (strcmp(var0.name, data_ov031_0224a264) != 0) var0.unknown_14_ = 1;
    else var0.unknown_14_ = 0;
    var0.unknown_18_ = 20000;
    if (func_ov031_02217c00(var1->unknown_8_, &var0)) {
        func_ov031_02211b08(9, -24100);
        return 0;
    }
    unsigned char buffer[0x94];
    if (!func_ov031_022175dc(buffer) || !func_ov031_022178b4(data_ov031_0224e69c->unknown_8_, buffer, 0)) {
        func_ov031_022183b4(data_ov031_0224e69c->unknown_8_);
        func_ov031_02211b08(9, -24100);
        return 0;
    }
    if (func_ov031_02218604(data_ov031_0224e69c->unknown_8_, data_ov031_0224a284, data_ov031_0224a28c, 6) ||
        func_ov031_02218604(data_ov031_0224e69c->unknown_8_, data_ov031_0224a294, value, 4)) {
        func_ov031_022183b4(data_ov031_0224e69c->unknown_8_);
        func_ov031_02211b08(9, -24100);
        return 0;
    }
    if (func_ov031_02217d1c(data_ov031_0224e69c->unknown_8_)) {
        func_ov031_022183b4(data_ov031_0224e69c->unknown_8_);
        func_ov031_02211b08(9, -24100);
        return 0;
    }
    int priority = GetContextPriority(data_02111304.activeContext);
    func_ov031_02217db4(data_ov031_0224e69c->unknown_8_, priority - 1);
    if (data_ov031_0224e69c->context.uniqueID) return 1;
    func_ov031_022183b4(data_ov031_0224e69c->unknown_8_);
    func_ov031_02211b08(9, -24100);
    return 0;
}
