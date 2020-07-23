# 2048
Another game, the usual stuff.

## TimeLog: Wed Jul 22 19:13:12 PDT 2020
	About to start, hold up let me git push...

## TimeLog: Wed Jul 22 20:22:35 PDT 2020
	They say wifi came back up, got stuff going...

## TimeLog: Wed Jul 22 20:50:06 PDT 2020
	Big time loss with a bug caused by wrong TILE_SIZE

## TimeLog: Wed Jul 22 21:31:25 PDT 2020
	Figured out the logic for sliding left. Not sure if 2 2 2 2 should turn into 4 4 0 0, or 8 0 0 0. Also both 4 2 8 0 and 2 4 8 0 are valid for 2 2 2 8. Time to see gameplay determine behavior.

## TimeLog: Thu Jul 23 00:24:26 PDT 2020
	Took a break and finding out how to do all four sliding movements with one function was difficult. Tested it also, because it has a lot of edge cases.
