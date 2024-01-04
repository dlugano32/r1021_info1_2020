#include "lib.h"

int main()
{
        int ret;
        ret=enviarInvertido("/mnt/c/info1/myfifo", "in.txt");
        return ret;
}
