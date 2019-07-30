#include "Common.h"

void throwUninitializedHandleException(JNIEnv *env) {
    env->ThrowNew(env->FindClass("java/lang/IllegalStateException"), "Native handle is not initialized!");
}