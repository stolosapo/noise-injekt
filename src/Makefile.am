AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = noiseinjekt

mainincludedir = $(includedir)/noiseinjekt
maininclude_HEADERS = \
    Service.h \
    ServiceFactory.h 

common_sources = \
    Service.cpp \
    ServiceFactory.cpp 

noiseinjekt_SOURCES = main.cpp $(common_sources)
noiseinjekt_LDADD = libnoiseinjekt.la
noiseinjekt_CXXFLAGS = $(AM_CXXFLAGS)

lib_LTLIBRARIES = libnoiseinjekt.la
libnoiseinjekt_la_LDFLAGS = -version-info 1:0:0
libnoiseinjekt_la_CXXFLAGS = $(AM_CXXFLAGS)
libnoiseinjekt_la_SOURCES = $(common_sources)

TESTS = noiseinjekt