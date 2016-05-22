apt-get install --yes build-essential xorg-dev libudev-dev libts-dev libgl1-mesa-dev libglu1-mesa-dev libasound2-dev libpulse-dev libopenal-dev libogg-dev libvorbis-dev libaudiofile-dev libpng12-dev libfreetype6-dev libusb-dev libdbus-1-dev zlib1g-dev libdirectfb-dev
mkdir SDL2
cd SDL2
wget http://www.libsdl.org/release/SDL2-2.0.4.tar.gz
tar -xvzf SDL2-2.0.4.tar.gz
cd SDL2-2.0.4
./configure
make
make install
