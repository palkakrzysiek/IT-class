#!/bin/bash

NORMAL="\033[m"
BOLD="\033[1m"
ITALIC="\033[4m"
TERMINALSIZE=`stty size | awk '{ print $2 }'`

VERSION="1.0"
AUTHOR="Krzysztof Palka, IT, 181427"
DATE="May 10, 2013"
HELP="Usage:\

 ${BOLD}${0}${NORMAL} ${ITALIC}user's_file${NORMAL} ${ITALIC}opponent's_file${NORMAL} [${ITALIC}username${NORMAL}];\
 ${BOLD}${0}${NORMAL} [${ITALIC}OPTIONS${NORMAL}] $NORMAL
    OPTIONS:
        -h - show this message
        -v - version of program
Author: $AUTHOR"


USERNAME=$USER
OPPONENTNAME="Opponent"

for ((i=1;i<=$#;i++)); do
    if [[ "${!i}" == "-v" || "${!i}" == "--version" ]]; then
        echo -e "Version: $VERSION\nAuthor: $AUTHOR\nCreated: $DATE"
        exit 0
    fi
    if [[ "${!i}" == "-h" || "${!i}" == "--help" ]]; then
        echo -e "$HELP"
        exit 0
    fi
    if [[ $i == 1 ]]; then
        USERFILEPATH=${!i}
    fi
    if [[ $i == 2 ]]; then
        OPPONETFILEPATH=${!i}
    fi
    if [[ $i == 3 ]]; then 
        if [[ ! ${!i} =~ [\ \t]+ ]]; then
            USERNAME=${!i}
        fi
    fi
done

if [[ $# -lt 2 ||  $# -gt 3 ]]; then
    echo -e "$HELP" >&2
    exit 1
fi

echo "[`date`] $USERFILEPATH $OPPONETFILEPATH $USERNAME" >> log.txt

echo -n "" > $USERFILEPATH
chmod 644 $USERFILEPATH
if [ ! -f $USERFILEPATH ]; then
    echo "[`date`] It's impossible to create file $USERFILEPATH" >&2 >> log.txt
    return 1
fi

i=0
while [[ ! -f $OPPONETFILEPATH  ||  -s $OPPONETFILEPATH ]]; do 
    clear
    echo "Your file has been successfully created. Waiting for your opponent. Try: $(( i += 1 ))"
    sleep 1
done
    

CONTINUEGAME="true"
USERPOINTS="0"
OPPONENTPOINTS="0"
USERMOVES="0"
OPPONENTMOVES="0"

while [[ $USERMOVES -le $OPPONENTMOVES ]] && $CONTINUEGAME; do 
clear
echo -e "\
SCORE: $USERNAME: ${BOLD}${USERPOINTS}${NORMAL} | $OPPONENTNAME: ${BOLD}${OPPONENTPOINTS}${NORMAL}
NUMBER OF TURNS: ${BOLD}${USERMOVES}${NORMAL}"
for ((i=1;i<=${TERMINALSIZE};i++)); do
    echo -ne "="
done
echo -e "
Type \
${ITALIC}paper${NORMAL}, \
${ITALIC}rock${NORMAL}, \
${ITALIC}scissors${NORMAL} or \
${ITALIC}exit${NORMAL} "


    while true; do
        read LASTMOVE
        case $LASTMOVE in
            rock)
                echo "$USERNAME rock" >> $USERFILEPATH
                USERMOVES=$((USERMOVES+1))
                echo -n "Waiting for opponent" 
                break
                ;;
            paper)
                echo "$USERNAME paper" >> $USERFILEPATH
                USERMOVES=$((USERMOVES+1))
                echo -n "Waiting for opponent" 
                break
                ;;
            scissors)
                echo "$USERNAME scissors" >> $USERFILEPATH
                USERMOVES=$((USERMOVES+1))
                echo -n "Waiting for opponent" 
                break
                ;; 
            exit)
                echo "$USERNAME done" >> $USERFILEPATH
                CONTINUEGAME=false
                break 
                ;;
            *)
                echo "Wrong choice, try again:"
                continue 
                ;;
        esac
    done

    while [[ $OPPONENTMOVES -ne $USERMOVES ]]; do
        echo -n "."
        OPPONENTMOVES=`wc -l $OPPONETFILEPATH | awk '{print $1 }'`
        sleep 1
    done
    echo ""
    OPPONENTNAME=`tail -n 1 $OPPONETFILEPATH | awk '{ print $1 }'`
    USERCHOISE=`tail -n 1 $USERFILEPATH | awk '{ print $2 }'` 
    OPPONENTCHOISE=`tail -n 1 $OPPONETFILEPATH | awk '{ print $2 }'`

    if [[ $USERCHOISE == "done" || $OPPONENTCHOISE == "done" ]]; then
        echo "The game has been finished"
        break
    fi

    echo "$USERCHOISE vs $OPPONENTCHOISE"

    if [[ $USERCHOISE == $OPPONENTCHOISE ]]; then
        echo "draw"
    fi

    if [[ $USERCHOISE == "paper" && $OPPONENTCHOISE == "rock" ]]; then
        echo "You win"
        ((USERPOINTS++))
    fi

    if [[ $USERCHOISE == "paper" && $OPPONENTCHOISE == "scissors" ]]; then
        echo "You lose"
        ((OPPONENTPOINTS++))
    fi

    if [[ $USERCHOISE == "rock" && $OPPONENTCHOISE == "scissors" ]]; then
        echo "You win"
        ((USERPOINTS++))
    fi

    if [[ $USERCHOISE == "rock" && $OPPONENTCHOISE == "paper" ]]; then
        echo "You lose"
        ((OPPONENTPOINTS++))
    fi

    if [[ $USERCHOISE == "scissors" && $OPPONENTCHOISE == "paper" ]]; then
        echo "You win"
        ((USERPOINTS++))
    fi

    if [[ $USERCHOISE == "scissors" && $OPPONENTCHOISE == "rock" ]]; then
        echo "You lose"
        ((OPPONENTPOINTS++))
    fi

    read -p "press enter to continue"

done
