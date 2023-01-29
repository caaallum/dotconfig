AUTOMAKE_OPTIONS = foreign
SUBDIRS = test

bin_PROGRAMS = dotconfig

dotconfig_SOURCES = args.c main.c config.c
dotconfig_CFLAGS = -Wall -Wextra -std=c99 -pedantic @INIH_CFLAGS@
dotconfig_LDADD = @INIH_LIBS@

CLEANFILES = *~
