AC_PREREQ([2.69])
AC_INIT([dotconfig], [0.1.0], [caaallum])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([config])

AM_INIT_AUTOMAKE([1.9.6 -Wall -Werror subdir-objects dist-bzip2 dist-xz])
AM_MAINTAINER_MODE([enable])
AM_SILENT_RULES([yes])

AC_PROG_CC
AM_PROG_AR
AC_PATH_PROG(TAR, tar, /bin/bar)
AC_PROG_INSTALL
LT_INIT

PKG_CHECK_MODULES([CHECK], [check])

AC_CONFIG_HEADERS([dotconfig.h])
AC_CONFIG_FILES([Makefile test/Makefile])

AC_OUTPUT
