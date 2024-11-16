#pragma once
#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>

class mprpcChannel : public google::protobuf::RpcChannel
{
public:
    // 所有通过 stub 代理对象调用的 rpc 方法, 都到这里统一做数据序列化和网络发送.
    void CallMethod(const google::protobuf::MethodDescriptor *method,
                    google::protobuf::RpcController *controller,
                    const google::protobuf::Message *request,
                    google::protobuf::Message *response,
                    google::protobuf::Closure *done);

private:
};