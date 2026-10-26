#include <globaldefs.h>

#if defined(jpn)
static const int kSearch=0x16c, kOther=0x910, kFlags=0xfe;
#else
static const int kSearch=0x41c, kOther=0xb30, kFlags=0x31e;
#endif

// USA: func_ov017_021954c4
extern "C" ARM void func_ov017_021954c4(void* obj, int arg1) {
	unsigned char* ptr = *(unsigned char**)((char*)obj + 0x4000 + kSearch);
	if (ptr[0] != 0) {
		if (ptr[2] == arg1) {
			ptr[0] = 0;
			ptr[1] = 0;
			{
				unsigned char* other = *(unsigned char**)((char*)obj + 0x3000 + kOther);
				if (other[3] != 0) other[8] = 1;
			}
		}
	}
	*((unsigned char*)obj + 0x4000 + kFlags) |= (1 << arg1);
}
