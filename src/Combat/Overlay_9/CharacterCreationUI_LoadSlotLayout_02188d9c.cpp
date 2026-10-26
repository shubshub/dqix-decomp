#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void CharacterCreationUI_ResetTargetLayout(CreationSlotLayout *s);

#if !defined(jpn) && !defined(eur)
// {tab, x, y, width, height, stepX, stepY, columns, rows} per tab, ending in -1
extern const short CharacterCreationUI_slotLayouts[] = {
	1, 64, 48, 128, 32, 0, 48, 1, 2, // gender
	2, 32, 40, 32, 72, 40, 0, 5, 1, // body type
	3, 32, 40, 32, 32, 40, 40, 5, 2, // hairstyle
	4, 32, 40, 32, 32, 40, 40, 5, 2, // hair colour
	5, 32, 40, 32, 32, 40, 40, 5, 2, // face
	7, 40, 40, 32, 32, 48, 40, 4, 2, // eye colour
	6, 40, 40, 32, 32, 48, 40, 4, 2, // skin colour
	8, 24, 56, 16, 16, 16, 16, 11, 6, // name keyboard
	-1,
};
#endif

// Overlay 9, originally func_ov009_02188d9c (USA/EUR 0x02188d9c, JPN 0x02189c60)
extern "C" ARM void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI *self) {
	CreationSlotLayout *currentLayout = &self->grid;
	int i;

	CharacterCreationUI_ResetTargetLayout(currentLayout);

	for (i = 0; CharacterCreationUI_slotLayouts[i] >= 0; i += 9) {
		if (self->state == CharacterCreationUI_slotLayouts[i]) {
			currentLayout->x = CharacterCreationUI_slotLayouts[i + 1];
			currentLayout->y = CharacterCreationUI_slotLayouts[i + 2];
			currentLayout->width = CharacterCreationUI_slotLayouts[i + 3];
			currentLayout->height = CharacterCreationUI_slotLayouts[i + 4];
			currentLayout->stepX = CharacterCreationUI_slotLayouts[i + 5];
			currentLayout->stepY = CharacterCreationUI_slotLayouts[i + 6];
			currentLayout->columns = CharacterCreationUI_slotLayouts[i + 7];
			currentLayout->rows = CharacterCreationUI_slotLayouts[i + 8];
			return;
		}
	}
}
