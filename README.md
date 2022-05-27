# noiseinjekt
A simple C++ library that implements dependecy injection.

![GitHub release (latest by date)](https://img.shields.io/github/v/release/stolosapo/noise-injekt)

![Build](https://github.com/stolosapo/noise-injekt/actions/workflows/makefile.yml/badge.svg) 

### Prepare compilation
```bash
./autogen.sh
```

### Installation
```bash
./configure
make
sudo make install
sudo ldconfig /usr/local/lib
```

### Uninstallation
```bash
sudo make uninstall
```

### Run
```bash
noiseinjekt
```

## Clean all untracked files
```bash
git clean -xdf
```

### Use Library
If everything installed fine then pass `-lnoiseinjekt` parameter in linker, when build your application.
Then use it in your app like in `example/`.
