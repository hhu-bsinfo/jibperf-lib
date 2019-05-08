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

package de.hhu.bsinfo.jibperf.app;

import de.hhu.bsinfo.jibperf.lib.IbNode;
import de.hhu.bsinfo.jibperf.lib.NativeBuildConfig;
import de.hhu.bsinfo.jibperf.lib.exception.IbPerfException;
import de.hhu.bsinfo.jibperf.lib.exception.IbVerbsException;

public class IbNodeTest {

    private static final String CLASS_NAME = IbNodeTest.class.getSimpleName();

    private static boolean isRunning = true;

    public static void main(String[] args) {
        System.out.printf("Running %s!\nUsing IbPerfLib %s - git %s(%s)\nBuild date: %s\n" +
                        "Additional extended counters: %s\n\n", CLASS_NAME, NativeBuildConfig.getVersion(),
                NativeBuildConfig.getGitRevision(), NativeBuildConfig.getGitBranch(), NativeBuildConfig.getBuildDate(),
                NativeBuildConfig.areAdditionalExtendedCountersEnabled() ? "Enabled" : "Disabled");

        IbNode[] nodes = null;

        try {
            nodes = IbNode.getLocalNodes();
        } catch(IbVerbsException e) {
            e.printStackTrace();
            System.exit(1);
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> isRunning = false));

        while(isRunning) {
            try {
                for(IbNode node : nodes) {
                    node.refreshCounters();
                    System.out.println(node + "\n");
                }

                Thread.sleep(5000);
            } catch(IbPerfException exception) {
                System.out.printf("An exception occurred: %s", exception.getMessage());
            } catch(InterruptedException ignored) {}
        }
    }
}
