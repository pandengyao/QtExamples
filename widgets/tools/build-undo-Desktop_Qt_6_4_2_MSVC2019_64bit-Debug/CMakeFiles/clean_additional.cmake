# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\undo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\undo_autogen.dir\\ParseCache.txt"
  "undo_autogen"
  )
endif()
