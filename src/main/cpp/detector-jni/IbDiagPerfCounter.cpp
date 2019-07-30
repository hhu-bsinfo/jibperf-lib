#include "IbDiagPerfCounter.h"
#include "Common.h"
#include <vector>
#include <cstring>
#include <verbs.h>
#include <detector/IbDiagPerfCounter.h>
#include <detector/exception/IbFileException.h>

JNIEXPORT jobjectArray JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getLocalPorts(JNIEnv *env, jclass cls) {
    int32_t numDevices;

    ibv_device **deviceList = ibv_get_device_list(&numDevices);

    if(deviceList == nullptr) {
        std::string errorMessage("Unable to get device list! Error: ");
        errorMessage += strerror(errno);

        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbVerbsException"), errorMessage.c_str());
        return env->NewObjectArray(0, cls, nullptr);
    }

    std::vector<Detector::IbDiagPerfCounter*> tmpCounters;

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
            tmpCounters.emplace_back(new Detector::IbDiagPerfCounter(name, 0));
        } catch(const Detector::IbFileException &exception) {
            continue;
        }

        for(uint8_t j = 1; j < attr.phys_port_cnt + 1; j++) {
            try {
                tmpCounters.emplace_back(new Detector::IbDiagPerfCounter(name, j));
            } catch(const Detector::IbFileException &exception) {
                continue;
            }
        }
    }

    jobjectArray counters = env->NewObjectArray(tmpCounters.size(), cls, nullptr);

    for(uint32_t i = 0; i < tmpCounters.size(); i++) {
        Detector::IbDiagPerfCounter *counterHandle = tmpCounters[i];

        jobject port = env->NewObject(cls, constructor, reinterpret_cast<jlong>(counterHandle),
                counterHandle->GetPortNumber(), env->NewStringUTF(counterHandle->GetDeviceName().c_str()));

        env->SetObjectArrayElement(counters, i, port);
    }

    return counters;
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_resetCounters(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    handle->ResetCounters();
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_refreshCounters(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    try {
        handle->RefreshCounters();
    } catch(const Detector::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbFileException"), exception.what());
        return;
    }
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getLifespan(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetLifespan();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getRqLocalLengthErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetRqLocalLengthErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getRqLocalProtectionErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetRqLocalProtectionErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getRqLocalQpProtectionErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetRqLocalQpProtectionErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getRqOutOfSequenceErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetRqOutOfSequenceErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getRqRemoteAccessErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetRqRemoteAccessErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getRqRemoteInvalidRequestErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetRqRemoteInvalidRequestErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getRqRnrNakNum(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetRqRnrNakNum();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getRqCompletionQueueEntryErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetRqCompletionQueueEntryErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqBadResponseErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqBadResponseErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqLocalLengthErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqLocalLengthErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqLocalProtectionErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqLocalProtectionErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqLocalQpProtectionErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqLocalQpProtectionErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqMemoryWindowBindErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqMemoryWindowBindErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqOutOfSequenceErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqOutOfSequenceErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqRemoteAccessErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqRemoteAccessErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqRemoteInvalidRequestErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqRemoteInvalidRequestErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqRnrNakNum(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqRnrNakNum();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqRemoteOperationErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqRemoteOperationErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqRnrNakRetriesExceededErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqRnrNakRetriesExceededErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqTransportRetriesExceededErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqTransportRetriesExceededErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_getSqCompletionQueueEntryErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }

    return handle->GetSqCompletionQueueEntryErrors();
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbDiagPerfCounter_close(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbDiagPerfCounter>(env, obj);

    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    delete handle;

    setNativeHandle<Detector::IbDiagPerfCounter>(env, obj, nullptr);
}
