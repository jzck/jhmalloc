if [ -z $1 ]
then
	echo "Need an arg";
	exit;
fi
if [ -z $2 ]
then
	make && gcc -w -L. $1 -o .bin -lft_malloc && /usr/bin/time -l ./.bin
else
	make && gcc -w -L. $1 -o .bin -lft_malloc && ./tests/run.sh /usr/bin/time -l ./.bin
fi
