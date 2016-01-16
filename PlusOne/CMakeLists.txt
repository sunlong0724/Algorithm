
include_directories(${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})
set(SRC_LIST main.cc)
add_executable(PlusOne ${SRC_LIST})

install(TARGETS PlusOne DESTINATION ${CMAKE_SOURCE_DIR}/output)