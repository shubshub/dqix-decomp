#include <globaldefs.h>
#include "Input/Input.h"

struct SePlayer;
extern struct SePlayer g_sePlayer;

int SePlayer_Play(struct SePlayer* obj, int a, int b);

// USA: func_ov023_021ed014
ARM int DispatchIfFlagsOrByteSet_021ed014(struct GuideWindow_021ec480* window) {
	if (g_keyManager.TestKeysPressed(0xf03) == 0 && g_touchInput.pressed_ == 0) {
		return 0;
	}
	SePlayer_Play(&g_sePlayer, 1, 0);
	return 1;
}
