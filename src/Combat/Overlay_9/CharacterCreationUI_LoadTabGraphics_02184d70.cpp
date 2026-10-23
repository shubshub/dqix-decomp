#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/CharacterCreationUI.h"

int KeyTable_Get(Container020e0310*, int);

// Overlay 9, originally UpdateCombatantState_02184d70 (USA/EUR 0x02184d70, JPN 0x02186098)
ARM void CharacterCreationUI_LoadTabGraphics(void* storage) {
    CharacterCreationUI* self = (CharacterCreationUI*)storage;
    if (!(self->flags & CreationFlag_TabLoading) || self->resourceStep == TabLoadStep_Loaded)
        return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char step = self->resourceStep;
#if !defined(jpn)
    int tab = self->state;
#endif
    if (step == TabLoadStep_Queue) {
#if defined(jpn)
        int tab = self->state;
#endif
        short key = tab;
        if ((tab == CreationTab_HairStyle) | ((tab == CreationTab_BodyType) | (tab == CreationTab_Face)))
            key = self->sex * CreationText_FemaleOffset + key;
#if defined(jpn)
        const char* filename = (const char*)KeyTable_Get(&self->texts, key);
        self->resourceTask = loader->QueueLoadFile(filename, 0);
#else
        const char* filename = (const char*)KeyTable_Get(&self->texts, (short)(key + CreationText_InnerFileOffset));
        const char* archive = (const char*)KeyTable_Get(&self->texts, key);
        self->resourceTask = loader->QueueLoadFileInGP2(archive, filename, 0);
#endif
        self->resourceStep = TabLoadStep_Wait;
    } else if (step == TabLoadStep_Wait) {
        if (loader->GetTaskStatus(self->resourceTask) != 0)
            self->resourceStep = TabLoadStep_Loaded;
    }
}
