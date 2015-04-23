include_directories(${douglas_peucker_SOURCE_DIR}/include)
include_directories(${douglas_peucker_SOURCE_DIR}/test/include)

add_subdirectory(src)

add_executable(testRunner testRunner.cpp)
target_link_libraries(testRunner cppunit dpTest douglas_peucker)

add_test(dpTest testRunner)