# chmod +x lab2.sh && ./lab2.sh


# Problem 2.1 Prompt string
# Task: Permanently set URL-like prompt of the form:
# <shell-name>://<username>@<host>/<current-directory><caret-return (CR)>$

echo "PS1=\"\s://\u@\H/\w\r$\"" >> ~/.bash_profile

# Problem 2.2 Annoyingly secure file operations
# Task: Create ``secure'' versions of commands ``rm'', ``cp'' and ``mv'' giving them names ``del'', ``copy'' and ``move'' respectively.

alias del='rm -i'
alias copy='cp -i'
alias move='mv -i'

# Problem 2.3 Who am I and where am I
# Task: Write a short script printing (in consecutive lines) information helpful to absent-minded user:
#
# username,
# man group name,
# all group names, to which the user belongs,
# hostname, on which he is working,
# current directory name.

#chmod a+x [filename]
echo "username: `id -u -n`"
echo "man group name: `id -g -n`"
echo "all group names: `id -G -n`"
echo "hostname: `hostname`"
echo "working directory: `pwd`" 

# Problem 2.4 Mr. Proper
# Task: Write a script cleaning user' home directory and all it's subdirectories from those kinds of files. The command
# ``find'' can be used to search appropriate files (see ``man find'').

find ~ -type f -name '*~' -delete

# Problem 2.5 The machine theat goes ``ping''
# Task: Write a short script emulating the work of ``ping machine''. The sound ``ping'' can be signalled using ``echo''
# command (see ``man echo''), one second pause - using ``sleep'' (see ``man sleep'').

while true; do echo -ne "PING\a\r"; sleep 0.2; echo -ne "     \r"; sleep 0.8; done # if it's possible \a should be interpreted as BEL sound

# Problem 2.6 At exit helpful
# The task is to inform the user being logging out about all processes he is leaving in the system. During main session
# closing a shell (in this case bash) executes ~/.bash_logout script, so this is the file that should be modified. A
# process list can be obtained using ``ps'' command (see ``man ps''). The print should contain parental relations
# among processes in the form of tree or forest (look for appropriate parameters). After describing processes the user
# should be asked to hit any key, after which the screen should be cleaned (see ``man clear''). Waiting on user prompt
# can be done using ``read'' (see ``man bash''), using which 1 character should be read without echo. Maximal wait time
# can also be set.

echo 'ps -ejH; read -p "press any key [auto log off in 10 seconds]" -t 10; clear' >> ~/.bash_logout
chmod a+x ~/.bash_logout

# Problem 2.7 Console clock
# Task: Create a bash script, which will print actual hour time at the console (hour,minutes and seconds - see man
# date). Printing should be done in one line - new values should replace the old ones. It is sugested to perform time
# read not often thant once a second, e.g. using sleep (see man sleep).

# to create script in location /usr/bin root privileges are required 
if [ "$(id -u)" != "0" ]; then
   echo ">You Must Run As Root<" 1>&2
   exit 1
fi
echo "while true; do echo -en \"\`date '+%H:%M:%S'\`\r\"; sleep 1; done" > /usr/bin/showdate
chmod a+x /usr/bin/showdate
# to run script type in terminal "showdate" 

