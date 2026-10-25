#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int memcmp(void*, void*, int);

// USA: func_ov031_0223b744
ARM int EndsWithMatch_0223b744(char* s1, char* s2, int n) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 < n || len2 < n) return 0;
	return memcmp(s1 + (len1 - n), s2 + (len2 - n), n) == 0;
}
