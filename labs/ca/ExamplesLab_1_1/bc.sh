#! /bin/bash
borlandpath="/home/krzysiek/programy/Borlandc"


echo "
mount d $borlandpath
d:
Set PATH=C:\;D:\BIN;D:\INCLUDE;%PATH%
#cd bin
bc $@

" > tasks.bat
dosbox tasks.bat
rm tasks.bat

