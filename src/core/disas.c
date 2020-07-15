#include <assert.h>
#include <capstone/capstone.h>
#include <core/disas.h>
#include <inttypes.h>
#include <io/logger.h>
#include <stdio.h>

enum cs_arch arch_to_cs_arch(enum arch_e arch) {
  switch (arch) {
  case x86:
    return CS_ARCH_X86;
  case sparc:
    return CS_ARCH_SPARC;
  case mips:
    return CS_ARCH_MIPS;
  case powerpc:
    return CS_ARCH_PPC;
  case s390:
    // TO FIX
    fprintf(stderr, "[octo-internal] Error : incompatible arch s390\n");
    exit(1);
  case arm:
    return CS_ARCH_ARM;
  case superh:
    // TO FIX
    fprintf(stderr, "[octo-internal] Error : incompatible arch SUPERH\n");
    exit(1);
  case ia64:
    fprintf(stderr, "[octo-internal] Error : incompatible arch ia64\n");
    exit(1);
  case amd64:
    // TO FIX
    fprintf(stderr, "[octo-internal] Error : incompatible arch AMD64\n");
    exit(1);
  case aarch64:
    return CS_ARCH_ARM64;
  case riscv:
    // TO FIX
    fprintf(stderr, "[octo-internal] Error : incompatible arch RISCV\n");
    exit(1);
  default:
    fprintf(stderr, "[octo-internal] Error : unknown arch\n");
    exit(1);
  }
}

int disas(enum arch_e arch, const unsigned char *buff, unsigned int size) {

  csh handle;
  cs_insn *insn;
  size_t count;

  if (cs_open(arch_to_cs_arch(arch), CS_MODE_64, &handle) != CS_ERR_OK) {
    fprintf(stderr,
            "[octo-internal] Error : disassembler failed unexpectedly\n");
    return -1;
  }

  count = cs_disasm(handle, buff, size, 0x1000, 0, &insn);
  if (count > 0) {
    size_t j;
    for (j = 0; j < count; j++) {
      fprintf(stdout, "0x%" PRIx64 ":\t%s\t\t%s\n", insn[j].address,
              insn[j].mnemonic, insn[j].op_str);
    }
    cs_free(insn, count);
  } else {
    fprintf(stderr, "[octo-io] Error : Failed to disassemble given code ! "
                    "Please ensure that the given input is valid.\n");
    return 1;
  }

  cs_close(&handle);
  return 0;
}
