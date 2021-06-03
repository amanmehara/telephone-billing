set (SRC
     bill.h
     bill.cpp
     bill_options.h
     bill_options.cpp
     bill_service.h
     bill_service.cpp
     rate.h
     user.h
     user.cpp
     user_options.h
     user_options.cpp
     user_service.h
     user_service.cpp)

add_library (src ${SRC})
add_executable (main "main.cpp")

target_link_libraries(main src)
