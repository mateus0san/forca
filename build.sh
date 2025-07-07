#!/bin/bash
set -e  # Exit if any command fails

# Go to project root (assumes script is in project root)
mkdir -p build
cd build

# Configure CMake (default Debug build)
cmake ..

# Build the project
cmake --build .

echo "Build finished successfully!"

