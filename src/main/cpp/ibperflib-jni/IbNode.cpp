#include "IbNode.h"
#include "Common.h"
#include <IbPerfLib/IbNode.h>
#include <IbPerfLib/Exception/IbFileException.h>
#include <IbPerfLib/Exception/IbMadException.h>

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_resetCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbNode *handle = static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj));

    try {
        handle->RefreshCounters();
    } catch(const IbPerfLib::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbFileException"), exception.what());
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_refreshCounters(JNIEnv *env, jobject obj) {
    IbPerfLib::IbNode *handle = static_cast<IbPerfLib::IbNode*>(getNativeHandle(env, obj));

    try {
        handle->ResetCounters();
    } catch(const IbPerfLib::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jibperf/lib/exception/IbMadException"), exception.what());
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