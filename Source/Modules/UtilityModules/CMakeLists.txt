set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_subdirectory(Logger)
add_subdirectory(Constant)
add_subdirectory(Add)
add_subdirectory(Scale)
add_subdirectory(Oscillator)
add_subdirectory(Print)

set(SOURCE ${SOURCE} PARENT_SCOPE)
set(MODULES_INCLUDS ${MODULES_INCLUDS} PARENT_SCOPE)
set(MODULES_LIBS ${MODULES_LIBS} PARENT_SCOPE)

