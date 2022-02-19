# CMakeList.txt: CMake-Projekt für "Conways Game Of Life". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

project ("Conways Game Of Life")

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (CMakeTarget "Conways Game Of Life.cpp" "Conways Game Of Life.h")

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
