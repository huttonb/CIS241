
while read x
do
    if [ $1 = "f" ];then
	if [ -f "$x" ];then
	    echo "$x"
	fi
    elif [ $1 = "d" ];then
	if [ -d "$x" ];then
	    echo "$x"
	fi
    fi
    
    #command to process data x
done
