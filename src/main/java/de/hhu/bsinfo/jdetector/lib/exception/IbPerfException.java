package de.hhu.bsinfo.jdetector.lib.exception;

/**
 * Super-class for all InfiniBand related exceptions.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de
 */
public class IbPerfException extends Exception {

    /**
     * Constructor.
     *
     * @param message Error message
     */
    IbPerfException(String message) {
        super(message);
    }
}
