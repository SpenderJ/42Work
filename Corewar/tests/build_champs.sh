for file in champs/*.cor
do
	rm "$file" && echo rm "$file"
done
	for file in champs/*.s
do
	echo "$file"
	../asm "$file" >> results0.out
done
