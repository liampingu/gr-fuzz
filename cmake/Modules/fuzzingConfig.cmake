INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_FUZZING fuzzing)

FIND_PATH(
    FUZZING_INCLUDE_DIRS
    NAMES fuzzing/api.h
    HINTS $ENV{FUZZING_DIR}/include
        ${PC_FUZZING_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    FUZZING_LIBRARIES
    NAMES gnuradio-fuzzing
    HINTS $ENV{FUZZING_DIR}/lib
        ${PC_FUZZING_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FUZZING DEFAULT_MSG FUZZING_LIBRARIES FUZZING_INCLUDE_DIRS)
MARK_AS_ADVANCED(FUZZING_LIBRARIES FUZZING_INCLUDE_DIRS)

