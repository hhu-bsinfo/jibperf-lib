#include <jni.h>

void* getNativeHandle(JNIEnv *env, jobject obj) {
    jclass jCls = env->GetObjectClass(obj);
    jfieldID fieldId = env->GetFieldID(jCls, "nativeHandle", "J");
    return reinterpret_cast<void*>(env->GetLongField(obj, fieldId));
}

void setNativeHandle(JNIEnv *env, jobject obj, void *handle) {
    jclass jCls = env->GetObjectClass(obj);
    jfieldID fieldId = env->GetFieldID(jCls, "nativeHandle", "J");
    env->SetLongField(obj, fieldId, reinterpret_cast<jlong>(handle));
}