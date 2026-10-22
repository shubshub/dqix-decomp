#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif
#define J(o) RG(o, (o) - 0x84)

struct Obj2081;
struct Cont0207fe44;
struct Obj0208203c;
struct SePlayer;

short FindMappedMemberId02080468(void* obj, int id);
extern "C" void func_020813ec(void* obj, int id, int value);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void SetElementFlag0x40_02081ea4(struct Obj2081* obj, int id, int value);
void ResetWithSub0208203c(struct Obj0208203c* obj);
extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);
extern struct SePlayer g_sePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" int _s32_div_f(int a, int b);
extern "C" void func_0207fe44(struct Struct_0207fe44* arg0);

// USA: func_ov003_021786bc
extern "C" ARM void func_ov003_021786bc(unsigned char* arg0) {
    unsigned char var0 = *(unsigned char*)(arg0 + J(0x1000 + 0x3f));
    struct Struct_0207fdcc_2* var1 = *(struct Struct_0207fdcc_2**)(arg0 + J(0x89c));

    if (var0 == 0) {
        *(unsigned short*)(arg0 + J(0x1000 + 0x46)) &= ~0x400;
        *(short*)(arg0 + J(0xf00 + 0xfe)) = 2;
        if (*(short*)(arg0 + J(0x1000 + 4)) < 0) {
            short var2 = func_02080468(var1, *(short*)(arg0 + J(0xf00 + 0xfe)));
            *(short*)(arg0 + J(0x1000 + 4)) = var2;
        }
        short var3 = *(short*)(arg0 + J(0x1000 + 4));
        *(short*)((char*)var1 + RG(0x36, 0x2a)) = var3;
        func_020813ec(var1, *(short*)(arg0 + J(0xf00 + 0xfe)), var3);
        func_02080c68(var1, *(short*)(arg0 + J(0xf00 + 0xfe)), 0);
        func_02081ea4(var1, *(short*)(arg0 + J(0xf00 + 0xfe)), 0);
        func_0208203c((struct Struct_02081f20_2*)(arg0 + J(0x88c)));
        *(void**)(arg0 + J(0xff8)) = 0;
        (*(unsigned char*)(arg0 + J(0x1000 + 0x3f)))++;
        return;
    }

    if (var0 != 1) return;

    *(void**)(self + J(0xff8)) = self + J(0x1000 + 4);
    if (func_ov003_021765b4(self) != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        ResetWithSub0208203c((struct Obj0208203c*)(self + J(0x88c)));
        *(void**)(self + J(0xff8)) = 0;

        unsigned char var4 = 0;
        short var5 = -1;
        *(short*)(arg0 + J(0x1000)) = var5;
        switch (*(short*)(arg0 + J(0x1000 + 4))) {
        case 4:
            var5 = 1;
            var4 = 2;
            func_02080c68(var1, *(short*)(arg0 + J(0xf00 + 0xfe)), 1);
            *(short*)(arg0 + J(0xf00 + 0xfc)) = *(short*)(arg0 + J(0xf00 + 0xfe));
            *(unsigned short*)(arg0 + J(0x1000 + 0x46)) |= 0x20;
            *(short*)(arg0 + J(0x1000 + 0x14)) = 0;
            *(short*)(arg0 + J(0x1000 + 0x16)) = _s32_div_f(*(unsigned char*)(arg0 + J(0x835)) + 5, 6);
            *(unsigned short*)(arg0 + J(0x1000 + 0x46)) &= ~0x400;
            if (*(short*)(arg0 + J(0x1000 + 0x16)) > 1) {
                *(unsigned short*)(arg0 + J(0x1000 + 0x46)) |= 0x400;
            }
            break;
        case 5:
            var4 = 3;
            *(short*)(arg0 + J(0x1000 + 0xc)) = 0x76;
            func_02080c68(var1, *(short*)(arg0 + J(0xf00 + 0xfe)), 1);
            *(short*)(arg0 + J(0xf00 + 0xfc)) = *(short*)(arg0 + J(0xf00 + 0xfe));
            break;
        case 6:
            var4 = 9;
            var5 = 6;
            func_0207fe44((struct Struct_0207fe44*)var1);
            break;
        }

        *(short*)(arg0 + J(0x1000 + 0x36)) = var5;
        *(unsigned char*)(arg0 + J(0x1000 + 0x3e)) = var4;
        *(unsigned char*)(arg0 + J(0x1000 + 0x3f)) = 0;
        return;
    }

    if (func_ov003_021766e8(arg0) == 0) return;
    func_0208203c((struct Struct_02081f20_2*)(arg0 + J(0x88c)));
    *(void**)(arg0 + J(0xff8)) = 0;
    *(unsigned char*)(arg0 + J(0x1000 + 0x3e)) = 9;
    *(short*)(arg0 + J(0x1000 + 0x36)) = 6;
    func_0207fe44((struct Struct_0207fe44*)var1);
}
