#!/bin/bash
if [[ $(git status -s | grep -v '^$') ]]
then
	FILE=.commit_message
	date "+DATE: %d.%m.%Y%nTIME: %H:%M:%S" > $FILE
	if [ $# -ne 0 ]
	then
		I=1
		echo "Comment:" >> $FILE
		for P in "$@"
		do
			echo -n "$I)" >> $FILE
			echo "$P" >> $FILE
			I=$(( $I + 1 ))
		done
	fi
	echo "Files to commit:" >> $FILE
	git status -s >> $FILE
	echo "====____git add____===="
	git add .
	echo "====    git commit start    ===="
	git commit -F $FILE
	echo "====    git commit end    ===="
	echo "*****   git push start   *****"
	git push
	echo "*****   git push end   *****"
#	if [[ $(git commit --short | grep -v '^$') ]]
#	then
#		echo "___Commit DONE___"
#	else
#		echo "Commit ERROR!"
#	fi
else
	echo "Nothing to be done."
fi
