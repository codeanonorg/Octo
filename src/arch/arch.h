#include <stdbool.h>

typedef enum format_e {
     elf = 0x7F454C46,
     pe = 0x4D5A,
     macho32 = 0xFEEDFACE,
     macho64 = 0xFEEDFACF
} format;

typedef enum arch_e {
    no_spec = 0x00,
    sparc = 0x02,
    x86 = 0x03,
    mips = 0x08,
    powerpc = 0x14,
    s390 = 0x16,
    arm = 0x28,
    superh = 0x2A,
    ia64 = 0x32,
    amd64 = 0x3E,
    aarch64 = 0xB7,
    riscv = 0xF3
} arch;

typedef struct gen_arch_s {
    format file_format;
    bool is_64;
    arch arch_name;
    unsigned char* text;
    unsigned int text_size;
} gen_arch;
