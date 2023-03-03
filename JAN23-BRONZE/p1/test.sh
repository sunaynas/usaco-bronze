g++ -g -O2 -std=c++17 ./main.cpp -o main
for i in {1..10}
do
   echo "testing " + $i 
   ./main < $i.in > /tmp/a 
   diff -wb /tmp/a $i.out
done