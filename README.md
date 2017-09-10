# 42-filler
## Game-playing AI project in C

#### Usage: ./filler_vm -f path [-i | -p1 path | -p2 path] <b>[-s | -q | -t time]
   -t  --time		set timeout in second
   <br>-q  --quiet		quiet mode
   <br>-i  --interactive	interactive mode(default)
   <br>-p1 --player1	use filler binary as a first player
   <br>-p2 --player2	use filler binary as a second player
   <br>-f  --file		use a map file (required)
   <br>-s  --seed		use the seed number (initialization random) (man srand)</b>

The purpose of this project is to write a competitive AI to place more random objects on a playing board than the opponent.

In this game, players are provided with a playing board and starting location. On alternating turns, each player is given the 
updated game board with the opponent's most recent piece placement, and given a random piece shape to place on the board. The 
piece must be placed according to rules:
<br>• The new piece must overlap one and only one grid unit of the current player's existing sprawl.
<br>• The placement coordinates must set the piece such that none of the piece overlaps the oppenent's sprawl nor overflows the playing board boundaries.

The game is won not by covering the most area on the playing board (piece size and shape is completely random), but by whichever player can place the most pieces. Therefore, the strategy is to be able to fill the board in such a way that traps the opponent and prevents them from any further legal placements.

## The Project

The game is played through a provided VM that feeds the text representing the game to each player or player binary in turn. My program must interpret the instructions, board, and new piece as fed through the VM STDIN stream on each turn, and relay only the coordinates as "Y X\n" to the VM STDOUT stream. If the gameplay VM accepts the coordinates as a valid piece placement, the game will continue. If a piece is placed incorrectly, the game will only continue for the other player until they can no longer place a piece.

My program receives will include the which player is which and the original board with board size and starting points: 

[screenshot of what my program reads in]

for contrast, this is the game output to the user:

[screenshot of first turn]

A piece may look something like this:

[screenshot of random piece]

The asterisks represent the body of the piece. Placement rules only apply to the asterisked grid units. The empty (".") spaces are ignored. However, the coordinates of the placement correspont to the top left corner of the piece, whethe it is a filled space or an empty space. Negative integers are valid placement coordinates so long as is still allows all filled spaces on the piece to be placed according to the game rules. Here's another example of a bigger piece with lots of empty space:

[screenshot of large piece]

The bulk of the project is reading the VM input and writing an algorithm to place a piece according to the rules. The basic strategy is to interpret the map into a 2D char array and iterate from negative coordinates all the way until the end of the array or until the the program finds a valid spot to place the piece. Once this basic algortithm has been written, implementing an "attack" strategy becomes an easy fine tuning and tinkering project.

My attack strategy dynamically changes depending on where my starting position is, which walls I've already touched (and therefore halted the opponent in that direction, and the relative position of the opponent's sprawl to my own. I created macros to be able to give more weight to certain strategy (ie do I want to sprint at the opposite wall or do I favor choking out my opponent, how much breathing room do I give my opponent, etc). Once the strategies were weighted in such a manner that I always win on large and medium maps and lose less than 40% of the time on small maps in a disadvantaged starting position, I considered the project complete.

## Project Bonuses

In addition to the efficacy of my attack algorithms, I also included a graphic visualizer for the game. At each turn, it outputs the current game board, with white spaces representing my own sprawl, black spaces representing my opponent, and a green, yellow and red heat map to indicate the attack value of different parts of the game board. 

[screenshot of starting heat map]

This heat map is the best indication of the dynamic switching my program does on certain cues to prioritize different attack strategies.

[screenshots of heat map switching]

## Project Improvements

The attack algorithms can always be improved. An optimal strategy, which I feel was unnecessary to fully complete the project, would include an algorithm that responds to the deviation of the opponent's sprawl to effectively figure out which direction the opponent is trying to head.

An obvious improvement would be to add a Makefile command that would allow me to compile with or without my heat map. It would be relatively simple—the only challenge would be norme compliance. As it is, I have to go into my code and manually add a line to print out the heat map array, which feels ugly.
