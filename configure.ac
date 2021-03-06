# Copyright (C) 2012 Ole Wolf <wolf@blazingangles.com>
#
# This file is part of aws-s3fs.
# 
# aws-s3fs is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_PREREQ([2.68])

m4_include([m4/version.m4])

AC_INIT([aws-s3fs], [_AWS_S3FS_VERSION], [wolf@blazingangles.com])
AC_CONFIG_SRCDIR([src/aws-s3fs.c])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE

LIBAWS_S3FS_CURRENT=_LIBAWS_S3FS_CURRENT
LIBAWS_S3FS_REVISION=_LIBAWS_S3FS_REVISION
LIBAWS_S3FS_AGE=_LIBAWS_S3FS_AGE
AC_SUBST([LIBAWS_S3FS_CURRENT])
AC_SUBST([LIBAWS_S3FS_REVISION])
AC_SUBST([LIBAWS_S3FS_AGE])

CFLAGS=""

# Prepare autotest suite.
AC_CONFIG_TESTDIR([test])
AC_CONFIG_FILES([test/atlocal])

# Add configuration options.
AC_ARG_ENABLE([doc],
    AS_HELP_STRING([--enable-doc], [Build source code documentation]),
	[ac_enable_doc=$enableval], [ac_enable_doc=auto])
AC_ARG_ENABLE([openssltest],
    AS_HELP_STRING([--disable-openssltest], [Skip OpenSSL tests]),
	[ac_enable_openssltest=$enableval], [ac_enable_openssltest=auto])

#AC_CANONICAL_SYSTEM
AC_GNU_SOURCE

# Check for programs.
AC_PROG_CC
AC_PROG_CC_STDC
AM_PROG_CC_C_O
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_GREP
AC_CHECK_PROG(HAVE_DOXYGEN, doxygen, true, false)
AC_CHECK_PROG(HAVE_GRAPHVIZ, dot, true, false)
AC_CHECK_PROG(HAVE_OPENSSL, openssl, true, false)
AC_CHECK_PROG(HAVE_SPLINT, splint, true, false)
AC_CHECK_PROG(HAVE_FLAWFINDER, flawfinder, true, false)
AC_CHECK_PROG(HAVE_RATS, rats, true, false)
AC_CHECK_PROG(HAVE_PSCAN, pscan, true, false)
AC_CHECK_PROG(HAVE_SQLITE_UTIL, sqlite3, true, false)
AC_PATH_PROGS(DOXYGEN, doxygen)
AC_PATH_PROGS(SPLINT, splint)
AC_PATH_PROGS(FLAWFINDER, flawfinder)
AC_PATH_PROGS(RATS, rats)
AC_PATH_PROGS(PSCAN, pscan)

# Check for typedefs, structures, and compiler characteristics.
AC_HEADER_STDC
AC_C_CONST
AC_C_INLINE
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T
AC_TYPE_SIZE_T
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_FUNC_FORK
AC_TYPE_SIZE_T

# Large file support.
AC_SYS_LARGEFILE

# Check for libraries.
AC_CHECK_LIB([config], [config_init],,
    AC_MSG_ERROR([*** config library not found **]))
AC_CHECK_LIB([fuse], [fuse_main],,
    AC_MSG_ERROR([*** fuse library not found **]))
AC_CHECK_LIB([pthread], [pthread_mutex_lock],,
    AC_MSG_ERROR([*** pthread library function not found **]))
AC_CHECK_LIB([curl], [curl_easy_init],,
    AC_MSG_ERROR([*** curl library not found **]))
AC_CHECK_LIB([xml2], [xmlReadMemory],,
    AC_MSG_ERROR([*** libxml2 library not found **]))
AC_CHECK_LIB([sqlite3], [sqlite3_open],,
    AC_MSG_ERROR([*** sqlite3 not found **]))
AC_CHECK_LIB([glib-2.0], [g_slist_append],,
    AC_MSG_ERROR([*** glib2 not found **]))

# Check for modules.
PKG_CHECK_MODULES([DEPS], [fuse >= 2.8 libxml-2.0 >= 2.7.0 libconfig >= 1.3 libcurl >= 7.20 sqlite3 >= 3.7.0 glib-2.0 >= 2.30.0],,
    AC_MSG_ERROR([*** libfuse, libconfig, libxml2, libsqlite3, or curl source not found **]))

# Check for library functions.
AC_CHECK_FUNCS([getopt_long],,
    AC_MSG_ERROR([*** Getopt functions not found. **]))
AC_CHECK_FUNCS([strcasecmp strlen strcat strcpy strncpy isspace],,
    AC_MSG_ERROR([*** String handling functions not found. **]))
AC_CHECK_FUNCS([fopen fprintf fclose getenv system lockf chdir umask dup \
               open write close getdtablesize chmod],,
    AC_MSG_ERROR([*** File handling functions not found. **]))
AC_CHECK_FUNCS([malloc free memset],,
    AC_MSG_ERROR([*** Memory allocation functions not found. **]))
AC_CHECK_FUNCS([openlog syslog closelog],,
    AC_MSG_ERROR([*** Syslog functions not found. **]))
AC_CHECK_FUNCS([time localtime],,
    AC_MSG_ERROR([*** Time functions not found. **]))
AC_CHECK_FUNCS([sigaction fork setsid exit perror pthread_mutex_lock \
	       pthread_mutex_unlock getsid getuid],,
    AC_MSG_ERROR([*** Process functions not found. **]))
AC_CHECK_FUNCS([config_init config_lookup_bool config_lookup_string \
               config_read_file config_destroy],,
AC_MSG_ERROR([*** libopt functions not found. **]))
AC_CHECK_FUNCS([fuse_main],,
    AC_MSG_ERROR([*** FUSE functions not found. **]))
AC_CHECK_FUNCS([curl_easy_init curl_easy_setopt curl_easy_perform \
	       curl_easy_cleanup curl_slist_append],,
AC_MSG_ERROR([*** CURL functions not found. **]))
AC_CHECK_FUNCS([socket bind listen setsockopt getsockopt recvmsg sendmsg \
 	       accept socketpair],,
AC_MSG_ERROR([*** Socket functions not found. **]))


# Check for header files.
AC_CHECK_HEADERS([stdio.h],,
    AC_MSG_ERROR([*** stdio.h missing **]))
AC_CHECK_HEADER([string.h],,
    AC_MSG_ERROR([*** string.h missing **]))
AC_CHECK_HEADER([stdlib.h],,
    AC_MSG_ERROR([*** stdlib.h not found **]))
AC_HEADER_STDBOOL
#AC_CHECK_HEADER([stdbool.h],,
#    AC_MSG_ERROR([*** stdbool.h not found **]))
AC_CHECK_HEADER([libconfig.h],,
    AC_MSG_ERROR([*** libconfig.h not found **]))
AC_CHECK_HEADER([getopt.h],,
    AC_MSG_ERROR([*** getopt.h not found **]))
AC_HEADER_ASSERT
AC_CHECK_HEADER([assert.h],,
    AC_MSG_ERROR([*** assert.h not found **]))
AC_CHECK_HEADER([ctype.h],,
    AC_MSG_ERROR([*** ctype.h not found **]))
AC_CHECK_HEADER([syslog.h],,
    AC_MSG_ERROR([*** syslog.h not found **]))
AC_CHECK_HEADER([signal.h],,
    AC_MSG_ERROR([*** signal.h not found **]))
AC_CHECK_HEADER([unistd.h],,
    AC_MSG_ERROR([*** unistd.h not found **]))
AC_CHECK_HEADER([limits.h],,
    AC_MSG_ERROR([*** limits.h not found **]))
AC_HEADER_TIME
#AC_CHECK_HEADER([time.h],,
#    AC_MSG_ERROR([*** time.h not found **]))
AC_CHECK_HEADER([fcntl.h],,
    AC_MSG_ERROR([*** fcntl.h not found **]))
AC_CHECK_HEADER([sys/stat.h],,
    AC_MSG_ERROR([*** sys/stat.h not found **]))
AC_CHECK_HEADER([sys/signal.h],,
    AC_MSG_ERROR([*** sys/stat.h not found **]))
AC_CHECK_HEADER([uthash.h],,
    AC_MSG_ERROR([*** uthash.h not found **]))
AC_CHECK_HEADER([pthread.h],,
    AC_MSG_ERROR([*** pthread.h not found **]))
AC_CHECK_HEADER([curl/curl.h],,
    AC_MSG_ERROR([*** curl.h not found **]))
AC_CHECK_HEADER([sys/socket.h],,
    AC_MSG_ERROR([*** sys/socket.h not found **]))
CFLAGS_SAVE="$CFLAGS"
CFLAGS="$CFLAGS -Wall -Werror $DEPS_CFLAGS"
AC_CHECK_HEADER([glib-2.0/glib.h], [], 
AC_MSG_ERROR([*** glib-2.0/glib.h not found **]),
[
AC_INCLUDES_DEFAULT
])
AC_CHECK_HEADER([libxml/tree.h], [], 
AC_MSG_ERROR([*** libxml/tree.h not found **]),
[
AC_INCLUDES_DEFAULT
])
CFLAGS="$CFLAGS_SAVE"
AC_DEFINE([_GNU_SOURCE], [], [Use GNU extensions])
AC_DEFINE([FUSE_USE_VERSION], [26], [Use FUSE version 26])

LT_INIT([disable-static])

MAKE_DOXYGEN=false
if @<:@ "x$ac_enable_doc" = "xyes" @:>@; then
    if @<:@ "x$HAVE_DOXYGEN" = "xfalse" -o "x$HAVE_GRAPHVIZ" = "xfalse" @:>@; then
        AC_MSG_ERROR([*** source documentation requested but Doxygen/GraphViz not found])
    else
        MAKE_DOXYGEN=true
    fi
fi
AM_CONDITIONAL(MAKE_DOXYGEN,$MAKE_DOXYGEN)

MAKE_OPENSSL_TESTS=false
if @<:@ "x$ac_enable_openssltest" != "xno" @:>@; then
    if @<:@ $HAVE_OPENSSL = "false" -a "x$ac_enable_openssltest" = "xyes" @:>@; then
        AC_MSG_ERROR([*** OpenSSL tests explicitly enabled, but OpenSSL not found])
    fi
    if @<:@ $HAVE_OPENSSL = "false" -a "x$ac_enable_openssltest" = "xauto" @:>@; then
        AC_MSG_WARN([*** OpenSSL not found, some tests will not be performed])
    fi
    if @<:@ $HAVE_OPENSSL = "true" -a "x$ac_enable_openssltest" != "xno" @:>@; then
        MAKE_OPENSSL_TESTS=true
    fi
fi
AM_CONDITIONAL(MAKE_OPENSSL_TESTS,$MAKE_OPENSSL_TESTS)
AM_CONDITIONAL(HAVE_SQLITE_UTIL,$HAVE_SQLITE_UTIL)

CFLAGS="$CFLAGS -Wall -Werror -Wextra $DEPS_CFLAGS"
LIBS_OLD="$LIBS"
LIBS="$DEPS_LIBS"

# Output files.
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile data/Makefile doc/Makefile doc/man/Makefile test/Makefile])
AC_OUTPUT([doc/main.doc debian/libaws-s3fs0.postinst debian/libaws-s3fs0.postrm aws-s3fs.pc])

AC_MSG_NOTICE([
$PACKAGE_NAME version $PACKAGE_VERSION:
  Prefix..........: $prefix
  C Compiler......: $CC $CFLAGS
  C++ Compiler....: $CXX $CXXFLAGS $CPPFLAGS
  Linker..........: $LD $LDFLAGS $LIBS

Options:
  Generate source code documentation: $ac_enable_doc
  Perform OpenSSL tests:              $ac_enable_openssltest])
