# CMakeList.txt : CMake project for DFS_Project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("DFS_Project")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add subdirectories for each component
add_subdirectory(src/backend/function1)
add_subdirectory(src/backend/function2)

# Define the executable that uses component1 and component2
add_executable(DFS_Project src/DFS_Project.cpp)

# TODO: Add tests and install targets if needed.

target_link_libraries(DFS_Project PRIVATE function1 function2)  # Link to the DLLs
target_include_directories(DFS_Project PRIVATE 
    ${CMAKE_SOURCE_DIR}/src/function1
    ${CMAKE_SOURCE_DIR}/src/function2
)  # Include the header directories
