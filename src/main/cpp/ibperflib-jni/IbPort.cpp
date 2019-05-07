#include "IbPort.h"
#include "Common.h"
#include <IbPerfLib/IbPort.h>
#include <IbPerfLib/Exception/IbFileException.h>
#include <IbPerfLib/Exception/IbMadException.h>

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_resetCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbPort *handle = static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj));

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

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_refreshCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbPort *handle = static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj));

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

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getXmitDataBytes(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetXmitDataBytes();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getRcvDataBytes(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetRcvDataBytes();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getXmitPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getRcvPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getUnicastXmitPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetUnicastXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getUnicastRcvPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetUnicastRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getMulticastXmitPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetMulticastXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getMulticastRcvPkts(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetMulticastRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getSymbolErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetSymbolErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getLinkDownedCounter(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetLinkDownedCounter();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getLinkRecoveryCounter(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetLinkRecoveryCounter();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getRcvErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetRcvErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getRcvRemotePhysicalErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetRcvRemotePhysicalErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getRcvSwitchRelayErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetRcvSwitchRelayErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getXmitDiscards(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetXmitDiscards();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getXmitConstraintErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetXmitConstraintErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getRcvConstraintErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetRcvConstraintErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getLocalLinkIntegrityErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetLocalLinkIntegrityErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getExcessiveBufferOverrunErrors(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetExcessiveBufferOverrunErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getVL15Dropped(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetVL15Dropped();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbPort_getXmitWait(JNIEnv *env, jobject obj) {
    return static_cast<IbPerfLib::IbPort*>(getNativeHandle(env, obj))->GetXmitWait();
}