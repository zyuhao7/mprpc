// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: user.proto

#include "user.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace fixbug {
PROTOBUF_CONSTEXPR ResultCode::ResultCode(
    ::_pbi::ConstantInitialized)
  : errmsg_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , errcode_(0){}
struct ResultCodeDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ResultCodeDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ResultCodeDefaultTypeInternal() {}
  union {
    ResultCode _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ResultCodeDefaultTypeInternal _ResultCode_default_instance_;
PROTOBUF_CONSTEXPR LoginRequest::LoginRequest(
    ::_pbi::ConstantInitialized)
  : name_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , pwd_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}){}
struct LoginRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LoginRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LoginRequestDefaultTypeInternal() {}
  union {
    LoginRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LoginRequestDefaultTypeInternal _LoginRequest_default_instance_;
PROTOBUF_CONSTEXPR LoginResponse::LoginResponse(
    ::_pbi::ConstantInitialized)
  : result_(nullptr)
  , success_(false){}
struct LoginResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LoginResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LoginResponseDefaultTypeInternal() {}
  union {
    LoginResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LoginResponseDefaultTypeInternal _LoginResponse_default_instance_;
}  // namespace fixbug
static ::_pb::Metadata file_level_metadata_user_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_user_2eproto = nullptr;
static const ::_pb::ServiceDescriptor* file_level_service_descriptors_user_2eproto[1];

const uint32_t TableStruct_user_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::fixbug::ResultCode, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::fixbug::ResultCode, errcode_),
  PROTOBUF_FIELD_OFFSET(::fixbug::ResultCode, errmsg_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::fixbug::LoginRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::fixbug::LoginRequest, name_),
  PROTOBUF_FIELD_OFFSET(::fixbug::LoginRequest, pwd_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::fixbug::LoginResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::fixbug::LoginResponse, result_),
  PROTOBUF_FIELD_OFFSET(::fixbug::LoginResponse, success_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::fixbug::ResultCode)},
  { 8, -1, -1, sizeof(::fixbug::LoginRequest)},
  { 16, -1, -1, sizeof(::fixbug::LoginResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::fixbug::_ResultCode_default_instance_._instance,
  &::fixbug::_LoginRequest_default_instance_._instance,
  &::fixbug::_LoginResponse_default_instance_._instance,
};

const char descriptor_table_protodef_user_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\nuser.proto\022\006fixbug\"-\n\nResultCode\022\017\n\007er"
  "rcode\030\001 \001(\005\022\016\n\006errmsg\030\002 \001(\014\")\n\014LoginRequ"
  "est\022\014\n\004name\030\001 \001(\014\022\013\n\003pwd\030\002 \001(\014\"D\n\rLoginR"
  "esponse\022\"\n\006result\030\001 \001(\0132\022.fixbug.ResultC"
  "ode\022\017\n\007success\030\002 \001(\0102F\n\016UserServiceRpc\0224"
  "\n\005Login\022\024.fixbug.LoginRequest\032\025.fixbug.L"
  "oginResponseB\003\200\001\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_user_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_user_2eproto = {
    false, false, 265, descriptor_table_protodef_user_2eproto,
    "user.proto",
    &descriptor_table_user_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_user_2eproto::offsets,
    file_level_metadata_user_2eproto, file_level_enum_descriptors_user_2eproto,
    file_level_service_descriptors_user_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_user_2eproto_getter() {
  return &descriptor_table_user_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_user_2eproto(&descriptor_table_user_2eproto);
namespace fixbug {

// ===================================================================

class ResultCode::_Internal {
 public:
};

ResultCode::ResultCode(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:fixbug.ResultCode)
}
ResultCode::ResultCode(const ResultCode& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  errmsg_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    errmsg_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_errmsg().empty()) {
    errmsg_.Set(from._internal_errmsg(), 
      GetArenaForAllocation());
  }
  errcode_ = from.errcode_;
  // @@protoc_insertion_point(copy_constructor:fixbug.ResultCode)
}

inline void ResultCode::SharedCtor() {
errmsg_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  errmsg_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
errcode_ = 0;
}

ResultCode::~ResultCode() {
  // @@protoc_insertion_point(destructor:fixbug.ResultCode)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ResultCode::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  errmsg_.Destroy();
}

void ResultCode::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void ResultCode::Clear() {
// @@protoc_insertion_point(message_clear_start:fixbug.ResultCode)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  errmsg_.ClearToEmpty();
  errcode_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ResultCode::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 errcode = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          errcode_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes errmsg = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_errmsg();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ResultCode::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:fixbug.ResultCode)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 errcode = 1;
  if (this->_internal_errcode() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_errcode(), target);
  }

  // bytes errmsg = 2;
  if (!this->_internal_errmsg().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_errmsg(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fixbug.ResultCode)
  return target;
}

size_t ResultCode::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:fixbug.ResultCode)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes errmsg = 2;
  if (!this->_internal_errmsg().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_errmsg());
  }

  // int32 errcode = 1;
  if (this->_internal_errcode() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_errcode());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ResultCode::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    ResultCode::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ResultCode::GetClassData() const { return &_class_data_; }

void ResultCode::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<ResultCode *>(to)->MergeFrom(
      static_cast<const ResultCode &>(from));
}


void ResultCode::MergeFrom(const ResultCode& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:fixbug.ResultCode)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_errmsg().empty()) {
    _internal_set_errmsg(from._internal_errmsg());
  }
  if (from._internal_errcode() != 0) {
    _internal_set_errcode(from._internal_errcode());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ResultCode::CopyFrom(const ResultCode& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fixbug.ResultCode)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ResultCode::IsInitialized() const {
  return true;
}

void ResultCode::InternalSwap(ResultCode* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &errmsg_, lhs_arena,
      &other->errmsg_, rhs_arena
  );
  swap(errcode_, other->errcode_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ResultCode::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_user_2eproto_getter, &descriptor_table_user_2eproto_once,
      file_level_metadata_user_2eproto[0]);
}

// ===================================================================

class LoginRequest::_Internal {
 public:
};

LoginRequest::LoginRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:fixbug.LoginRequest)
}
LoginRequest::LoginRequest(const LoginRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    name_.Set(from._internal_name(), 
      GetArenaForAllocation());
  }
  pwd_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    pwd_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_pwd().empty()) {
    pwd_.Set(from._internal_pwd(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:fixbug.LoginRequest)
}

inline void LoginRequest::SharedCtor() {
name_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  name_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
pwd_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  pwd_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

LoginRequest::~LoginRequest() {
  // @@protoc_insertion_point(destructor:fixbug.LoginRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void LoginRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  name_.Destroy();
  pwd_.Destroy();
}

void LoginRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void LoginRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:fixbug.LoginRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty();
  pwd_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LoginRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bytes name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes pwd = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_pwd();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* LoginRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:fixbug.LoginRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bytes name = 1;
  if (!this->_internal_name().empty()) {
    target = stream->WriteBytesMaybeAliased(
        1, this->_internal_name(), target);
  }

  // bytes pwd = 2;
  if (!this->_internal_pwd().empty()) {
    target = stream->WriteBytesMaybeAliased(
        2, this->_internal_pwd(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fixbug.LoginRequest)
  return target;
}

size_t LoginRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:fixbug.LoginRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_name());
  }

  // bytes pwd = 2;
  if (!this->_internal_pwd().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_pwd());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LoginRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    LoginRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LoginRequest::GetClassData() const { return &_class_data_; }

void LoginRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<LoginRequest *>(to)->MergeFrom(
      static_cast<const LoginRequest &>(from));
}


void LoginRequest::MergeFrom(const LoginRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:fixbug.LoginRequest)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _internal_set_name(from._internal_name());
  }
  if (!from._internal_pwd().empty()) {
    _internal_set_pwd(from._internal_pwd());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LoginRequest::CopyFrom(const LoginRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fixbug.LoginRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LoginRequest::IsInitialized() const {
  return true;
}

void LoginRequest::InternalSwap(LoginRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &name_, lhs_arena,
      &other->name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &pwd_, lhs_arena,
      &other->pwd_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata LoginRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_user_2eproto_getter, &descriptor_table_user_2eproto_once,
      file_level_metadata_user_2eproto[1]);
}

// ===================================================================

class LoginResponse::_Internal {
 public:
  static const ::fixbug::ResultCode& result(const LoginResponse* msg);
};

const ::fixbug::ResultCode&
LoginResponse::_Internal::result(const LoginResponse* msg) {
  return *msg->result_;
}
LoginResponse::LoginResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:fixbug.LoginResponse)
}
LoginResponse::LoginResponse(const LoginResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_result()) {
    result_ = new ::fixbug::ResultCode(*from.result_);
  } else {
    result_ = nullptr;
  }
  success_ = from.success_;
  // @@protoc_insertion_point(copy_constructor:fixbug.LoginResponse)
}

inline void LoginResponse::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&result_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&success_) -
    reinterpret_cast<char*>(&result_)) + sizeof(success_));
}

LoginResponse::~LoginResponse() {
  // @@protoc_insertion_point(destructor:fixbug.LoginResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void LoginResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete result_;
}

void LoginResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void LoginResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:fixbug.LoginResponse)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && result_ != nullptr) {
    delete result_;
  }
  result_ = nullptr;
  success_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LoginResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .fixbug.ResultCode result = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_result(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bool success = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          success_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* LoginResponse::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:fixbug.LoginResponse)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .fixbug.ResultCode result = 1;
  if (this->_internal_has_result()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::result(this),
        _Internal::result(this).GetCachedSize(), target, stream);
  }

  // bool success = 2;
  if (this->_internal_success() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(2, this->_internal_success(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:fixbug.LoginResponse)
  return target;
}

size_t LoginResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:fixbug.LoginResponse)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .fixbug.ResultCode result = 1;
  if (this->_internal_has_result()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *result_);
  }

  // bool success = 2;
  if (this->_internal_success() != 0) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData LoginResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    LoginResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*LoginResponse::GetClassData() const { return &_class_data_; }

void LoginResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<LoginResponse *>(to)->MergeFrom(
      static_cast<const LoginResponse &>(from));
}


void LoginResponse::MergeFrom(const LoginResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:fixbug.LoginResponse)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_result()) {
    _internal_mutable_result()->::fixbug::ResultCode::MergeFrom(from._internal_result());
  }
  if (from._internal_success() != 0) {
    _internal_set_success(from._internal_success());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void LoginResponse::CopyFrom(const LoginResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:fixbug.LoginResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LoginResponse::IsInitialized() const {
  return true;
}

void LoginResponse::InternalSwap(LoginResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LoginResponse, success_)
      + sizeof(LoginResponse::success_)
      - PROTOBUF_FIELD_OFFSET(LoginResponse, result_)>(
          reinterpret_cast<char*>(&result_),
          reinterpret_cast<char*>(&other->result_));
}

::PROTOBUF_NAMESPACE_ID::Metadata LoginResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_user_2eproto_getter, &descriptor_table_user_2eproto_once,
      file_level_metadata_user_2eproto[2]);
}

// ===================================================================

UserServiceRpc::~UserServiceRpc() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* UserServiceRpc::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_user_2eproto);
  return file_level_service_descriptors_user_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* UserServiceRpc::GetDescriptor() {
  return descriptor();
}

void UserServiceRpc::Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::fixbug::LoginRequest*,
                         ::fixbug::LoginResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Login() not implemented.");
  done->Run();
}

void UserServiceRpc::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_user_2eproto[0]);
  switch(method->index()) {
    case 0:
      Login(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::fixbug::LoginRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::fixbug::LoginResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& UserServiceRpc::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::fixbug::LoginRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& UserServiceRpc::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::fixbug::LoginResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

UserServiceRpc_Stub::UserServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
UserServiceRpc_Stub::UserServiceRpc_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
UserServiceRpc_Stub::~UserServiceRpc_Stub() {
  if (owns_channel_) delete channel_;
}

void UserServiceRpc_Stub::Login(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::fixbug::LoginRequest* request,
                              ::fixbug::LoginResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace fixbug
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::fixbug::ResultCode*
Arena::CreateMaybeMessage< ::fixbug::ResultCode >(Arena* arena) {
  return Arena::CreateMessageInternal< ::fixbug::ResultCode >(arena);
}
template<> PROTOBUF_NOINLINE ::fixbug::LoginRequest*
Arena::CreateMaybeMessage< ::fixbug::LoginRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::fixbug::LoginRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::fixbug::LoginResponse*
Arena::CreateMaybeMessage< ::fixbug::LoginResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::fixbug::LoginResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
