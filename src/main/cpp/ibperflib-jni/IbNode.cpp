#include "IbNode.h"
#include "Common.h"
#include <IbPerfLib/IbNode.h>
#include <IbPerfLib/Exception/IbFileException.h>
#include <IbPerfLib/Exception/IbVerbsException.h>
#include <IbPerfLib/Exception/IbMadException.h>

JNIEXPORT jobjectArray JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getLocalNodes(JNIEnv *env, jclass cls) {
    int32_t numDevices;

    ibv_device **deviceList = ibv_get_device_list(&numDevices);

    if(deviceList == nullptr) {
        std::string errorMessage("Unable to get device list! Error: ");
        errorMessage += strerror(errno);

        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbVerbsException"), errorMessage.c_str());
        return env->NewObjectArray(0, cls, nullptr);
    }

    jmethodID constructor = env->GetMethodID(cls, "<init>", "(JJLjava/lang/String;)V");
    jobjectArray nodes = env->NewObjectArray(numDevices, cls, nullptr);

    jclass portClass = env->FindClass("de/hhu/bsinfo/jibperf/lib/IbPort");
    jmethodID portConstructor = env->GetMethodID(portClass, "<init>", "(JSSS)V");
    jfieldID portsID = env->GetFieldID(cls, "m_ports", "[Lde/hhu/bsinfo/jibperf/lib/IbPort;");

    for(int32_t i = 0; i < numDevices; i++) {
        IbPerfLib::IbNode *nodeHandle = nullptr;

        try {
            nodeHandle = new IbPerfLib::IbNode(deviceList[i]);
        } catch(const IbPerfLib::IbFileException &exception) {
            continue;
        } catch(const IbPerfLib::IbMadException &exception) {
            continue;
        }

        jobject node = env->NewObject(cls, constructor, reinterpret_cast<jlong>(nodeHandle), nodeHandle->GetGuid(),
                env->NewStringUTF(nodeHandle->GetDescription().c_str()));

        jobjectArray ports = env->NewObjectArray(nodeHandle->GetNumPorts(), portClass, nullptr);

        for(uint32_t j = 0; j < nodeHandle->GetNumPorts(); j++) {
            IbPerfLib::IbPort *portHandle = nodeHandle->GetPorts()[j];

            jobject port = env->NewObject(portClass, portConstructor, reinterpret_cast<jlong>(portHandle),
                        portHandle->GetLid(), portHandle->GetNum(), portHandle->GetLinkWidth());

            env->SetObjectArrayElement(ports, j, port);
        }

        env->SetObjectField(node, portsID, ports);

        env->SetObjectArrayElement(nodes, i, node);
    }

    return nodes;
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_resetCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbNode *handle = static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj));

    try {
        handle->ResetCounters();
    } catch(const IbPerfLib::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbFileException"), exception.what());
        return;
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
        return;
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_refreshCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbNode *handle = static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj));

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

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitDataBytes(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetXmitDataBytes();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvDataBytes(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetRcvDataBytes();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getUnicastXmitPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetUnicastXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getUnicastRcvPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetUnicastRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getMulticastXmitPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetMulticastXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getMulticastRcvPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetMulticastRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getSymbolErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetSymbolErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getLinkDownedCounter(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetLinkDownedCounter();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getLinkRecoveryCounter(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetLinkRecoveryCounter();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetRcvErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvRemotePhysicalErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetRcvRemotePhysicalErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvSwitchRelayErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetRcvSwitchRelayErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitDiscards(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetXmitDiscards();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitConstraintErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetXmitConstraintErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvConstraintErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetRcvConstraintErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getLocalLinkIntegrityErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetLocalLinkIntegrityErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getExcessiveBufferOverrunErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetExcessiveBufferOverrunErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getVL15Dropped(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetVL15Dropped();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitWait(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj))->GetXmitWait();
}