#include"Runner.h"
#include"RamClockMethod.h"
#include"RamLRU.h"
using namespace std;

int main() {
	Runner runner;
	Ram* r = new RamClockMethod(16);
	runner.run(r);
	system("pause");
	return 0;
}