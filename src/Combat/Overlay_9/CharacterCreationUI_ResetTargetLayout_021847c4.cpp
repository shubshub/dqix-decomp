#include <globaldefs.h>
#include "Resource/CreationSlotLayout.h"

// Overlay 9, originally func_ov009_021847c4 (USA/EUR 0x021847c4, JPN 0x02185828)
ARM void CharacterCreationUI_ResetTargetLayout(CreationSlotLayout *layout) {
	layout->y = -1;
	layout->x = -1;
	layout->height = -1;
	layout->width = -1;
	layout->stepX = -1;
	layout->stepY = -1;
	layout->columns = -1;
	layout->rows = -1;
}
