var=0
# This will run our compiler on a C file, export its LLVM ASM to a .ll file and output how it went to the log.
# The LLVM ASM is than ran and its outut sent to the execution log.
function runTest {
    # var passed
    ./run.sh -i tests/$1.py -fAsm -o tests/$1.ll &> tests/$1.log
    lli tests/$1.ll &> tests/$1Execution.log 
    python3 tests/$1.py &> tests/$1Python.log
   
    diff tests/$1Execution.log tests/$1Python.log
    if [ $? -eq 0 ]; then
        echo "Test $1 passed ✅"
    else
        echo "Test $1 failed ❌"
        var=1
    fi
}

# Run all the python  file tests.
for file in "tests"/*.py; do
    file=$(basename $file .py)
    echo "Testing: $file"
    runTest $file
done

# if all passed then echo fire 🔥    
if [ $var -eq 0 ]; then
    echo "That's fire 🔥🔥🔥"
fi

if [ $var -eq 1 ]; then
    echo "That's not fire"
fi