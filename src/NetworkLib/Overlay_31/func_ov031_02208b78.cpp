#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "NitroSDK/NetworkProtocolVersion.h"

extern "C" void func_ov031_02207a10(void* obj);
extern "C" int func_ov031_02208a40(void* addr, int v1, int v2);

// USA: func_ov031_02208b78
extern "C" ARM int func_ov031_02208b78(void* obj, unsigned char* data) {
    int var0 = func_ov031_02208aa0(data[0], data[1]);
    if (!var0) return var0;

    VectorizedInvertedMemcpy(data + 2, (char*)obj + 0x34, 0x20);
    unsigned char b = data[0x22];
    unsigned char* p = data + 0x23;
    if (b != 0x20) {
        *(unsigned char*)((char*)obj + 0x30) = 0;
    } else {
        VectorizedInvertedMemcpy(p, (char*)obj + 0x74, 0x20);
        func_ov031_02207a10(obj);
    }

    unsigned char* addr = p + b;
    int len = addr[0];
    len = (len << 8) + addr[1];

    unsigned short ret = (unsigned short)func_ov031_02208a40(addr + 2, len / 2, 2);
    *(unsigned short*)((char*)obj + 0x32) = ret;
    if (ret != 0) {
        ret = 1;
        *(unsigned char*)((char*)obj + 0x455) = 1;
    }
    return ret;
}
