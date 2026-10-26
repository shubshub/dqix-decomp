#include <globaldefs.h>

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
extern "C" void* func_0207d78c(void);
extern "C" int func_0207d978(Entry0207d9bc* arr, unsigned short key);
extern "C" Entry0207d9bc* func_0207d9bc(Entry0207d9bc* arr, unsigned short key);

// USA: func_ov017_021c5bf8
extern "C" ARM int func_ov017_021c5bf8(int index, int arg1) {
	if (index >= 4)
		goto zero;
	{
	Entry0207d9bc* arr = (Entry0207d9bc*)func_0207d78c();
	if (!func_0207d978(arr, (unsigned short)arg1))
		goto zero;
	{
	Entry0207d9bc* e = func_0207d9bc(arr, (unsigned short)arg1);
	if (e != NULL) {
		signed char v = *((signed char*)e + index + 8);
		if (v != -1)
			return 1;
	}
	}
	}
zero:
	return 0;
}
