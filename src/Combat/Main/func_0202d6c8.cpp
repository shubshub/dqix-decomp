#include <globaldefs.h>
extern "C" void OS_GetMacAddress(void*);
void SetField0x48UnlessState9Or10_0202c848(int);
extern "C" int func_0202d788(unsigned short);
extern char data_021015a0[];
static inline unsigned long inline_0202d6c8() { return *(volatile unsigned long*)0x027ffc3c; }
// USA: func_0202d6c8
extern "C" ARM int func_0202d6c8() {
    unsigned short mac[3];
    OS_GetMacAddress(mac);
    *(unsigned*)(data_021015a0 + 0x20) = (mac[0] + OS_GetVBlankCount() + mac[1] + mac[2]) * 0x00010dcd + 0x3039;
    *(unsigned short*)(data_021015a0 + 2) = 0;
    *(unsigned short*)(data_021015a0 + 6) = 0x65;
    *(int*)(data_021015a0 + 0x10) = 3;
    int var1 = func_0202d788(1);
    if (var1 == 0x18) { func_0202c848(0x18); *(int*)(data_021015a0 + 0x10) = 9; return 0; }
    if (var1 == 2) return 1;
    func_0202c848(var1);
    *(int*)(data_021015a0 + 0x10) = 9;
    return 0;
}
