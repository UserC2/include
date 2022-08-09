# include
Useful stuff I wrote because I'm too lazy to find prewritten things. You'll likely need this installed whenever using one of my repos.

Make scripts will expect this to be in the same parent directory as the project **folder** that they are used in.
For example, if the project is in `~/src/project/`, then this should be cloned into `~/src/include/`.

Header guards should follow this format: `C2_INCLUDE_NAMEOFTHING_H`

`FstreamHandler` uses `C2Utility` so make sure to compile `C2Utility.cpp` along with your project.
