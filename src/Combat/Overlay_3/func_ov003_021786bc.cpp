#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif
#define J(o) RG(o, (o) - 0x84)

struct Struct_0207fdcc_2;
struct Struct_0207fe44;
struct Struct_02081f20_2;
struct SePlayer;

extern "C" short func_02080468(void* obj, int id);
extern "C" void func_020813ec(void* obj, int id, int value);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_02081ea4(struct Struct_0207fdcc_2* obj, int id, int value);
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);
extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);
extern struct SePlayer g_sePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_0207fe44(struct Struct_0207fe44* obj);

// USA: func_ov003_021786bc
extern "C" ARM void func_ov003_021786bc(unsigned char* self) {
    unsigned char state = *(unsigned char*)(self + J(0x1000 + 0x3f));
    struct Struct_0207fdcc_2* var1 = *(struct Struct_0207fdcc_2**)(self + J(0x89c));

    if (state == 0) {
        *(unsigned short*)(self + J(0x1000 + 0x46)) &= ~0x400;
        *(short*)(self + J(0xf00 + 0xfe)) = 2;
        if (*(short*)(self + J(0x1000 + 4)) < 0) {
            short id = func_02080468(var1, *(short*)(self + J(0xf00 + 0xfe)));
            *(short*)(self + J(0x1000 + 4)) = id;
        }
        short value = *(short*)(self + J(0x1000 + 4));
        *(short*)((char*)var1 + RG(0x36, 0x2a)) = value;
        func_020813ec(var1, *(short*)(self + J(0xf00 + 0xfe)), value);
        func_02080c68(var1, *(short*)(self + J(0xf00 + 0xfe)), 0);
        func_02081ea4(var1, *(short*)(self + J(0xf00 + 0xfe)), 0);
        func_0208203c((struct Struct_02081f20_2*)(self + J(0x88c)));
        *(void**)(self + J(0xff8)) = 0;
        (*(unsigned char*)(self + J(0x1000 + 0x3f)))++;
        return;
    }

    if (state != 1) return;

    *(void**)(self + J(0xff8)) = self + J(0x1000 + 4);
    if (func_ov003_021765b4(self) != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        func_0208203c((struct Struct_02081f20_2*)(self + J(0x88c)));
        *(void**)(self + J(0xff8)) = 0;

        unsigned char mode = 0;
        short var5 = -1;
        *(short*)(self + J(0x1000)) = var5;
        switch (*(short*)(self + J(0x1000 + 4))) {
        case 4:
            var5 = 1;
            mode = 2;
            func_02080c68(var1, *(short*)(self + J(0xf00 + 0xfe)), 1);
            *(short*)(self + J(0xf00 + 0xfc)) = *(short*)(self + J(0xf00 + 0xfe));
            *(unsigned short*)(self + J(0x1000 + 0x46)) |= 0x20;
            *(short*)(self + J(0x1000 + 0x14)) = 0;
            *(short*)(self + J(0x1000 + 0x16)) = _s32_div_f(*(unsigned char*)(self + J(0x835)) + 5, 6);
            *(unsigned short*)(self + J(0x1000 + 0x46)) &= ~0x400;
            if (*(short*)(self + J(0x1000 + 0x16)) > 1) {
                *(unsigned short*)(self + J(0x1000 + 0x46)) |= 0x400;
            }
            break;
        case 5:
            mode = 3;
            *(short*)(self + J(0x1000 + 0xc)) = 0x76;
            func_02080c68(var1, *(short*)(self + J(0xf00 + 0xfe)), 1);
            *(short*)(self + J(0xf00 + 0xfc)) = *(short*)(self + J(0xf00 + 0xfe));
            break;
        case 6:
            mode = 9;
            var5 = 6;
            func_0207fe44((struct Struct_0207fe44*)var1);
            break;
        }

        *(short*)(self + J(0x1000 + 0x36)) = var5;
        *(unsigned char*)(self + J(0x1000 + 0x3e)) = mode;
        *(unsigned char*)(self + J(0x1000 + 0x3f)) = 0;
        return;
    }

    if (func_ov003_021766e8(self) == 0) return;
    func_0208203c((struct Struct_02081f20_2*)(self + J(0x88c)));
    *(void**)(self + J(0xff8)) = 0;
    *(unsigned char*)(self + J(0x1000 + 0x3e)) = 9;
    *(short*)(self + J(0x1000 + 0x36)) = 6;
    func_0207fe44((struct Struct_0207fe44*)var1);
}
