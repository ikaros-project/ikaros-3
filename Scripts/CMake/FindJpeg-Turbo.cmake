# www.ikaros-project.org
#
# Find the libjpeg-turbo includes and libraries
# Used by the ikaros kernel
#
# This module defines
# TURBO_JPEG_INCLUDE_DIRS
# TURBO_JPEG_LIBRARIES
# TURBO_JPEG_FOUND

# Find header files
find_path(TURBO_JPEG_INCLUDE_DIRS
  NAMES
    turbojpeg.h jpeglib.h
  PATHS
    /usr/local/opt/jpeg-turbo/ # homebrew
    /opt/homebrew/opt/jpeg-turbo/ # Homebrew 2021
    /usr/lib/x86_64-linux-gnu/ # Ubuntu
  PATH_SUFFIXES
    include
)

# Finding libs
find_library(TURBO_JPEG_LIBRARIES
  NAMES
    turbojpeg libturbojpeg.so.1 libturbojpeg.so.0 libturbojpeg.0.dylib libjpeg.so
  PATHS
    /usr/local/opt/jpeg-turbo/ # homebrew
    /opt/homebrew/opt/jpeg-turbo/ # Homebrew 2021
    /usr/lib/x86_64-linux-gnu/ # Ubuntu
  PATH_SUFFIXES
    lib
  )

if (TURBO_JPEG_INCLUDE_DIRS AND TURBO_JPEG_LIBRARIES)
  message(STATUS "Found libjpeg-turbo: Includes: ${TURBO_JPEG_INCLUDE_DIRS} Libraries: ${TURBO_JPEG_LIBRARIES}")
  set(TURBO_JPEG_FOUND "YES" )
endif ()
