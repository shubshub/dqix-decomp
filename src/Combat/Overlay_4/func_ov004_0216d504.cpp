#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { flagOffset = 0xc9d };
#else
enum { flagOffset = 0xf71 };
#endif

extern "C" void func_020aaf84(void*, int, int, int);
extern "C" unsigned char func_0209ca98(char* obj);
extern "C" unsigned char func_0205ea18(unsigned char* obj);
extern "C" void func_0209ca70(void* obj, int val);
struct Obj0205e9f4;
extern "C" void func_0205e9f4(struct Obj0205e9f4* obj, int state);
extern "C" void func_02012028(void* obj, unsigned char value);
extern "C" void func_0200fb94(char* obj, unsigned char value);
extern "C" void func_02012010(void* obj, int value);
extern "C" void func_ov011_021848a0(void* obj, int val);

#if defined(jpn)
struct Struct_ov004_02171034_4 { unsigned char pad0[6]; unsigned char field1; unsigned char field4; unsigned char pad8[4]; unsigned char* unknown_10_; };
#else
struct Struct_ov004_02171034_4 {
    unsigned char pad0[1];
    unsigned char field1;
    unsigned char pad2[2];
    unsigned char field4;
    unsigned char pad5[0xb];
    unsigned char* unknown_10_;
};
#endif
extern Struct_ov004_02171034_4 data_ov004_02171034;
extern char g_bgmPlayer;
extern unsigned char g_sePlayer;

// USA: func_ov004_0216d504
extern "C" ARM int func_ov004_0216d504(void* self) {
    func_020aaf84(data_ov004_02171034.unknown_10_, 0, 0, 0);
    data_ov004_02171034.field4 = func_0209ca98(&g_bgmPlayer);
    data_ov004_02171034.field1 = func_0205ea18(&g_sePlayer);
    func_0209ca70(&g_bgmPlayer, 3);
    func_0205e9f4((struct Obj0205e9f4*)&g_sePlayer, 3);

    GameState* battle = GameState::GetInstance();
    func_02012028(battle, 0);
    ((unsigned char*)battle + 0x7000)[flagOffset] = 0;
    func_0200fb94((char*)battle, 0);
    func_02012010(battle, 5);

    func_ov011_021848a0(self, 0x3e7);
    return 0;
}
