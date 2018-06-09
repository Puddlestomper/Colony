


//Will take in an image file and return what is needed to encode the map to be used in Colony
//Possibly output a .clnymap file that will contain all needed data
class MapEncoder
{

};

/*Design of .clnymap:
-Start with string "ColonyMapFile" (13 bytes)
-Single byte for amount of different cells (1 byte)
-Data for each cell:
	+RGB colour value (3 bytes)
	+Number of effects (1 byte)
	+Data for effects (there will only be certain predetermined effects available)
-Unsigned short for width (2 bytes)
-Unsigned short for height (2 bytes)
-Map Data consisting of a single byte per tile referencing tile number (width * height bytes)
*/

//Note: Tile number 255 will be reserved for empty tiles