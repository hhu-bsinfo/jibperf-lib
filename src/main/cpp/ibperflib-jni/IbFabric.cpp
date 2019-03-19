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

    jclass fabricClass = env->GetObjectClass(obj);
    jclass nodeClass = env->FindClass("de/hhu/bsinfo/jibperf/lib/IbNode");

    jobjectArray nodes = env->NewObjectArray(handle->GetNumNodes(), nodeClass, nullptr);
    jmethodID nodeConstructor = env->GetMethodID(nodeClass, "<init>", "(JJLjava/lang/String;)V");

    jfieldID nodesID = env->GetFieldID(fabricClass, "m_nodes", "[Lde/hhu/bsinfo/jibperf/lib/IbNode;");

    for(uint32_t i = 0; i < handle->GetNumNodes(); i++) {
        IbPerfLib::IbNode *nodeHandle = handle->GetNodes()[i];
        jobject node = env->NewObject(nodeClass, nodeConstructor, reinterpret_cast<jlong>(nodeHandle),
                        nodeHandle->GetGuid(), env->NewStringUTF(nodeHandle->GetDescription().c_str()));

        env->SetObjectArrayElement(nodes, i, node);
    }

    env->SetObjectField(obj, nodesID, nodes);
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_refreshCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    try {
        handle->RefreshCounters();
    } catch(const IbPerfLib::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbFileException"), exception.what());
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_resetCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    try {
        handle->ResetCounters();
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_close(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    delete handle;

    setNativeHandle(env, obj, nullptr);
}
