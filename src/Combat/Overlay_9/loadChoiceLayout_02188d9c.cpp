#if defined(jpn)
#define data_ov009_0218ac04 data_ov009_0218bb6c
#endif
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

void ResetFields021847c4(ChoiceGrid *s);

extern const short data_ov009_0218ac04[];

// Overlay 9, originally func_ov009_02188d9c (USA/EUR 0x02188d9c, JPN 0x02189c60)
extern "C" ARM void loadChoiceLayout(CharacterCreationUI *self) {
	ChoiceGrid *currentGrid = &self->grid;
	int i;

	ResetFields021847c4(currentGrid);

	i = 0;
	while (data_ov009_0218ac04[i] >= 0) {
		if (self->state == data_ov009_0218ac04[i]) {
			int i1 = i + 1;
			int i2 = i + 2;
			int i3 = i + 3;
			int i4 = i + 4;
			int i5 = i + 5;
			int i6 = i + 6;
			int i7 = i + 7;
			int i8 = i + 8;
			currentGrid->x = data_ov009_0218ac04[i1];
			currentGrid->y = data_ov009_0218ac04[i2];
			currentGrid->width = data_ov009_0218ac04[i3];
			currentGrid->height = data_ov009_0218ac04[i4];
			currentGrid->stepX = data_ov009_0218ac04[i5];
			currentGrid->stepY = data_ov009_0218ac04[i6];
			currentGrid->columns = data_ov009_0218ac04[i7];
			currentGrid->rows = data_ov009_0218ac04[i8];
			return;
		}
		i += 9;
	}
}
