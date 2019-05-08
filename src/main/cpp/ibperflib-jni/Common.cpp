#include "Common.h"

void* getNativeHandle(JNIEnv *env, jobject obj) {
    jclass cls = env->GetObjectClass(obj);
    jfieldID fieldID = env->GetFieldID(cls, "m_nativeHandle", "J");
    return reinterpret_cast<void*>(env->GetLongField(obj, fieldID));
}

void setNativeHandle(JNIEnv *env, jobject obj, void *handle) {
    jclass cls = env->GetObjectClass(obj);
    jfieldID fieldID = env->GetFieldID(cls, "m_nativeHandle", "J");
    env->SetLongField(obj, fieldID, reinterpret_cast<jlong>(handle));
}

void throwUninitializedHandleException(JNIEnv *env) {
    env->ThrowNew(env->FindClass("java/lang/IllegalStateException"), "Native handle is not initialized!");
}