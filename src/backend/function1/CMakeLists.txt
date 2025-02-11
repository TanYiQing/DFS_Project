# src/function1/CMakeLists.txt
add_library(function1 SHARED function1.cpp)

# Include directories if needed
target_include_directories(function1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
