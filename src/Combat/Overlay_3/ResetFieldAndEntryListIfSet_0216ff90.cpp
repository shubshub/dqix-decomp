#include <globaldefs.h>

struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);

struct Entry_0205d6a0;
void Window_ClosePane(struct Entry_0205d6a0* a, int flag);

// USA: func_ov003_0216ff90  (semantic: ResetFieldAndEntryListIfSet_0216ff90)
extern "C" ARM void func_ov003_0216ff90(char* obj) {
	if (*(void**)(obj + 0x3c) == 0) return;
	SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)*(void**)(obj + 0x3c), 0);
	Window_ClosePane((struct Entry_0205d6a0*)*(void**)(obj + 0x3c), 0);
}
