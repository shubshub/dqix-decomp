#include <globaldefs.h>

extern unsigned char g_sePlayer;
extern char g_bgmPlayer;
extern "C" unsigned char func_0205ea18(unsigned char*);
extern "C" unsigned char func_0209ca98(char*);

#if defined(jpn)
#define FIELDS_0215b234 0x1af4
#else
#define FIELDS_0215b234 0x1c2c
#endif

// USA: func_ov002_0215b234
extern "C" ARM void func_ov002_0215b234(unsigned char* self) {
    self[FIELDS_0215b234] = func_0209ca98(&g_bgmPlayer);
    self[FIELDS_0215b234 + 1] = func_0205ea18(&g_sePlayer);
}
