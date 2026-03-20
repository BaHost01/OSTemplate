#include "syscalls.h"

void syscall_handler(int num, const char* str, char* buf) {
    if (num == 0) sys_write(str);
    if (num == 1) sys_read(buf);
}
