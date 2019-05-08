package de.hhu.bsinfo.jibperf.lib;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;

class JniUtil {

    private static boolean IB_PERF_LIB_JNI_LOADED = false;

    /**
     * Load the shared object 'libIbPerfLibJNI.so' from the JAR-file.
     */
    public static void loadIbPerfLibJNI() {
        if(IB_PERF_LIB_JNI_LOADED) {
            return;
        }

        try {
            JniUtil.loadNativeLibraryFromJar("/libIbPerfLibJNI.so");
            IB_PERF_LIB_JNI_LOADED = true;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Load a native library, that is contained inside the .jar-file.
     *
     * Based on https://stackoverflow.com/a/49500154
     *
     * @param path The library's path inside the .jar-file
     */
     private static void loadNativeLibraryFromJar(String path) throws IOException {
        File tmpDir = Files.createTempDirectory("jibperf-native").toFile();
        tmpDir.deleteOnExit();

        File nativeLibTmpFile = new File(tmpDir, path);
        nativeLibTmpFile.deleteOnExit();

        URL url = JniUtil.class.getResource(path);
        InputStream in = url.openStream();

        Files.copy(in, nativeLibTmpFile.toPath());
        System.load(nativeLibTmpFile.getAbsolutePath());
    }
}
