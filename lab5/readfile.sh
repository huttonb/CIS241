#code reads line by lied from classes

while read -r field1 field2
do
#commands
    echo $field1
    mkdir -p $field1
    cd $field1
    mkdir $field2
    cd ..
done <"classes"
