cmake_minimum_required(VERSION 3.30.3)

project(noteFlip)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Start - C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
# End - C++ standard

# Start - Release mode
option(USE_RELEASE "Builds project in release mode" ON)
option(USE_DEBUG "Builds project in debug mode" OFF)

if (USE_RELEASE AND USE_DEBUG)
    message(FATAL_ERROR "Both release and debug modes are selected. Please enable only one in the CMakeLists.txt file.")
elseif (USE_RELEASE)
    set(CMAKE_BUILD_TYPE Release)
elseif (USE_DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
else()
    message(FATAL_ERROR "No build mode was selected. Enable one in the CMakeLists.txt file.")
endif()
# End - Release mode

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)
