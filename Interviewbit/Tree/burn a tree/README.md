![image](https://user-images.githubusercontent.com/80675137/177565297-10553f80-2c01-4ade-93a8-0ff9f6ca4c31.png)

The trick is to use the diameter of the tree concept, but here we just need a little tweak, we want that our diameter to always picks up the given leaf node with value B.

So when the recursive call, comes to the leaf, I return a very high value, and it will ensure that my leaf node always gets picked up.

temp variable -> height
ans variable -> diameter

ans is not really carried forward as we keep storing max diameter in time. So it is not like the typical diamter problem.

10000000 is taken cause there might be a case where there are leaf nodes lower than B, they would be counted in diameter effectively, but we don't want that.
So we forcibly tell diameter variable to choose B by returning a large value
