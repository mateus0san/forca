@echo off
REM Change to script directory (assumes script is in project root)
cd /d %~dp0

IF NOT EXIST build (
    mkdir build
)
cd build

REM Configure CMake (default Debug build)
cmake ..

REM Build the project
cmake --build .

echo Build finished successfully!
pause

