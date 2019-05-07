#include "IbDiagPerfCounter.h"
#include "Common.h"
#include <vector>
#include <cstring>
#include <verbs.h>
#include <IbPerfLib/IbDiagPerfCounter.h>
#include <IbPerfLib/Exception/IbFileException.h>

JNIEXPORT jobjectArray JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getLocalPorts(JNIEnv *env, jclass cls) {
    int32_t numDevices;

    ibv_device **deviceList = ibv_get_device_list(&numDevices);

    if(deviceList == nullptr) {
        std::string errorMessage("Unable to get device list! Error: ");
        errorMessage += strerror(errno);

        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbVerbsException"), errorMessage.c_str());
        return env->NewObjectArray(0, cls, nullptr);
    }

    std::vector<IbPerfLib::IbDiagPerfCounter*> tmpCounters;

    jmethodID constructor = env->GetMethodID(cls, "<init>", "(JSLjava/lang/String;)V");

    for(int32_t i = 0; i < numDevices; i++) {
        std::string name = ibv_get_device_name(deviceList[i]);
        ibv_context *context = ibv_open_device(deviceList[i]);

        if(context == nullptr) {
            continue;
        }

        ibv_device_attr attr{};

        int ret = ibv_query_device(context, &attr);

        if(ret != 0) {
            continue;
        }

        try {
            tmpCounters.emplace_back(new IbPerfLib::IbDiagPerfCounter(name, 0));
        } catch(const IbPerfLib::IbFileException &exception) {
            continue;
        }

        for(uint8_t j = 1; j < attr.phys_port_cnt + 1; j++) {
            try {
                tmpCounters.emplace_back(new IbPerfLib::IbDiagPerfCounter(name, j));
            } catch(const IbPerfLib::IbFileException &exception) {
                continue;
            }
        }
    }

    jobjectArray counters = env->NewObjectArray(tmpCounters.size(), cls, nullptr);

    for(uint32_t i = 0; i < tmpCounters.size(); i++) {
        IbPerfLib::IbDiagPerfCounter *counterHandle = tmpCounters[i];

        jobject port = env->NewObject(cls, constructor, reinterpret_cast<jlong>(counterHandle),
                counterHandle->GetPortNumber(), env->NewStringUTF(counterHandle->GetDeviceName().c_str()));

        env->SetObjectArrayElement(counters, i, port);
    }

    return counters;
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_resetCounters(JNIEnv *env, jobject obj) {
    static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->ResetCounters();
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_refreshCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbDiagPerfCounter *handle = static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj));

    try {
        handle->RefreshCounters();
    } catch(const IbPerfLib::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbFileException"), exception.what());
        return;
    }
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getLifespan(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetLifespan();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getRqLocalLengthErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetRqLocalLengthErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getRqLocalProtectionErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetRqLocalProtectionErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getRqLocalQpProtectionErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetRqLocalQpProtectionErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getRqOutOfSequenceErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetRqOutOfSequenceErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getRqRemoteAccessErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetRqRemoteAccessErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getRqRemoteInvalidRequestErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetRqRemoteInvalidRequestErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getRqRnrNakNum(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetRqRnrNakNum();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getRqCompletionQueueEntryErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetRqCompletionQueueEntryErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqBadResponseErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqBadResponseErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqLocalLengthErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqLocalLengthErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqLocalProtectionErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqLocalProtectionErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqLocalQpProtectionErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqLocalQpProtectionErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqMemoryWindowBindErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqMemoryWindowBindErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqOutOfSequenceErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqOutOfSequenceErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqRemoteAccessErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqRemoteAccessErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqRemoteInvalidRequestErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqRemoteInvalidRequestErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqRnrNakNum(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqRnrNakNum();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqRemoteOperationErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqRemoteOperationErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqRnrNakRetriesExceededErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqRnrNakRetriesExceededErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqTransportRetriesExceededErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqTransportRetriesExceededErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbDiagPerfCounter_getSqCompletionQueueEntryErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbDiagPerfCounter*>(getNativeHandle(env, obj))->GetSqCompletionQueueEntryErrors();
}
