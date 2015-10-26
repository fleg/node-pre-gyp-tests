#include <nan.h>

using namespace Nan;

NAN_METHOD(ReturnPrimitive) {
	info.GetReturnValue()
		.Set(New<v8::String>("TestPackage hello world!").ToLocalChecked());
}

NAN_MODULE_INIT(Init) {
	Set(target, New<v8::String>("test").ToLocalChecked(),
		New<v8::FunctionTemplate>(ReturnPrimitive)->GetFunction());
}

NODE_MODULE(TestPackage, Init)
