#include <globaldefs.h>

extern int g_sePlayer;
extern int data_02109bf4;

unsigned char GetByteFieldAt0xcc_0205ea18(unsigned char* obj);
void SetModeClamped0209ca70(void* obj, int val);
struct Obj0205e9f4;
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);

// USA: func_ov002_0215b268
ARM void SyncModeIfChanged0215b268(char* p) {
#if defined(jpn)
    enum { regionalMode = 0xaf4 };
#else
    enum { regionalMode = 0xc2c };
#endif
    unsigned char a = GetByteFieldAt0xcc_0205ea18((unsigned char*)&g_sePlayer);
    unsigned char b1 = *(unsigned char*)(p + 0x1000 + regionalMode);
    SetModeClamped0209ca70(&data_02109bf4, b1);
    unsigned char b2 = *(unsigned char*)(p + 0x1000 + regionalMode + 1);
    SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)&g_sePlayer, b2);
    unsigned char b3 = *(unsigned char*)(p + 0x1000 + regionalMode + 1);
    if (a == b3) return;
    SePlayer_Play((struct SePlayer*)&g_sePlayer, 1, 0);
}
