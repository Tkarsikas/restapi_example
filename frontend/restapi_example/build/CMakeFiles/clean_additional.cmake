# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\restapi_example_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\restapi_example_autogen.dir\\ParseCache.txt"
  "restapi_example_autogen"
  )
endif()
