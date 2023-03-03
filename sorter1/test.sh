for idx in {1..5} 
do
echo "sort Test  $idx"
./sorter < "sorttest${idx}.input" > "/tmp/sorttest${idx}.output"
diff -wc "/tmp/sorttest${idx}.output" "./sorttest${idx}.output"  > /dev/null || echo "Failed test sorttest${idx}.input"
done