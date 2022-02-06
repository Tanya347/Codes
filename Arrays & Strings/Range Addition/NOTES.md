```
This question uses the concept of prefix sum.


We first update the start indices everywhere with the increment value and replace the next index of end 
index with negative of the increment value. We do this to remove the effect of that particular increment 
value when we continue adding the previous sums. 


After doing so, we just replace every element with its prefix sum.
```
