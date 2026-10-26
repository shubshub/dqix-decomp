#include <globaldefs.h>


void InitializeCardReading(void);
void SetReadContextPriority(unsigned int priority);
int GenerateLockOwnerID(void);
extern "C" void HaltSystem(void);
extern "C" void func_020d0040(int mode);
extern "C" int func_020d06fc(void* handle);
extern "C" void func_020d0050(int value);

struct Struct_02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
};

extern struct Struct_02108dfc data_02108dfc;
extern unsigned char data_020f0dc8;

// USA: func_020758a8
extern "C" ARM void func_020758a8(void) {
    int id;

    InitializeCardReading();
    SetReadContextPriority(8);

    id = GenerateLockOwnerID();
    if (id == -3) {
        HaltSystem();
    }

    data_02108dfc.value = (unsigned short)id;
    func_020d0040((int)data_02108dfc.value);
    func_020d06fc((void*)0x1001);
    func_020d0050((int)data_02108dfc.value);
    data_020f0dc8 = 1;
}
