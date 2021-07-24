# UE4_BP_MazeGen_MIT

'UE4_BP_MazeGenerator' is a free and open source tile-based Maze Generator. The generator supports both in-editor and runtime maze generation and has extensive documentation via the [wiki](https://github.com/frasergeorgeking/UE4_BP_MazeGen_MIT/wiki). Key functionality has been implemented via blueprint as to make the project as accessible as possible.

## Current Project Details
* Latest Main Branch Release: [v2.0.1](https://github.com/frasergeorgeking/UE4_BP_MazeGen_MIT/releases/tag/v2.0.1)
* Unreal Engine Compatibility:
  - 4.25.x (current master branch project version)
  - 4.26.x (available via [release](https://github.com/frasergeorgeking/UE4_BP_MazeGen_MIT/releases/tag/v2.0.1) or in-place upgrade)
  - 5.0 EA (available via [release](https://github.com/frasergeorgeking/UE4_BP_MazeGen_MIT/releases/tag/v2.0.1) - in-place upgrade **not** recommended due to UE5 UI changes)

## Key Functionality
* Maze generator creates [perfect, solvable mazes](http://www.cr31.co.uk/stagecast/wang/perfect.html) through the implementation of a [sidewinder](https://weblog.jamisbuck.org/2011/2/3/maze-generation-sidewinder-algorithm) algorithm
* Key generator functionality written in Blueprint to provide accessibility for artists & designers - also easy to extend & modify!
* Tile-based approach allows for complex tile geometry and maze generation with only 6 base tiles
* Implements Unreal Engine 4's stream-based RNG, thereby enabling the use of custom seeds (ideal for synchronising states over a network etc...)
* Import/Export maze state from .CSV
* Custom Utility Widget for detailed in-engine generation
* Free and Open Source via [MIT License](https://github.com/frasergeorgeking/UE4_BP_MazeGen_MIT/blob/master/LICENSE)
