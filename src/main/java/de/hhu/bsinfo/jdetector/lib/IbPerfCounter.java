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

public interface IbPerfCounter {

    void resetCounters() throws IbFileException, IbMadException;

    void refreshCounters() throws IbFileException, IbMadException;

    long getXmitDataBytes();

    long getRcvDataBytes();

    long getXmitPkts();

    long getRcvPkts();

    long getUnicastXmitPkts();

    long getUnicastRcvPkts();

    long getMulticastXmitPkts();

    long getMulticastRcvPkts();

    long getSymbolErrors();

    long getLinkDownedCounter();

    long getLinkRecoveryCounter();

    long getRcvErrors();

    long getRcvRemotePhysicalErrors();

    long getRcvSwitchRelayErrors();

    long getXmitDiscards();

    long getXmitConstraintErrors();

    long getRcvConstraintErrors();

    long getLocalLinkIntegrityErrors();

    long getExcessiveBufferOverrunErrors();

    long getVL15Dropped();

    long getXmitWait();
}
