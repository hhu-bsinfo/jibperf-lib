#include "IbNode.h"
#include "Common.h"
#include <verbs.h>
#include <detector/IbNode.h>
#include <detector/exception/IbFileException.h>
#include <detector/exception/IbVerbsException.h>
#include <detector/exception/IbMadException.h>

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_resetCounters(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return;
    }

    try {
        handle->ResetCounters();
    } catch(const Detector::IbFileException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbFileException"), exception.what());
        return;
    } catch(const Detector::IbMadException &exception) {
        env->ThrowNew(env->FindClass("de/hhu/bsinfo/jdetector/lib/exception/IbMadException"), exception.what());
        return;
    }
}

JNIEXPORT void JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_refreshCounters(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
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

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getXmitDataBytes(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetXmitDataBytes();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getRcvDataBytes(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetRcvDataBytes();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getXmitPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getRcvPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getUnicastXmitPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetUnicastXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getUnicastRcvPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetUnicastRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getMulticastXmitPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetMulticastXmitPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getMulticastRcvPkts(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetMulticastRcvPkts();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getSymbolErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetSymbolErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getLinkDownedCounter(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetLinkDownedCounter();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getLinkRecoveryCounter(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetLinkRecoveryCounter();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getRcvErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetRcvErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getRcvRemotePhysicalErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetRcvRemotePhysicalErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getRcvSwitchRelayErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetRcvSwitchRelayErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getXmitDiscards(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetXmitDiscards();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getXmitConstraintErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetXmitConstraintErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getRcvConstraintErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetRcvConstraintErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getLocalLinkIntegrityErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetLocalLinkIntegrityErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getExcessiveBufferOverrunErrors(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetExcessiveBufferOverrunErrors();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getVL15Dropped(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetVL15Dropped();
}

JNIEXPORT jlong JNICALL Java_de_hhu_bsinfo_jdetector_lib_IbNode_getXmitWait(JNIEnv *env, jobject obj) {
    auto *handle = getNativeHandle<Detector::IbNode>(env, obj);
        
    if(handle == nullptr) {
        throwUninitializedHandleException(env);
        return 0;
    }
    
    return handle->GetXmitWait();
}