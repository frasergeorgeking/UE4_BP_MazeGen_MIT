# UE4_BP_MazeGen_MIT

'UE4_BP_MazeGenerator' is a free and open source tile-based Maze Generator. The generator supports both in-editor and runtime maze generation and has extensive documentation via the [wiki](https://github.com/frasergeorgeking/UE4_BP_MazeGen_MIT/wiki). Key functionality has been implemented via blueprint as to make the project as accessible as possible.

## Current Project Details
* Latest Main Branch Release: v2.0
* Unreal Engine Compatibility: 4.25+

## Key Functionality
* Maze generator creates [perfect, solvable mazes](http://www.cr31.co.uk/stagecast/wang/perfect.html) through the implementation of a [sidewinder](https://weblog.jamisbuck.org/2011/2/3/maze-generation-sidewinder-algorithm) algorithm
* Tile-based not wall-based, allowing for a complex range of custom tile geometry to be utilised
* Implements Unreal Engine 4's stream-based RNG, thereby enabling the use of custom seeds (ideal for synchronising states over a network etc...)
* Import/Export maze state from .CSV
* Custom Utility Widget for detailed in-engine generation
* Free and Open Source via [MIT License](https://github.com/frasergeorgeking/UE4_BP_MazeGen_MIT/blob/master/LICENSE)