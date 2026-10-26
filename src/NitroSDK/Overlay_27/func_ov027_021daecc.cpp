#include <globaldefs.h>

extern "C" unsigned int func_ov027_021dd024(void);
extern "C" unsigned short func_ov027_021dd038(void);
extern "C" void func_ov027_021dae1c(void);
extern "C" int func_020d69cc(int a0, int a1, int a2, int a3, unsigned short a4, unsigned char a5);

struct Struct_ov027_021daecc {
    unsigned char pad0[0x4b4];
    unsigned char unknown_4b4_;
    unsigned char pad1[0x4bc - 0x4b5];
    Struct_ov027_021daecc* next;
};

struct Struct_ov027_021dd940_5 {
    unsigned char pad0[0x18];
    Struct_ov027_021daecc* head;
    Struct_ov027_021daecc* cur;
    unsigned char pad1[0x24 - 0x20];
    unsigned char state;
    unsigned char pad2;
    unsigned char fieldB;
};

extern Struct_ov027_021dd940_5 data_ov027_021dd940;
extern int data_ov027_021dd980;

// USA: func_ov027_021daecc
#pragma optimize_for_size off
extern "C" ARM int func_ov027_021daecc(void) {
    Struct_ov027_021daecc* head = data_ov027_021dd940.head;
    if (head == 0) {
        unsigned int a = func_ov027_021dd024();
        func_020d69cc(0, (int)&data_ov027_021dd980, 0x70, a, func_ov027_021dd038(), 8);
        return 0;
    }
    Struct_ov027_021daecc* cur = data_ov027_021dd940.cur;
    if (cur == 0 || cur->next == 0) {
        cur = *(Struct_ov027_021daecc* *)&data_ov027_021dd940.head;
    } else {
        cur = cur->next;
    }
    data_ov027_021dd940.cur = cur;
    func_ov027_021dae1c();
    data_ov027_021dd940.fieldB = data_ov027_021dd940.cur->unknown_4b4_;
    data_ov027_021dd940.state = 2;
    return 1;
}
