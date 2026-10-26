#include <globaldefs.h>

struct Struct_ov031_02220190 {
    unsigned char unknown_0_[4];
    unsigned char size;
    unsigned char type;
    unsigned short command;
    int result;
};
extern "C" int func_ov031_02206f3c();
extern "C" void func_ov031_0220781c(unsigned int value, unsigned char* output);
extern "C" int func_ov031_02220178(void* context, void* request, void* arg2, int first, int second);

// USA: func_ov031_02220190
extern "C" THUMB int func_ov031_02220190(void* context, int first, int second) {
    Struct_ov031_02220190 request;
    request.size = 8;
    request.type = 2;
    request.result = -1;
    request.command = 0x1e6;
    func_ov031_0220781c(func_ov031_02206f3c(), request.unknown_0_);
    return func_ov031_02220178(context, &request.size, request.unknown_0_, first, second);
}
