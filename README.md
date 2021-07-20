# jDetector

<p align="center">
<img src="logo.svg" height=175>
</p>

<p align="center">
<a href="https://travis-ci.com/hhu-bsinfo/jdetector"><img src="https://travis-ci.org/hhu-bsinfo/jdetector.svg?branch=master"></a>
  <a href="https://openjdk.java.net/projects/jdk8/"><img src="https://img.shields.io/badge/java-8-blue.svg"></a>
<a href="https://github.com/hhu-bsinfo/observatory/blob/master/LICENSE"><img src="https://img.shields.io/badge/license-GPLv3-orange.svg"></a>
</p>

This library is a JNI-wrapper for <a href="https://github.com/hhu-bsinfo/detector">Detector</a>, which enables Java programs to read the performance counters of all InfiniBand devices in a network.

# Build instructions

This project consists of a Java and a native component, which need to be build independently.  
The native library depends on the *ibmad*- and *ibnetdisc*-, as well as the *ibverbs*-libraries. You need to have these installed on your system, in order to build and use jDetector.  
Since Ubuntu 18.04 (or Debian 10) these libraries are provided by the rdma-core package. To install it, you can issue the following command:

```
sudo apt install rdma-core
```

On older Debian-based systems, you need to install the libraries seperately, using this command:

```
sudo apt install libibverbs-dev libibmad-dev libibumad-dev libibnetdisc-dev libopensm-dev
```

To now build the native library, make sure CMake is installed on your system and run:

```
./gradlew cmakeBuild
```

For ease of use, you can now copy the library from `build/libs/libdetectorJNI.so` to somewhere your `LD_LIBRARY_PATH` points (e.g. `/usr/lib/`). Otherwise, you need to specify the the library's path every time you run a program depending on jDetector, using either `LD_LIBRARY_PATH` or `java -Djava.library.path`.

Building the Java component does not require any special preparation. You can just run:

```
./gradlew jar
```

# Include in other projects

It is possible to use jDetector in other Gradle projects. The latest releases are available from the GitHub Package Registry.
To include jDetector into your project, use the following code in your `build.gradle`:

```
repositories {
    maven {
        name = "GitHubPackages jDetector"
        url = "https://maven.pkg.github.com/hhu-bsinfo/jdetector"
        credentials {
            username = project.findProperty("gpr.user")
            password = project.findProperty("gpr.token")
        }
    }
}

dependencies {
    implementation 'de.hhu.bsinfo:jdetector:0.1.1'
}
```

Use a file called `gradle.properties` to set `gpr.user` to your GitHub username and `gpr.token` to a Personal Access Token with `read:packages` enabled. See the [GitHub Docs](https://docs.github.com/en/packages/working-with-a-github-packages-registry/working-with-the-gradle-registry) for mor information on the GitHub Package Registry.

# Usage

Using jDetector is very simple and does not require a lot of code. To scan for InfiniBand devices, you just need to create an instance of `IbFabric`:

```
boolean network = true;
boolean compatibility = true;
IbFabric fabric = null;

try {
    fabric = new IbFabric(network, compatibility);
} catch (IbFileException | IbMadException | IbVerbsException | IbNetDiscException e) {
    e.printStackTrace();
}
```

The parameters `network` and `compatibility` determine how your network will be scanned. See [Run instructions](#run-instructions
) for more detail on these parameters.

`IbFabric` provides an array of nodes, that have been found in your network, while each node has an array of ports. To print out the amount of transmitted bytes of each port, you can use the following code:

```
for(IbNode node : fabric.getNodes()) {
    for(IbPort port : node.getPorts()) {
        System.out.println(node.getDescription() + " (port " + port.getNum() + "): " + port.getXmitDataBytes() + " Bytes");
    }
}
```

This will output a string like that for every device:

```
mlx4_0 (port 1): 25672032 Bytes
```

It is also possible to get aggregated counters for a whole node, by calling the getter-methods on an `IbNode` object.

To refresh or reset the counters of a node or port, you can call `refreshCounters()` or `resetCounters()` respectively.  
It is also possible to refresh/reset the counters of the whole fabric at once.

# Run instructions

jDetector comes with two small test programs called *PerfTest* and *DiagTest*.  

*PerfTest* scans your InfiniBand network for devices and prints their counters to `System.out`, while *DiagTest* prints the diagnostic counters of your local infiniBand devices.

To build and run *PerfTest*, you can use these commands:

```
./gradlew cmakeBuild jar
sudo java -Djava.library.path=build/libs/ -cp build/libs/jdetector-0.1.0-SNAPSHOT.jar de.hhu.bsinfo.jdetector.app.PerfTest network mad
```

*PerfTest* can either scan your entire network or only your local machine. This is determined by the first parameter (`network`/`local`).  
The second parameter determines, whether to use the ibmad-library or run in compatibility mode (`mad`/`compat`).

In compatibility mode, the performance counters are read using the filesystem. In contrary to `mad`, this mode does not require root privileges, however it will only work for local InfiniBand devices.

To run DiagTest, run the following command:

```
sudo java -Djava.library.path=build/libs/ -cp build/libs/jdetector-0.1.0-SNAPSHOT.jar de.hhu.bsinfo.jdetector.app.DiagTest
```