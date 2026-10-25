#include <globaldefs.h>

extern unsigned char g_sePlayer;
extern char g_bgmPlayer;
unsigned char GetByteFieldAt0xcc_0205ea18(unsigned char*);
unsigned char GetField0xcc0209ca98(char*);

#if defined(jpn)
#define FIELDS_0215b234 0x1af4
#else
#define FIELDS_0215b234 0x1c2c
#endif

// USA: func_ov002_0215b234  (semantic: Trans_0215b234)
extern "C" ARM void func_ov002_0215b234(unsigned char* self) {
    self[FIELDS_0215b234] = GetField0xcc0209ca98(&g_bgmPlayer);
    self[FIELDS_0215b234 + 1] = GetByteFieldAt0xcc_0205ea18(&g_sePlayer);
}
