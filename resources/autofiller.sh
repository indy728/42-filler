export you="../filler"

echo "\x1B[31m    .    _    _ _______ ____      ______ _____ _      _      ___________";
echo "\x1B[32m    /\  | |  | |__   __/ __ \     |  ___|_   _| |    | |    |  ___| ___ \\";
echo "\x1B[33m   /  \ | |  | |  | | | |  | |    | |_    | | | |    | |    | |__ | |_/ /";
echo "\x1B[34m  / /\ \| |  | |  | | | |  | |    |  _|   | | | |    | |    |  __||    /";
echo "\x1B[35m / ____ \ |__| |  | | | |__| |    | |    _| |_| |____| |____| |___| |\ \\";
echo "\x1B[36m/_/    \_\____/   |_|  \____/     \_|    \___/\_____/\_____/\____/\_| \_|\x1B[0m";

echo "\x1B[31m         ___      \x1B[32m  _  __  ___   _   _   __ ___  ___   ___";
echo "\x1B[31m        / o.)_ __ \x1B[32m / |/ /,' _/ .' \ / \,' // o |/ o | / _/";
echo "\x1B[31m       / o \ \V / \x1B[32m/ || /_\ \`. / o // \,' // _,'/  ,' / _/";
echo "\x1B[31m      /___,'  )/ \x1B[32m/_/|_//___,'/_n_//_/ /_//_/  /_/\`_\/___/";
echo "\x1B[31m             //";

echo "\x1B[35m"; for k in {0..75}; do printf "*"; done; echo ""; for k in {0..75}; do printf "*"; done; echo "\x1B[0m\n";

for map in {0..1};	do

	for j in "abanlin.filler" "carli.filler" "champely.filler" "grati.filler" "hcao.filler" "superjeannot.filler"; do

		for i in {1..5}; do
			echo "\033[36mMAP0\033[1m\033[36m$map\033[0m -- \x1B[33mRound $i NORMAL\x1B[0m -- \x1B[31m[P1]\x1B[0m \033[1m\033[31m$you\x1B[0m vs \x1B[32m[P2] \x1B[0m$j\x1B[0m";
			./filler_vm -f maps/map0$map -p1 $you -p2 ./players/$j | grep fin | GREP_COLOR='01;31' egrep --color=always 'O| ' | GREP_COLOR='01;32' egrep -i --color=always 'X| ';
		done;

		for i in {1..5}; do
			echo "\033[36mMAP0\033[1m\033[36m$map\033[0m -- \x1B[33mRound $i REVERSE\x1B[0m -- \x1B[31m[P1] \x1B[0m$j vs \x1B[32m[P2] \033[1m\033[32m$you\x1B[0m";
			./filler_vm -f maps/map0$map -p2 $you -p1 ./players/$j | grep fin | GREP_COLOR='01;31' egrep --color=always 'O| ' | GREP_COLOR='01;32' egrep -i --color=always 'X| ';
		done;

		echo "\x1B[35m"; for k in {0..75}; do printf "*"; done; echo ""; for k in {0..75}; do printf "*"; done; echo "\x1B[0m\n";

	done;
done;

printf "Bonus round ? (y/n) : "; read bonus;
if [ $bonus = "y" ]; then
	echo "\033[36mMAP0\033[1m\033[36m1\033[0m -- \x1B[31m[P1]\x1B[0m \033[1m\033[31m$you\x1B[0m vs \x1B[32m[P2] \033[1m\033[32m$you\x1B[0m";
	./filler_vm -f maps/map01 -p1 $you -p2 $you | grep fin | GREP_COLOR='01;31' egrep --color=always 'O| ' | GREP_COLOR='01;32' egrep -i --color=always 'X| ';
fi;
echo "Done."

exit;
