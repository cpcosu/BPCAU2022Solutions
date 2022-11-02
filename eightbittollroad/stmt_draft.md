*This is not the final problem statement. For presenting the concept only.*

# 8-bit Toll Road
#### Runtime Limit: 5.0s
#### Memory Limit: 500.00 MB
## Description
> Mr. Mario is driving from city 1 to city 2 to get to his friends Halloween party. He can only take some one-way toll roads for $1 per mile. The good news is, most facilities in the world, including the toll roads' charging system, are in 8-bit which will cause overflow. For instance, he must pay $44 if his total driving distance is 300 miles. And if he drives 256 miles, he can pass for free! Your job is to help him find the cheapest route breaking tie by shortest distance.
## Input
> First line is one integer N, 1 ≤ N ≤ 2000 denotes the number of toll roads. The next N lines will have three integers S, T, and L, 1 ≤ S, T ≤ 1000, 1 ≤ L ≤ 1000000 denotes the start city, end city, and length of each toll road. The start and end points are guaranteed to be connected.
## Output
> Two numbers in one line: the minimum cost and the distance.
## Examples
|Inputs|Outputs|
| :--- | :--- |
| 4<br>1 3 100<br>1 4 200<br>3 2 300<br>4 2 400<br> | 88 600<br> |
| 5<br>1 3 100<br>1 4 200<br>3 2 300<br>4 2 400<br>2 3 340<br> | 16 1040<br> |
