clear

mkdir -p build
cd build

mkdir -p linux
cd linux

mkdir -p cmake
mkdir -p out
cd cmake

cmake ../../../
make

mv mw_website ../out
cd ../out

cp ../../../config/server.config ./server.config
cp -r ../../../website ./
chmod +x mw_website

echo ""
./mw_website
