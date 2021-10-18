cmake_minimum_required(VERSION 3.10)

project(cpp-bench CXX)

include(${PROJECT_SOURCE_DIR}/cmake/conan.cmake)
conan_cmake_run(
  CONANFILE conanfile.txt
  BASIC_SETUP
  CMAKE_TARGETS # individual targets to link to
  BUILD
    missing
 
)

add_executable(${PROJECT_NAME} src/bench.cpp)
conan_target_link_libraries(${PROJECT_NAME})

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -march=native
        -mavx2 
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

add_custom_target(
    bench $<TARGET_FILE:${PROJECT_NAME}> --benchmark_repetitions=10 --benchmark_display_aggregates_only=true
    DEPENDS ${PROJECT_NAME}
)

add_executable(test-calculate tests/test_calculate.cpp)
conan_target_link_libraries(test-calculate)
target_include_directories(test-calculate PRIVATE src)
target_compile_options(test-calculate PRIVATE
    -march=native
    -Wall
    -Wextra
    -Werror
    -pedantic
)
target_compile_features(test-calculate PUBLIC cxx_std_20)

add_custom_target(
    tests $<TARGET_FILE:test-calculate>
    DEPENDS test-calculate
)