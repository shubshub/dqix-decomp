#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char* arg0, int arg1, int arg2);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

extern "C" void func_020dc4d0(signed char* arg0, signed char* arg1);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* arg0);

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendFormatted02041fac(char* buf, int a, int b);
int AppendPaletteTag_02041e70(char* dst, int palette);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int CallFunc020e0434With02153694_020e51cc(int value);
extern "C" int func_ov002_02159774(void* base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215e250
extern "C" ARM void func_ov002_0215e250(unsigned char* arg0, char* arg1, int arg2) {
    if (arg1 == NULL) return;

    GameState* var0 = GameState::GetInstance();
    int var1 = *(short*)(arg0 + RG(0x1bf6, 0x1abe));

    signed char var2[7];
    signed char var3;
    func_020dc4d0(var2, &var3);

    signed char var4 = 0;
    for (int var5 = 0; var5 < var3; var5++) {
        GameObject* var6 = func_0200ff1c(var0, var2[var5]);
        if (var6 != NULL) {
            if (func_02061bd8((struct Struct_0205faf4_11*)var6) != 0) {
                var4++;
            }
        }
    }
    var3 = var3 - var4;

    int var7 = 0;
    if (arg2) {
        func_02041c08(arg1, var1, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var1);

    int field = KeyTable_Get((struct Container020e0310*)(base + RG(0x20, 0x8)), 2);
    AppendFormatted02041fac(dst, field, 0x16);

    for (int var9 = 0; var9 < var3; var9++) {
        GameObject* var10 = var0->GetPartyMemberByIndex(var2[var7]);
        if (var10 != NULL) {
            GameObject* var11 = func_0200ff1c(var0, var2[var7]);
            if (func_02061bd8((struct Struct_0205faf4_11*)var11) != 0) {
                for (int var12 = 0; var12 < 4; var12++) {
                    var7 = (var7 + 1) % 4;
                    if (var7 == 0) break;
                    GameObject* var13 = func_0200ff1c(var0, var2[var7]);
                    if (var13 == NULL) continue;
                    if (func_02061bd8((struct Struct_0205faf4_11*)var13) != 0) continue;
                    var0->GetPartyMemberByIndex(var2[var7]);
                    break;
                }
            }

            int var14 = func_ov002_02159774(arg0, var2[var7], 0, 1, 1);
            func_02041e70(arg1, var14);
            func_02041b70(arg1, var9, (const char*)(arg0 + RG(0x1ab0, 0x1a08) + var2[var7] * RG(0x3c, 0x18)));
            func_02041e70(arg1, 0xf);
            func_02042058(arg1, *(const char**)(arg0 + 0x1000 + RG(0xbdc, 0xaa4)));

            var7++;
        }
    }

#if defined(jpn)
    AppendNameTag_02041b70(dst, count, (const char*)KeyTable_Get((struct Container020e0310*)(base + 0x8), 0x76d));
#else
    func_02041b70(arg1, var3, (const char*)func_020e51cc(0x1a));
#endif
}
