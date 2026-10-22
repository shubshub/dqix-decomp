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
void CallFunc0204c804OverAllElems(struct Cont0207fe44* obj);

// USA: func_ov003_021786bc
extern "C" ARM void func_ov003_021786bc(unsigned char* self) {
    unsigned char state = *(unsigned char*)(self + J(0x1000 + 0x3f));
    struct Obj2081* elemObj = *(struct Obj2081**)(self + J(0x89c));

    if (state == 0) {
        *(unsigned short*)(self + J(0x1000 + 0x46)) &= ~0x400;
        *(short*)(self + J(0xf00 + 0xfe)) = 2;
        if (*(short*)(self + J(0x1000 + 4)) < 0) {
            short id = FindMappedMemberId02080468(elemObj, *(short*)(self + J(0xf00 + 0xfe)));
            *(short*)(self + J(0x1000 + 4)) = id;
        }
        short value = *(short*)(self + J(0x1000 + 4));
        *(short*)((char*)elemObj + RG(0x36, 0x2a)) = value;
        func_020813ec(elemObj, *(short*)(self + J(0xf00 + 0xfe)), value);
        SetEntryLowNibbleAndElement02080c68(elemObj, *(short*)(self + J(0xf00 + 0xfe)), 0);
        SetElementFlag0x40_02081ea4(elemObj, *(short*)(self + J(0xf00 + 0xfe)), 0);
        ResetWithSub0208203c((struct Obj0208203c*)(self + J(0x88c)));
        *(void**)(self + J(0xff8)) = 0;
        (*(unsigned char*)(self + J(0x1000 + 0x3f)))++;
        return;
    }

    if (state != 1) return;

    *(void**)(self + J(0xff8)) = self + J(0x1000 + 4);
    if (func_ov003_021765b4(self) != 0) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        ResetWithSub0208203c((struct Obj0208203c*)(self + J(0x88c)));
        *(void**)(self + J(0xff8)) = 0;

        unsigned char mode = 0;
        short mark = -1;
        *(short*)(self + J(0x1000)) = mark;
        switch (*(short*)(self + J(0x1000 + 4))) {
        case 4:
            mark = 1;
            mode = 2;
            SetEntryLowNibbleAndElement02080c68(elemObj, *(short*)(self + J(0xf00 + 0xfe)), 1);
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
            SetEntryLowNibbleAndElement02080c68(elemObj, *(short*)(self + J(0xf00 + 0xfe)), 1);
            *(short*)(self + J(0xf00 + 0xfc)) = *(short*)(self + J(0xf00 + 0xfe));
            break;
        case 6:
            mode = 9;
            mark = 6;
            CallFunc0204c804OverAllElems((struct Cont0207fe44*)elemObj);
            break;
        }

        *(short*)(self + J(0x1000 + 0x36)) = mark;
        *(unsigned char*)(self + J(0x1000 + 0x3e)) = mode;
        *(unsigned char*)(self + J(0x1000 + 0x3f)) = 0;
        return;
    }

    if (func_ov003_021766e8(self) == 0) return;
    ResetWithSub0208203c((struct Obj0208203c*)(self + J(0x88c)));
    *(void**)(self + J(0xff8)) = 0;
    *(unsigned char*)(self + J(0x1000 + 0x3e)) = 9;
    *(short*)(self + J(0x1000 + 0x36)) = 6;
    CallFunc0204c804OverAllElems((struct Cont0207fe44*)elemObj);
}
