# CMakeList.txt: CMake-Projekt für "Conways Game Of Life". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
project (cgol)
set(cgol_VERSION_MAJOR 1)
set(cgol_VERSION_MINOR 0)
# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
#add_executable (CMakeTarget "Conways Game Of Life.cpp" "Conways Game Of Life.h")

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.

include_directories("${PROJECT_BINARY_DIR}")

set(EXECUTABLE_NAME "cgol")

add_executable(${EXECUTABLE_NAME} src/main.cpp src/GUI.cpp src/Game.cpp include/Game.h include/GUI.h)

include(FetchContent)

# add an option for choosing the build type (shared or static)

set(BUILD_SHARED_LIBS OFF)


FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)



target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-system sfml-window)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

#include(InstallRequiredSystemLibraries)
#set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
#set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
#include(CPack)


