#ifndef DISAS_H
#define DISAS_H

#include <core/arch.h>

int disas(enum arch_e arch, const unsigned char *buff, unsigned int size);

#endif