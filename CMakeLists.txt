# CMAKE header.
cmake_minimum_required(VERSION 3.13.4)
project(LLVM-Lab)
project(LLVM-Lab)

set(CMAKE_CXX_STANDARD 17)
set(LLVM_PATH "/opt/homebrew/opt/llvm@17")

# Set binary output destination.
set(BINARY_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})

# Include project sources.
include_directories("src")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/files/*.cpp" "src/files/*.c")

# Get LLVM linker flags.
execute_process(COMMAND llvm-config --ldflags --system-libs --libs all OUTPUT_VARIABLE LLVM_FLAGS)

# Get rid of whitespace and replace newlines with spaces.
string(STRIP "${LLVM_FLAGS}" LLVM_FLAGS)
string(REPLACE "\n" " " LLVM_FLAGS  "${LLVM_FLAGS}")

link_directories(${LLVM_PATH}/lib)
include_directories(${LLVM_PATH}/include)

add_definitions(
        -D__STDC_LIMIT_MACROS
        -D__STDC_CONSTANT_MACROS
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -std=c++11 -frtti" )

# Append LLVM linker flags to CMAKE_EXE_LINKER_FLAGS
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LLVM_FLAGS}")



# Set binary output destination.
set(BINARY_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_DIR})



# Include project sources.
include_directories("src/files")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/files/*.cpp" "src/files/*.c")

# Get LLVM linker flags.
execute_process(COMMAND llvm-config --ldflags --system-libs --libs all OUTPUT_VARIABLE LLVM_FLAGS)

# Get rid of whitespace and replace newlines with spaces.
string(STRIP "${LLVM_FLAGS}" LLVM_FLAGS)
string(REPLACE "\n" " " LLVM_FLAGS "${LLVM_FLAGS}")

# Find bison: add  -Wcounterexamples flag to bison
find_package(BISON)
BISON_TARGET(Parser "src/files/frontend/parser.y" "${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cc" DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/parser.tab.hh"
    COMPILE_FLAGS "-Wcounterexamples")

# Find flex:
find_package(FLEX)
FLEX_TARGET(Lexer "src/files/frontend/lexer.l" "${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cc" )
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# Finally link the program with LLVM.
add_executable(${PROJECT_NAME} ${SOURCES}
        src/files/expressions/multiplication.cpp
        src/files/expressions/multiplication.h
        src/files/expressions/division.cpp
        src/files/expressions/division.h
        src/files/expressions/negative.cpp
        src/files/expressions/negative.h
        src/files/statements/return.cpp
        src/files/statements/return.h
        src/files/expressions/or.cpp
        src/files/expressions/or.h ${FLEX_Lexer_OUTPUTS} ${BISON_Parser_OUTPUTS}
        src/files/statements/for.cpp
        src/files/statements/for.h
        src/files/expressions/division.cpp
        src/files/expressions/division.h
        src/files/expressions/negative.cpp
        src/files/expressions/negative.h
        src/files/statements/for.cpp
        src/files/statements/for.h
        src/files/expressions/and.cpp
        src/files/expressions/and.h
)
