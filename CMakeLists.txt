# You should always specify a range with the newest
# and oldest tested versions of CMake. 
cmake_minimum_required(VERSION 3.14...3.19)

# This is your project statement. You should always list languages;
project(
  SunSpecModBus
  VERSION 1.0
  LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find external packages for project
include(FetchContent)
FetchContent_Declare(
    sunspec
    GIT_REPOSITORY    https://github.com/sunspec/models.git
    GIT_TAG           master
)
FetchContent_MakeAvailable(sunspec)

add_definitions(-DSUNSPEC_MODEL_PATH="${sunspec_SOURCE_DIR}/")

# Find preinstall packages 
find_package (Boost REQUIRED)
find_package (PkgConfig REQUIRED)
pkg_check_modules(modbus REQUIRED)


add_subdirectory(src)

# include CMakePackageConfigHelpers macro
include(CMakePackageConfigHelpers)

# set version
set(version 3.4.1)

# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/SunSpecModBus.cmake"
  VERSION "${version}"
  COMPATIBILITY AnyNewerVersion
)

# create config file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/SunSpecModBus.cmake"
  INSTALL_DESTINATION lib/cmake
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# install config files
install(FILES
          "${CMAKE_CURRENT_BINARY_DIR}/SunSpecModBus.cmake"
          "${CMAKE_CURRENT_BINARY_DIR}/SunSpecModBus.cmake"
        DESTINATION lib/cmake
)