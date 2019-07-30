#include "IbFabric.h"
#include "Common.h"
#include <detector/IbFabric.h>
#include <detector/exception/IbFileException.h>
#include <detector/exception/IbMadException.h>
#include <detector/exception/IbVerbsException.h>
#include <detector/exception/IbNetDiscException.h>

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbFabric_init(JNIEnv *env, jobject obj, jboolean network, jboolean compatibility) {
    Detector::IbFabric *fabricHandle = nullptr;

    try {
        fabricHandle = new Detector::IbFabric(network, compatibility);
    } catch(const Detector::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbFileException"), exception.what());
        return;
    } catch(const Detector::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbMadException"), exception.what());
        return;
    } catch(const Detector::IbVerbsException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbVerbsException"), exception.what());
        return;
    } catch(const Detector::IbNetDiscException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbNetDiscException"), exception.what());
        return;
    }

    setNativeHandle<Detector::IbFabric>(env, obj, fabricHandle);

    jclass fabricClass = env->FindClass("de/hhu/bsinfo/jdetector/lib/IbFabric");
    jclass nodeClass = env->FindClass("de/hhu/bsinfo/jdetector/lib/IbNode");
    jclass portClass = env->FindClass("de/hhu/bsinfo/jdetector/lib/IbPort");

    jobjectArray nodes = env->NewObjectArray(fabricHandle->GetNumNodes(), nodeClass, nullptr);
    jmethodID nodeConstructor = env->GetMethodID(nodeClass, "<init>", "(JJLjava/lang/String;)V");
    jfieldID nodesID = env->GetFieldID(fabricClass, "m_nodes", "[Lde/hhu/bsinfo/jdetector/lib/IbNode;");

    jmethodID portConstructor = env->GetMethodID(portClass, "<init>", "(JSSS)V");
    jfieldID portsID = env->GetFieldID(nodeClass, "m_ports", "[Lde/hhu/bsinfo/jdetector/lib/IbPort;");

    for(uint32_t i = 0; i < fabricHandle->GetNumNodes(); i++) {
        Detector::IbNode *nodeHandle = fabricHandle->GetNodes()[i];

        jobject node = env->NewObject(nodeClass, nodeConstructor, reinterpret_cast<jlong>(nodeHandle),
                        nodeHandle->GetGuid(), env->NewStringUTF(nodeHandle->GetDescription().c_str()));

        env->SetObjectArrayElement(nodes, i, node);

        jobjectArray ports = env->NewObjectArray(nodeHandle->GetNumPorts(), portClass, nullptr);
        
        for(uint32_t j = 0; j < nodeHandle->GetNumPorts(); j++) {
            Detector::IbPort *portHandle = nodeHandle->GetPorts()[j];

            jobject port = env->NewObject(portClass, portConstructor, reinterpret_cast<jlong>(portHandle),
                        portHandle->GetLid(), portHandle->GetNum(), portHandle->GetLinkWidth());

            env->SetObjectArrayElement(ports, j, port);
        }

        env->SetObjectField(node, portsID, ports);
    }

    env->SetObjectField(obj, nodesID, nodes);
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbFabric_refreshCounters(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbFabric>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    try {
        handle->RefreshCounters();
    } catch(const Detector::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbFileException"), exception.what());
        return;
    } catch(const Detector::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbMadException"), exception.what());
        return;
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbFabric_resetCounters(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbFabric>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    try {
        handle->ResetCounters();
    } catch(const Detector::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbMadException"), exception.what());
        return;
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbFabric_close(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbFabric>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    delete handle;

    setNativeHandle<Detector::IbFabric>(env, obj, nullptr);
}
