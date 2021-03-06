#include "NativeBuildConfig.h"
#include <detector/BuildConfig.h>

JNIEXPORT jstring JNICALL Java_de_hhu_bsinfo_jdetector_lib_NativeBuildConfig_getVersion(JNIEnv *env, jclass cls) {
    return env->NewStringUTF(Detector::BuildConfig::VERSION);
}

JNIEXPORT jstring JNICALL Java_de_hhu_bsinfo_jdetector_lib_NativeBuildConfig_getGitRevision(JNIEnv *env, jclass cls) {
    return env->NewStringUTF(Detector::BuildConfig::GIT_REV);
}

JNIEXPORT jstring JNICALL Java_de_hhu_bsinfo_jdetector_lib_NativeBuildConfig_getGitBranch(JNIEnv *env, jclass cls) {
    return env->NewStringUTF(Detector::BuildConfig::GIT_BRANCH);
}

JNIEXPORT jstring JNICALL Java_de_hhu_bsinfo_jdetector_lib_NativeBuildConfig_getBuildDate(JNIEnv *env, jclass cls) {
    return env->NewStringUTF(Detector::BuildConfig::BUILD_DATE);
}

JNIEXPORT jboolean JNICALL Java_de_hhu_bsinfo_jdetector_lib_NativeBuildConfig_areAdditionalExtendedCountersEnabled(JNIEnv *env, jclass cls) {
    return Detector::BuildConfig::ADDITIONAL_EXTENDED_COUNTERS_ENABLED;
}
