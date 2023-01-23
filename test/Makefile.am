check_PROGRAMS = config


noinst_LIBRARIES = libdotconfig.a
libdotconfig_a_SOURCES = ../src/config.c ../src/stringarr.c
libdotconfig_a_LIBADD = @INIH_LIBS@

config_SOURCES = check_config.c 
config_CFLAGS = @CHECK_CFLAGS@ -I $(top_builddir)/src
config_LDFLAGS = @CHECK_LIBS@ libdotconfig.a

TESTS = config
