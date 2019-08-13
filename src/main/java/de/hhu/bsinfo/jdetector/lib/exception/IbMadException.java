package de.hhu.bsinfo.jdetector.lib.exception;

/**
 * An exception, which signalises an error during an ibmad-operation.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbMadException extends IbPerfException {

    /**
     * Constructor.
     *
     * @param message Error message
     */
    IbMadException(String message) {
        super(message);
    }
}
