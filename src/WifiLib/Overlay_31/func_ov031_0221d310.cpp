#include <globaldefs.h>


extern "C" int func_ov031_0221e650(const char* text);
extern "C" void func_ov031_0221e51c(void* dst, const void* src, unsigned int length);
extern char data_ov031_0224b0d0;
extern char data_ov031_0224b0dc;

// USA: func_ov031_0221d310
extern "C" THUMB int func_ov031_0221d310(void* obj) {
    *(int*)obj = func_ov031_0221e650(&data_ov031_0224b0d0);
    func_ov031_0221e51c((char*)obj + 0x4, &data_ov031_0224b0d0, *(int*)obj);
    *(int*)((char*)obj + 0x24) = 1;
    *(unsigned int*)((char*)obj + 0x28) = func_ov031_0221e650(&data_ov031_0224b0dc);
    unsigned int len2 = *(unsigned int*)((char*)obj + 0x28);
    if (len2 > 0xd) {
        return -1;
    }
    func_ov031_0221e51c((char*)obj + 0x2c, &data_ov031_0224b0dc, len2);
    return 0;
}
