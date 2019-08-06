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

public class IbFabric implements AutoCloseable {

    static {
        JniUtil.loadIbPerfLibJNI();
    }

    private long m_nativeHandle;

    private IbNode[] m_nodes = null;

    public IbFabric(boolean network, boolean compatibility)
            throws IbFileException, IbMadException, IbVerbsException, IbNetDiscException {
        init(network, compatibility);
    }

    private native void init(boolean network, boolean compatibility)
            throws IbFileException, IbMadException, IbVerbsException, IbNetDiscException;

    public native void refreshCounters() throws IbFileException, IbMadException;

    public native void resetCounters() throws IbMadException;

    public int getNumNodes() {
        return m_nodes.length;
    }

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
