#include <globaldefs.h>
#include "GameState/GameState.h"

struct BackgroundGraphics;
struct Struct_0204b878;
struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
struct Struct_ov000_02173954;

extern "C" void Background_ClearMap(struct BackgroundGraphics*, void*);
extern "C" void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Window_ClearLayers(struct Cont0205d1e0*);
extern "C" void Window_DrawPanes(struct Cont0205d228*);
extern "C" void Window_FlushLayers(struct Cont0205d274*);
extern "C" void* Background_GetScreen(struct BackgroundGraphics*, unsigned int);
extern "C" void func_0204b878(struct Struct_0204b878*, int, int, int, short, short, short, short, unsigned short);
extern "C" void func_ov000_0217f5e4(struct Struct_ov000_02173954*, int);

extern "C" void Background_FlushMap(void*, int);
extern "C" void* LinkSession_GetInstance(void*);
extern "C" void OamManager_GetInstance(void*);
extern "C" void func_ov000_0217a8f4(void*);
extern "C" void func_ov000_021750e4(void*);
extern "C" void func_ov000_02175544(void*);
extern "C" void func_ov000_02180bac(void*);
extern "C" void func_ov000_02170538(void*, int, int, int);
extern "C" int func_ov000_0217f5dc(void*);
extern "C" void func_ov000_021707f0(void*);
extern "C" void func_ov000_02181164(void*, int, int, int, int, int, int, int);
extern "C" int func_ov000_02174324(void*, int, int, int);
extern "C" void func_ov000_02180ca8(void*, void*, void*);
#if defined(jpn)
extern "C" void func_ov000_0218124c(void*, int, void*, int, short, short);
#else
extern "C" void func_ov000_0218124c(void*, int, void*, int, short, short, short, short);
#endif
extern "C" void func_ov000_021741e0(void* obj, float maxSpeed, float speed, int x, int arg4,
    unsigned char arg5, unsigned char arg6, unsigned char arg7, unsigned char arg8, unsigned char arg9);
#if defined(jpn)
extern "C" void func_ov000_021811f4(void*, int, void*, int, short, short);
#else
extern "C" void func_ov000_021811f4(void*, int, short, short);
#endif

extern const int data_ov000_021833cc[][2];
extern const int data_ov000_021833c8[][2];
extern const int data_ov000_02183390[];
extern const int data_ov000_02183398[];
extern const int data_ov000_021833dc[][2];
extern const int data_ov000_021833d8[][2];

struct Struct_ov000_02173954_2 {
    char pad0[8];
    short unknown_8_;
    short sa;
    short unknown_c_;
    short se;
    char pad1[0x24 - 0x10];
    unsigned char flags;
    char pad2[0x44 - 0x25];
    int x;
    int y;
    int idx;
#if defined(jpn)
    char pad3[0x47f - 0x50];
    unsigned char unknown_47f_;
#else
    char pad3[0x440 - 0x50];
#endif
    unsigned char unknown_440_;
#if defined(jpn)
    char pad4[0x488 - 0x481];
#else
    char pad4[0x448 - 0x441];
#endif
};

static inline int inline_ov000_0215f57c(int i) { return i >= 0 && i <= 3; }

// USA: func_ov000_02173954
extern "C" ARM void func_ov000_02173954(char* obj) {
#if defined(jpn)
    if (*(unsigned short*)(obj + 0x1faa) & 0x80) {
#else
    if (*(unsigned short*)(obj + 0x1d72) & 0x80) {
#endif
        Background_ClearMap((struct BackgroundGraphics*)(obj + 0x8a4), 0);
        Background_DrawScreen((struct BackgroundGraphics*)(obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
        Window_ClearLayers((struct Cont0205d1e0*)(obj + 0x188));
        Background_FlushMap(obj + 0x8c4, 0);
        return;
    }
    func_ov000_0217a8f4(obj);
    func_ov000_021750e4(obj);
    Background_ClearMap((struct BackgroundGraphics*)(obj + 0x8a4), 0);
    Background_DrawScreen((struct BackgroundGraphics*)(obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
    Window_ClearLayers((struct Cont0205d1e0*)(obj + 0x188));
#if defined(jpn)
    if (*(unsigned char*)(obj + 0x1fb8) == 0 && (*(unsigned short*)(obj + 0x1faa) & 0x600)) {
#else
    if (*(unsigned char*)(obj + 0x1d80) == 0 && (*(unsigned short*)(obj + 0x1d72) & 0x600)) {
#endif
        Window_DrawPanes((struct Cont0205d228*)(obj + 0x188));
        func_ov000_02175544(obj);
        Background_FlushMap(obj + 0x8a4, 0);
        Background_FlushMap(obj + 0x8c4, 0);
        Window_FlushLayers((struct Cont0205d274*)(obj + 0x188));
        func_ov000_02180bac(obj);
        return;
    }
    OamManager_GetInstance(LinkSession_GetInstance(GameState::GetInstance()));
    signed char* ids;
#if defined(jpn)
    int x, y;
#endif
    int tx, ty;
    int found;
    int var4, var5;
#if defined(jpn)
    int idx, w;
#endif
    short var6, var7;
    unsigned char var8;
#if defined(jpn)
    unsigned char var9;
#else
    int x, y;
#endif
    struct Struct_ov000_02173954_2* e;
#if defined(jpn)
    int i, h;
#else
    int i, idx, w, h;
#endif
    found = -1;
    for (i = 0; i < 4; i++) {
        ids = (signed char*)(obj + 0x6c);
        e = (struct Struct_ov000_02173954_2*)(obj + 0x958) + ids[i];
        idx = e->idx;
        if (idx < 0) continue;
        w = e->unknown_c_;
        h = e->se;
        var6 = e->unknown_8_;
        var7 = e->sa;
        var8 = e->unknown_440_;
#if defined(jpn)
        var9 = e->unknown_47f_;
#endif
        if (e->flags & 8) {
            func_ov000_02170538(e, *(int*)(obj + 0x940), *(int*)(obj + 0x944), *(unsigned char*)(obj + 0x954));
        } else {
            func_ov000_02170538(e, 0, 0, *(unsigned char*)(obj + 0x954));
        }
        x = e->x;
        y = e->y;
        tx = x >> 3;
        ty = y >> 3;
        if (!func_ov000_0217f5dc(e)) continue;
        func_ov000_0217f5e4((struct Struct_ov000_02173954*)obj, (int)e);
        if (e->flags & 4) {
            found = idx;
            int wh[2];
            int a[2] = { x + 0x37, x + 0x37 };
            int b[2] = { y + 0x1c, y + 0x2c };
#if defined(jpn)
            int c[2] = { i * 3 + 0x60, i * 3 + 0x6c };
#else
            int c[2] = { i * 3 + 0x64, i * 3 + 0x70 };
#endif
            int p = *(int*)(obj + 0x170) + 0x118;
            var4 = 0;
            int d[2];
            wh[0] = w;
            wh[1] = h;
            d[0] = p;
            d[1] = p;
            for (; var4 < 2; var4++) {
                func_ov000_02181164(obj, wh[var4], d[var4], a[var4], b[var4], 1, c[var4], 0xa);
            }
            float var23[2];
            var23[0] = (1.52f * (float)w) / (float)var6;
            var23[1] = (1.52f * (float)h) / (float)var7;
            int var24[2] = { w, h };
            int j = 0;
#if defined(jpn)
#else
            int base = i * 2 + 1;
#endif
            for (; j < 2; j++) {
                if (var24[j] > 0) {
                    int var27 = y + data_ov000_021833cc[j][0];
                    unsigned char g = data_ov000_02183390[j];
                    unsigned char var29 = i + data_ov000_02183398[j];
#if defined(jpn)
                    unsigned char var30 = (i * 2 + 1) - (-j);
#else
                    unsigned char var30 = base + j;
#endif
                    func_ov000_021741e0(obj, var23[j], 1.52f, x + data_ov000_021833c8[j][0], var27, g, var29, var30, 1, 0);
                }
            }
            Background_DrawScreen((struct BackgroundGraphics*)(obj + 0x8c4), 1, 0, 0, tx, ty, 0x20, 0x19, idx + 2);
#if defined(jpn)
            if (!func_ov000_02174324(obj, ids[i], x + 0x25, y + 0x17)) {
                func_ov000_021811f4(obj, idx, obj + 0x8c4, var9, tx + 7, ty + 3);
                func_ov000_0218124c(obj, idx, obj + 0x8c4, var8, tx + 2, ty + 2);
#else
            if (!func_ov000_02174324(obj, ids[i], x + 0x24, y + 0x16)) {
                func_ov000_021811f4(obj, idx, x + 0x2c, y + 0x16);
                func_ov000_0218124c(obj, idx, obj + 0x8c4, var8, tx + 2, ty + 2, x + 0xc, y + 0x16);
#endif
            }
            func_ov000_021707f0(e);
        } else {
            int var31 = 0;
            int var32 = 0;
            if (e->flags & 8) {
                var31 = *(int*)(obj + 0x940);
                var32 = *(int*)(obj + 0x944);
            }
            int wh[2];
#if defined(jpn)
            int a[2] = { x + 0x72 + var31, x + 0x72 + var31 };
#else
            int a[2] = { x + 0x6a + var31, x + 0x6a + var31 };
#endif
            int b[2] = { y + 1 + var32, y + 0xf + var32 };
#if defined(jpn)
            int c[2] = { i * 3 + 0x60, i * 3 + 0x6c };
#else
            int c[2] = { i * 3 + 0x64, i * 3 + 0x70 };
#endif
            int p = *(int*)(obj + 0x170) + 0x118;
            var5 = 0;
            int d[2] = { p, p };
            wh[0] = w;
            wh[1] = h;
            for (; var5 < 2; var5++) {
                func_ov000_02181164(obj, wh[var5], d[var5], a[var5], b[var5], 1, c[var5], 9);
            }
            float var39[2];
            var39[0] = (1.28f * (float)w) / (float)var6;
            var39[1] = (1.28f * (float)h) / (float)var7;
            int var40[2] = { w, h };
            int j = 0;
#if defined(jpn)
#else
            int base = i * 2 + 1;
#endif
            for (; j < 2; j++) {
                if (var40[j] > 0) {
                    int var43 = y + data_ov000_021833dc[j][0];
                    unsigned char g = data_ov000_02183390[j];
                    unsigned char var45 = i + data_ov000_02183398[j];
#if defined(jpn)
                    unsigned char var46 = (i * 2 + 1) - (-j);
#else
                    unsigned char var46 = base + j;
#endif
                    func_ov000_021741e0(obj, var39[j], 1.28f, x + data_ov000_021833d8[j][0], var43, g, var45, var46, 1, 1);
                }
            }
            char* list = obj + 0x8c4;
            if (e->flags & 8) list = obj + 0x8a4;
            void* ent = Background_GetScreen((struct BackgroundGraphics*)(obj + 0x8c4), 2);
#if defined(jpn)
            func_0204b878((struct Struct_0204b878*)list, (int)ent, 0, 0, tx + 2, ty, 0x20, 0x19, idx + 2);
#else
            func_0204b878((struct Struct_0204b878*)list, (int)ent, 0, 0, tx + 1, ty, 0x20, 0x19, idx + 2);
#endif
            func_ov000_02180ca8(obj, e, list);
#if defined(jpn)
            if (!func_ov000_02174324(obj, idx, x + 0x30, y + 0x16)) {
                func_ov000_021811f4(obj, idx, list, var9, tx + 8, ty + 3);
                func_ov000_0218124c(obj, idx, list, var8, tx + 3, ty + 2);
#else
            if (!func_ov000_02174324(obj, idx, x + 0x28, y + 0x16)) {
                func_ov000_021811f4(obj, idx, x + 0x2c, y + 0x16);
                func_ov000_0218124c(obj, idx, list, var8, tx + 2, ty + 2, x + 0x14, y + 0x16);
#endif
            }
        }
    }
    if (inline_ov000_0215f57c(found)) {
        Window_DrawPanes((struct Cont0205d228*)(obj + 0x188));
        func_ov000_02175544(obj);
    }
    Background_FlushMap(obj + 0x8a4, 0);
    Background_FlushMap(obj + 0x8c4, 0);
    Window_FlushLayers((struct Cont0205d274*)(obj + 0x188));
}
