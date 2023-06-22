include(../../qt_shared/common.pri)

QT += core gui charts sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -DMY_DB_NAME=\\\"budget\\\"

HEADERS *= $$files(../SRC/inc/*.h, ../SRC/inc)
INCLUDEPATH *= ../SRC/inc
SOURCES *= $$files(../SRC/src/*.cpp, ../SRC/src)
FORMS *= $$files(../SRC/ui/*.ui, ../SRC/ui)

PATH_TO_DB_LIB = "../../db_helper"
HEADERS *= $$files($${PATH_TO_DB_LIB}/SRC/inc/*.h, $${PATH_TO_DB_LIB}/SRC/inc)
INCLUDEPATH *= $${PATH_TO_DB_LIB}/SRC/inc
SOURCES *= $$files($${PATH_TO_DB_LIB}/SRC/src/*.cpp, $${PATH_TO_DB_LIB}/SRC/src)
FORMS *= $$files($${PATH_TO_DB_LIB}/SRC/ui/*.ui, $${PATH_TO_DB_LIB}/SRC/ui)

DESTDIR = $$PWD/../EXE
