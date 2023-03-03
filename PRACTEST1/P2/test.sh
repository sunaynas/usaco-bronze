g++ -g -o2 -std=c++11 ./main.cpp -o main
for i in {1..11}
do
   echo "testing " + $i 
   time ./main < $i.in > /tmp/a 
   diff -wb /tmp/a $i.out
done