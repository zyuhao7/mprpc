# set(SRC_LIST userservice.cc ../user.pb.cc)
set(SRC_LIST friendservice.cc ../friend.pb.cc)


add_executable(provider ${SRC_LIST}) 

# target_link_libraries(<目标名称> <库1> <库2>...)
target_link_libraries(provider mprpc protobuf)