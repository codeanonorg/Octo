#include <capstone/capstone.h>
#include <inttypes.h>
#include <stdio.h>

int disas_x86(const unsigned char *buff, unsigned int size) {
  csh handle;
  cs_insn *insn;
  size_t count;

  if (cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK) {
    fprintf(stderr,
            "[octo-internal] Error : disassembler failed unexpectedly\n");
    return -1;
  }

  count = cs_disasm(handle, buff, size, 0x1000, 0, &insn);
  if (count > 0) {
    size_t j;
    for (j = 0; j < count; j++) {
      fprintf(stderr, "0x%" PRIx64 ":\t%s\t\t%s\n", insn[j].address,
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