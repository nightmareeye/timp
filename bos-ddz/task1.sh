#!/bin/bash
read d2;
read d1;
read fn;
N1=18; N3=1;
for N2 in 2 3 4 5
do 
var1=`awk 'END{print NR}' ./$d1/$N2.txt`
var2=$(((((($N1+$N2*$N3))%$var1))+1)) 
string=`awk 'NR=='$var2' {print; exit}' ./$d1/$N2.txt`
cd ./$d2
touch task$N2-$var2.sh
echo "#!/bin/bash" >> task$N2-$var2.sh
echo $fn >> task$N2-$var2.sh
echo "$string" >> task$N2-$var2.sh
cd ..
done
echo "done"
