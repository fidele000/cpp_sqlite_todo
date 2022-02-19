file(GLOB SRC_FILES *.cpp)
file(GLOB HDR_FILED ../include/*.h)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HDR_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ../vendor/sqlite/include ../include)
target_link_libraries(${PROJECT_NAME} sqlite)