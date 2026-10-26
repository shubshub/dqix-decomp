#if defined(jpn)
#define R(j,u) (j)
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>


struct Struct_ov027_021e33e0 {
    unsigned char pad0[8];
    unsigned char* ptr;
    unsigned char* ptrC;
};

extern Struct_ov027_021e33e0 data_ov027_021e33e0;

struct Struct_ov027_021dd8ec {
    unsigned char pad0[0xc];
    int unknown_c_;
};

extern Struct_ov027_021dd8ec data_ov027_021dd8ec;

struct Struct_ov027_021db524 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    unsigned short fa;
    unsigned short fc;
    unsigned short fe;
    unsigned short f10;
};

struct Struct_0202db64;

typedef void (*Type_ov027_021db524)(int, void*);

extern "C" ARM void func_ov027_021db524(Struct_ov027_021db524* msg);
extern "C" void func_ov027_021db4e0(int a);
extern "C" int func_ov027_021db430(void);
extern "C" void func_ov027_021dd0cc(int a, int b);
extern "C" void func_020d4770(int a, int b, int c);
extern "C" void func_020c976c(unsigned int cycles);
extern "C" void HaltSystem(void);

extern "C" void func_ov027_021db490(void);
extern "C" int func_020d507c(int a, Struct_0202db64* ctx);
extern "C" int func_020d6a84(int a, int mode);
extern "C" int func_020d51a8(int a, int b);
extern "C" int func_020d503c(int a);
extern "C" int func_020d57f4(int a, int b, int c, int d, unsigned short e, unsigned short f,
                      unsigned short g, int h, int i, int j, int k);
extern "C" int func_020d472c(void* p);

#pragma optimize_for_size off

// USA: func_ov027_021db524
extern "C" ARM void func_ov027_021db524(Struct_ov027_021db524* msg) {
    switch (msg->f0) {
    case 0:
        if (msg->f2 != 0) {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x100, msg);
        } else {
            func_ov027_021db490();
        }
        break;

    case 0x1d:
        if (msg->f2 != 0) {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x100, msg);
        } else {
            func_ov027_021dd0cc(7, func_020d507c((int)func_ov027_021db524,
                (Struct_0202db64*)data_ov027_021e33e0.ptr));
        }
        break;

    case 7: {
        Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
        fn(0x15, msg);
        func_ov027_021dd0cc(0x19, func_020d6a84((int)func_ov027_021db524, 1));
        break;
    }

    case 0x19:
        if (*(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) == 0) {
            if (msg->f2 != 0) {
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(0x100, msg);
            } else {
                func_ov027_021dd0cc(8, func_020d51a8((int)func_ov027_021db524,
                    data_ov027_021dd8ec.unknown_c_));
            }
        } else {
            if (msg->f2 != 0) {
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) = 0;
                {
                    Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                    fn(0x100, msg);
                }
            } else {
                func_ov027_021db4e0((int)msg);
            }
        }
        break;

    case 8:
        if (msg->f2 != 0) {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x100, msg);
        } else {
            switch (msg->f8) {
            case 0:
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x52a) = 0;
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x528) = 0;
                break;

            case 7: {
                if (*(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) == 1) break;
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x52a) |= 1 << msg->f10;
                {
                    Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                    fn(0, msg);
                }
                if (*(unsigned short*)(data_ov027_021e33e0.ptr + 0x528) == 0) {
                    unsigned char* stage = data_ov027_021e33e0.ptrC;
                    stage += 0x1000;
                    if (*(int*)(stage + 0x31c) == 0) {
                        int flag = 1;
                        *(int*)(stage + 0x31c) = flag;
                        if (*(unsigned short*)(data_ov027_021e33e0.ptr + 0x52c) != 0) flag = 0;
                        func_ov027_021dd0cc(0xe, func_020d57f4((int)func_ov027_021db524,
                            *(int*)(data_ov027_021e33e0.ptr + 0x504),
                            *(unsigned short*)(data_ov027_021e33e0.ptr + 0x51a),
                            (int)(data_ov027_021e33e0.ptr + 0x40),
                            *(unsigned short*)(data_ov027_021e33e0.ptr + 0x518),
                            (unsigned short)flag, 0, 0, 0, 1, 1));
                        break;
                    }
                }
                if (func_ov027_021db430() != 0) {
                    Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                    fn(0x19, 0);
                }
                break;
            }

            case 9: {
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x52a) &= ~(1 << msg->f10);
                {
                    Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                    fn(1, msg);
                }
                break;
            }

            case 2: {
                if (*(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) == 1) break;
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(0x1c, msg);
                break;
            }

            case 0x1a:
                break;

            default: {
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(0x100, msg);
                break;
            }
            }
        }
        break;

    case 14:
        *(int*)(data_ov027_021e33e0.ptrC + 0x131c) = 0;
        switch (msg->f4) {
        case 0xa:
            *(unsigned short*)(data_ov027_021e33e0.ptr + 0x528) = 1;
            if (*(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) == 0) {
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(0x19, 0);
            }
            break;

        case 0xb: {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(3, *(void**)((char*)msg + 8));
            break;
        }

        default: {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x100, msg);
            break;
        }
        }
        break;

    case 15:
        if (*(int*)(data_ov027_021e33e0.ptrC + 0x74c8) != 0) {
            unsigned int i;
            unsigned int count = 0;
            i = 0;
            do {
                if (*(int*)(data_ov027_021e33e0.ptrC + (i << 2) + 0x14e8) != 0) {
                    count++;
                    if (count >= 2) break;
                }
                i++;
            } while (i < 0xf);
            if (count == 1) {
                func_020c976c(0x32c8);
            }
        }
        data_ov027_021e33e0.ptr[0x50c] = 0;
        if (msg->f2 == 0) {
            {
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(2, msg);
            }
            if (*(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) == 0) {
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(0x19, 0);
            }
        } else if (msg->f2 == 0xa) {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x2a, msg);
        } else {
            {
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(0x13, msg);
            }
            if (*(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) == 0) {
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(0x19, 0);
            }
        }
        break;

    case 1:
        if (*(int*)(data_ov027_021e33e0.ptrC + 0x1320) == 0) {
            if (msg->f2 != 0) {
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) = 0;
                {
                    Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                    fn(0x100, msg);
                }
            } else {
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x52a) = 0;
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x528) = 0;
                func_ov027_021dd0cc(2, func_020d503c((int)func_ov027_021db524));
            }
        } else {
            func_020d4770(1, 0, 0);
            func_020d472c(0);
            if (msg->f2 != 0) {
                *(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) = 0;
                {
                    Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                    fn(0x100, msg);
                }
            } else {
                func_ov027_021dd0cc(0x19, func_020d6a84((int)func_ov027_021db524, 0));
            }
        }
        break;

    case 2:
        if (msg->f2 != 0) {
            *(unsigned short*)(data_ov027_021e33e0.ptr + 0x526) = 0;
            {
                Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
                fn(0x100, msg);
            }
        } else {
            func_ov027_021db4e0((int)msg);
        }
        break;

    case 13:
        if (msg->f2 != 0) break;
        *(unsigned short*)(data_ov027_021e33e0.ptr + 0x52a) &= ~msg->fa;
        break;

    case 0x80:
        switch (msg->f4) {
        case 0x10: {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x1d, msg);
            break;
        }
        case 0x11: {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x1f, msg);
            break;
        }
        case 0x12: {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x20, msg);
            break;
        }
        case 0x13: {
            Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
            fn(0x21, msg);
            break;
        }
        case 0x16:
            HaltSystem();
            break;
        case 0x17:
            break;
        default:
            break;
        }
        break;

    default: {
        Type_ov027_021db524 fn = *(Type_ov027_021db524*)(data_ov027_021e33e0.ptr + 0x51c);
        fn(0x100, msg);
        break;
    }
    }
}
