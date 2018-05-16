#ifndef NODE_TREE_SITTER_NODE_ARRAY_H_
#define NODE_TREE_SITTER_NODE_ARRAY_H_

#include <nan.h>
#include <node_object_wrap.h>
#include <tree_sitter/runtime.h>
#include <v8.h>

namespace node_tree_sitter {

class NodeArray : public Nan::ObjectWrap {
 public:
  static void Init(v8::Local<v8::Object> exports);
  static v8::Local<v8::Value> NewInstance(TSNode, bool);

 private:
  explicit NodeArray(TSNode, bool);

  static void New(const Nan::FunctionCallbackInfo<v8::Value> &);
  static void Length(v8::Local<v8::String>, const Nan::PropertyCallbackInfo<v8::Value> &);
  static void GetIndex(uint32_t, const Nan::PropertyCallbackInfo<v8::Value> &);
  static void IsNamed(v8::Local<v8::String>, const Nan::PropertyCallbackInfo<v8::Value> &);

  TSNode parent_node_;
  bool is_named_;

  static Nan::Persistent<v8::Function> constructor;
};

}  // namespace node_tree_sitter

#endif  // NODE_TREE_SITTER_NODE_ARRAY_H_