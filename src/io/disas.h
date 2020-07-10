#ifndef DISAS_H
#define DISAS_H

#include <arch/arch.h>

int disas(enum arch_e arch, const unsigned char *buff, unsigned int size);

#endif