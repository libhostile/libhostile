# vim:ft=automake

ACLOCAL_AMFLAGS = -I m4

# includes append to these:
SUFFIXES =
.PHONY =
TESTS =
CLEANFILES =
DISTCLEANFILES =
bin_PROGRAMS =
dist_bin_SCRIPTS =
noinst_HEADERS =
lib_LTLIBRARIES =
noinst_LTLIBRARIES =
noinst_PROGRAMS =
include_HEADERS =
nobase_include_HEADERS =
check_PROGRAMS =
EXTRA_HEADERS =
EXTRA_SCRIPTS =
BUILT_SOURCES=
EXTRA_DIST=
CONFIGURE_DEPENDENCIES=

#includes additional rules from aminclude.am
@INC_AMINCLUDE@
DISTCLEANFILES+= aminclude.am

EXTRA_DIST+= README
EXTRA_DIST+= LICENSE

aclocaldir= $(datadir)/aclocal
dist_aclocal_DATA=

TESTS+= ${check_PROGRAMS}

include m4/include.am
include src/include.am
include docs/include.am

dist_bin_SCRIPTS+= @GENERIC_CONFIG@
DISTCLEANFILES+= @GENERIC_CONFIG@

# Cleanup individual files in order to preserve uninstall/etc order
maintainer-clean-local:
	-rm Makefile.in
	-rm aclocal.m4
	-rm build-aux/config.guess
	-rm build-aux/config.sub
	-rm build-aux/depcomp
	-rm build-aux/install-sh
	-rm build-aux/ltmain.sh
	-rm build-aux/missing
	-rm build-aux/test-driver
	-rmdir build-aux
	-rm configure
	-rm config.log
	-rm config.status
	-rm config.in
	-rm m4/libtool.m4
	-rm m4/ltoptions.m4
	-rm m4/ltsugar.m4
	-rm m4/ltversion.m4
	-rm m4/lt~obsolete.m4
	find . -type f -name '*~' -exec rm -f '{}' \;
	-rm -f @PACKAGE@-*.tar.gz
