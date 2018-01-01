## Makefile.am
## Copyright 2017 Mac Radigan
## All Rights Reserved

AM_LDFLAGS  = -pthread                                                         \
              -L/usr/lib -ldl -lm                                              \
              -L/usr/lib/x86_64-linux-gnu -lgflags                             \
              -lstdc++fs                                                       \
              -lltdl                                                            

AM_CPPFLAGS = -I$(top_srcdir)/include                                          \
              -std=c++1z                                                       \
              -O3
AM_FCFLAGS  = -Jmod

nomsg_ldadd                = libnomsg.la                                       \
                             -ldl -lm                                          \
                             -lrt                                              \
                             -lstdc++fs                                        \
                             -lltdl                                             

bin_PROGRAMS               = test_nomsg

test_nomsg_SOURCES         = src/tests/test_nomsg.cc
test_nomsg_LDADD           = $(nomsg_ldadd)

lib_LTLIBRARIES            = libnomsg.la                                        

libnomsg_la_SOURCES        = src/packages/nomsg/nomsg.cc                       \
                             src/packages/nomsg/NomsgParser.cc
libnomsg_la_LIBADD         = -L/usr/lib/x86_64-linux-gnu -lrt
libnomsg_la_LDFLAGS        = -export-symbols-regex '^nomsg_[^_]' -fPIC         \
                             -shared -pthread                                  \
                             -L/usr/lib/x86_64-linux-gnu -lrt                   

pkginclude_HEADERS         = include/packages/nomsg/nomsg.h                    \
                             include/packages/nomsg/NomsgParser.h

## *EOF*
