#include <string>
#include "memory.h"

using namespace std;

void   initMemoryLohja(ComputerMemory &memory);
void   updateMemoryLohja(int row, int col, int result, ComputerMemory &memory);
string smartMoveLohja(const ComputerMemory &memory);

