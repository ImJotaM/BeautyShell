//#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
#include "BeautyShell.h"

int main() {

	Cnsl::InitializeConsole();

	Cnsl::TerminateConsole();

	return 0;
}