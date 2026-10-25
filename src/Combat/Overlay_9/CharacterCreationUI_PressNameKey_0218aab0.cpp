#if defined(jpn)
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
extern "C" void* memcpy(void*, const void*, unsigned int);

int MessageSystem_GetInstance();
int KeyTable_Get(Container020e0310*, int);
struct SePlayer;
extern SePlayer g_sePlayer;
void SePlayer_Play(SePlayer*, int, int);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" void func_ov009_0218b200(CharacterCreationUI*, int);
extern "C" void func_ov009_0218b2e8(CharacterCreationUI*);
extern "C" void func_ov009_0218b680(CharacterCreationUI*);
extern "C" void CharacterCreationUI_PickRandomName(CharacterCreationUI*);
extern const char data_ov009_0218bc73[];
extern const char data_ov009_0218bc76[];
extern const char data_ov009_0218bc79[];
extern const char data_ov009_0218bc7c[];
extern const char data_ov009_0218bc7f[];
extern const char data_ov009_0218bc82[];
extern const char data_ov009_0218bc85[];
extern const char data_ov009_0218bc88[];

// Overlay 9, originally func_ov009_0218aab0 (JPN 0x0218aab0; jpn only)
extern "C" ARM int CharacterCreationUI_PressNameKey(CharacterCreationUI* self, unsigned char choice)
{
    MessageSystem_GetInstance();
    char character[3] = {};
    int changedIndex = -1;
    int inserted = 0;
    const char* page = (const char*)KeyTable_Get(&self->texts, (short)(self->keyboardPage + 0x4268));
    memcpy(character, page + choice * 2, 2);
    SePlayer_Play(&g_sePlayer, 1, 0);
    if (memcmp(character, data_ov009_0218bc73, 2) == 0) {
        self->flags |= CreationFlag_KeyboardOk;
    } else if (memcmp(character, data_ov009_0218bc76, 2) == 0) {
        func_ov009_0218b200(self, 0);
        changedIndex = self->nameLengths[self->sex];
    } else if (memcmp(character, data_ov009_0218bc79, 2) == 0) {
        self->keyboardPage = 0;
        self->flags |= CreationFlag_RedrawPanel;
    } else if (memcmp(character, data_ov009_0218bc7c, 2) == 0) {
        self->keyboardPage = 1;
        self->flags |= CreationFlag_RedrawPanel;
    } else if (memcmp(character, data_ov009_0218bc7f, 2) == 0) {
        func_ov009_0218b2e8(self);
        changedIndex = self->nameLengths[self->sex] - 1;
    } else if (memcmp(character, data_ov009_0218bc82, 2) == 0) {
        func_ov009_0218b680(self);
        changedIndex = self->nameLengths[self->sex] - 1;
    } else if (memcmp(character, data_ov009_0218bc85, 2) == 0) {
    } else if (memcmp(character, data_ov009_0218bc88, 2) == 0) {
        if (self->mode == CreationMode_PartyMemberCreation) {
            CharacterCreationUI_PickRandomName(self);
            self->flags |= CreationFlag_RefreshName;
        }
    } else {
        changedIndex = self->nameLengths[self->sex];
        if (changedIndex >= 5) --changedIndex;
        memcpy(&self->names[self->sex][changedIndex * 2], character, 2);
        self->nameLengths[self->sex] = changedIndex + 1;
        inserted = 1;
    }
    if (changedIndex >= 0) self->flags |= CreationFlag_RefreshName;
    return inserted;
}
#endif
