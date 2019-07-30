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

package de.hhu.bsinfo.jdetector.app;

import de.hhu.bsinfo.jdetector.lib.IbFabric;
import de.hhu.bsinfo.jdetector.lib.NativeBuildConfig;
import de.hhu.bsinfo.jdetector.lib.exception.*;

public class PerfTest {

    private static boolean isRunning = true;

    public static void main(String[] args) {
        NativeBuildConfig.printBanner();

        if(args.length < 2) {
            System.out.println("Usage: IbPerfTest <network/local> <mad/compat>");
            System.exit(1);
        }

        boolean network = false;
        boolean compatibility = false;

        if(args[0].equals("network")){
            network = true;
        } else if(!args[0].equals("local")){
            System.out.println("Usage: IbPerfTest <network/local> <mad/compat>");
            System.exit(1);
        }

        if(args[1].equals("compat")){
            compatibility = true;
        } else if(!args[1].equals("mad")){
            System.out.println("Usage: IbPerfTest <network/local> <mad/compat>");
            System.exit(1);
        }

        IbFabric fabric = null;

        try {
            fabric = new IbFabric(network, compatibility);
        } catch (IbFileException | IbMadException | IbVerbsException | IbNetDiscException e) {
            e.printStackTrace();
            System.exit(1);
        }

        Runtime.getRuntime().addShutdownHook(new Thread(() -> isRunning = false));

        while(isRunning) {
            try {
                fabric.refreshCounters();
                System.out.println(fabric + "\n");

                Thread.sleep(5000);
            } catch(IbPerfException exception) {
                System.out.printf("An exception occurred: %s", exception.getMessage());
            } catch(InterruptedException ignored) {}
        }
    }
}
