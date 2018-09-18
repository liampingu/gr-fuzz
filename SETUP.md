
# Setup

### Build afl-fuzz

```
git clone https://github.com/mirrorer/afl
cd afl
make
```

### Install UHD

Optional, unless USRP fucntionality is required. Note that this must be installed **before** building GNURadio, since `cmake` will disable the `gr-uhd` module unless this is found.

```
git clone --recursive git://github.com/EttusResearch/uhd.git
cd uhd/host/
mkdir build
cd build
CC=/path/to/afl-gcc CXX=/path/to/afl-g++ cmake -DCMAKE_BUILD_TYPE=Debug ../
make && make test
sudo make install
```

See `https://files.ettus.com/manual/page_build_guide.html#build_instructions_unix` for more detailed instructions.

### Install GNURadio

GNURadio needs to be compiled with afl `instrumentation`, and so must be built from source:

```
git clone https://github.com/gnuradio/gnuradio.git
cd gnuradio
mkdir build
cd build
CC=/path/to/afl-gcc CXX=/path/to/afl-g++ cmake -DENABLE_DOXYGEN=OFF -DCMAKE_BUILD_TYPE=Debug ../
make && make test
sudo make install
```

See `https://wiki.gnuradio.org/index.php/BuildGuide` for more detailed instructions.

### Install gr-dvbt

Optional, but some fuzz test harness are testing 

```
git clone https://github.com/BogdanDIA/gr-dvbt.git
cd gr-dvbt
mkdir build
cd build
CC=/path/to/afl-gcc CXX=/path/to/afl-g++ cmake -DCMAKE_BUILD_TYPE=Debug ../
make
sudo make install
sudo ldconfig
```

### Install this module

```
git clone https://github.com/liampingu/gr-fuzzing
cd gr-fuzzing
mkdir build
cd build
CC=/path/to/afl-gcc CXX=/path/to/afl-g++ cmake -DCMAKE_BUILD_TYPE=Debug ../
make
sudo make install # to install the tester blocks
```

