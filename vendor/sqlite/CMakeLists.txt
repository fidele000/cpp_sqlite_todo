file(GLOB IMGUI_SRC_FILES src/*.c)
file(GLOB IMGUI_HDR_FILES include/*.h)

add_library(sqlite ${IMGUI_SRC_FILES} ${IMGUI_HDR_FILES})
target_include_directories(sqlite PUBLIC ./include/)

target_link_libraries(sqlite PUBLIC ${CMAKE_DL_LIBS})