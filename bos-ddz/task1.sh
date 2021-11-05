#!/bin/bash
N1=$(echo $3 | head --bytes=9 | tail --bytes=2)
xx=$(echo $3 | head --bytes=6 | tail --bytes=1)
N3=$(($xx-2))
for N2 in 2 3 4 5
do 
	var1=`awk 'END{print NR}' ./$2/$N2.txt`
	var2=$(((((($N1+$N2*$N3))%$var1))+1)) 
	string=`awk 'NR=='$var2' {print; exit}' ./$2/$N2.txt`
	cd ./$1
	touch task$N2-$var2.sh
	echo "#!/bin/bash" >> task$N2-$var2.sh
	echo "#$3" >> task$N2-$var2.sh
	echo "#$string" >> task$N2-$var2.sh
	cd ..
done
echo "done"
