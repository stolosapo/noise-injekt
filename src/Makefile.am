AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = noiseinjekt

mainincludedir = $(includedir)/noiseinjekt
maininclude_HEADERS = \
    all_header_files.h

common_sources = \
    all_source_files.cpp

noiseinjekt_SOURCES = main.cpp $(common_sources)
noiseinjekt_LDADD = libnoiseinjekt.la
noiseinjekt_CXXFLAGS = $(AM_CXXFLAGS)

lib_LTLIBRARIES = libnoiseinjekt.la
libnoiseinjekt_la_LDFLAGS = -version-info 1:0:0 -pthread
libnoiseinjekt_la_CXXFLAGS = $(AM_CXXFLAGS) -pthread
libnoiseinjekt_la_SOURCES = $(common_sources)

TESTS = noiseinjekt