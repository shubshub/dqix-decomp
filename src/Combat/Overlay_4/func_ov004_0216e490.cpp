#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020aaf84(void* ptr, int a, int b, int c);
struct StateBits5ccc_1155c;
void GameState_ClearErrorScreenRequest(struct StateBits5ccc_1155c* state);
unsigned char GetField0xcc0209ca98(char* obj);
unsigned char GetByteFieldAt0xcc_0205ea18(unsigned char* obj);
void SetModeClamped0209ca70(void* obj, int val);
struct Obj0205e9f4;
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
int VerifyAndApplySaveBuffer_020ac864(int flag);
extern "C" void func_ov011_021848a0(void* obj, int val);
int SendShortBufferOrReturnZero020aba5c(int flag);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
void* GetNodeIfType6_0216ae9c(void* a, int id);
void SetOffset100Fields_021f8960(char* base, short a, unsigned short b);
void SetByte0x4_0200fb94(char* obj, unsigned char value);

extern unsigned char data_ov004_02171034[];
extern int g_bgmPlayer;
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
    if (res == 0) {
        GameState_ClearErrorScreenRequest((struct StateBits5ccc_1155c*)bs);
#if defined(jpn)
        data_ov004_02171034[3] = 1;
#else
        data_ov004_02171034[5] = 1;
#endif
    } else {
        unsigned char v1 = GetField0xcc0209ca98((char*)&g_bgmPlayer);
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
        SetModeClamped0209ca70(&g_bgmPlayer, 3);
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
        if (SendShortBufferOrReturnZero020aba5c(1) == 0) {
            char* g = (char*)MessageSystem_GetInstance();
            MessageSystem_Reset(g);
            MessageSystem_Stop(g);
            void* node = GetNodeIfType6_0216ae9c(obj, 0xd4);
            SetOffset100Fields_021f8960((char*)node, 0, 7);
            func_ov011_021848a0(obj, 0x1f5);
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
