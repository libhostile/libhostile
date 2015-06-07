# SYNOPSIS
#
#   AX_UNIVERSAL_BINARY()
#
# DESCRIPTION
#
#   --enable-universal-binary
#
# LICENSE
#
#  Copyright 2014 Hewlett-Packard Development Company, L.P.
#  All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may
# not use this file except in compliance with the License. You may obtain 
# a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations
# under the License.

#serial 1

AC_DEFUN([AX_UNIVERSAL_BINARY],
    [AC_ARG_ENABLE([universal-binary],
                   [AC_HELP_STRING([--enable-universal-binary=auto],
                                   [Apple combined x86 & x86_64 binary support])],,
                   [enable_universal_binary=auto])
    have_universal_binary=no
    if test x"enable_universal_binary" != x"no"; then
        AC_CANONICAL_HOST
        AC_MSG_CHECKING([for universal binary support])
        case $host in *-apple-darwin*)
            save_CFLAGS="$CFLAGS"
            save_CXXFLAGS="$CXXFLAGS"
            save_LDFLAGS="$LDFLAGS"
            CFLAGS="$CFLAGS -arch x86_64 -arch i386"
            CXXFLAGS="$CXXFLAGS -arch x86_64 -arch i386"
            LDFLAGS="$LDFLAGS -arch x86_64 -arch i386"
            AC_LINK_IFELSE([AC_LANG_SOURCE([int main() {return 0;}])],
                          [have_universal_binary=yes])
            if test x"$have_universal_binary" = x"no"; then
                CFLAGS="$save_CFLAGS"
                CXXFLAGS="$save_CXXFLAGS"
                LDFLAGS="$save_LDFLAGS"
            fi
            ;;
        esac
        AC_MSG_RESULT($have_universal_binary)
    fi
    case "$have_universal_binary:$enable_universal_binary" in
        no:yes) AC_MSG_ERROR([no universal binary support on this host]) ;;
        yse:*)  AC_MSG_WARN([disabling dependency tracking])
                AM_CONDITIONAL([AMDEP],[false])
                AM_CONDITIONAL([am__fastdepCC],[false])
                AMDEPBACKSLASH=
                ;;
    esac])
