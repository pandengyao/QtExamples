# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\reflectionprobes_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\reflectionprobes_autogen.dir\\ParseCache.txt"
  "reflectionprobes_autogen"
  )
endif()
