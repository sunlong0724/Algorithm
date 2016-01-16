
include_directories(${PROJECT_SOURCE_DIR})
message(STATUS ${PROJECT_SOURCE_DIR})
set(SRC_LIST main.cc)
add_executable(RemoveDupElement ${SRC_LIST})

install(TARGETS RemoveDupElement DESTINATION ${CMAKE_SOURCE_DIR}/output)