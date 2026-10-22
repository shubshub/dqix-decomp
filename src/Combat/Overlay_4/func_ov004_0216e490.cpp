#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020aaf84(void* arg0, int arg1, int arg2, int arg3);
struct Struct_02000c9c_11;
extern "C" void func_0201155c(struct Struct_02000c9c_11* arg0);
extern "C" unsigned char func_0209ca98(char* arg0);
extern "C" unsigned char func_0205ea18(unsigned char* arg0);
extern "C" void func_0209ca70(void* arg0, int arg1);
struct Struct_02108760_2;
extern "C" void func_0205e9f4(struct Struct_02108760_2* arg0, int arg1);
extern "C" int func_020ac864(int arg0);
extern "C" void func_ov011_021848a0(void* arg0, int arg1);
extern "C" int func_020aba5c(int arg0);
extern "C" int func_020421a0(void);
extern "C" void func_02043204(char* arg0);
extern "C" void func_02043124(char* arg0);
extern "C" void* func_ov004_0216ae9c(void* arg0, int arg1);
extern "C" void func_ov023_021f8960(char* arg0, short arg1, unsigned short arg2);
extern "C" void func_0200fb94(char* arg0, unsigned char arg1);

extern unsigned char data_ov004_02171034[];
extern int data_02109bf4;
extern int g_sePlayer;

// USA: func_ov004_0216e490
extern "C" ARM int func_ov004_0216e490(void* arg0) {
    GameState* var0 = GameState::GetInstance();
#if defined(jpn)
    data_ov004_02171034[3] = 0;
    int var1 = func_020aaf84(*(void**)&data_ov004_02171034[0xc], 0, 1, 0);
#else
    data_ov004_02171034[5] = 0;
    int var1 = func_020aaf84(*(void**)&data_ov004_02171034[0x10], 0, 1, 0);
#endif
    if (var1 == 0) {
        func_0201155c((struct Struct_02000c9c_11*)var0);
#if defined(jpn)
        data_ov004_02171034[3] = 1;
#else
        data_ov004_02171034[5] = 1;
#endif
    } else {
        unsigned char var2 = func_0209ca98((char*)&data_02109bf4);
#if defined(jpn)
        data_ov004_02171034[7] = var2;
#else
        data_ov004_02171034[4] = var2;
#endif
        unsigned char v2 = GetByteFieldAt0xcc_0205ea18((unsigned char*)&g_sePlayer);
#if defined(jpn)
        data_ov004_02171034[6] = var3;
#else
        data_ov004_02171034[1] = var3;
#endif
        SetModeClamped0209ca70(&data_02109bf4, 3);
        SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)&g_sePlayer, 3);
        if (VerifyAndApplySaveBuffer_020ac864(1) == 0) {
#if defined(jpn)
            data_ov004_02171034[3] = 1;
#else
            data_ov004_02171034[5] = 1;
#endif
        }
    }

#if defined(jpn)
    if (data_ov004_02171034[3] != 0) {
#else
    if (data_ov004_02171034[5] != 0) {
#endif
        func_ov011_021848a0(arg0, 0x3e7);
        return 0;
    }
#if defined(jpn)
    if (data_ov004_02171034[1] == 1) {
#else
    if (data_ov004_02171034[0] == 1) {
#endif
        if (func_020aba5c(1) == 0) {
            char* var4 = (char*)func_020421a0();
            func_02043204(var4);
            func_02043124(var4);
            void* var5 = func_ov004_0216ae9c(arg0, 0xd4);
            func_ov023_021f8960((char*)var5, 0, 7);
            func_ov011_021848a0(arg0, 0x1f5);
            return 0;
        } else {
            func_0200fb94((char*)var0, 5);
#if defined(jpn)
            data_ov004_02171034[0] = 0;
#else
            data_ov004_02171034[2] = 0;
#endif
            func_ov011_021848a0(arg0, 0x3e7);
            return 0;
        }
    }
    return 0;
}
