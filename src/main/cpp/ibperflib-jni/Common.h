#ifndef IBPERFLIBJNI_COMMON_H
#define IBPERFLIBJNI_COMMON_H

#include <jni.h>

void* getNativeHandle(JNIEnv *env, jobject obj);

void setNativeHandle(JNIEnv *env, jobject obj, void *handle);

void throwUninitializedHandleException(JNIEnv *env);

#endif