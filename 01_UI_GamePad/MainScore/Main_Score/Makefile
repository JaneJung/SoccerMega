#############################################################################
# Makefile for building: Main_Score
# Generated by qmake (2.01a) (Qt 4.5.2) on: Wed Apr 30 01:19:47 2014
# Project:  Main_Score.pro
# Template: app
# Command: /usr/local/qt-4.5.2/bin/qmake -unix -o Makefile Main_Score.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-none-linux-gnueabi-gcc
CXX           = arm-none-linux-gnueabi-g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/qt-4.5.2/mkspecs/qws/linux-arm-g++ -I. -I/usr/local/qt-4.5.2/include/QtCore -I/usr/local/qt-4.5.2/include/QtNetwork -I/usr/local/qt-4.5.2/include/QtGui -I/usr/local/qt-4.5.2/include -I. -I. -I.
LINK          = arm-none-linux-gnueabi-g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/local/qt-4.5.2/lib
LIBS          = $(SUBLIBS)  -L/usr/local/qt-4.5.2/lib -lQtGui -L/usr/local/ts-1.0/lib -L/usr/local/qt-4.5.2/lib -lts -lQtNetwork -lQtCore -lm -lrt -ldl -lpthread
AR            = arm-none-linux-gnueabi-ar cqs
RANLIB        = 
QMAKE         = /usr/local/qt-4.5.2/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		scoreboard.cpp \
		worker.cpp moc_scoreboard.cpp \
		moc_worker.cpp
OBJECTS       = main.o \
		scoreboard.o \
		worker.o \
		moc_scoreboard.o \
		moc_worker.o
DIST          = /usr/local/qt-4.5.2/mkspecs/common/g++.conf \
		/usr/local/qt-4.5.2/mkspecs/common/unix.conf \
		/usr/local/qt-4.5.2/mkspecs/common/linux.conf \
		/usr/local/qt-4.5.2/mkspecs/common/qws.conf \
		/usr/local/qt-4.5.2/mkspecs/qconfig.pri \
		/usr/local/qt-4.5.2/mkspecs/features/qt_functions.prf \
		/usr/local/qt-4.5.2/mkspecs/features/qt_config.prf \
		/usr/local/qt-4.5.2/mkspecs/features/exclusive_builds.prf \
		/usr/local/qt-4.5.2/mkspecs/features/default_pre.prf \
		/usr/local/qt-4.5.2/mkspecs/features/release.prf \
		/usr/local/qt-4.5.2/mkspecs/features/default_post.prf \
		/usr/local/qt-4.5.2/mkspecs/features/warn_on.prf \
		/usr/local/qt-4.5.2/mkspecs/features/qt.prf \
		/usr/local/qt-4.5.2/mkspecs/features/unix/thread.prf \
		/usr/local/qt-4.5.2/mkspecs/features/moc.prf \
		/usr/local/qt-4.5.2/mkspecs/features/resources.prf \
		/usr/local/qt-4.5.2/mkspecs/features/uic.prf \
		/usr/local/qt-4.5.2/mkspecs/features/yacc.prf \
		/usr/local/qt-4.5.2/mkspecs/features/lex.prf \
		/usr/local/qt-4.5.2/mkspecs/features/include_source_dir.prf \
		Main_Score.pro
QMAKE_TARGET  = Main_Score
DESTDIR       = 
TARGET        = Main_Score

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_scoreboard.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Main_Score.pro  /usr/local/qt-4.5.2/mkspecs/qws/linux-arm-g++/qmake.conf /usr/local/qt-4.5.2/mkspecs/common/g++.conf \
		/usr/local/qt-4.5.2/mkspecs/common/unix.conf \
		/usr/local/qt-4.5.2/mkspecs/common/linux.conf \
		/usr/local/qt-4.5.2/mkspecs/common/qws.conf \
		/usr/local/qt-4.5.2/mkspecs/qconfig.pri \
		/usr/local/qt-4.5.2/mkspecs/features/qt_functions.prf \
		/usr/local/qt-4.5.2/mkspecs/features/qt_config.prf \
		/usr/local/qt-4.5.2/mkspecs/features/exclusive_builds.prf \
		/usr/local/qt-4.5.2/mkspecs/features/default_pre.prf \
		/usr/local/qt-4.5.2/mkspecs/features/release.prf \
		/usr/local/qt-4.5.2/mkspecs/features/default_post.prf \
		/usr/local/qt-4.5.2/mkspecs/features/warn_on.prf \
		/usr/local/qt-4.5.2/mkspecs/features/qt.prf \
		/usr/local/qt-4.5.2/mkspecs/features/unix/thread.prf \
		/usr/local/qt-4.5.2/mkspecs/features/moc.prf \
		/usr/local/qt-4.5.2/mkspecs/features/resources.prf \
		/usr/local/qt-4.5.2/mkspecs/features/uic.prf \
		/usr/local/qt-4.5.2/mkspecs/features/yacc.prf \
		/usr/local/qt-4.5.2/mkspecs/features/lex.prf \
		/usr/local/qt-4.5.2/mkspecs/features/include_source_dir.prf \
		/usr/local/qt-4.5.2/lib/libQtGui.prl \
		/usr/local/qt-4.5.2/lib/libQtNetwork.prl \
		/usr/local/qt-4.5.2/lib/libQtCore.prl
	$(QMAKE) -unix -o Makefile Main_Score.pro
/usr/local/qt-4.5.2/mkspecs/common/g++.conf:
/usr/local/qt-4.5.2/mkspecs/common/unix.conf:
/usr/local/qt-4.5.2/mkspecs/common/linux.conf:
/usr/local/qt-4.5.2/mkspecs/common/qws.conf:
/usr/local/qt-4.5.2/mkspecs/qconfig.pri:
/usr/local/qt-4.5.2/mkspecs/features/qt_functions.prf:
/usr/local/qt-4.5.2/mkspecs/features/qt_config.prf:
/usr/local/qt-4.5.2/mkspecs/features/exclusive_builds.prf:
/usr/local/qt-4.5.2/mkspecs/features/default_pre.prf:
/usr/local/qt-4.5.2/mkspecs/features/release.prf:
/usr/local/qt-4.5.2/mkspecs/features/default_post.prf:
/usr/local/qt-4.5.2/mkspecs/features/warn_on.prf:
/usr/local/qt-4.5.2/mkspecs/features/qt.prf:
/usr/local/qt-4.5.2/mkspecs/features/unix/thread.prf:
/usr/local/qt-4.5.2/mkspecs/features/moc.prf:
/usr/local/qt-4.5.2/mkspecs/features/resources.prf:
/usr/local/qt-4.5.2/mkspecs/features/uic.prf:
/usr/local/qt-4.5.2/mkspecs/features/yacc.prf:
/usr/local/qt-4.5.2/mkspecs/features/lex.prf:
/usr/local/qt-4.5.2/mkspecs/features/include_source_dir.prf:
/usr/local/qt-4.5.2/lib/libQtGui.prl:
/usr/local/qt-4.5.2/lib/libQtNetwork.prl:
/usr/local/qt-4.5.2/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile Main_Score.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Main_Score1.0.0 || $(MKDIR) .tmp/Main_Score1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Main_Score1.0.0/ && $(COPY_FILE) --parents scoreboard.h worker.h .tmp/Main_Score1.0.0/ && $(COPY_FILE) --parents main.cpp scoreboard.cpp worker.cpp .tmp/Main_Score1.0.0/ && $(COPY_FILE) --parents scoreboard.ui .tmp/Main_Score1.0.0/ && (cd `dirname .tmp/Main_Score1.0.0` && $(TAR) Main_Score1.0.0.tar Main_Score1.0.0 && $(COMPRESS) Main_Score1.0.0.tar) && $(MOVE) `dirname .tmp/Main_Score1.0.0`/Main_Score1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Main_Score1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_scoreboard.cpp moc_worker.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_scoreboard.cpp moc_worker.cpp
moc_scoreboard.cpp: worker.h \
		scoreboard.h
	/usr/local/qt-4.5.2/bin/moc $(DEFINES) $(INCPATH) scoreboard.h -o moc_scoreboard.cpp

moc_worker.cpp: worker.h
	/usr/local/qt-4.5.2/bin/moc $(DEFINES) $(INCPATH) worker.h -o moc_worker.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_scoreboard.h
compiler_uic_clean:
	-$(DEL_FILE) ui_scoreboard.h
ui_scoreboard.h: scoreboard.ui
	/usr/local/qt-4.5.2/bin/uic scoreboard.ui -o ui_scoreboard.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp scoreboard.h \
		worker.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

scoreboard.o: scoreboard.cpp scoreboard.h \
		worker.h \
		ui_scoreboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scoreboard.o scoreboard.cpp

worker.o: worker.cpp worker.h \
		scoreboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o worker.o worker.cpp

moc_scoreboard.o: moc_scoreboard.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_scoreboard.o moc_scoreboard.cpp

moc_worker.o: moc_worker.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_worker.o moc_worker.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

