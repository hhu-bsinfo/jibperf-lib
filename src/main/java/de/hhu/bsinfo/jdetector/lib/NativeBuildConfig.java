/*
 * Copyright (C) 2019 Heinrich-Heine-Universitaet Duesseldorf, Institute of Computer Science,
 * Department Operating Systems
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

package de.hhu.bsinfo.jdetector.lib;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.stream.Collectors;

import de.hhu.bsinfo.jdetector.generated.BuildConfig;

/**
 * Provides build information about the native library 'detector', which jDetector depends on.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class NativeBuildConfig {

    static {
        System.loadLibrary("detectorJNI");
    }

    /**
     * Print the jDetector banner, including version and build information.
     */
    public static void printBanner() {
        InputStream inputStream = NativeBuildConfig.class.getClassLoader().getResourceAsStream("banner.txt");

        if (inputStream == null) {
            return;
        }

        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        String banner = reader.lines().collect(Collectors.joining(System.lineSeparator()));

        System.out.print("\n");
        System.out.printf(banner, BuildConfig.VERSION, getVersion(), BuildConfig.BUILD_DATE, BuildConfig.GIT_BRANCH, BuildConfig.GIT_COMMIT, areAdditionalExtendedCountersEnabled() ? "Enabled" : "Disabled");
        System.out.print("\n\n");
    }

    /**
     * Get the version of detector.
     */
    public static native String getVersion();

    /**
     * Get the git commit hash of detector.
     */
    public static native String getGitRevision();

    /**
     * Get the git commit branch of detector.
     */
    public static native String getGitBranch();

    /**
     * Get the build date of detector.
     */
    public static native String getBuildDate();

    /**
     * Check, if the loaded version of detector supports additional extended counters.
     * If yes, all performance counters are 64-bit values, otherwise some counters are only 32-bit values.
     */
    public static native boolean areAdditionalExtendedCountersEnabled();
}