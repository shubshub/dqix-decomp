#include <globaldefs.h>

extern "C" int func_ov031_02206ce8(void* g);
extern "C" int func_ov031_022068cc(void* obj);
extern "C" int func_ov031_02206900(void* a);
extern "C" void func_ov031_02206c08(void);
extern "C" int func_ov031_022004d4(void);
extern "C" void func_ov031_0220f0e4(int v);

extern void* data_ov031_0224e1cc;

// USA: func_ov031_02206d90
extern "C" ARM int func_ov031_02206d90(void) {
	int result;
	void* g = data_ov031_0224e1cc;
	if (g) {
		result = func_ov031_02206ce8(g);
		if (result == 0) {
			func_ov031_02206900(data_ov031_0224e1cc);
			if (func_ov031_022068cc(data_ov031_0224e1cc) != 0) {
				data_ov031_0224e1cc = 0;
			}
			result = -26;
		}
		func_ov031_02206c08();
	} else {
		if (func_ov031_022004d4() == 0) {
			result = -26;
		} else {
			func_ov031_0220f0e4(0);
			result = 0;
		}
	}
	return result;
}
