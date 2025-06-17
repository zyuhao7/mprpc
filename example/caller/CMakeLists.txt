set(SRC_LIST calluserservice.cc ../user.pb.cc)


add_executable(consumer ${SRC_LIST}) 

# target_link_libraries(<目标名称> <库1> <库2>...)
target_link_libraries(consumer mprpc protobuf)