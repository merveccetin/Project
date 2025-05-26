cmake_minimum_required(VERSION 3.8)

project(CProject C CXX)

# Dil standartları
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(/MTd)

# pthreads kapat (bazı sistemler için gerekli)
set(gtest_disable_pthreads ON)

# Google Test alt projesi (şimdi doğru ayarla derlenecek)
add_subdirectory(src/googletest-main)

# C kütüphanen
add_library(math src/math/deneme.c)
set_source_files_properties(src/math/deneme.c PROPERTIES LANGUAGE C)

# Ana program hedefi
add_executable(CProject src/main.c)
target_link_libraries(CProject PRIVATE math)
target_include_directories(CProject PRIVATE src/math)

# Test hedefi
add_executable(CProjectTests tests/test.cpp)
target_link_libraries(CProjectTests PRIVATE math gtest_main)
target_include_directories(CProjectTests PRIVATE
    src/math
    src/googletest-main/googletest/include
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(CProjectTests)
