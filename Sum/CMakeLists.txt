
include_directories(${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})
set(SRC_LIST main.cc)
add_executable(Sum ${SRC_LIST})

install(TARGETS Sum DESTINATION ${CMAKE_SOURCE_DIR}/output)