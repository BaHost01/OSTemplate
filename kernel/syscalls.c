volatile char* video = (volatile char*) 0xb8000;
int cursor = 0;

int sys_write(const char* str) {
    while (*str) {
        video[cursor++] = *str++;
        video[cursor++] = 0x07;
    }
    return 0;
}

int sys_read(char* buf) {
    char c;
    int i = 0;

    while (1) {
        __asm__ volatile (
            "mov $0x00, %%ah \n"
            "int $0x16      \n"
            "mov %%al, %0   \n"
            : "=r"(c)
        );

        if (c == 13) break;

        buf[i++] = c;
        sys_write((char[]){c,0});
    }

    buf[i] = 0;
    return i;
}
