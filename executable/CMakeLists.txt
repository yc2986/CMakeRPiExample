# set target name
set(TARGET executable)
# add source
file(GLOB_RECURSE SRC_FILES *.cc *.cpp *.cxx)
file(GLOB_RECURSE HDR_FILES *.h *.hpp)
# executable
add_executable(${TARGET} ${SRC_FILES} ${HDR_FILES})
if (NOT MSVC)
    target_link_libraries(${TARGET} pthread)
endif()