# ==============================================================================
#
# Defines.common.otm.mk
#
# ==============================================================================


CC       := gcc
CFLAGS   += -Wall -pthread
CFLAGS   += -O3
CFLAGS   += -I$(LIB)
CPP      := g++
CPPFLAGS += $(CFLAGS)
LD       := g++
LIBS     += -lpthread

#For openmp
CFLAGS   += -fopenmp

# Remove these files when doing clean
OUTPUT +=

LIB := ../lib

STM := ../../tinySTM


# ==============================================================================
#
# End of Defines.common.otm.mk
#
# ==============================================================================
