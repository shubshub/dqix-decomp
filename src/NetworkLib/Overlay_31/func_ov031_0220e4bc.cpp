#include <globaldefs.h>

extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220db6c(void);
extern "C" void func_ov031_0220d984(int, int, int, int);

extern void* data_ov031_0224e53c;

struct Struct_ov031_0220e4bc { short f0; unsigned short type; };

// USA: func_ov031_0220e4bc
extern "C" ARM void func_ov031_0220e4bc(struct Struct_ov031_0220e4bc *s) {
    switch (s->type) {
        case 0: {
            int f260 = *(int*)((char*)data_ov031_0224e53c + 0x2000 + 0x260);
            if (f260 == 0xc) {
                func_ov031_0220da1c(0xa);
                func_ov031_0220db6c();
                break;
            }
            *(short*)((char*)data_ov031_0224e53c + 0x2282) = 0;
            func_ov031_0220da1c(3);
            func_ov031_0220d984(0, (int)((char*)data_ov031_0224e53c + 0x2140), 0, 0x83d);
            break;
        }
        case 1:
        case 3:
            func_ov031_0220da1c(0xa);
            func_ov031_0220db6c();
            break;
        case 2:
        case 4:
        default:
            func_ov031_0220da1c(0xb);
            func_ov031_0220d984(7, (int)((char*)data_ov031_0224e53c + 0x2140), 0, 0x84f);
            break;
    }
}
