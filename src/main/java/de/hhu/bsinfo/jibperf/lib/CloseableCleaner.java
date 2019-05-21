package de.hhu.bsinfo.jibperf.lib;

class CloseableCleaner implements Runnable {

    private final Closeable closeable;

    CloseableCleaner(Closeable closeable) {
        this.closeable = closeable;
    }

    @Override
    public void run() {
        closeable.close();
    }
}
