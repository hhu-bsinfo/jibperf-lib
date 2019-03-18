#include "IbFabric.h"
#include "Common.h"
#include <IbPerfLib/IbFabric.h>
#include <IbPerfLib/Exception/IbFileException.h>
#include <IbPerfLib/Exception/IbMadException.h>
#include <IbPerfLib/Exception/IbVerbsException.h>

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_init(JNIEnv *env, jobject obj, jboolean compatibility) {
    IbPerfLib::IbFabric *handle = nullptr;

    try {
        handle = new IbPerfLib::IbFabric(compatibility);
    } catch(const IbPerfLib::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbFileException"), exception.what());
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
    } catch(const IbPerfLib::IbVerbsException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbVerbsException"), exception.what());
    }

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
