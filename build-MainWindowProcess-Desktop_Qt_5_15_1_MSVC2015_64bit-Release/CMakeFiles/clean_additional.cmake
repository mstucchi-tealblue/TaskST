# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\MainWindowProcess_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MainWindowProcess_autogen.dir\\ParseCache.txt"
  "MainWindowProcess_autogen"
  )
endif()
