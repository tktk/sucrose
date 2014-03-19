#ifndef SUCROSE_BOOT_DEFAULT_CONFIG_H
#define SUCROSE_BOOT_DEFAULT_CONFIG_H

#include "fg/def/common/primitives.h"
#include "fgpp/def/common/string.h"

struct FgBootConfig
{
    FgUtf32     mainFile;
    fg::BUtf32  mainFileBuffer;
    //TODO
};

#endif  // SUCROSE_BOOT_DEFAULT_CONFIG_H
