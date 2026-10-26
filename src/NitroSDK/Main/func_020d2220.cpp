#include <globaldefs.h>

extern "C" void func_020d2820(void);
extern "C" void func_020d2a48(void*);
struct Struct_020d217c_2;
extern "C" void func_020d248c(Struct_020d217c_2*);
extern "C" int func_020d2404(int);
extern "C" void func_020d24c4(int);

struct Struct_02112a60 {
    struct Struct_02112a60* next;
    unsigned char pad[20];
};
extern struct Struct_02112a60 data_02112a60[256] __attribute__((aligned(32)));

extern int data_02114248;

struct Struct_02112780 {
    struct Struct_02112a60* pool;
    int field4;
    struct Struct_02112a60* head;
    struct Struct_02112a60* tail;
    void* last;
    int field14;
    int field18;
    int field1c;
    int field20;
};
extern struct Struct_02112780 data_02112780;

struct Struct_02113780 {
    unsigned char pad[0xac8];
    int tail;
};
extern struct Struct_02113780 data_02113780;

struct Struct_021127e0 {
    unsigned char pad[0x280];
};
extern struct Struct_021127e0 data_021127e0;
extern struct Struct_021127e0* data_021142c0;

struct Struct_020d2220 {
    void* next;
    int kind;
    void* arg;
};

// USA: func_020d2220
extern "C" ARM void func_020d2220(void) {
    int i;
    struct Struct_020d2220* node;
    func_020d2820();
    data_02112780.pool = data_02112a60;
    for (i = 0; i < 255; i++) {
        data_02112a60[i].next = &data_02112a60[i + 1];
    }
    data_02113780.tail = 0;
    data_02112780.last = &data_02114248;
    data_02112780.head = 0;
    data_02112780.tail = 0;
    data_02112780.field1c = 0;
    data_02112780.field14 = 0;
    data_02112780.field18 = 0;
    data_02112780.field20 = 1;
    data_02112780.field4 = 0;
    data_021142c0 = &data_021127e0;
    func_020d2a48(&data_021127e0);
    node = (struct Struct_020d2220*)func_020d2404(1);
    if (node == 0) return;
    node->kind = 0x1d;
    node->arg = data_021142c0;
    func_020d248c((Struct_020d217c_2*)node);
    func_020d24c4(1);
}
