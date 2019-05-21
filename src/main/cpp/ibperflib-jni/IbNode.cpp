#include "IbNode.h"
#include "Common.h"
#include <verbs.h>
#include <IbPerfLib/IbNode.h>
#include <IbPerfLib/Exception/IbFileException.h>
#include <IbPerfLib/Exception/IbVerbsException.h>
#include <IbPerfLib/Exception/IbMadException.h>

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_resetCounters(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

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
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
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

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitDataBytes(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetXmitDataBytes();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvDataBytes(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetRcvDataBytes();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getUnicastXmitPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetUnicastXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getUnicastRcvPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetUnicastRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getMulticastXmitPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetMulticastXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getMulticastRcvPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetMulticastRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getSymbolErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetSymbolErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getLinkDownedCounter(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetLinkDownedCounter();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getLinkRecoveryCounter(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetLinkRecoveryCounter();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetRcvErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvRemotePhysicalErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetRcvRemotePhysicalErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvSwitchRelayErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetRcvSwitchRelayErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitDiscards(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetXmitDiscards();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitConstraintErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetXmitConstraintErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getRcvConstraintErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetRcvConstraintErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getLocalLinkIntegrityErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetLocalLinkIntegrityErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getExcessiveBufferOverrunErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetExcessiveBufferOverrunErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getVL15Dropped(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetVL15Dropped();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jibperf_lib_IbNode_getXmitWait(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<IbPerfLib::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    handle->GetXmitWait();
}