# 	NuSYSTEM samples nulod Makefile
#       Copyright (C) 1997-1999, NINTENDO Co,Ltd.

include $(ROOT)/usr/include/make/PRdefs

# The directory which has the include file and library of NuSYSTEM
#
N64KITDIR   = C:\nintendo\n64kit
NUSYSINCDIR = $(N64KITDIR)/nusys/include
NUSYSLIBDIR = $(N64KITDIR)/nusys/lib

# For allocating memory.
NUSTDINCDIR = $(N64KITDIR)/nustd/include
NUSTDLIBDIR = $(N64KITDIR)/nustd/lib

LIB = $(ROOT)/usr/lib
LPR = $(LIB)/PR
INC = $(ROOT)/usr/include
CC  = gcc
LD  = ld
MAKEROM = mild

DIRS = sprites

INCDIR = include
HFILES = $(foreach DIR,$(DIRS), $(wildcard $(INCDIR)/$(DIR)/*.h) $(wildcard $(INCDIR)/*.h)

SRCDIR = src
CODEFILES = $(foreach DIR,$(DIRS), $(wildcard $(SRCDIR)/$(DIR)/*.c)) $(wildcard $(SRCDIR)/*.c) 

ENEMYDIR = src/enemies
ENEMYFILES = $(foreach DIR,$(DIRS), $(wildcard $(ENEMYDIR)/$(DIR)/*.c)) $(wildcard $(ENEMYDIR)/*.c) 

AUDIODIR = src/audio
AUDIOFILES = $(foreach DIR,$(DIRS), $(wildcard $(AUDIODIR)/$(DIR)/*.c)) $(wildcard $(AUDIODIR)/*.c) 

LCDEFS = -DNU_DEBUG -DF3DEX_GBI_2
LCINCS = -I$(NUSYSINCDIR) -I$(ROOT)/usr/include/PR -I$(INCDIR)
#LCOPTS = -G 0 -o $@
LCOPTS = -G 0 -O3 -ffast-math -o $@

NUAUDIOLIB = -lnualstl_n_d -ln_gmus_d -ln_gaudio_sc

LDFLAGS = $(MKDEPOPT) -L$(LIB) -L$(NUSTDLIBDIR) -L$(NUSYSLIBDIR) $(NUAUDIOLIB) -lnusys_d -lnustd_d -lgultra_d -L$(GCCDIR)/mipse/lib -lkmc

OPTIMIZER =	-g

APP = 3rdPersonDemo.out

TARGETS = 3rdPersonDemo.n64

CODEOBJECTS = $(CODEFILES:.c=.o) $(AUDIOFILES:.c=.o) $(ENEMYFILES:.c=.o) $(PHYSCODEFILES:.c=.o) $(NUSYSLIBDIR)/nusys.o

CODESEGMENT = codesegment.o

default: $(TARGETS)

include $(COMMONRULES)

$(CODESEGMENT):	$(CODEOBJECTS) Makefile
		$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

$(TARGETS):	$(CODESEGMENT)
		$(MAKEROM) spec -I$(NUSYSINCDIR) -s 32 -r $(TARGETS) -e $(APP)
		makemask $(TARGETS)
