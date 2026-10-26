#include <globaldefs.h>

extern "C" int func_02003c80(char* buf, int limit, const char* fmt, void* args);

// KEEP-NAME: the ROM symbol is the C library name, not a func_ tag.
// USA: func_02003ce8
// The `...` makes mwccarm home r0-r3 on entry; the argument list then starts one
// word past the (word-aligned) address of `fmt`, which is what the ROM computes.
extern "C" ARM int sprintf(char* buf, const char* fmt, ...) {
    const char** slot = (const char**)((unsigned int)&fmt & ~3u);
    return func_02003c80(buf, -1, fmt, (void*)(slot + 1));
}
