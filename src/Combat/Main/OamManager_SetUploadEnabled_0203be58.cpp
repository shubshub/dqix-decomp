#include <globaldefs.h>

enum { kUploadOamFlags = 0xc };  // data_02105ab4: +0xc main, +0xd sub (OamManager_UploadBuffers)

// Main, originally SetByteAt0xc0203be58 (USA 0x0203be58, EUR 0x0203be68, JPN 0x0203b8b0)
extern "C" ARM void OamManager_SetUploadEnabled(char* oamManager, int screen, int enabled) {
    *(oamManager + screen + kUploadOamFlags) = enabled;
}
