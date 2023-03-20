#include <napi.h>
#include "add.h"
#include <iostream>

Napi::Number addFuncWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() < 3 || !info[0].IsNumber() || !info[1].IsNumber() || !info[2].IsString())
    {
        Napi::TypeError::New(env, "3 arguments expected (number, number, string)").ThrowAsJavaScriptException();
    }

    int arg0 = info[0].As<Napi::Number>().Int64Value();
    int arg1 = info[1].As<Napi::Number>().Int64Value();

    std::string path = info[2].As<Napi::String>().ToString();
    char *filepath = &path[0];

    int result = addFunc(arg0, arg1, filepath);

    return Napi::Number::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, addFuncWrapped));
    return exports;
}

NODE_API_MODULE(add, Init)