# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "echowindow\\CMakeFiles\\echopluginwindow_autogen.dir\\AutogenUsed.txt"
  "echowindow\\CMakeFiles\\echopluginwindow_autogen.dir\\ParseCache.txt"
  "echowindow\\echopluginwindow_autogen"
  "plugin\\CMakeFiles\\echoplugin_autogen.dir\\AutogenUsed.txt"
  "plugin\\CMakeFiles\\echoplugin_autogen.dir\\ParseCache.txt"
  "plugin\\echoplugin_autogen"
  )
endif()
