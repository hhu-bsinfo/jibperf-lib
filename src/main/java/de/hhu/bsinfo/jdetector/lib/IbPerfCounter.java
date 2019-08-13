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

/**
 * Base class for an implementation that reads InfiniBand performance values.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public interface IbPerfCounter {

    /**
     * Reset all counters.
     */
    void resetCounters() throws IbFileException, IbMadException;

    /**
     * Update all counters. The updated values can be retrieved via the getter-methods.
     */
    void refreshCounters() throws IbFileException, IbMadException;

    /**
     * Get the amount of transmitted data.
     */
    long getXmitDataBytes();

    /**
     * Get the amount of received data.
     */
    long getRcvDataBytes();

    /**
     * Get the amount of transmitted packets.
     */
    long getXmitPkts();

    /**
     * Get the amount of received packets.
     */
    long getRcvPkts();

    /**
     * Get the amount of transmitted unicast packets.
     */
    long getUnicastXmitPkts();

    /**
     * Get the amount of received unicast packets.
     */
    long getUnicastRcvPkts();

    /**
     * Get the amount of transmitted multicast packets.
     */
    long getMulticastXmitPkts();

    /**
     * Get the amount of received multicast packets.
     */
    long getMulticastRcvPkts();

    /**
     * Get the symbol-error counter.
     */
    long getSymbolErrors();

    /**
     * Get the Link-downed counter.
     */
    long getLinkDownedCounter();

    /**
     * Get the link-recovery counter.
     */
    long getLinkRecoveryCounter();

    /**
     * Get the receive-error counter.
     */
    long getRcvErrors();

    /**
     * Get the receive-error counter for physical errors.
     */
    long getRcvRemotePhysicalErrors();

    /**
     * Get the receive-error counter for switch errors.
     */
    long getRcvSwitchRelayErrors();

    /**
     * Get the amount of discarded transmissions.
     */
    long getXmitDiscards();

    /**
     * Get the transmit-error counter for constraint errors.
     */
    long getXmitConstraintErrors();

    /**
     * Get the receive-error counter for constraint errors.
     */
    long getRcvConstraintErrors();

    /**
     * Get the amount of link integrity errors, that occurred.
     */
    long getLocalLinkIntegrityErrors();

    /**
     * Get the amount of buffer overrun errors, that occurred.
     */
    long getExcessiveBufferOverrunErrors();

    /**
     * Get the amount of dropped packets on virtual lane 15.
     */
    long getVL15Dropped();

    /**
     * Get the transmission-wait counter.
     */
    long getXmitWait();
}
