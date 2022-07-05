![image](https://user-images.githubusercontent.com/80675137/177285252-4d65bbac-234f-46fb-895e-a5f82945cc7f.png)

# Flow :
* When sum = 0, then omly one array can satisfy that i.e. the empty array hence initialize 0th column with 1
* When n = 0, no subset can satisfy sum greater than 0, hence initialize 0th row beginning from 1 with 0
* For every cell check whether sum is greater than or equal to array element
* if lesser simply copy the previous row's value for that particular sum.
* If >= then add previous row's value for that particular sum with what is present on previous row with sum = sum - arr element
* This signifies that in order to bring the current sum how many ways exist
* One way is to include the current element, if we do so then we need to check what were the ways to make the sum when this element was not present i.e. sum - arr element
* One way is to exclude, which basically is present in previous row for that particular value because as we are not including it we are just taking what the results the previous elements brought
