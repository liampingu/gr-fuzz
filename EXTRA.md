
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

