#!/bin/bash
#set -e
declare -a OPTS=('64' '128' '512' '1000' '2000' '4000' '1000000' '10000000' '20000000')

touch results.txt
touch debug.txt
make >> debug.txt


for b in `seq 1 3`; do
  echo "Run  ${b}" >> results.txt
  for i in ${OPTS[@]}; do
    echo "Test  ${i}" >> results.txt
    (time ./demo ${i}) >> results.txt 2>&1
    echo "
    " >> results.txt
    rm -f out
  done
done

echo "Donezo-washington"
