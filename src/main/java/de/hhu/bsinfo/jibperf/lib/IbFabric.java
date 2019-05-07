package de.hhu.bsinfo.jibperf.lib;

import de.hhu.bsinfo.jibperf.lib.exception.IbFileException;
import de.hhu.bsinfo.jibperf.lib.exception.IbMadException;
import de.hhu.bsinfo.jibperf.lib.exception.IbNetDiscException;
import de.hhu.bsinfo.jibperf.lib.exception.IbVerbsException;

import java.io.IOException;

public class IbFabric {

    private long m_nativeHandle = 0;

    private IbNode[] m_nodes = null;

    public IbFabric(boolean compatibility) throws IbFileException, IbMadException, IbVerbsException, IbNetDiscException {
        init(compatibility);
    }

    private native void init(boolean compatibility) throws IbFileException, IbMadException, IbVerbsException;

    public native void refreshCounters() throws IbFileException, IbMadException;

    public native void resetCounters() throws IbMadException;

    public native void close();

    public int getNumNodes() {
        return m_nodes.length;
    }

    public IbNode[] getNodes() {
        return m_nodes;
    }

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
