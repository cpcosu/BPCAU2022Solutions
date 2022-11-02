# Tomb Be Decided
#### Runtime Limit: 4.0s
#### Memory Limit: 500.00 MB
## Description
> Dr. Watatack is hiding his treasure in a haunted ancient pyramid. The doctor has converted the structure of the pyramid into a 3D grid. Each point in the 3D grid is given a integer effort score. This number is the amount of effort it takes to dig into that node of the pyramid from an adjacent node. Also, the pyramid is a tetrahedron. From each node you can travel to any of the 12 adjacent nodes in the pyramid: 3 on the layer below, 6 surrounding the node on the same layer, and 3 on the layer above (There will be less than 12 adjacent nodes for nodes on the edge of the pyramid). To help Dr. Watatack, you have been tasked with the challenge of figuring out what location provides the most protection for his treasure. That means you need to find the location in the pyramid that requires the greatest amount of minimum effort to break into. The treasure can be broken into from any node that is on the outside surface of the pyramid (the base is against the ground, so it is not including in outside faces).
## Input
> The first line contains a single integer, n, 1 ≤ n ≤ 100, the length of each side of the pyramid. The rest of the input will contain the pyramid one layer at a time. Each node in the pyramid will an effort v, 1 ≤ n ≤ 1000000.
## Output
> One integer the effort taken to get to location that requires the greatest amount of minimum effort to break into.
## Examples
Cases 0 and 1
