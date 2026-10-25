#if defined(jpn)
enum {SelectionOffset=0xd48, regionalOffset1=0x38, TextsOffset=0xc0};
#else
enum {SelectionOffset=0xd84, regionalOffset1=0x30, TextsOffset=0xe0};
#endif
#include <globaldefs.h>
#include "Resource/CreationEnums.h"

struct Container020e0310;
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int Text_AppendSdrcTag(char* dst, int a, int b, int c, int d, int e);
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);

// Overlay 23, originally func_ov023_021da100 (USA/EUR 0x021da100, JPN 0x021da8cc)
extern "C" ARM void CharacterCreationUI_WriteYesNoText(char* self, char* dst, int withFrame) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(self + SelectionOffset);
    if (withFrame) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    Text_AppendSdrcTag(dst, 0, 0, 0, regionalOffset1, 0x28);

    struct Container020e0310* texts = (struct Container020e0310*)(self + TextsOffset);
    for (int i = 0; i < 2; i++) {
        int text = KeyTable_Get(texts, (short)(i + CreationText_Yes));
        Text_AppendNTag(dst, i, (const char*)text);
        if (i != 1) {
            int sep = KeyTable_Get(texts, CreationText_NewLine);
            Text_Append(dst, (const char*)sep);
        }
    }
}
