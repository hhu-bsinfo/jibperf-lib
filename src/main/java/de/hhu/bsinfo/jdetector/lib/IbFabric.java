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

import de.hhu.bsinfo.jdetector.lib.exception.IbFileException;
import de.hhu.bsinfo.jdetector.lib.exception.IbMadException;
import de.hhu.bsinfo.jdetector.lib.exception.IbNetDiscException;
import de.hhu.bsinfo.jdetector.lib.exception.IbVerbsException;

/**
 * Represents an entire InfiniBand network, which may consist of multiple {@link IbNode}s whith multiple {@link IbPort}s each.
 * 
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbFabric implements AutoCloseable {

    static {
        System.loadLibrary("detectorJNI");
    }

    /**
     * Pointer to the corresponding native object.
     */
    private long m_nativeHandle;

    /**
     * All of the fabric's nodes.
     */
    private IbNode[] m_nodes = null;

    /**
     * Constructor.
     *
     * Scans either the local machine or the entire network for InfiniBand devices.
     *
     * Set compatibility to true, to activate compatibility mode.
     * In this mode, detector will use the filesystem to query performance counters instead of the ibmad-library.
     * In contrary to the ibmad-library, this mode does not require root privileges,
     * but it will only detect local InfiniBand devices, even if you set network to true.
     *
     *
     * CAUTION: This class allocates native resources, which need to be cleared by calling
     *          {@link #close()}, once an instance is not needed anymore.
     *
     * @param network Set to true, to scan the entire network
     * @param compatibility Set to true, to activate compatibility mode
     */
    public IbFabric(boolean network, boolean compatibility) throws IbFileException, IbMadException, IbVerbsException, IbNetDiscException {
        init(network, compatibility);
    }

    /**
     * Initializes this instance of IbFabric. This method is only called by the constructor.
     * It scans for InfiniBand devices and sets up this instance accordingly.
     *
     * @param network Set to true, to scan the entire network
     * @param compatibility Set to true, to activate compatibility mode
     */
    private native void init(boolean network, boolean compatibility) throws IbFileException, IbMadException, IbVerbsException, IbNetDiscException;

    /**
     * Refreshes the performance counters on all nodes in the fabric.
     */
    public native void refreshCounters() throws IbFileException, IbMadException;

    /**
     * Resets the performance counters on all nodes in the fabric.
     */
    public native void resetCounters() throws IbMadException;

    /**
     * Get the amount of nodes in the fabric.
     */
    public int getNumNodes() {
        return m_nodes.length;
    }

    /**
     * Get all of the nodes in the fabric in an array.
     */
    public IbNode[] getNodes() {
        return m_nodes;
    }

    @Override
    public native void close();

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("Discovered ")
                .append(m_nodes.length)
                .append(m_nodes.length == 1 ? " node" : " nodes")
                .append(" in the fabric:\n");

        for(IbNode node : m_nodes) {
            builder.append(node).append("\n");
        }

        builder.setLength(builder.length() - 1);

        return builder.toString();
    }
}
