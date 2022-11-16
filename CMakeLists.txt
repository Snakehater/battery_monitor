cmake_minimum_required(VERSION 3.20.1)
project(Batter-monitor LANGUAGES CXX)

#find_package(sqlite3 CONFIG REQUIRED)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options (-fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options (-fcolor-diagnostics)
    endif ()
endif ()

add_executable(main
	src/main.cpp
)

include_directories(main PRIVATE
	include/
)

# Ugly way of adding sqlite3
SET(GCC_COVERAGE_LINK_FLAGS "-lsqlite3")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

#target_link_libraries(main ${SQLITE3_LIBRARIES})
#target_link_libraries(main PUBLIC sqlite3)
