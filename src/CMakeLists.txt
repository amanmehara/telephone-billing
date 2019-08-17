set (SRC
     bill.cpp
     bill_options.cpp
     bill_service.cpp
     rate.cpp
     user.cpp
     user_options.cpp
     user_service.cpp)

add_library (src ${SRC})
add_executable (main "main.cpp")

target_link_libraries(main src)
