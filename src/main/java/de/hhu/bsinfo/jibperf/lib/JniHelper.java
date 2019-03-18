package de.hhu.bsinfo.jibperf.lib;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;

class JniHelper {

    /**
     * Load a native library, that is contained inside the .jar-file.
     *
     * Based on https://stackoverflow.com/a/49500154
     *
     * @param path The library's path inside the .jar-file
     */
     static void loadNativeLibraryFromJar(String path) throws IOException {
        File tmpDir = Files.createTempDirectory("JSocketBench-native").toFile();
        tmpDir.deleteOnExit();

        File nativeLibTmpFile = new File(tmpDir, path);
        nativeLibTmpFile.deleteOnExit();

        URL url = JniHelper.class.getResource(path);
        InputStream in = url.openStream();

        Files.copy(in, nativeLibTmpFile.toPath());
        System.load(nativeLibTmpFile.getAbsolutePath());
    }
}
