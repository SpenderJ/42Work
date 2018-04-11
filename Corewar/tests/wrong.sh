for file in wrong_asm/*
do
	../asm "$file"
done
for file in champs/errors/*
do
	echo "$file"
	../asm "$file"
done
