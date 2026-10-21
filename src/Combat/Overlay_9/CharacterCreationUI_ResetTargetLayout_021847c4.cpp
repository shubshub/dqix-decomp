#include <globaldefs.h>
#include "Resource/CreationSlotLayout.h"

// Overlay 9, originally func_ov009_021847c4 (USA/EUR 0x021847c4, JPN 0x02185828)
ARM void CharacterCreationUI_ResetTargetLayout(CreationSlotLayout *s) {
	s->y = -1;
	s->x = -1;
	s->height = -1;
	s->width = -1;
	s->stepX = -1;
	s->stepY = -1;
	s->columns = -1;
	s->rows = -1;
}
