#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
struct Struct0200fb08;
extern "C" int GameState_GetLanguage(Struct0200fb08*);
extern "C" int STD_GetStringLength(const char*);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern char data_020e7e35[7];
extern char data_020e7e30[5];
// USA: func_020680cc
extern "C" ARM int func_020680cc(const char* text) {
    if (GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance()) == 3) {
        char var0[7];
        char suffix[5];
        INLINE_MEMCPY(var0, data_020e7e35, 7);
        INLINE_MEMCPY(suffix, data_020e7e30, 5);
        int length = STD_GetStringLength(text);
        if (length) {
            char last = text[length - 1];
            for (char* var4 = var0; *var4; var4++) {
                if (!*var4) break;
                if (*var4 == last) return 1;
            }
            if (length >= 4 && memcmp(text + (length - 4), suffix, 4) == 0) return 1;
        }
    }
    return 0;
}
