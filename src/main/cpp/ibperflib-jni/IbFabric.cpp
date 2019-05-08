#include "IbFabric.h"
#include "Common.h"
#include <IbPerfLib/IbFabric.h>
#include <IbPerfLib/Exception/IbFileException.h>
#include <IbPerfLib/Exception/IbMadException.h>
#include <IbPerfLib/Exception/IbVerbsException.h>
#include <IbPerfLib/Exception/IbNetDiscException.h>

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_init(JNIEnv *env, jobject obj, jboolean compatibility) {
    IbPerfLib::IbFabric *fabricHandle = nullptr;

    try {
        fabricHandle = new IbPerfLib::IbFabric(compatibility);
    } catch(const IbPerfLib::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbFileException"), exception.what());
        return;
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
        return;
    } catch(const IbPerfLib::IbVerbsException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbVerbsException"), exception.what());
        return;
    } catch(const IbPerfLib::IbNetDiscException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbNetDiscException"), exception.what());
        return;
    }

    setNativeHandle(env, obj, fabricHandle);

    jclass fabricClass = env->FindClass("de/hhu/bsinfo/jibperf/lib/IbFabric");
    jclass nodeClass = env->FindClass("de/hhu/bsinfo/jibperf/lib/IbNode");
    jclass portClass = env->FindClass("de/hhu/bsinfo/jibperf/lib/IbPort");

    jobjectArray nodes = env->NewObjectArray(fabricHandle->GetNumNodes(), nodeClass, nullptr);
    jmethodID nodeConstructor = env->GetMethodID(nodeClass, "<init>", "(JJLjava/lang/String;)V");
    jfieldID nodesID = env->GetFieldID(fabricClass, "m_nodes", "[Lde/hhu/bsinfo/jibperf/lib/IbNode;");

    jmethodID portConstructor = env->GetMethodID(portClass, "<init>", "(JSSS)V");
    jfieldID portsID = env->GetFieldID(nodeClass, "m_ports", "[Lde/hhu/bsinfo/jibperf/lib/IbPort;");

    for(uint32_t i = 0; i < fabricHandle->GetNumNodes(); i++) {
        IbPerfLib::IbNode *nodeHandle = fabricHandle->GetNodes()[i];

        jobject node = env->NewObject(nodeClass, nodeConstructor, reinterpret_cast<jlong>(nodeHandle),
                        nodeHandle->GetGuid(), env->NewStringUTF(nodeHandle->GetDescription().c_str()));

        env->SetObjectArrayElement(nodes, i, node);

        jobjectArray ports = env->NewObjectArray(nodeHandle->GetNumPorts(), portClass, nullptr);
        
        for(uint32_t j = 0; j < nodeHandle->GetNumPorts(); j++) {
            IbPerfLib::IbPort *portHandle = nodeHandle->GetPorts()[j];

            jobject port = env->NewObject(portClass, portConstructor, reinterpret_cast<jlong>(portHandle),
                        portHandle->GetLid(), portHandle->GetNum(), portHandle->GetLinkWidth());

            env->SetObjectArrayElement(ports, j, port);
        }

        env->SetObjectField(node, portsID, ports);
    }

    env->SetObjectField(obj, nodesID, nodes);
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_refreshCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    try {
        handle->RefreshCounters();
    } catch(const IbPerfLib::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbFileException"), exception.what());
        return;
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
        return;
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_resetCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    try {
        handle->ResetCounters();
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
        return;
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbFabric_close(JNIEnv *env, jobject obj) {
    IbPerfLib::IbFabric *handle = static_cast<IbPerfLib::IbFabric*>(getNativeHandle(env, obj));

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    delete handle;

    setNativeHandle(env, obj, nullptr);
}
