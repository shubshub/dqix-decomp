#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

void ResetFields021847c4(CreationSlotLayout *s);

#if defined(jpn) || defined(eur)
extern const short CharacterCreationUI_slotLayoutTable[];
#else
extern const short CharacterCreationUI_slotLayoutTable[] = {
	1, 64, 48, 128, 32, 0, 48, 1, 2,
	2, 32, 40, 32, 72, 40, 0, 5, 1,
	3, 32, 40, 32, 32, 40, 40, 5, 2,
	4, 32, 40, 32, 32, 40, 40, 5, 2,
	5, 32, 40, 32, 32, 40, 40, 5, 2,
	7, 40, 40, 32, 32, 48, 40, 4, 2,
	6, 40, 40, 32, 32, 48, 40, 4, 2,
	8, 24, 56, 16, 16, 16, 16, 11, 6,
	-1,
};
#endif

// Overlay 9, originally func_ov009_02188d9c (USA/EUR 0x02188d9c, JPN 0x02189c60)
extern "C" ARM void CharacterCreationUI_LoadSlotLayout(CharacterCreationUI *self) {
	CreationSlotLayout *currentLayout = &self->grid;
	int i;

	ResetFields021847c4(currentLayout);

	i = 0;
	while (CharacterCreationUI_slotLayoutTable[i] >= 0) {
		if (self->state == CharacterCreationUI_slotLayoutTable[i]) {
			int i1 = i + 1;
			int i2 = i + 2;
			int i3 = i + 3;
			int i4 = i + 4;
			int i5 = i + 5;
			int i6 = i + 6;
			int i7 = i + 7;
			int i8 = i + 8;
			currentLayout->x = CharacterCreationUI_slotLayoutTable[i1];
			currentLayout->y = CharacterCreationUI_slotLayoutTable[i2];
			currentLayout->width = CharacterCreationUI_slotLayoutTable[i3];
			currentLayout->height = CharacterCreationUI_slotLayoutTable[i4];
			currentLayout->stepX = CharacterCreationUI_slotLayoutTable[i5];
			currentLayout->stepY = CharacterCreationUI_slotLayoutTable[i6];
			currentLayout->columns = CharacterCreationUI_slotLayoutTable[i7];
			currentLayout->rows = CharacterCreationUI_slotLayoutTable[i8];
			return;
		}
		i += 9;
	}
}
