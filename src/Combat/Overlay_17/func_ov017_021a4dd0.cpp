#include <globaldefs.h>
#include <Resource/GameResources.h>

struct TailList020469b4;
struct TailNode020469b4;

extern signed char data_ov017_021d76d8;
extern "C" void func_ov017_021a967c(unsigned char* node, int id);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021a4dd0
extern "C" ARM void func_ov017_021a4dd0(GameResources* resources) {
	TailList020469b4* list = (TailList020469b4*)resources->fieldTaskQueue_;
	TailNode020469b4* node = (TailNode020469b4*)resources->fieldTasks_[34];
	signed char id = data_ov017_021d76d8;
	if (id < 0) {
		return;
	}
	func_ov017_021a967c((unsigned char*)node, id);
	func_020469b4(list, node);
}
