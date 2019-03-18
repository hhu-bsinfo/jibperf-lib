#include "IbFabric.h"
#include "Common.h"
#include <IbPerfLib/IbFabric.h>

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_init(JNIEnv *env, jobject obj, jboolean compatibility) {
    IbPerfLib::IbFabric *handle = new IbPerfLib::IbFabric(compatibility);

    setNativeHandle(env, obj, handle);
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_refreshCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    handle->RefreshCounters();
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_resetCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    handle->ResetCounters();

}

JNIEXPORT jint JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_getNumNodes(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    return handle->GetNumNodes();
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_close(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    delete handle;
}
