# Zombie Room Keeper
#### Runtime Limit: 1.0s
#### Memory Limit: 500.00 MB
## Description

The room keeper of the Horror Hotel is a zombie! At every night, he takes a sequence of actions with the following rules:
<br><br>
<ol>
<li>An action is either "open the door of room X", "close the door of room X", or "visit room X".</li>
<li>If the action cannot be taken (for instance, the door he want to open is already opened, or the door of the room he want to visit is closed), he will wait until the action is valid.</li>
<li>All the doors are closed at the beginning and should be closed at the end.</li>
</ol>
<br><br>
It works perfectly. The zombie can finish these actions without getting stuck. Until one day, he bit a guest and turned the guest into another zombie! Now, two zombies will take the same sequence of actions in an arbitrary order. Is it possible that they can get into infinite waiting?


## Input

An integer N, 3 ≤ N ≤ 1000 denotes the number of actions. The next N lines contain the actions. An action can be "open the door of room X", "close the door of room X", or "visit room X" where 1 ≤ X ≤ 300. The action sequence is guaranteed legal as described above (one zombie will never get stuck).

## Output

Whether the two zombies may get into infinite waiting. Either "possible" or "impossible".

## Examples

Case 0, 1, and 2.
