# aux_source_directory(. SRC_LIST)

set(SRC_LIST mprpcapplication.cc mprpcconfig.cc rpcprovider.cc rpcheader.pb.cc mprpcchannel.cc)

add_library(mprpc ${SRC_LIST})

target_link_libraries(mprpc muduo_net muduo_base pthread)
