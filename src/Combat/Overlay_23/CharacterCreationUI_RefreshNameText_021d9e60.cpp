#include <globaldefs.h>
#include "Graphics/Window.h"
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"
#include "Combat/TryApplyElemFields.h"

struct Struct_0205d81c;
WindowPane* FindElementByC40205d81c(Struct_0205d81c*, int);
int KeyTable_Get(Container020e0310*, int);
int Text_Append(char*, const char*);

#if defined(jpn)
extern "C" int func_02042428(char*, int);

// Overlay 23, originally BuildFieldTag_021d9e60 (USA/EUR 0x021d9e60, JPN 0x021da6f0)
ARM void CharacterCreationUI_RefreshNameText(char* obj) {
    CharacterCreationUI* self = (CharacterCreationUI*)obj;
    if (!(self->flags & CreationFlag_RefreshName)) return;
    memset(self->textBuffer, 0, 0x800);
    if (self->state == CreationTab_NameEntry) {
        WindowPane* namePane = FindElementByC40205d81c((Struct_0205d81c*)&self->windows[CreationWindowIndex_Bottom], BottomWindow_NamePane);
        namePane->unk_b8 = 0x11;
        namePane->sizeTagLineHeight_ = 0x10;
        func_02042428(self->textBuffer, 12);
        Text_Append(self->textBuffer, self->names[self->sex]);
    } else {
        int text = KeyTable_Get(&self->texts, CreationText_WidthTag);
        Text_Append(self->textBuffer, (const char*)text);
    }
    Window_SetPaneText((StructA0205d5d0*)&self->windows[CreationWindowIndex_Bottom], BottomWindow_NamePane, (int)self->textBuffer, 0);
    self->flags &= ~CreationFlag_RefreshName;
}
#else
int AppendXTag_02041a28(char*, int);

extern "C" void __clear(void*, int);
extern "C" int Font_EncodeText(void*, void*, int);
extern "C" void Font_DecodeText(void*, void*, int);
extern "C" int Font_GetTextWidth(void*, int);

// Overlay 23, originally BuildFieldTag_021d9e60 (USA/EUR 0x021d9e60, JPN 0x021da6f0)
ARM void CharacterCreationUI_RefreshNameText(char* obj) {
	CharacterCreationUI* self = (CharacterCreationUI*)obj;
	if (!(self->flags & CreationFlag_RefreshName)) return;
	char* textBuffer = self->textBuffer;
	memset(textBuffer, 0, 0x960);
	if (self->state == CreationTab_NameEntry) {
		WindowPane* namePane = FindElementByC40205d81c((Struct_0205d81c*)&self->windows[CreationWindowIndex_Bottom], BottomWindow_NamePane);
		namePane->unk_b8 = 0x11;
		namePane->sizeTagLineHeight_ = 0x10;
		char nameTokens[0x80];
		char paddedName[0x80];
		__clear(nameTokens, 0x80);
		__clear(paddedName, 0x80);
		int sex = self->sex;
		char** names = self->names;
		int length = Font_EncodeText(names[sex], nameTokens, 0);
		for (; length < CreationName_MaxLength; length++) nameTokens[length] = self->nameFill;
		Font_DecodeText(nameTokens, paddedName, 0);
		int width = Font_GetTextWidth(paddedName, 0);
		AppendXTag_02041a28(textBuffer, (0x50 - width) >> 1);
		Text_Append(textBuffer, paddedName);
	} else {
		int text = KeyTable_Get(&self->texts, CreationText_WidthTag);
		Text_Append(textBuffer, (const char*)text);
	}
	Window_SetPaneText((StructA0205d5d0*)&self->windows[CreationWindowIndex_Bottom], BottomWindow_NamePane, (int)textBuffer, 0, 0);
	self->flags &= ~CreationFlag_RefreshName;
}

#endif
