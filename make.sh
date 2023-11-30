echo Starting build...

rm -rf /build 
mkdir build

cd build
cmake ../
make
cd ..

if [ $# -ne 0 ] && [ $1 == 'run' ]
then
    ./build/bin/mapmaker
    code noise.bmp
fi
