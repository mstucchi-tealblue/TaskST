# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/browserWindowProcess_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/browserWindowProcess_autogen.dir/ParseCache.txt"
  "browserWindowProcess_autogen"
  )
endif()
