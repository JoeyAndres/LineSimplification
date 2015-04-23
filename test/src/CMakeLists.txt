include_directories(
  ${douglas_peucker_SOURCE_DIR}/include
  ${douglas_peucker_SOURCE_DIR}/test/include)

file(GLOB TEST_SRC_FILES "*.cpp")
add_library(dpTest ${TEST_SRC_FILES})
target_link_libraries(dpTest douglas_peucker cppunit)