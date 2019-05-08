#ifndef IBPERFLIBJNI_COMMON_H
#define IBPERFLIBJNI_COMMON_H

#include <jni.h>

template<typename T>
T* getNativeHandle(JNIEnv *env, jobject obj) {
    jclass cls = env->GetObjectClass(obj);
    jfieldID fieldID = env->GetFieldID(cls, "m_nativeHandle", "J");

    return reinterpret_cast<T*>(env->GetLongField(obj, fieldID));
}

template<typename T>
void setNativeHandle(JNIEnv *env, jobject obj, T *handle) {
    jclass cls = env->GetObjectClass(obj);
    jfieldID fieldID = env->GetFieldID(cls, "m_nativeHandle", "J");

    env->SetLongField(obj, fieldID, reinterpret_cast<jlong>(handle));
}

void throwUninitializedHandleException(JNIEnv *env);

#endif