#include <globaldefs.h>


extern "C" void VCountIrq_PushDisable(void);
extern "C" void func_020d84e4(void);
extern "C" void func_020d84e8(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void VCountIrq_PopDisable(void);
extern "C" void HaltSystem(void);
extern "C" int LinkSession_IsActive(int* obj);

struct Struct_0205e1e4_2 {
    char pad[0x18];
    struct Struct_0205e1e4_2* next;
};
struct Struct_0205e1e4 {
    struct Struct_0205e1e4_2* head;
    struct Struct_0205e1e4_2* tail;
    int count;
};
extern "C" struct Struct_0205e1e4_2* func_0205e1e4(struct Struct_0205e1e4* list);

struct Struct_0205e18c_2 {
    char pad[0x18];
    struct Struct_0205e18c_2* next;
};
struct Struct_0205e18c {
    struct Struct_0205e18c_2* head;
    struct Struct_0205e18c_2* tail;
    int count;
};
extern "C" void func_0205e18c(struct Struct_0205e18c* list, struct Struct_0205e18c_2* node);

struct Struct_0205e3ec { unsigned int v[4]; };
struct Struct_0205e330_3 { unsigned char a; unsigned char b; unsigned char pad[2]; struct Struct_0205e3ec unknown_4_; };
extern "C" struct Struct_0205e330_3* func_0205e3ec(struct Struct_0205e330_3* dst, struct Struct_0205e330_3* src);

struct Struct_0205e330 {
    char pad[0x16];
    short unknown_16_;
};

struct Struct_0205e330_2 {
    char pad0[0x508];
    volatile int unknown_508_;
    char pad1[0x514 - 0x508 - 4];
    volatile int unknown_514_;
    char pad2[0x520 - 0x514 - 4];
    volatile int unknown_520_;
};

// USA: func_0205e330
extern "C" ARM void func_0205e330(unsigned char* obj, struct Struct_0205e330_3* arg1, short arg2) {
    struct Struct_0205e1e4_2* node;

    VCountIrq_PushDisable();
    func_020d84e4();

    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        node = func_0205e1e4((struct Struct_0205e1e4*)(obj + 0x1500));
        if (node != NULL) {
            func_0205e3ec((struct Struct_0205e330_3*)node, arg1);
            ((struct Struct_0205e330*)node)->unknown_16_ = arg2;
            func_0205e18c((struct Struct_0205e18c*)(obj + 0x150c), (struct Struct_0205e18c_2*)node);
        } else {
            for (int var1 = 0; var1 < ((struct Struct_0205e330_2*)(obj + 0x1000))->unknown_508_; var1++);

            for (int i1 = 0; i1 < ((struct Struct_0205e330_2*)(obj + 0x1000))->unknown_514_; i1++);

            for (int i2 = 0; i2 < ((struct Struct_0205e330_2*)(obj + 0x1000))->unknown_520_; i2++);

            HaltSystem();
        }
    }

    func_020d84e8();
    VCountIrq_PopDisable();
}
