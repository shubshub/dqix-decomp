#include <globaldefs.h>

typedef void (*Type_ov027_021d8c94)(int, int, int);

extern void* data_ov027_021e33ec;

extern "C" int func_ov027_021d9bdc(void);
extern "C" void func_ov027_021d9e04(int a, short arg1);
extern "C" unsigned int func_ov027_021dd024();
extern "C" unsigned int func_ov027_021dd038();
extern "C" void MIi_CpuClearFast(unsigned int value, void* dest, int count);
extern "C" void VectorizedMemset(void* dst, int val, int size);

extern "C" void func_ov027_021d8c20(int index, int value, int c);
extern "C" void func_ov027_021d9618(int index);
extern "C" void func_ov027_021dd5f4(int arg0);
extern "C" int func_ov027_021dd04c();
extern "C" void func_ov027_021dae40(int a, int b, int c);

struct Struct_ov027_021d8c94;
extern "C" void func_ov027_021dad14(Struct_ov027_021d8c94* s, int a, unsigned int flags, int c);

// USA: func_ov027_021d8c94
extern "C" ARM void func_ov027_021d8c94(int type, void* obj) {
    switch (type) {
    case 0x15:
        func_ov027_021d8c20(0, 1, (int)obj);
        break;
    case 0: {
        unsigned short v = *(unsigned short*)((char*)obj + 0x10);
        if (v != 0 && v < 0x10) {
            func_ov027_021d8c20(v, 2, (int)obj);
        }
        break;
    }
    case 1: {
#define V (*(unsigned short*)((char*)obj + 0x10))
        unsigned short var1 = V;
        if (var1 != 0 && var1 < 0x10) {
            *(unsigned short*)((char*)data_ov027_021e33ec + (V - 1) * 2 + 0x1400 + 0x8a) = 0;
            VectorizedMemset((char*)data_ov027_021e33ec + 0x14a8 + (V - 1) * 4, 0, 4);
            VectorizedMemset((char*)data_ov027_021e33ec + 0x1340 + (V - 1) * 0x16, 0, 0x16);
            func_ov027_021dd5f4(V);
            *(unsigned short*)((char*)data_ov027_021e33ec + (V - 1) * 2 + 0x1700 + 0x54) = 0;
            {
                unsigned short v2 = V;
                int idx2 = v2 - 1;
                signed char slot = *(signed char*)((char*)data_ov027_021e33ec + idx2 + 0x1500 + 0x26);
                if (slot != -1) {
                    int mask = ~(1 << v2);
                    int off = (unsigned char)slot * 0x5d4;
                    *(unsigned short*)((char*)data_ov027_021e33ec + off + 0x1d00 + 0x4e) &= mask;
                    *(unsigned short*)((char*)data_ov027_021e33ec + off + 0x1d00 + 0x50) |= (1 << v2);
                    *(signed char*)((char*)data_ov027_021e33ec + idx2 + 0x1000 + 0x526) = -1;
                    *(unsigned short*)((char*)data_ov027_021e33ec + off + 0x1d00 + 0x4c) &= mask;
                }
            }
            if (*(unsigned short*)((char*)data_ov027_021e33ec + 0x1500 + 0x36) & (1 << V)) {
                (*(unsigned char*)((char*)data_ov027_021e33ec + 0x1000 + 0x535))--;
                *(unsigned short*)((char*)data_ov027_021e33ec + 0x1500 + 0x36) &= ~(1 << V);
            }
            if (*(int*)((char*)data_ov027_021e33ec + (V - 1) * 4 + 0x1000 + 0x4e8) == 8) {
                func_ov027_021d8c20(V, 9, 0);
            }
            func_ov027_021d8c20(V, 3, (int)obj);
            *(int*)((char*)data_ov027_021e33ec + (V - 1) * 4 + 0x1000 + 0x4e8) = 0;
        }
#undef V
        break;
    }
    case 3:
        func_ov027_021d9618((int)obj);
        break;
    case 0x19:
        func_ov027_021d9bdc();
        break;
    case 0x1c: {
        unsigned char i = 0;
        do {
            int off = i * 0x5d4;
            if (*(unsigned char*)((char*)data_ov027_021e33ec + off + 0x1d52) != 0) {
                unsigned short var9 = *(unsigned short*)((char*)data_ov027_021e33ec + off + 0x1d50);
                if (var9 != 0) {
                    unsigned short var10 = *(unsigned short*)((char*)data_ov027_021e33ec + off + 0x1d4e);
                    func_ov027_021dad14((Struct_ov027_021d8c94*)((char*)data_ov027_021e33ec + 0x6c + 0x1800 + off),
                        (int)((char*)data_ov027_021e33ec + 0x1340), var10, var9);
                    *(unsigned short*)((char*)data_ov027_021e33ec + off + 0x1d50) = 0;
                }
            }
            i++;
        } while (i < 0x10);
        unsigned int a = func_ov027_021dd024();
        unsigned int b = func_ov027_021dd038();
        int c = func_ov027_021dd04c();
        func_ov027_021dae40(a, b, c);
        break;
    }
    case 0xff: {
        unsigned short f2 = *(unsigned short*)((char*)obj + 0x2);
        switch (f2) {
        case 1: case 4: case 5: case 6: case 8: case 9:
            func_ov027_021d9e04(0, 9);
            break;
        case 0: case 2: case 3: case 7: case 10: case 11: case 12: case 13: case 14: case 15:
        default:
            func_ov027_021d9e04(0, 8);
            break;
        }
        break;
    }
    case 0x100: {
        unsigned short f0 = *(unsigned short*)((char*)obj + 0x0);
        switch (f0) {
        case 0: case 7: case 8: case 13: case 14: case 15: case 17: case 18: case 21: case 25: case 29:
            func_ov027_021d9e04(0, 9);
            break;
        case 1: case 2: case 3: case 4: case 5: case 6: case 9: case 10: case 11: case 12:
        case 16: case 19: case 20: case 22: case 23: case 24: case 26: case 27: case 28:
        default:
            func_ov027_021d9e04(0, 8);
            break;
        }
        break;
    }
    case 0x11:
    default:
        break;
    }

    if (type == 0x11) {
        void* root = data_ov027_021e33ec;
        Type_ov027_021d8c94 cb = *(Type_ov027_021d8c94*)((char*)root + 0x14e4);
        MIi_CpuClearFast(0, root, 0x7d00);
        data_ov027_021e33ec = 0;
        if (cb) cb(0, 0xc, 0);
    }
}
