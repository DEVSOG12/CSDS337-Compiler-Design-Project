export CC=/usr/bin/clang
export CXX=/usr/bin/clang++
./build.sh
echo "Running $@" 
bin/LLVM-Lab $@