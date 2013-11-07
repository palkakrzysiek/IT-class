#! /bin/bash
borlandpath="/home/krzysiek/programy/Borlandc"


#commands=

for n in $@; 
do
    if [[ $n == *cc* ]]; then
        commands="$commands C:\\$n"
    elif [[ $n == *.h* ]]; then
        commands="$commands $n"
        cp $n $borlandpath/BIN
    else
        commands="$commands $n"
    fi
done


echo "
mount d $borlandpath
d:
Set PATH=C:\;D:\BIN;D:\INCLUDE;%PATH%
#cd bin
bcc $commands > C:\OUTPUT.LOG

exit
" > tasks.bat
dosbox tasks.bat
cat OUTPUT.LOG
rm tasks.bat

