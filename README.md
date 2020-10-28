# 2048

This is a 2048 recreation made in C with the help of the SDL2.0 graphics library. All assets were made by hand with the pixel editor [aseprite](https://www.aseprite.org/). Color for each tile is changed by an SDL function. This project was made after having made several other SDL projects ([chess](https://github.com/ASSERT-game/chess), [flappy bird](https://github.com/ASSERT-game/flappy_bird), and [pacman](https://github.com/ASSERT-game/pac_man)). I wanted to see how much I had improved and the progress I had made in coding. Below you will see a Timelog that I recorded to have a record of my progress. This was possible because of practice and having created tools like [SDL_2D_init](https://github.com/MrColour/SDL_2D_init).

<br>
<img align="top" height="250" src="https://github.com/ASSERT-game/2048/tree/master/resources/2048_gameplay.gif" />
<br>


## TimeLog: Wed Jul 22 19:13:12 PDT 2020
	About to start, hold up let me git push...

## TimeLog: Wed Jul 22 20:22:35 PDT 2020
	They say wifi came back up, got stuff going...

## TimeLog: Wed Jul 22 20:50:06 PDT 2020
	Big time loss with a bug caused by wrong TILE_SIZE

## TimeLog: Wed Jul 22 21:31:25 PDT 2020
	Figured out the logic for sliding left. Not sure if 2 2 2 2 should turn into 4 4 0 0, or 8 0 0 0. Also both 4 2 8 0 and 2 4 8 0 are valid for 2 2 2 8. Time to see gameplay to determine behavior.

## TimeLog: Thu Jul 23 00:24:26 PDT 2020
	Took a break and finding out how to do all four sliding movements with one function was difficult. Tested it also, because it has a lot of edge cases.

## TimeLog: Thu Jul 23 01:07:12 PDT 2020
	There are bugs =[

## TimeLog: Thu Jul 23 02:36:05 PDT 2020
	Play testing! But also then found a bug, will rewrite the update function to be robust...

## TimeLog: Thu Jul 23 21:40:08 PDT 2020
	Back at it now, give me a few seconds to git push and fix that bug from earlier...

## TimeLog: Fri Jul 24 00:44:11 PDT 2020
	I had finished earlier but played until I was able to overflow the 2048 block. Really fun game.
