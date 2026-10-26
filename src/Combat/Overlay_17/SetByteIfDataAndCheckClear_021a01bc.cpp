#include <globaldefs.h>

extern "C" int* LinkSession_GetInstance(void);
int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void* p);

// USA: func_ov017_021a01bc
ARM void SetByteIfDataAndCheckClear_021a01bc(unsigned char* self) {
	int* ptr = LinkSession_GetInstance();
	if (!LinkSession_IsActive(ptr)) return;
	if (LinkSession_IsHostOrSolo(ptr) == 0) {
		self[
#if defined(jpn)
            0x40c9
#else
            0x42e9
#endif
        ] = 1;
	}
}
