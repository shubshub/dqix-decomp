#include <globaldefs.h>

extern "C" void func_ov028_021d9188(void* a);
extern "C" void func_0208be90(void*);
extern "C" int Overlay_IsLoaded(unsigned int idx);
extern "C" void func_ov001_0215686c(int a);

// USA: func_ov017_021bb8f0
extern "C" ARM void func_ov017_021bb8f0(char* p) {
	#if defined(jpn)
    void* a = *(void**)(p + 0x15c);
#else
    void* a = *(void**)(p + 0x160);
#endif
	if (a != NULL) func_ov028_021d9188(a);
	#if defined(jpn)
    void* state = *(void**)(p + 0x11c);
#else
    void* state = *(void**)(p + 0x120);
#endif
    if (state != NULL) func_0208be90(state);
	int r = Overlay_IsLoaded(1);
	if (r == 0) return;
	func_ov001_0215686c(r);
}
