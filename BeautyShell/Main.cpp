//#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#include "BeautyShell.h"

int main() {

	Cnsl::InitilizeConsole();

	StartBeautyShell();

	Cnsl::TerminateConsole();

	return 0;
}