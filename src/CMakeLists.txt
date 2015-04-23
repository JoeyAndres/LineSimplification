include_directories(${douglas_peucker_SOURCE_DIR}/include)

# Non-Intrinsic Sources.
file(GLOB SRC_FILES "*.cpp")
add_library(douglas_peucker ${SRC_FILES})