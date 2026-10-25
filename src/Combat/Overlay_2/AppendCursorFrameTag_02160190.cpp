#include <globaldefs.h>

#if defined(jpn)
enum { CursorOffset = 0x1ace };
#else
enum { CursorOffset = 0x1c06 };
#endif

int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);

// USA: func_ov002_02160190
ARM void AppendCursorFrameTag_02160190(char* base, char* dst, int flag) {
    if (flag) {
        int cursor = *(short*)(base + CursorOffset);
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    int cursor2 = *(short*)(base + CursorOffset);
    Text_AppendCursorTag(dst, cursor2);
}
