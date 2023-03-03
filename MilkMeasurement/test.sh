for TEST in {2..10}
do
   echo "RUNNING TEST ${TEST}"
   ./main < $TEST.in > /tmp/a && diff -wb /tmp/a $TEST.out
done