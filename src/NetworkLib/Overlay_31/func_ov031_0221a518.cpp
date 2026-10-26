#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/ProcessorContext.h"
#include "std_library_functions.h"


struct Struct_ov031_0221a518 {
    void* unknown_0_;
    void* unknown_4_;
    unsigned char unknown_8_[0x1b38];
    ProcessorContext unknown_1b40_;
    unsigned char unknown_1c08_[0x1c1c - 0x1c00];
    void* unknown_1c24_;
};
struct Struct_ov031_0221a518_2 {
    const char* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_;
    void* unknown_c_;
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
extern "C" int func_ov031_02217c00(void*, ServiceOptionsA518*);
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
    ServiceOptionsA518 options;
    RuntimeA518* runtime = data_ov031_0224e69c;
    options.name = data_ov031_02249b54;
    options.field4 = 0;
    options.bufferSize = 0x1000;
    options.allocator = runtime->allocator;
    options.allocatorContext = runtime->allocatorContext;
    if (strcmp(options.name, data_ov031_0224a264) != 0) options.differentName = 1;
    else options.differentName = 0;
    options.timeout = 20000;
    if (func_ov031_02217c00(runtime->service, &options)) {
        SetGlobal0224e5a4IfNotNine_ov031_02211b08(9, -24100);
        return 0;
    }
    unsigned char var2[0x94];
    if (!func_ov031_022175dc(var2) || !func_ov031_022178b4(data_ov031_0224e69c->unknown_8_, var2, 0)) {
        func_ov031_022183b4(data_ov031_0224e69c->unknown_8_);
        func_ov031_02211b08(9, -24100);
        return 0;
    }
    if (func_ov031_02218604(data_ov031_0224e69c->unknown_8_, data_ov031_0224a284, data_ov031_0224a28c, 6) ||
        func_ov031_02218604(data_ov031_0224e69c->unknown_8_, data_ov031_0224a294, arg0, 4)) {
        func_ov031_022183b4(data_ov031_0224e69c->unknown_8_);
        func_ov031_02211b08(9, -24100);
        return 0;
    }
    if (func_ov031_02217d1c(data_ov031_0224e69c->unknown_8_)) {
        func_ov031_022183b4(data_ov031_0224e69c->unknown_8_);
        func_ov031_02211b08(9, -24100);
        return 0;
    }
    int var3 = GetContextPriority(data_02111304.activeContext);
    func_ov031_02217db4(data_ov031_0224e69c->unknown_8_, var3 - 1);
    if (data_ov031_0224e69c->unknown_1b40_.uniqueID) return 1;
    func_ov031_022183b4(data_ov031_0224e69c->unknown_8_);
    func_ov031_02211b08(9, -24100);
    return 0;
}
