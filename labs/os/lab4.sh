#!/bin/bash

VERSION="0.1"
HELP="Usage: $0 user's_file opponent's_file [username]\n\
        -h - show this message\n\
        -v - version of program"


USERNAME=$USER

for ((i=1;i<=$#;i++)); do
    if [ "${!i}" == "-v" ]; then
        echo "$VERSION"
        exit 0
    fi
    if [ "${!i}" == "-h" ]; then
        echo -e "$HELP"
        exit 0
    fi
    if [ $i == 1 ]; then
        USERFILEPATH=${!i}
    fi
    if [ $i == 2 ]; then
        OPPONETFILEPATH=${!i}
    fi
    if [ $i == 3 ]; then 
        if [[ ! ${!i} =~ [\ \t]+ ]]; then
            USERNAME=${!i}
        fi
    fi
done

if [ $# -lt 2 ] || [ $# -gt 3 ]; then
    echo -e "$HELP" >&2
    exit 1
fi

echo "[`date`] $USERFILEPATH $OPPONETFILEPATH $USERNAME" >> log.txt

< /dev/zero head -c 0 > $USERFILEPATH
chmod 644 $USERFILEPATH
if [ ! -f $USERFILEPATH ]; then
    echo "[`date`] It's impossible to create file $USERFILEPATH" >&2 >> log.txt
    return 1
fi

i=0
while [ ! -f $OPPONETFILEPATH ] || [ -s $OPPONETFILEPATH ]; do 
    clear
    echo "Your file has been successfully created. Waiting for your opponent. Try: $(( i += 1 ))"
    sleep 1
done
    

CONTINUEGAME="true"
USERPOINTS="0"
OPPONENTPOINTS="0"
USERMOVES="0"
OPPONENTMOVES="0"

while [ $USERMOVES -le $OPPONENTMOVES ] && $CONTINUEGAME; do 
clear
echo "$USERMOVES $OPPONENTMOVES"
    while true; do
        read LASTMOVE
        echo $LASTMOVE
        case $LASTMOVE in
            rock)
                echo "$USERNAME rock" >> $USERFILEPATH
                USERMOVES=$((USERMOVES+1))
                break
                ;;
            paper)
                echo "$USERNAME paper" >> $USERFILEPATH
                USERMOVES=$((USERMOVES+1))
                break
                ;;
            scissors)
                echo "$USERNAME scissors" >> $USERFILEPATH
                USERMOVES=$((USERMOVES+1))
                break
                ;; 
            exit)
                echo "$USERNAME done" >> $USERFILEPATH
                CONTINUEGAME=false
                break 
                ;;
            *)
                continue 
                ;;
        esac
    done
    while [ $OPPONENTMOVES -ne $USERMOVES ]; do
        echo -n "."
        OPPONENTMOVES=`wc -l $OPPONETFILEPATH | awk '{print $1 }'`
        ((OPPONENTMOVES--))
        sleep 1
    done
    USERCHOISE=`tail -n 1 $USERFILEPATH | awk '{ print $2 }'` 
    OPPONENTCHOISE=`tail -n 1 $OPPONETFILEPATH | awk '{ print $2 }'`
    echo "$USERCHOISE vs $OPPONENTCHOISE"

done
    

