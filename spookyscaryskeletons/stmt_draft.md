# Problem
### Time Limit: 7 seconds
### Memory Limit: 1.0 gb

Every Halloween, a group of spooky scary skeletons come together to perform a spooky scary skeleton dance. In this dance, a row N of spooky scary skeletons all dance in a line. There are K different types of spooky scary skeletons, characterized by their bone structure.
<br><br>
Now, to make the spooky scary dance more exciting, there are often time periods known as "Boogies" when an interval of spooky scary skeletons will step out of the line together. This move is considered to be especially spooky scary when all of the spooky scary skeletons can be paired with another spooky scary skeleton of the same type except for exactly 1. In this case, it is known as a "Super Boogie of type k", where k is the type of the spooky scary skeleton that was different.
<br><br>
Given the choreography of a spooky scary skeleton dance, can you identify, for each Boogie, if it was a Super Boogie, and if so, what type of super boogie it was?
<hr>
<h3> Explanation of Test Case</h3>
For example, in the first test case that we have 7 spooky scary skeletons of types [1, 3, 4, 3, 3, 4, 3] dancing in a line.
<br><br>
When the 2nd to 4th Boogie, we have [3, 4, 3]. Since the two types 3 spooky scary skeletons are paired together, and 4 is left over, we should output 4.
<br><br>
When the 2nd to 6th Boogie, we have [3, 4, 3, 3, 4]. Since after we pair up two of the type 3 spooky scary skeletons and the two type 4 spooky scary skeletons, there will be one type 3 spooky scary skeleton remaining, so we should output 3.
<br><br>
When all of them Boogie, we can pair up two type 3 spooky scary skeletons twice, and the type 4 spooky scary skeletons can be paired up once. In the end, we have one type 1 spooky scary skeleton remaining, so we should output 1.
<br><br>
When the first 5 spooky scary skeletons Boogie, we have [1, 3, 4, 3, 3]. Though we can pair up the last two, there will not be exactly one remaining, so the dance is not a Super Boogie, and we should output 0.
<br><br>
When the first 3 spooky scary skeletons Boogie, we have [1, 3, 4] but cannot pair any of them and need to output 0.
<br><br>
Finally, if the 2nd spooky scary skeleton Boogies alone, we get just [3]. In this case, we output 3.


## Input description

The first line contains `N, K, Q`: The number of skeletons, the number of
different types of skeletons, and the number of Boogies. It is guaranteed
that 1 ≤ N ≤ 3,000,000 and that 1 ≤ K ≤ 100,000. It is also guaranteed that 1 ≤ Q ≤ 1,000,000.

The next line contains `N` numbers 1 ≤ s<sub>i</sub> ≤ K: The line of skeletons, and the type of each skeleton.

Finally, there are `Q` lines containing two numbers `l, r` with 1 ≤ l ≤ r ≤ N: the interval of skeletons (inclusive) that step out to boogie.

## Output description

`Q` lines. If the `i`th boogie was a super Boogie of type k<sub>i</sub>, output k<sub>i</sub>. Otherwise, output `0`.

## Test Cases
case0.in

```
7 4 6
1 3 4 3 3 4 3
2 4
2 6
1 7
1 5
1 3
2 2
```

case0.out
```
4
3
1
0
0
3
```

## Explanation of the Test Cases
//Added to descritiption also
For example, in the first test case that we have 7 spooky scary skeletons of types [1, 3, 4, 3, 3, 4, 3] dancing in a line. 

When the 2nd to 4th Boogie,
we have [3, 4, 3]. Since the two type 3 spooky scary skeletons are paired together, and 4 is left over, we should output 4.

When the 2nd to 6th Boogie, we have [3, 4, 3, 3, 4]. Since after we
pair up two of the type 3 spooky scary skeletons and the two type 4 spooky scary skeletons, there
will be one type 3 spooky scary skeleton remaining, so we should output 3.

When all of them Boogie, we can pair up two type 3 spooky scary skeletons twice, and
the type 4 spooky scary skeletons can be paired up once. In the end, we have one
type 1 spooky scary skeleton remaining, so we should output 1.

When the first 5 spooky scary skeletons Boogie, we have [1, 3, 4, 3, 3]. Though
we can pair up the last two, there will not be exactly one remaining,
so the dance is not a Super Boogie and we should output 0.

When the first 3 spooky scary skeletons Boogie, we have [1, 3, 4] but cannot pair any of them and need to output 0.

Finally, if the 2nd spooky scary skeleton Boogies alone, we get just [3]. In this case, we output 3.
